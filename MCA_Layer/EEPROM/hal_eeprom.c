/* 
 * File:   hal_eeprom.c
 * Author: Joe
 *
 * Created on February 29, 2024, 11:32 PM
 */


#include "hal_eeprom.h"


Std_ReturnType eeprom_write_byte(uint16_t addr, uint8_t data){
    /* save global interrupt state*/
    uint8_t global_interrupt_state = INTCONbits.GIE;
    /*set the EEPROM address */
    EEADR = (uint8_t)addr;
    EEADRH = (uint8_t) (addr>>8);
    /*set the EEPROM data to be written*/
    EEDATA = data;
    /* configure EECON1 REG. to select EEPROM and write enable */
    EECON1bits.EEPGD = STD_ZERO;
    EECON1bits.CFGS = STD_ZERO;
    EECON1bits.WREN = STD_ONE;
    /* disable global interrupt during write operation*/
    INTCONbits.GIE = STD_ZERO;
    /* sequence to EECON2 to complete the write operation */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = STD_ONE;
    /*wait while writing then disable WREN after complete*/
    while(EECON1bits.WR);
    EECON1bits.WREN = STD_ONE;
    /*get global interrupt back to its state */
    INTCONbits.GIE= global_interrupt_state;
    
    return E_OK;
    
}
Std_ReturnType eeprom_read_byte(uint16_t addr, uint8_t *data){
    
    if (NULL== data){
        return E_NOT_OK;
    }
    else{
    
        /*set the EEPROM address */
        EEADR = (uint8_t)addr;
        EEADRH = (uint8_t) (addr>>8);
        /* configure EECON1 REG. to select EEPROM and read enable */
        EECON1bits.EEPGD = 0;
        EECON1bits.CFGS = 0;
        EECON1bits.RD = 1;
        NOP();
        NOP();
        *data = EEDATA;
        return E_OK;
    }
    
}