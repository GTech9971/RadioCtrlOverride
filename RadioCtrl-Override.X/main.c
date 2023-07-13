#include "mcc_generated_files/mcc.h"

#define _XTAL_FREQ 8000000

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    ANSELA = 0x00;
    TRISA = 0x00;
    LATA = 0x00;
    
    uint8_t fw_pin = 0x01;
    uint8_t bk_pin = 0x02;
    
    uint8_t lf_pin = 0x04;
    uint8_t ri_pin = 0x08;
        

    while (1)
    {
        //fw
        LATA |= fw_pin;        
        __delay_ms(3000);        
        LATA = 0x00;
        
        //bk
        LATA |= bk_pin;
        __delay_ms(3000);
        LATA = 0x00;
        
        //lf
        LATA |= lf_pin;
        __delay_ms(3000);
        LATA = 0x00;
        
        //ri
        LATA |= ri_pin;
        __delay_ms(3000);
        LATA = 0x00;
        
    }
}
/**
 End of File
*/