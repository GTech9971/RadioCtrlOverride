/*
 * File:   RadioCtrl.c
 * Author: george
 *
 * Created on August 6, 2023, 7:20 PM
 */


#include <xc.h>
#include "RadioCtrl.h"
#include "RadioCtrlCommand.h"

#define _XTAL_FREQ 8000000

/**
 * ピン設置を初期化する
 * @param p
 */
void initialize_radio_ctrl_pin(RadioCtrl *p){
    LATA = 0x00;
    
    TRISA &= ~p->fw_pin;
    TRISA &= ~p->bk_pin;
    TRISA &= ~p->lf_pin;
    TRISA &= ~p->ri_pin;
}

/**
 * 停止
 * @param p
 */
void stop(RadioCtrl *p){
    LATA = 0x00;
    __delay_ms(100);    
}

/**
 * 前進
 * @param p
 */
void forward(RadioCtrl *p){
    stop(p);
    LATA |= p->fw_pin;
}

/**
 * 後退
 * @param p
 */
void back(RadioCtrl *p){
    stop(p);
    LATA |= p->bk_pin;
}

/**
 * 左
 * @param p
 */
void left(RadioCtrl *p){
    stop(p);
    LATA |= p->lf_pin;
}

/**
 * 右
 * @param p
 */
void right(RadioCtrl *p){
    stop(p);
    LATA |= p->ri_pin;
}

/**
 * コマンド実行
 * @param p
 * @param cmd
 */
void execute_command(RadioCtrl *p, RadioCtrlCommand *cmd){
    switch(cmd->cmd){
        case STOP:{
            stop(p);
            break;
        }case FORWARD:{
            forward(p);
            break;
        }case BACK:{
            back(p);
            break;
        }case LEFT:{
            left(p);
            break;
        }case RIGHT:{
            right(p);
            break;
        }
    }
}
