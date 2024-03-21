
#include "mcal_external_interrupt.h"




static void (* INT0_Handler)(void)=NULL;
static void (* INT1_Handler)(void)=NULL;
static void (* INT2_Handler)(void)=NULL;



static Std_ReturnType Interrupt_INTx_Enable(uint8_t INTx_index);
static Std_ReturnType Interrupt_INTx_Disable(uint8_t INTx_index);
static Std_ReturnType Interrupt_INTx_clear_flag(uint8_t INTx_index);
static Std_ReturnType Interrupt_INTx_pin_init(uint8_t INTx_index);
static Std_ReturnType Interrupt_INTx_Set_Priority(uint8_t INTx_index, uint8_t priority);
static Std_ReturnType Interrupt_INTx_Set_Edge(uint8_t INTx_index, uint8_t edge);
static Std_ReturnType Interrupt_INTx_Set_INT_Handler(uint8_t INTx_index, void(* INT_handler)(void));


Std_ReturnType Interrupt_INTx_Init(ext_INTx_config_t * intx_config){
    Std_ReturnType ret = E_OK;
    if (intx_config == NULL)
    {
        return E_NOT_OK;
    }
    else{
        /*ENABLE GLOBAL/HIGH-LOW Interrupt*/
        #if (INTERRUPT_PRIORITY_LEVELS)
        /* priority levels interrupts */
        INTERRUPT_PRIORITY_ENABLE()
        INTERRUPT_GLOBAL_HIGH_ENABLE();
        INTERRUPT_GLOBAL_LOW_ENABLE();
        #else
        /* non priority interrupts */
        INTERRUPT_GLOBAL_ENABLE();
        INTERRUPT_PERIFERALS_ENABLE();
        #endif
        /*Disable INTx */
        ret |= Interrupt_INTx_Disable( intx_config->INTx_index );
        /*Clear Flag bit */
        ret |= Interrupt_INTx_clear_flag(intx_config->INTx_index);
        #if (INTERRUPT_PRIORITY_LEVELS)
        /*set priority*/
        ret |= Interrupt_INTx_Set_Priority(intx_config->INTx_index, intx_config->priority);
        #endif
        /*set edge*/
        ret |= Interrupt_INTx_Set_Edge(intx_config->INTx_index, intx_config->i_edge);
        /*INIT I/O PIN*/
        ret |= Interrupt_INTx_pin_init(intx_config->INTx_index);
        /*call the handler callback*/
        ret |= Interrupt_INTx_Set_INT_Handler(intx_config->INTx_index, intx_config->ext_interrupt_handler);
        /*Enable INT if disabled*/
        ret |= Interrupt_INTx_Enable(intx_config->INTx_index);
    }
}
Std_ReturnType Interrupt_INTx_DeInit(ext_INTx_config_t * intx_config){
    Std_ReturnType ret = E_OK;
    if (intx_config == NULL)
    {
        return E_NOT_OK;
    }
    ret =  Interrupt_INTx_Disable(intx_config->INTx_index);
    if (intx_config->INTx_index == 0)       {INT0_Handler = NULL;}
    else if (intx_config->INTx_index == 1)  {INT1_Handler = NULL;}
    else if (intx_config->INTx_index == 2)  {INT2_Handler = NULL;}
    return ret;
}

Std_ReturnType Interrupt_RBx_Init(ext_RBx_config_t * RBx_config){
    
}
Std_ReturnType Interrupt_RBx_DeInit(ext_RBx_config_t * RBx_config){
    
}


void INT0_ISR(void){
    INT0_CLEAR_INTERRUPT_FLAG();
    /* code in MCAL context*/
    
    /*callback APP. ISR*/
    if (INT0_Handler) {
        INT0_Handler();
    }
}
void INT1_ISR(void){
    INT1_CLEAR_INTERRUPT_FLAG();
    /* code in MCAL context*/
    
    /*callback APP. ISR*/
    if (INT1_Handler) {
        INT1_Handler();
    }
}
void INT2_ISR(void){
    INT2_CLEAR_INTERRUPT_FLAG();
    /* code in MCAL context*/
    
    /*callback APP. ISR*/
    if (INT2_Handler) {
        INT2_Handler();
    }
}


