#pragma once

#include <xc.h>
#include "RadioCtrlCommand.h"

typedef struct{
    /**
     * 前進ピン番号
     */
    uint8_t fw_pin;
    /**
     * 後退ピン番号
     */
    uint8_t bk_pin;
    /**
     * 左ピン番号
     */
    uint8_t lf_pin;
    /**
     * 右ピン番号
     */
    uint8_t ri_pin;
} RadioCtrl;

/**
 * ピン設置を初期化する
 * @param p
 */
void initialize_radio_ctrl_pin(RadioCtrl *p);

/**
 * 停止
 * @param p
 */
void stop(RadioCtrl *p);

/**
 * 前進
 * @param p
 */
void forward(RadioCtrl *p);

/**
 * 後退
 * @param p
 */
void back(RadioCtrl *p);

/**
 * 左
 * @param p
 */
void left(RadioCtrl *p);

/**
 * 右
 * @param p
 */
void right(RadioCtrl *p);

/**
 * コマンド実行
 * @param p
 * @param cmd
 */
void execute_command(RadioCtrl *p, RadioCtrlCommand *cmd);