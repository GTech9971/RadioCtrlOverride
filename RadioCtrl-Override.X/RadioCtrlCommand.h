#pragma once

#include <xc.h>

enum Command{
    /**
     * 停止
     */
    STOP,
    /**
     * 前進
     */
    FORWARD,
    /**
     * 後退
     */
    BACK,
    /**
     * 左
     */
    LEFT,
    /**
     * 右
     */
    RIGHT,
};

typedef struct {
    /**
     * コマンド
     */
    enum Command cmd;    
} RadioCtrlCommand;


/**
 * 受信データからコマンドを生成する
 * @param data 受信データ
 * @param command
 */
void create_ctrl_command(const uint8_t data, RadioCtrlCommand *command);


