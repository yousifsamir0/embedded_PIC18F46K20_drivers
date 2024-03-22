
#include "mcal_interrupt_manager.h"
#include "mcal_external_interrupt.h"
#include "mcal_internal_interrupt.h"


#if (INTERRUPT_PRIORITY_LEVELS)
/* priority levels interrupts */
void __interrupt() InterruptManagerHigh(void){

}
void __interrupt(low_priority) InterruptManagerLow(void){

}

#else
/* non priority interrupts */
void __interrupt() InterruptManager(void){
    if ((INT0_INTERRUPT_IS_ENABLE) && (INT0_INTERRUPT_FLAG) ){
        INT0_ISR();
    }
    else if ((INT1_INTERRUPT_IS_ENABLE) && (INT1_INTERRUPT_FLAG) ){
        INT1_ISR();
    }
    else if ((INT2_INTERRUPT_IS_ENABLE) && (INT2_INTERRUPT_FLAG) ){
        INT2_ISR();
    }
    else if ((ADC_INTERRUPT_IS_ENABLE) && (ADC_INTERRUPT_IS_OCCUREED) ){
        ADC_ISR();
    }
    else if ((TIMER0_INTERRUPT_IS_ENABLE) && (TIMER0_INTERRUPT_IS_OCCUREED) ){
        TIMER0_ISR();
    }
    else if ((TIMER1_INTERRUPT_IS_ENABLE) && (TIMER1_INTERRUPT_IS_OCCUREED) ){
        TIMER1_ISR();
    }
    else if ((TIMER2_INTERRUPT_IS_ENABLE) && (TIMER2_INTERRUPT_IS_OCCUREED) ){
        TIMER2_ISR();
    }
    else if ((TIMER3_INTERRUPT_IS_ENABLE) && (TIMER3_INTERRUPT_IS_OCCUREED) ){
        TIMER3_ISR();
    }
    else if ((USART_RX_INTERRUPT_IS_ENABLE) && (USART_RX_INTERRUPT_IS_OCCUREED) ){
        USART_RX_ISR();
    }
    else{ /*nothing*/ }

}
    
#endif