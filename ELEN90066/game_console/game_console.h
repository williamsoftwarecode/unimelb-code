/*************************************************************************
Title:    Game Console Template Header File
Inital Author:   David Jahshan
Extended by : (PUT YOUR NAME HERE) (PUT YOUR STUDENT NUMBER HERE) 
Software: AVR-GCC 
Hardware: ATMEGA16 @ 8Mhz 

DESCRIPTION:
	Macros for Game Console

*************************************************************************/

#include <avr/io.h> 
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdlib.h>

#define byte unsigned char 

/*ON OFF*/
#define ON 0xFF
#define OFF 0x00
#define HIGH 0xFF
#define LOW 0x00
#define IN 0x00
#define OUT 0xFF
#define ALL 0xFF
#define TRUE 1
#define FALSE 0
#define FORWARD 0x00
#define BACK 0xFF
#define PULLUP 0xFF
#define FLOATING 0x00
#define INFINITE_LOOP TRUE
#define CLEAR 0x00
#define INITIAL 0
#define BEGINNING 0
#define ONE 1
#define DDR_SPI DDRB
#define DD_MISO PB6
#define DD_MOSI PB5
#define DD_SCK PB7
#define CMD_PAGE 0xB0 
#define CMD_COL_MSB 0x10 
#define CMD_COL_LSB 0x00
#define MAX_PAGE 7
#define MAX_COLUMN 102
#define MAX_PIXEL 8
#define ROW_CENTRE 32
#define COLUMN_CENTRE 51
#define MAX_ROW 64
#define MIN_ROW 0
#define MIN_COLUMN 0
#define MIN_SELECT 1 
#define MAX_SELECT 3
#define GAME_ONE 1
#define GAME_TWO 2
#define GAME_THREE 3
#define COL_LSB_CONST 0x0F
#define COL_MSB_CONST 4
#define MAX_BRIGHT 0x00FF
#define MIN_BRIGHT 0x05
#define BRIGHT_INCREMENT 25
#define WREN 0x06
#define WRDI 0x04
#define RDSR 0x05
#define WRSR 0x01
#define READ 0x03
#define WRITE 0x02
#define INIT_ADD_MSB 0x00
#define INIT_ADD_LSB 0x00
#define INIT_ADD_LSB_FB 0x01
#define RANDOM_ADD 0x00
#define TINY_DELAY 10
#define SMALL_DELAY 127
#define BIG_DELAY 255
#define BAT_LOW_THRESHOLD 440


/*SET and GET MACRO*/
#define SET(PORT,MASK,VALUE) PORT = ((MASK & VALUE) | (PORT & ~MASK))
#define GET(PORT,MASK) PORT & MASK


//Devices Direction MACROs
//#define MULTI_LINES_DIR(DIR) SET(DDR?,(_BV(P?#)|_BV(P?#)|_BV(P?#)),DIR)
#define BAT_LOW_LED_DIR(DIR) SET(DDRB,_BV(PB1),DIR)
#define BACKLIGHT_DIR(DIR) SET(DDRD,_BV(PD4),DIR)
#define V_BATT_DIR(DIR) SET(DDRA,_BV(PA0),DIR)
#define UP_BUTTON_DIR(DIR) SET(DDRC,_BV(PC7),DIR)
#define DOWN_BUTTON_DIR(DIR) SET(DDRC,_BV(PC6),DIR)
#define LEFT_BUTTON_DIR(DIR) SET(DDRA,_BV(PA6),DIR)
#define RIGHT_BUTTON_DIR(DIR) SET(DDRA,_BV(PA7),DIR)
#define ACTION1_BUTTON_DIR(DIR) SET(DDRA,_BV(PA5),DIR)
#define ACTION2_BUTTON_DIR(DIR) SET(DDRA,_BV(PA4),DIR)
#define ACTION3_BUTTON_DIR(DIR) SET(DDRC,_BV(PC1),DIR)
#define MOSI_DIR(DIR) SET(DDRB,_BV(PB5),DIR)
#define MISO_DIR(DIR) SET(DDRB,_BV(PB6),DIR)
#define SCK_DIR(DIR) SET(DDRB,_BV(PB7),DIR)
#define INTERRUPT_DIR(DIR) SET(DDRD,_BV(PD3),DIR)
#define PB4_MSTR_DIR(DIR) SET(DDRB,_BV(PB4),DIR)
#define RAM_WP_DIR(DIR) SET(DDRD,_BV(PD0),DIR)
#define RAM_CHIP_SELECT_DIR(DIR) SET(DDRD,_BV(PD1),DIR)
#define RAM_HOLD_DIR(DIR) SET(DDRD,_BV(PD2),DIR)
#define LCD_COMMAND_DATA_DIR(DIR) SET(DDRA,_BV(PA1),DIR)
#define LCD_RESET_DIR(DIR) SET(DDRA,_BV(PA2),DIR)
#define LCD_CHIP_SELECT_DIR(DIR) SET(DDRA,_BV(PA3),DIR)


