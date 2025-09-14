#include <L1.h>

//---------------------------------------------------------------//
#define ON 					0
#define OFF 				1

#define RED_LED_ON 			GPIO_PinWrite(GPIO, 1, 2, ON)
#define RED_LED_OFF 		GPIO_PinWrite(GPIO, 1, 2, OFF)
#define RED_LED_TOGGLE 		GPIO_PortToggle(GPIO, 1, 1 << 2)
#define GREEN_LED_ON 		GPIO_PinWrite(GPIO, 1, 0, ON)
#define GREEN_LED_OFF 		GPIO_PinWrite(GPIO, 1, 0, OFF)
#define GREEN_LED_TOGGLE	GPIO_PortToggle(GPIO, 1, 1 << 0)
#define BLUE_LED_ON 		GPIO_PinWrite(GPIO, 1, 1, ON)
#define BLUE_LED_OFF 		GPIO_PinWrite(GPIO, 1, 1, OFF)
#define BLUE_LED_TOGGLE		GPIO_PortToggle(GPIO, 1, 1 << 1)
#define BUZZER_ON 			GPIO_PinWrite(GPIO, 0, 28, ~ON)
#define BUZZER_OFF 			GPIO_PinWrite(GPIO, 0, 28, ~OFF)
#define BUZZER_TOGGLE 		GPIO_PortToggle(GPIO, 0, 1 << 28)
#define WC_LED_ON 			GPIO_PinWrite(GPIO, 0, 29, ~ON)
#define WC_LED_OFF	 		GPIO_PinWrite(GPIO, 0, 29, ~OFF)
#define WC_LED_TOGGLE 		GPIO_PortToggle(GPIO, 0, 1 << 29)

#define RED_LED_STATUS		GPIO_PinRead(GPIO, 1, 2)
#define GREEN_LED_STATUS	GPIO_PinRead(GPIO, 1, 0)
#define BLUE_LED_STATUS		GPIO_PinRead(GPIO, 1, 1)

#define SW_USER	 			GPIO_PinRead(GPIO,0,4)
#define SW_ISP	 			GPIO_PinRead(GPIO,0,12)
#define SW_S1	 			GPIO_PinRead(GPIO,0,16)
#define SW_S2	 			GPIO_PinRead(GPIO,0,25)

#define CNY70_STATUS		GPIO_PinRead(GPIO,0,19)
#define CNY70_ON			GPIO_PinWrite(GPIO, 0, 17, 1)
#define CNY70_OFF			GPIO_PinWrite(GPIO, 0, 17, 0)

#define LCD_RS(x)			GPIO_PinWrite(GPIO, 0, 0, x)
#define LCD_RW(x)			GPIO_PinWrite(GPIO, 0, 1, x)
#define LCD_E(x)			GPIO_PinWrite(GPIO, 0, 6, x)
#define LCD_DB4(x)			GPIO_PinWrite(GPIO, 0, 15, x)
#define LCD_DB5(x)			GPIO_PinWrite(GPIO, 0, 14, x)
#define LCD_DB6(x)			GPIO_PinWrite(GPIO, 0, 13, x)
#define LCD_DB7(x)			GPIO_PinWrite(GPIO, 0, 11, x)
#define LCD_BL(x)			GPIO_PinWrite(GPIO, 0, 10, x)

#define SEG_A(x)			GPIO_PinWrite(GPIO, 0, 10, x)
#define SEG_B(x)			GPIO_PinWrite(GPIO, 0, 11, x)
#define SEG_C(x)			GPIO_PinWrite(GPIO, 0, 6, x)
#define SEG_D(x)			GPIO_PinWrite(GPIO, 0, 14, x)
#define SEG_E(x)			GPIO_PinWrite(GPIO, 0, 0, x)
#define SEG_F(x)			GPIO_PinWrite(GPIO, 0, 13, x)
#define SEG_G(x)			GPIO_PinWrite(GPIO, 0, 15, x)
#define SEG_DOT(x)			GPIO_PinWrite(GPIO, 0, 1, x)

#define DIGIT_1_ON			GPIO_PinWrite(GPIO, 0, 8, ON)
#define DIGIT_1_OFF			GPIO_PinWrite(GPIO, 0, 8, OFF)
#define DIGIT_2_OFF			GPIO_PinWrite(GPIO, 0, 9, OFF)
#define DIGIT_2_ON			GPIO_PinWrite(GPIO, 0, 9, ON)

#define DISPLAY(x)          SEG_A((x >> 7) & 1); SEG_B((x >> 6) & 1); SEG_C((x >> 5) & 1); SEG_D((x >> 4) & 1); SEG_E((x >> 3) & 1); SEG_F((x >> 2) & 1); SEG_G((x >> 1) & 1); SEG_DOT((x >> 0) & 1);

//---------------------------------------------------------------//

void GPIO_Init(void);
void Write_7segment(uint8_t num, uint8_t dp, uint8_t digit);
void Write_7segment_bits(uint8_t byte, uint8_t digit);

