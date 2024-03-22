/* 
 * File:   hal_usart.c
 * Author: Joe
 *
 * Created on March 21, 2024, 7:20 AM
 */

#include "hal_usart.h"



#if (INTERRUPT_FEATURE)
static void (* usart_rx_interrupt_handler)(uint8_t data_8_bits,uint8_t bit_9)=NULL;
static void (* usart_rx_overrun_interrupt_handler)(void)=NULL;
static void (* usart_rx_framing_interrupt_handler)(void)=NULL;
static volatile uint8_t rx_data_8;
static volatile uint8_t rx_bit_9;

#endif

static inline void set_bauderate_configs(uint32_t baudrate);
static inline void set_tris_registers(void);


void USART_RX_ISR(void){
    if (usart_rx_interrupt_handler){
        rx_data_8 = RCREG ; 
        rx_bit_9 = ( RCSTAbits.RX9D) ;  
        usart_rx_interrupt_handler(rx_data_8,rx_bit_9);
    }
    if (usart_rx_overrun_interrupt_handler){
        usart_rx_overrun_interrupt_handler();
    }
    if (usart_rx_framing_interrupt_handler){
        usart_rx_framing_interrupt_handler();
    }
}


Std_ReturnType usart_tx_init(usart_tx_t *usart_config){
    Std_ReturnType ret = E_OK;
    
    if (NULL == usart_config){
        ret= E_NOT_OK;
    }
    else{
        /*disable USART TX*/
        USART_TX_DISABLE();
        /*set BAUDRATE configuration*/
        set_bauderate_configs(usart_config->baudrate);
        /*set tris bit to 1 */
        set_tris_registers();
        /* Enable the asynchronous serial port by clearing the SYNC bit and setting the SPEN bit*/
        USART_SET_ASYNC_MODE();
        USART_SERIAL_PORT_ENABLE();
        /*handle 9th bit if enabled*/
        USART_SET_8BIT_TX();
        if (usart_config->is_9bit){
            USART_SET_9BIT_TX();
        }
        
        /*enable USART TX*/
        USART_TX_ENABLE();
        
    }
    
    return ret;
    
}
Std_ReturnType usart_tx_deinit(usart_tx_t *usart_config){
    if (NULL == usart_config){
        return E_NOT_OK;
    }
    else{
        USART_TX_DISABLE();
        return E_OK;
    }
}
Std_ReturnType usart_tx_write_byte_blocking(uint8_t data){
    while(!TXSTAbits.TRMT);
    TXREG = data;
    return E_OK;
}
Std_ReturnType usart_tx_write_9_bits_blocking(uint16_t data){
    while(!TXSTAbits.TRMT);
    TXREG = data;
    TXSTAbits.TX9D = (data>>8)&(0x01);
    return E_OK;
}


Std_ReturnType usart_rx_init(usart_rx_t *usart_config){
    Std_ReturnType ret = E_OK;
    
    if (NULL == usart_config){
        ret= E_NOT_OK;
    }
    else{
        /*disable USART TX*/
        USART_RX_DISABLE();
        /*set BAUDRATE configuration*/
        set_bauderate_configs(usart_config->baudrate);
        /*set tris bit to 1 */
        set_tris_registers();
        /* Enable the asynchronous serial port by clearing the SYNC bit and setting the SPEN bit*/
        USART_SET_ASYNC_MODE();
        USART_SERIAL_PORT_ENABLE();
        /*handle 9th bit if enabled*/
        USART_SET_8BIT_RX();
        if (usart_config->is_9bit){
            USART_SET_9BIT_RX();
        }
        /*configure interrupt*/
#if (INTERRUPT_FEATURE)
        if (usart_config->interrupt_enable == USART_STD_ENABLE){
            
            INTERRUPT_GLOBAL_ENABLE();
            INTERRUPT_PERIFERALS_ENABLE();
            USART_RX_INTERRUPT_ENABLE();

            usart_rx_interrupt_handler = usart_config->rx_interrupt_handler;
            usart_rx_framing_interrupt_handler = usart_config->rx_framing_error_handler;
            usart_rx_overrun_interrupt_handler = usart_config->rx_overrun_error_handler;
        
#if (INTERRUPT_PRIORITY_LEVELS)
        INTERRUPT_PRIORITY_ENABLE();
        if (usart_config->interrupt_priority == HIGH_PRIORITY)
        {
            USART_RX_HIGH_PRIOTIRY_SET();     
        }
        else{
            
            USART_RX_LOW_PRIOTIRY_SET();
        }
#endif
#endif
        }
        /*enable USART TX*/
        USART_RX_ENABLE();
    }
    
    return ret;
    
}
Std_ReturnType usart_rx_deinit(usart_rx_t *usart_config){
    if (NULL == usart_config){
        return E_NOT_OK;
    }
    else{
        USART_RX_DISABLE();
        return E_OK;
    }
}
Std_ReturnType usart_rx_read_byte_blocking(uint8_t *data_8){
    while(!PIR1bits.RCIF);
    *data_8 = RCREG;
    return E_OK;
}
Std_ReturnType usart_rx_read_9bits_blocking(uint16_t *data_9){
    while(!PIR1bits.RCIF);
    *data_9 = RCREG;
    *data_9 += (uint16_t)(RCSTAbits.RX9D << 8);
    return E_OK;
}

static inline void set_bauderate_configs(uint32_t baudrate){
    USART_SET_16_bit_BAUDRATE_GENERATOR();
    USART_SET_BAUD_RATE_GEN_HIGH_SPEED();
    
    uint16_t calculated_SPBRG =  (_XTAL_FREQ/(float)baudrate/4) - 1;
    SPBRGH = (calculated_SPBRG >> 8);
    SPBRG =  calculated_SPBRG;
    
}
static inline void set_tris_registers(void){
        TRISCbits.RC6 = 1;
        TRISCbits.RC7 = 1;
}