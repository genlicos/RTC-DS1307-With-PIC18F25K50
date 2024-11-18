#include "bibis\rtc_ds1307.h"                                                   // Inclui a biblioteca de RTC
#include "bibis\lcd_i2c.h"                                                      // Inclui a biblioteca de RTC

void main()                                                                     // Função principal
{
  // Variaveis locais
  char time_txt[8];
  rtc_time_t time;

  // Seta variaveis
  time.hours = 14;                                                              // Inicia hora como 14
  time.minutes = 20;                                                            // Inicia minutos como 20
  time.seconds = 2;                                                             // Inicia segundos como 00
  time.weekday = 1;                                                             // 1 = Domingo,...,7 = Sábado
  time.day = 10;                                                                // Inicia dia igual a 10
  time.month = 11;                                                              // Inicia mes igual a 11
  time.year = 24;                                                               // Inicia ano igual a 24

  // Inicializacao
  I2C1_Init(100000);                                                            // Inicializa I2C em 100kHz
  I2C_Lcd_Init();                                                               // Inicializa LCD
  rtc_set_time(&time);                                                          // Configura RTC com hora inicial


  while(1)
  {
      rtc_get_time(&time);                                                      // Lê hora atual

      sprintf(time_txt,"%02u:%02u:%02u", Ltrim(time.hours),                     // Formata hora
                                         Ltrim(time.minutes),
                                         Ltrim(time.seconds));

      I2C_Lcd_Out(1,1,time_txt);                                                // Exibe hora

      Ltrim(time.weekday);
      I2C_Lcd_Out(1,14,WEEKDAY_NAMES[time.weekday-1]);                          // Exibe dia da semana

      sprintf(time_txt,"%02u/%02u/%02u", Ltrim(time.day),                       // Formata data
                                         Ltrim(time.month),
                                         Ltrim(time.year));
      I2C_Lcd_Out(2,1,time_txt);                                                // Exibe data
      Delay_ms(250);                                                           // Atualiza a cada 1 segundo
  }
}