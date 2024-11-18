#ifndef RTC_DS1307_H
#define RTC_DS1307_H

// Definições de endereços do DS1307
#define DS1307_ADDRESS     0xD0
#define DS1307_REG_GERAL   0x00
#define DS1307_REG_CONTROL 0x07

// Definições de controle para onda quadrada
#define DS1307_SQWE_ON     0x10
#define DS1307_FREQ_4096HZ 0x01

extern char *WEEKDAY_NAMES[];

// Estrutura para armazenar data/hora
typedef struct {
    unsigned short seconds;
    unsigned short minutes;
    unsigned short hours;
    unsigned short weekday;
    unsigned short day;
    unsigned short month;
    unsigned short year;
} rtc_time_t;

// Protótipos das funções
void rtc_init(void);
void rtc_set_time(rtc_time_t *time);
void rtc_get_time(rtc_time_t *time);
const char rtc_get_weekday_str(unsigned short weekday);

#endif