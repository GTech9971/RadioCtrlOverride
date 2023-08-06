#include "mcc_generated_files/mcc.h"

#include "./HM10.h"
#include "RadioCtrl.h"
#include "RadioCtrlCommand.h"

#define _XTAL_FREQ 8000000

uint8_t led_pin = 0x01;
RadioCtrl radioCtrl;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    ANSELA = 0x00;
    ANSELB = 0x00;
    
    TRISA = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    

    //fw,bk,lf,ri
    radioCtrl.fw_pin = 0x01;
    radioCtrl.bk_pin = 0x02;
    radioCtrl.lf_pin = 0x04;
    radioCtrl.ri_pin = 0x08;    
    initialize_radio_ctrl_pin(&radioCtrl);
    
    //HM10 intialize
    initialize_hm10();
    
    //status_led
    LATB |= led_pin;

    while (1)
    {
    }
}


void response_data(uint8_t data){
    //send
    while(!TXSTAbits.TRMT);
    TXREG = data;
}

/**
 * interrupt func
 */
void __interrupt() isr(void){
    if(PIR1bits.RCIF){
        //flg clear
        PIR1bits.RCIF = 0;
        //error
        if((RCSTAbits.OERR) || (RCSTAbits.FERR)){
            RCSTA = 0;
            RCSTA = 0x90;
        }else{
            uint8_t data = RCREG;          
            
            //execute command
            RadioCtrlCommand command = {STOP};
            create_ctrl_command(data, &command);            
            execute_command(&radioCtrl, &command);
            
            //response
            response_data(data);
        }           
    }
}