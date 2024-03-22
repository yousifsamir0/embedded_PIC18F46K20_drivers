/* 
 * File:   hal_usart.h
 * Author: Joe
 *
 * Created on March 21, 2024, 7:20 AM
 */

#ifndef HAL_USART_H
#define	HAL_USART_H


/*  section: Includes */
#include "../device_config.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_internal_interrupt.h"

/* section : MACROS*/

#define USART_STD_ENABLE                    (STD_ONE)     
#define USART_STD_DISABLE                   (STD_ZERO)

#define USART_SYNC_CLK_SOURCE_MASTER        (STD_ONE)
#define USART_SYNC_CLK_SOURCE_SLAVE         (STD_ZERO)

#define USART_9BIT                          (STD_ONE)
#define USART_8BIT                          (STD_ZERO)

#define USART_TRANSMIT_ENABLED              (STD_ONE)
#define USART_TRANSMIT_DISABLED             (STD_ZERO)

#define USART_SYNC_MODE                     (STD_ONE)
#define USART_ASYNC_MODE                    (STD_ZERO)

#define USART_SEND_SYNC_BREAK_NEXT_TX       (STD_ONE)
#define USART_SEND_BREAK_TX_COMPLETE        (STD_ZERO)

#define USART_BAUD_RATE_HIGH_SPEED          (STD_ONE)
#define USART_BAUD_RATE_LOW_SPEED           (STD_ZERO)

#define USART_TRANSMIT_SHIFT_REG_EMPTY      (STD_ONE)
#define USART_TRANSMIT_SHIFT_REG_FULL       (STD_ZERO)

#define USART_SERIAL_PORT_ENABLED           (STD_ONE)
#define USART_SERIAL_PORT_DISABLED          (STD_ZERO)

#define USART_SINGLE_RECEIVE_ENABLED        (STD_ONE)
#define USART_SINGLE_RECEIVE_DISABLED       (STD_ZERO)

#define USART_ADDRESS_DETECT_ENABLED        (STD_ONE)
#define USART_ADDRESS_DETECT_DISABLED       (STD_ZERO)

#define USART_AUTO_BAUD_RATE_TIMER_OVERFLOW (STD_ONE)

#define USART_RECEIVER_IS_IDLE              (STD_ONE)  

#define USART_RX_TX_DT_REVERSED_POLARITY    (STD_ONE)

#define USART_16_bit_BAUDRATE_GENERATOR     (STD_ONE)
             



/* section : function like MACROS*/

#define USART_TX_ENABLE()                       (TXSTAbits.TXEN =USART_TRANSMIT_ENABLED)
#define USART_TX_DISABLE()                      (TXSTAbits.TXEN =USART_TRANSMIT_DISABLED)

#define USART_RX_ENABLE()                       (RCSTAbits.CREN =USART_STD_ENABLE)
#define USART_RX_DISABLE()                      (RCSTAbits.CREN =USART_STD_DISABLE)

#define USART_SET_BAUD_RATE_GEN_HIGH_SPEED()    (TXSTAbits.BRGH = USART_BAUD_RATE_HIGH_SPEED)
#define USART_SET_BAUD_RATE_GEN_LOW_SPEED()     (TXSTAbits.BRGH = USART_BAUD_RATE_LOW_SPEED)
#define USART_SET_16_bit_BAUDRATE_GENERATOR()   (BAUDCONbits.BRG16 =USART_16_bit_BAUDRATE_GENERATOR)
#define USART_SET_8_bit_BAUDRATE_GENERATOR()    (BAUDCONbits.BRG16 = ! USART_16_bit_BAUDRATE_GENERATOR)

#define USART_SET_SYNC_MODE()                     (TXSTAbits.SYNC =USART_SYNC_MODE )
#define USART_SET_ASYNC_MODE()                    (TXSTAbits.SYNC =USART_ASYNC_MODE)

#define USART_SERIAL_PORT_ENABLE()              (RCSTAbits.SPEN = USART_SERIAL_PORT_ENABLED)
#define USART_SERIAL_PORT_DISABLE()             (RCSTAbits.SPEN = USART_SERIAL_PORT_DISABLED)

#define USART_SET_9BIT_TX()                     (TXSTAbits.TX9 = USART_9BIT)
#define USART_SET_8BIT_TX()                     (TXSTAbits.TX9 = USART_8BIT)

#define USART_SET_9BIT_RX()                     (RCSTAbits.RX9 = USART_9BIT)
#define USART_SET_8BIT_RX()                     (RCSTAbits.RX9 = USART_8BIT)

#define USART_READ_RX_9TH_BIT()             (RCSTAbits.RX9D)
#define USART_WRITE_TX_9TH_BIT(_bit)        (TXSTAbits.TX9D=_bit)    

#define USART_IS_FRAMING_ERROR()            (RCSTAbits.FERR == STD_ONE)
#define USART_IS_OVERRUN_ERROR()            (RCSTAbits.OERR == STD_ONE)

#define USART_WAKE_UP_ENABLE()              (BAUDCONbits.WUE = STD_ONE)
#define USART_WAKE_UP_DISABLE()             (BAUDCONbits.WUE = STD_ZERO)
#define USART_AUTO_BAUD_DETECT_ENABLE()     (BAUDCONbits.ABDEN = STD_ONE)
#define USART_AUTO_BAUD_DETECT_DISABLE()    (BAUDCONbits.ABDEN = STD_ZERO)


/* section : data types declaration*/




typedef struct{
    void (* rx_interrupt_handler)(uint8_t data_8_bits,uint8_t data_9_bits);
    void (*rx_framing_error_handler)(void);
    void (*rx_overrun_error_handler)(void);
    uint32_t baudrate;    
    uint8_t interrupt_enable :1;
    uint8_t interrupt_priority :1;
    uint8_t is_9bit :1;
}usart_rx_t;
typedef struct{   
    uint32_t baudrate;
    uint8_t is_9bit :1;
}usart_tx_t;

/* section : interface declaration*/
Std_ReturnType usart_tx_init(usart_tx_t *usart_config);
Std_ReturnType usart_tx_deinit(usart_tx_t *usart_config);
Std_ReturnType usart_tx_write_byte_blocking(uint8_t data);
Std_ReturnType usart_tx_write_9_bits_blocking(uint16_t data);


Std_ReturnType usart_rx_init(usart_rx_t *usart_config);
Std_ReturnType usart_rx_deinit(usart_rx_t *usart_config);
Std_ReturnType usart_rx_read_byte_blocking(uint8_t *data_8);
Std_ReturnType usart_rx_read_9bits_blocking(uint16_t *data_9);


#endif	/* HAL_USART_H */