//Devices Outputs
//#define MULTI_LINES(STATE) SET(DDR?,(_BV(P?#)|_BV(P?#)|_BV(P?#)),DIR)

#define BAT_LOW_LED(STATE) SET(PORTB,_BV(PB1),~STATE)
#define BACKLIGHT_SET(STATE) SET(PORTD,_BV(PD4),STATE) 
#define UP_BUTTON_SET(STATE) SET(PORTC,_BV(PC7),STATE)
#define DOWN_BUTTON_SET(STATE) SET(PORTC,_BV(PC6),STATE)
#define LEFT_BUTTON_SET(STATE) SET(PORTA,_BV(PA6),STATE)
#define RIGHT_BUTTON_SET(STATE) SET(PORTA,_BV(PA7),STATE)
#define ACTION1_BUTTON_SET(STATE) SET(PORTA,_BV(PA5),STATE)
#define ACTION2_BUTTON_SET(STATE) SET(PORTA,_BV(PA4),STATE)
#define ACTION3_BUTTON_SET(STATE) SET(PORTC,_BV(PC1),STATE)
#define MOSI_SET(STATE) SET(PORTB,_BV(PB5),STATE)
#define SCK_SET(STATE) SET(PORTB,_BV(PB7),STATE)
#define RAM_WP_SET(STATE) SET(PORTD,_BV(PD0),STATE)
#define RAM_CHIP_SELECT_SET(STATE) SET(PORTD,_BV(PD1),STATE)
#define RAM_HOLD_SET(STATE) SET(PORTD,_BV(PD2),STATE)
#define LCD_COMMAND_DATA_SET(STATE) SET(PORTA,_BV(PA1),STATE)
#define LCD_RESET_SET(STATE) SET(PORTA,_BV(PA2),STATE)
#define LCD_CHIP_SELECT_SET(STATE) SET(PORTA,_BV(PA3),STATE)
#define PB4_MSTR_SET(STATE) SET(PORTB,_BV(PB4),STATE)
#define SPE_SET(STATE) SET(SPCR,_BV(SPE),STATE) 
#define MSTR_SET(STATE) SET(SPCR,_BV(MSTR),STATE) 
#define SPI2X_SET(STATE) SET(SPSR,_BV(SPI2X),STATE) 


//Devices Inputs
#define UP_BUTTON ~GET(PINC,_BV(PC7))
#define DOWN_BUTTON ~GET(PINC,_BV(PC6))
#define LEFT_BUTTON ~GET(PINA,_BV(PA6))
#define RIGHT_BUTTON ~GET(PINA,_BV(PA7))
#define ACTION1_BUTTON ~GET(PINA,_BV(PA5))
#define ACTION2_BUTTON ~GET(PINA,_BV(PA4))
#define ACTION3_BUTTON ~GET(PINC,_BV(PC1))


