#include "rtc_ds1307.h"

char *WEEKDAY_NAMES[] = {"DOM", "SEG", "TER", "QUA", "QUI", "SEX", "SAB"};

void rtc_set_time(rtc_time_t *time) {
    I2C1_Start();                                                                  // Inicia comunicação
    I2C1_Wr(DS1307_ADDRESS);                                                      // Endereço de escrita do RTC
    I2C1_Wr(DS1307_REG_GERAL);                                                    // Aponta para o registrador 0

    I2C1_Wr(Dec2Bcd(time->seconds));                                              // Segundos
    I2C1_Wr(Dec2Bcd(time->minutes));                                              // Minutos
    I2C1_Wr(Dec2Bcd(time->hours));                                                // Horas
    I2C1_Wr(Dec2Bcd(time->weekday));                                              // Dia da semana (1-7)
    I2C1_Wr(Dec2Bcd(time->day));                                                  // Dia
    I2C1_Wr(Dec2Bcd(time->month));                                                // Mês
    I2C1_Wr(Dec2Bcd(time->year));                                                 // Ano
    I2C1_Wr(DS1307_SQWE_ON | DS1307_FREQ_4096HZ);                               // Config: 4.096kHz

    I2C1_Stop();                                                                  // Finaliza comunicação
}

void rtc_get_time(rtc_time_t *time) {
    I2C1_Start();                                                                 // Inicia comunicação
    I2C1_Wr(DS1307_ADDRESS);                                                     // Endereço de escrita do RTC
    I2C1_Wr(DS1307_REG_GERAL);                                                   // Aponta para o registrador 0
    I2C1_Repeated_Start();                                                                // Reinicia comunicação
    I2C1_Wr(DS1307_ADDRESS | 0x01);                                             // Endereço de leitura do RTC

    time->seconds = Bcd2Dec16(I2C1_Rd(1));                                       // Lê e converte segundos
    time->minutes = Bcd2Dec16(I2C1_Rd(1));                                       // Lê e converte minutos
    time->hours = Bcd2Dec16(I2C1_Rd(1));                                         // Lê e converte horas
    time->weekday = Bcd2Dec16(I2C1_Rd(1));                                       // Lê e converte dia da semana
    time->day = Bcd2Dec16(I2C1_Rd(1));                                           // Lê e converte dia
    time->month = Bcd2Dec16(I2C1_Rd(1));                                         // Lê e converte mês
    time->year = Bcd2Dec16(I2C1_Rd(0));                                          // Lê e converte ano

    I2C1_Stop();                                                                 // Finaliza comunicação
}
