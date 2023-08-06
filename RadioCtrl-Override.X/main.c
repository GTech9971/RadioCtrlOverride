#include "mcc_generated_files/mcc.h"

#define _XTAL_FREQ 8000000

uint8_t led_pin = 0x01;
uint8_t fw_pin = 0x01;
uint8_t bk_pin = 0x02;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    ANSELA = 0x00;
    TRISA = 0x00;
    
    ANSELB = 0x00;
    //RB1(RX is input)
    TRISB = 0x02;    
    
    LATA = 0x00;
    LATB = 0x00;
    
    
    //USART setting
    //TX on
    TXSTA = 0x20;
    //RC on
    RCSTA = 0x90;
    //BAUDCON 16bit
    BAUDCON = 0x08;
    //BRGH = 0, BRG16 = 1 9600bit mode
    SPBRG = 51;
    
    //interrupt setting
    //interrupt flg clear
    PIR1bits.RCIF = 0;
    
    //USART recive interrupt enable
    PIE1bits.RCIE = 1;
    PEIE = 1;
    GIE = 1;
    
        
    LATB |= led_pin;

    while (1)
    {
    }
}
bool flag = true;


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
            LATA = 0x00;
            
            flag = !flag;
            if(flag){
                LATB |= led_pin;
            }else{
                LATB &= ~led_pin;
            }            
            
            if(data == 0x01){
                LATA |= fw_pin;
            }else if(data == 0x02){                
                LATA |= bk_pin;
            }else if(data == 0x00){
                LATA = 0x00;
            }
            
            //send
            while(!TXSTAbits.TRMT);
            TXREG = data;
        }           
    }
}