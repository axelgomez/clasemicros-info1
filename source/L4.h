#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <L2.Gpio.h>
//------------------------------------------------------------------------------------------------------
// enumeraciones
//------------------------------------------------------------------------------------------------------
enum adcs { ADC0_CH0, ADC0_CH1, ADC0_CH2, ADC0_CH3, ADC0_CH4, ADC0_CH5, ADC0_CH6, ADC0_CH7, ADC0_CH8, ADC0_CH9, ADC0_CH10, ADC0_CH11};
enum Leds_buzzer { ALL_LEDS, BLUE, RED, GREEN, WBLUE, BUZZER };
enum Mode_7seg { DIGITS, BITS};

//------------------------------------------------------------------------------------------------------
// defines
//------------------------------------------------------------------------------------------------------
#define CONSOLE_ENABLE 	0
#define USART_ENABLE 	1	// 0 consola local, != 0 consola por uart

#define PANTALLA CONSOLE_ENABLE

#define BUFFER_UART_RX_SIZE 70
#define BUFFER_UART_TX_SIZE 128
#define DAC_LIMIT		 	1023
#define TIME_UPDATE_LIMIT 	200

#define BAUD_RATE_I2C		200000
#define BAUD_RATE_UART		38400
#define BAUD_RATE_SPI		500000
#define TICK_1ms_18M		18000
#define TICK_1ms_24M		24000
#define TICK_1ms_30M		30000
#define REFRESH_7SEG		10
#define DIGIT_1				1
#define DIGIT_2				2
#define SECTOR				31
#define FLASH_ADDRESS		(0x400 * SECTOR)
#define FREQ_30MHZ			30000000
#define MAX_BYTES       	256

#define ADC_R21				(1 << ADC0_CH0)
#define ADC_R22				(1 << ADC0_CH8)
#define ADC_LM35DZ			(1 << ADC0_CH7)

#define DEBUG_CONSOLE_ENABLE	1
#define DEBUG_CONSOLE_DISABLE	0

//#define Console_Write       printf
#define Console_Read        scanf


//------------------------------------------------------------------------------------------------------
// prototypes
//------------------------------------------------------------------------------------------------------
/*!
 * Initializa modulos del kit
 */
void Kit_Cortex_Init(void);
//------------------------------------------------------------------------------------------------------
/*!
 * incremento de 1mseg por interrupcion
 */
void Tick_1mseg_interrupt(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Enciende led seleccionado
 * parametros: BLUE, GREEN, RED o WBLUE 
 */
void Led_On(uint8_t led);
//------------------------------------------------------------------------------------------------------
/*!
 * Apaga led seleccionado
 * parametros: (uint8_t) BLUE, GREEN, RED o WBLUE 
 */
void Led_Off(uint8_t led);
//------------------------------------------------------------------------------------------------------
/*!
 * Cambia de estado el led seleccionado
 * parametros: (uint8_t) BLUE, GREEN, RED o WBLUE
 */
void Led_Toggle(uint8_t led);
//------------------------------------------------------------------------------------------------------
/*!
 * Enciende el led WBLUE con brillo de 0 a 100
 * parametros: (uint8_t) brillo
 */
void Bright_Led(uint8_t bness);
//------------------------------------------------------------------------------------------------------
/*!
 * Genera demoras en milisegundos
 * parametros: (uint32_t) milisegundos 
 */
void Delay(uint32_t mseg);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene valor analogico de R21
 * retorno: (uint16_t) valor analogico
 */
uint16_t Get_R21(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene valor analogico de R22
 * retorno: (uint16_t) valor analogico
 */
uint16_t Get_R22(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Hace sonar el Buzzer a una frecuencia y tiempo determinados
 * parametros: (uint32_t) frecuencia, (uint32_t) milisegundos
 */
void Sound(uint32_t freq, uint32_t mseg);
//------------------------------------------------------------------------------------------------------
/*!
 * Hace sonar el Buzzer a 2500kHz
 * parametros: (uint32_t) milisegundos
 */
void Beep(uint32_t mseg);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene temperatura
 * retorno: (uint16_t) temperatura en °C
 */
uint16_t Get_Temperature(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene humedad relativa
 * retorno: (uint16_t) humedad %
 */
uint16_t Get_Humidity(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene presion atmosferica
 * retorno: (uint16_t) presion en hPa
 */
uint16_t Get_Pressure(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene intensidad luminica
 * retorno: (uint16_t) intensidad luminica en LUX
 */
uint16_t Get_Lux(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene estado de la salida del CNY70
 * retorno: (uint8_t) 0 = sin objeto, 1 = objeto detectado
 */
uint8_t Get_CNY70(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Escribe valor en display 7 segmentos de 2 digitos
 * parametro: (uint8_t) numero a mostrar
 */
void Display_Segments(uint8_t value);
//------------------------------------------------------------------------------------------------------
/*!
 * Escribe valor en bits en display 7 segmentos en digito seleccionado
 * parametro: (uint8_t) byte a mostrar, (uint8_t) digito seleccionado => 0 = display derecho, 1 = display izquierdo
 */
void Display_Segments_Bits(uint8_t byte, uint8_t digit);
//------------------------------------------------------------------------------------------------------
/*!
 * Guarda informacion en memoria
 * parameto: (uint8_t *) mensaje
 * retorno: 0 si fallo, si no distinto de 0
 */
uint8_t Save_Text(uint8_t *text);
//------------------------------------------------------------------------------------------------------
/*!
 * Guarda informacion en memoria
 * parameto: (uint8_t *) mensaje
 */
void Get_Text_Saved(uint8_t *text);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene estado de la tecla
 * retorno: (uint8_t) 0 tecla presionada, sino distinto de 0
 */
uint8_t Get_Key_S1(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene estado de la tecla
 * retorno: (uint8_t) 0 tecla presionada, sino distinto de 0
 */
uint8_t Get_Key_S2(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene estado de la tecla
 * retorno: (uint8_t) 0 tecla presionada, sino distinto de 0
 */
uint8_t Get_Key_USER(void);
//------------------------------------------------------------------------------------------------------
/*!
 * Obtiene estado de la tecla
 * retorno: (uint8_t) 0 tecla presionada, sino distinto de 0
 */
uint8_t Get_Key_ISP(void);
//------------------------------------------------------------------------------------------------------
void Console_Write(char console_uart, const char *format, ...);
