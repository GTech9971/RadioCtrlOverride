/*
 * File:   RadioCtrlCommand.c
 * Author: george
 *
 * Created on August 6, 2023, 7:15 PM
 */


#include <xc.h>
#include "RadioCtrlCommand.h"


void create_ctrl_command(const uint8_t data, RadioCtrlCommand *command){
    switch(data){
        case 0x00:{
            command->cmd = STOP;
            break;
        }case 0x01:{
            command->cmd = FORWARD;
            break;
        }case 0x02:{
            command->cmd = BACK;
            break;
        }case 0x03:{
            command->cmd = LEFT;
            break;
        }case 0x04:{
            command->cmd = RIGHT;
            break;
        }default:{
            command->cmd = STOP;
        }
    }
}