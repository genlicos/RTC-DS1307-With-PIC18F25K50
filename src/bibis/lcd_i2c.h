#ifndef LCD_I2C_H
#define LCD_I2C_H

// --- Definições do LCD_I2C ---
#define LCD_ADDR 0x4E                                                           //Endereço do hardware I2C

// --- Comandos do LCD_I2C ---
#define _LCD_FIRST_ROW          0x80                                            //Move cursor to the 1st row
#define _LCD_SECOND_ROW         0xC0                                            //Move cursor to the 2nd row
#define _LCD_THIRD_ROW          0x94                                            //Move cursor to the 3rd row
#define _LCD_FOURTH_ROW         0xD4                                            //Move cursor to the 4th row
#define _LCD_CLEAR              0x01                                            //Clear display
#define _LCD_RETURN_HOME        0x02                                            //Return cursor to home position, returns a shifted display to
                                                                                //its original position. Display data RAM is unaffected.
#define _LCD_CURSOR_OFF         0x0C                                            //Turn off cursor
#define _LCD_UNDERLINE_ON       0x0E                                            //Underline cursor on
#define _LCD_BLINK_CURSOR_ON    0x0F                                            //Blink cursor on
#define _LCD_MOVE_CURSOR_LEFT   0x10                                            //Move cursor left without changing display data RAM
#define _LCD_MOVE_CURSOR_RIGHT  0x14                                            //Move cursor right without changing display data RAM
#define _LCD_TURN_ON            0x0C                                            //Turn Lcd display on
#define _LCD_TURN_OFF           0x08                                            //Turn Lcd display off
#define _LCD_SHIFT_LEFT         0x18                                            //Shift display left without changing display data RAM
#define _LCD_SHIFT_RIGHT        0x1E                                            //Shift display right without changing display data RAM

// Prototipos de funcoes
void I2C_LCD_Cmd(char out_char);
void I2C_LCD_Chr(char row, char column, char out_char);                         //Apresentacao de caracter no LCD atraves de apontamento
void I2C_LCD_Chr_Cp(char out_char);                                             //Apresentacao de caracter no LCD
void I2C_LCD_Out(char row, char col, char *text);                               //Apresentacao de string no LCD atraves de apontamento
void I2C_LCD_Out_Cp(char *text);                                                //Apresentacao de string no LCD
void I2C_LCD_Init();                                                            //Prototipo da funcao de inicializacao do LCD
#endif