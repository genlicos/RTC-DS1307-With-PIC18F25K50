#include "lcd_i2c.h"

void I2C_LCD_Cmd(char out_char) {

    char hi_n, lo_n;
    char rs = 0x00;

    hi_n = out_char & 0xF0;
    lo_n = (out_char << 4) & 0xF0;

    I2C1_Start();
    I2C1_Is_Idle();
    I2C1_Wr(LCD_ADDR);
    I2C1_Is_Idle();
    I2C1_Wr(hi_n | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(hi_n | rs | 0x00 | 0x08);
    I2C1_Is_Idle();
    Delay_us(100);
    I2C1_Wr(lo_n | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(lo_n | rs | 0x00 | 0x08);
    I2C1_Is_Idle();
    I2C1_stop();

    if(out_char == 0x01)Delay_ms(2);
}

void I2C_LCD_Chr(char row, char column, char out_char) {

    char hi_n, lo_n;
    char rs = 0x01;

    switch(row){

        case 1:
        I2C_LCD_Cmd(0x80 + (column - 1));
        break;
        case 2:
        I2C_LCD_Cmd(0xC0 + (column - 1));
        break;
        case 3:
        I2C_LCD_Cmd(0x94 + (column - 1));
        break;
        case 4:
        I2C_LCD_Cmd(0xD4 + (column - 1));
        break;
    };

    hi_n = out_char & 0xF0;
    lo_n = (out_char << 4) & 0xF0;

    I2C1_Start();
    I2C1_Is_Idle();
    I2C1_Wr(LCD_ADDR);
    I2C1_Is_Idle();
    I2C1_Wr(hi_n | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(hi_n | rs | 0x00 | 0x08);
    I2C1_Is_Idle();
    Delay_us(100);
    I2C1_Wr(lo_n | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(lo_n | rs | 0x00 | 0x08);
    I2C1_Is_Idle();
    I2C1_stop();
}

void I2C_LCD_Chr_Cp(char out_char) {

    char hi_n, lo_n;
    char rs = 0x01;

    hi_n = out_char & 0xF0;
    lo_n = (out_char << 4) & 0xF0;

    I2C1_Start();
    I2C1_Is_Idle();
    I2C1_Wr(LCD_ADDR);
    I2C1_Is_Idle();
    I2C1_Wr(hi_n | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(hi_n | rs | 0x00 | 0x08);
    I2C1_Is_Idle();
    Delay_us(100);
    I2C1_Wr(lo_n | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(lo_n | rs | 0x00 | 0x08);
    I2C1_Is_Idle();
    I2C1_stop();
}

void I2C_LCD_Out(char row, char col, char *text) {
    while(*text)
         I2C_LCD_Chr(row, col++, *text++);
}

void I2C_LCD_Out_Cp(char *text) {
    while(*text)
         I2C_LCD_Chr_Cp(*text++);
}

void I2C_LCD_Init() {

    char rs = 0x00;

    I2C1_Start();
    I2C1_Is_Idle();
    I2C1_Wr(LCD_ADDR);
    I2C1_Is_Idle();

    Delay_ms(3);

    I2C1_Wr(0x30 | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(0x30 | rs | 0x00 | 0x08);
    I2C1_Is_Idle();

    Delay_ms(1);

    I2C1_Wr(0x30 | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(0x30 | rs | 0x00 | 0x08);
    I2C1_Is_Idle();

    Delay_ms(1);

    I2C1_Wr(0x30 | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(0x30 | rs | 0x00 | 0x08);
    I2C1_Is_Idle();

    Delay_ms(1);

    I2C1_Wr(0x20 | rs | 0x04 | 0x08);
    I2C1_Is_Idle();
    Delay_us(50);
    I2C1_Wr(0x20 | rs | 0x00 | 0x08);
    I2C1_Is_Idle();
    I2C1_Stop();

    Delay_ms(1);

    I2C_LCD_Cmd(0x28);
    I2C_LCD_Cmd(0x06);

    I2C_LCD_Cmd(_LCD_CURSOR_OFF);
    I2C_LCD_Cmd(_LCD_CLEAR);
}