static Std_ReturnType Interrupt_INTx_Enable(uint8_t INTx_index){
    Std_ReturnType ret = E_NOT_OK;
    
    if (INTx_index > 2){
        ret = E_NOT_OK;
    }
    if (INTx_index == 0){
        INT0_INTERRUPT_ENABLE();
        ret = E_OK;
    }
    else if(INTx_index == 1){
        INT1_INTERRUPT_ENABLE();
        ret = E_OK;
    }
    else if(INTx_index == 2){
        INT2_INTERRUPT_ENABLE();
        ret = E_OK;
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_Disable(uint8_t INTx_index){
    Std_ReturnType ret = E_NOT_OK;
    if (INTx_index > 2){
        ret = E_NOT_OK;
    }
    if (INTx_index == 0){
        INT0_INTERRUPT_DISABLE();
        ret = E_OK;
    }
    else if(INTx_index == 1){
        INT1_INTERRUPT_DISABLE();
        ret = E_OK;
    }
    else if(INTx_index == 2){
        INT2_INTERRUPT_DISABLE();
        ret = E_OK;
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_clear_flag(uint8_t INTx_index){
    Std_ReturnType ret = E_NOT_OK;
    if (INTx_index > 2){
        ret = E_NOT_OK;
    }
    if (INTx_index == 0){
        INT0_CLEAR_INTERRUPT_FLAG();
        ret = E_OK;
    }
    else if(INTx_index == 1){
        INT1_CLEAR_INTERRUPT_FLAG();
        ret = E_OK;
    }
    else if(INTx_index == 2){
        INT2_CLEAR_INTERRUPT_FLAG();
        ret = E_OK;
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_pin_init(uint8_t INTx_index){
    Std_ReturnType ret = E_NOT_OK;
    pin_config_t pin = {
        .port_index = PORTB_INDEX,
        .pin_index = PIN0,
        .direction = INPUT_DIRECTION
    };
    
    if (INTx_index > 2){
        ret = E_NOT_OK;
    }
    if (INTx_index == 0){
        pin.pin_index = PIN0;
    }
    else if(INTx_index == 1){
        pin.pin_index = PIN1;;
    }
    else if(INTx_index == 2){
        pin.pin_index = PIN2;
    }
    
    ret = gpio_pin_initialize(&pin);
    return ret;
}
#if (INTERRUPT_PRIORITY_LEVELS)
static Std_ReturnType Interrupt_INTx_Set_Priority(uint8_t INTx_index, uint8_t priority){
    Std_ReturnType ret = E_NOT_OK;
    if (priority>1 || INTx_index>2){
        ret = E_NOT_OK;
    }

    if (INTx_index == 0){
        //Nothing INT0 has fixed high P
    }
    else if(INTx_index == 1){
        if (priority == 0)      {INT1_LOW_PRIOTIRY_SET();}
        else if (priority == 1) {INT1_HIGH_PRIOTIRY_SET(); }
        ret = E_OK;
    }
    else if(INTx_index == 2){
        if (priority == 0)      {INT2_LOW_PRIOTIRY_SET();}
        else if (priority == 1) {INT2_HIGH_PRIOTIRY_SET(); }
        ret = E_OK;
    }
    
    return ret;
}
#endif
static Std_ReturnType Interrupt_INTx_Set_Edge(uint8_t INTx_index, uint8_t edge){
    Std_ReturnType ret = E_NOT_OK;
    if (edge>1 || INTx_index>2){
        ret = E_NOT_OK;
    }
    if (INTx_index == 0){
        if (edge == 0)      {INT0_FALLING_EDGE_SET();}
        else if (edge == 1) {INT0_RISING_EDGE_SET(); }
        ret = E_OK;
    }
    else if(INTx_index == 1){
        if (edge == 0)      {INT1_FALLING_EDGE_SET();}
        else if (edge == 1) {INT1_RISING_EDGE_SET(); }
        ret = E_OK;
    }
    else if(INTx_index == 2){
        if (edge == 0)      {INT2_FALLING_EDGE_SET();}
        else if (edge == 1) {INT2_RISING_EDGE_SET(); }
        ret = E_OK;
    }
    
    return ret;
}
static Std_ReturnType Interrupt_INTx_Set_INT_Handler(uint8_t INTx_index, void(* INT_handler)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if (INTx_index>2 || NULL == INT_handler){
        ret = E_NOT_OK;
    }
    
    if (INTx_index == 0){
        INT0_Handler = INT_handler;
        ret = E_OK;
    }
    else if(INTx_index == 1){
        INT1_Handler = INT_handler;
        ret = E_OK;
    }
    else if(INTx_index == 2){
        INT2_Handler = INT_handler;
        ret = E_OK;
    }
    
    return ret;
}