/*************************************************************************
Title:    game_console Template
Initial Author:   David Jahshan
Extended by : (William Ngeow Kit Mun) (596301)
Software: AVR-GCC 
Hardware: ATMEGA16 @ 8Mhz 

DESCRIPTION:
	Main and functions for Game Console basic sample code

*************************************************************************/


#include "game_console.h" 

void SPI_MasterInit(void);
void SPI_MasterTransmit(byte cData);
void LCD_command_tx(byte tx_byte);
void LCD_data_tx(byte tx_byte);
byte LCD_initialise(void);
byte select_page (byte page);
byte select_column (byte column);
void LCD_write_pixel(byte page, byte column, byte tx_byte);
void LCD_erase_pixel(byte page, byte column);
void LCD_clear(void);
void LCD_SPI_init(void);
void etch_a_sketch(byte *row, byte *column, byte frame_buffer[MAX_COLUMN][MAX_PAGE]);
void snake(byte *row, byte *column, byte frame_buffer[MAX_COLUMN][MAX_PAGE]);
void clear_frame_buffer(byte *row, byte *column, byte frame_buffer[MAX_COLUMN][MAX_PAGE]);
void LCD_select_1(void);
void LCD_select_2(void);
void LCD_select_3(void);
void PWM_initialise(void);
void adjust_backlight(void);
void INT_initialise(void);
void ADC_initialise(void);
void ADC_BATTERY_CHECK(void);
void RAM_initialise(void);
void RAM_write(unsigned int add, byte tx_byte);
byte RAM_read(unsigned int add);
void RAM_frame_buffer_write(unsigned int add, byte frame_buffer[MAX_COLUMN][MAX_PAGE]);
void RAM_frame_buffer_read(byte frame_buffer[MAX_COLUMN][MAX_PAGE]);
void LCD_reload(byte frame_buffer[MAX_COLUMN][MAX_PAGE]); 



int main(void)
{
	BAT_LOW_LED(OFF); 			//Make sure it is off before changing direction
	BAT_LOW_LED_DIR(OUT); 		//Set BATTERY LED I/Os as output 
	BACKLIGHT_DIR(OUT);			//Set BACKLIGHT I/Os as output 
	V_BATT_DIR(IN); 
	LCD_CHIP_SELECT_DIR(OUT); 
	LCD_RESET_DIR(OUT); 
	LCD_COMMAND_DATA_DIR(OUT); 
	RAM_CHIP_SELECT_DIR(OUT); 
	RAM_WP_DIR(OUT); 
	RAM_HOLD_DIR(OUT);

	MOSI_DIR(OUT);
	MISO_DIR(IN);  
	SCK_DIR(OUT); 
	
	PB4_MSTR_SET(PULLUP); 
	PB4_MSTR_DIR(OUT); 	
	UP_BUTTON_SET(PULLUP); 		//Set UP_BUTTON to pullup state
	UP_BUTTON_DIR(IN); 			//Set UP_BUTTON I/Os as input.
	DOWN_BUTTON_SET(PULLUP); 	//Set DOWN_BUTTON to pullup state
	DOWN_BUTTON_DIR(IN); 		//Set DOWN_BUTTON I/Os as input.
	LEFT_BUTTON_SET(PULLUP); 	//Set LEFT_BUTTON to pullup state
	LEFT_BUTTON_DIR(IN); 		//Set LEFT_BUTTON I/Os as input.
	RIGHT_BUTTON_SET(PULLUP); 	//Set RIGHT_BUTTON to pullup state
	RIGHT_BUTTON_DIR(IN); 		//Set RIGHT_BUTTON I/Os as input.
	ACTION1_BUTTON_SET(PULLUP); //Set ACTION1_BUTTON to pullup state
	ACTION1_BUTTON_DIR(IN); 	//Set ACTION1_BUTTON I/Os as input.
	ACTION2_BUTTON_SET(PULLUP); //Set ACTION2_BUTTON to pullup state
	ACTION2_BUTTON_DIR(IN); 	//Set ACTION2_BUTTON I/Os as input.
	ACTION3_BUTTON_SET(PULLUP); //Set ACTION3_BUTTON to pullup state
	ACTION3_BUTTON_DIR(IN); 	//Set ACTION3_BUTTON I/Os as input.

	byte frame_buffer[MAX_COLUMN][MAX_PAGE];
	byte row = ROW_CENTRE;
	byte column = COLUMN_CENTRE; 
	byte select = MIN_SELECT; 
	byte bright_val = MAX_BRIGHT;
	LCD_SPI_init(); 
	INT_initialise();

	clear_frame_buffer(&row,&column,frame_buffer); 
	PWM_initialise();
	ADC_initialise();
	RAM_initialise();

	while (TRUE)//Master loop always true so always loop
	{
		

	ADC_BATTERY_CHECK();
		 
	if(UP_BUTTON) 
	{ 	
		select--;
		if (select<MIN_SELECT) 
		{
			select = MAX_SELECT;
		} 
	}	
	
	if(DOWN_BUTTON) 
	{ 
		select++;
		if (select>MAX_SELECT) 
		{
			select = MIN_SELECT;
		} 	
	}	
	
	if(select==GAME_ONE) { 
		LCD_select_1(); 
	} 

	if (select==GAME_TWO) { 
		LCD_select_2();
	}

	if(select==GAME_THREE) { 
		LCD_select_3(); 
	} 	

	if(ACTION2_BUTTON) {
		
		if (select==1) {  	
			etch_a_sketch((&row),(&column),frame_buffer); 
		}

		if (select==2) {
	
			while(INFINITE_LOOP) {
				BAT_LOW_LED(OFF);
				if(ACTION2_BUTTON) {
					bright_val=bright_val-BRIGHT_INCREMENT;
				}
		
				if(bright_val==MIN_BRIGHT) { 
					bright_val = OFF; 
				}

				if(bright_val<OFF) { 
					bright_val = MAX_BRIGHT;
				}
				
				if(UP_BUTTON) {
					RAM_write(INIT_ADD_MSB, bright_val);
					BAT_LOW_LED(ON);
				}
		
				if(DOWN_BUTTON) {
					bright_val = RAM_read(INIT_ADD_MSB); 
				}
				
				OCR1B = bright_val;
				_delay_ms(BIG_DELAY);
			}
		}

		if (select==3) {  	
			snake(&row,&column,frame_buffer); 
		}
	}

		_delay_ms(SMALL_DELAY);	 
	}
	
	
}













/////////////////////////////////////////////////
void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	//DDR_SPI = ((1<<DD_MOSI)|(1<<DD_SCK));
	/* Enable SPI, Master, set clock rate fck/16 */	
	SPCR = ((1<<SPE)|(1<<MSTR)|(1<<SPR0));
}


/////////////////////////////////////////////////
void SPI_MasterTransmit(byte cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
}


/////////////////////////////////////////////////
void LCD_command_tx(byte tx_byte) { 
	LCD_CHIP_SELECT_SET(LOW); 
	LCD_COMMAND_DATA_SET(LOW); 
	SPI_MasterTransmit(tx_byte);
	LCD_CHIP_SELECT_SET(HIGH); 
} 


/////////////////////////////////////////////////
void LCD_data_tx(byte tx_byte) { 
	LCD_CHIP_SELECT_SET(LOW); 
	LCD_COMMAND_DATA_SET(HIGH); 
	SPI_MasterTransmit(tx_byte);
	LCD_CHIP_SELECT_SET(HIGH); 
} 

/////////////////////////////////////////////////
byte LCD_initialise(void) {
	LCD_command_tx(0x40);//Display start line 0
	LCD_command_tx(0xA1);//SEG reverse
	LCD_command_tx(0xC0);//Normal COM0~COM63
	LCD_command_tx(0xA4);//Disable -> Set All Pixel to ON
	LCD_command_tx(0xA6);//Display inverse off
	_delay_ms(5);
	LCD_command_tx(0xA2);//Set LCD Bias Ratio A2/A3
	LCD_command_tx(0x2F);//Set Power Control 28...2F
	LCD_command_tx(0x27);//Set VLCD Resistor Ratio 20...27
	LCD_command_tx(0x81);//Set Electronic Volume
	LCD_command_tx(0x10);//Set Electronic Volume 00...3F
	LCD_command_tx(0xFA);//Set Adv. Program Control
	LCD_command_tx(0x90);//Set Adv. Program Control x00100yz yz column wrap x Temp Comp
	LCD_command_tx(0xAF);//Display on
	return(TRUE);
}


/////////////////////////////////////////////////
byte select_page (byte page)
{
	if (page > MAX_PAGE) 
	{
		page = BEGINNING;
	} 
	byte page_cmd_address;
	page_cmd_address =(CMD_PAGE | page);
	LCD_command_tx(page_cmd_address );
	return(TRUE);
}


/////////////////////////////////////////////////
byte select_column (byte column)
{
	if (column > MAX_COLUMN) 
	{
		column = BEGINNING;
	} 
	byte page_cmd_address_MSB;
	byte page_cmd_address_LSB;
	page_cmd_address_LSB =(CMD_COL_LSB | (column&COL_LSB_CONST));
	page_cmd_address_MSB =(CMD_COL_MSB | (column >> COL_MSB_CONST));
	LCD_command_tx(page_cmd_address_LSB);
	LCD_command_tx(page_cmd_address_MSB);
	return(TRUE);
}


/////////////////////////////////////////////////
void LCD_write_pixel(byte page, byte column, byte tx_byte)
{ 
	select_page(page); 
	select_column(column); 
	LCD_data_tx(tx_byte); 
}


/////////////////////////////////////////////////
void LCD_erase_pixel(byte page, byte column)
{ 
	select_page(page); 
	select_column(column); 
	LCD_data_tx(OFF); 
}


/////////////////////////////////////////////////
void LCD_clear(void)
{
	int page; 
	int column; 
	
	for(page=INITIAL; page<MAX_PAGE; page++) {
		for(column=INITIAL; column<MAX_COLUMN; column++) {
			select_page(page); 
			select_column(column); 
			LCD_data_tx(CLEAR); 
		}
	}
}


/////////////////////////////////////////////////
void LCD_SPI_init(void) {	
	SPI_MasterInit(); 
	LCD_CHIP_SELECT_SET(LOW); 
	LCD_RESET_SET(LOW); 
	_delay_ms(TINY_DELAY); 
	LCD_RESET_SET(HIGH); 
	_delay_ms(TINY_DELAY); 
	LCD_initialise(); 
	LCD_COMMAND_DATA_SET(LOW); 
	LCD_CHIP_SELECT_SET(HIGH); 

	LCD_clear(); 
}


/////////////////////////////////////////////////
void etch_a_sketch(byte (*row), byte (*column), byte frame_buffer[MAX_COLUMN][MAX_PAGE]) 
{ 
	LCD_clear(); 
	RAM_frame_buffer_read(frame_buffer); 
	LCD_reload(frame_buffer);
	
	while(INFINITE_LOOP) {
		if(ACTION2_BUTTON) { 
			clear_frame_buffer(row,column,frame_buffer); 
		}
	
		if(UP_BUTTON) {
			(*row)--;
		}

		if(DOWN_BUTTON) {
			(*row)++;
		}
		
		if(LEFT_BUTTON)	{
			(*column)--;
		} 

		if(RIGHT_BUTTON) {
			(*column)++;		
		}

		if((*column)<MIN_COLUMN) {
			(*column) = MIN_COLUMN; 
		}
		
		if((*row)<MIN_ROW) { 
			(*row) = MIN_ROW; 
		}	

		if((*column)>=MAX_COLUMN) {
			(*column) = MAX_COLUMN - ONE; 
		}
		
		if((*row)>=MAX_ROW) { 
			(*row) = MAX_ROW - ONE; 
		}

		byte page = (*row)/MAX_PIXEL; 
		byte pixel = (*row)%MAX_PIXEL;
		select_page(page);
		select_column((*column));
		pixel = (_BV(pixel) | (frame_buffer[(*column)][page]));
		frame_buffer[(*column)][page] = pixel;
		LCD_data_tx(pixel);
		_delay_ms(BIG_DELAY);

		
		if(ACTION1_BUTTON) { 
			RAM_frame_buffer_write(RANDOM_ADD, frame_buffer); 
		}
	}
}


/////////////////////////////////////////////////
void snake(byte *row, byte *column, byte frame_buffer[MAX_COLUMN][MAX_PAGE]) 
{ 
	LCD_clear(); 
	byte left = OFF; 
	byte right = OFF;
	byte up = OFF;
	byte down = OFF;
	byte horizontal = OFF; 
	byte vertical = OFF; 

	byte row_one = OFF; 
	byte row_two = OFF; 
	byte row_three = OFF; 
	byte row_four = OFF; 
	byte row_five = OFF; 
	byte column_one = OFF; 
	byte column_two = OFF; 
	byte column_three = OFF; 
	byte column_four = OFF; 
	byte column_five = OFF; 	

	//int r = rand();
	
	byte counter = INITIAL;
	while(INFINITE_LOOP) {
		if(ACTION2_BUTTON) { 
			clear_frame_buffer(row,column,frame_buffer); 
		}

				

		if(counter>5) {
		byte page_clear = row_five/MAX_PIXEL;
		byte pixel_clear = row_five%MAX_PIXEL;
		select_page(page_clear);
		select_column(column_five);
		pixel_clear = (_BV(pixel_clear) | (frame_buffer[column_five][page_clear]));
		frame_buffer[column_five][page_clear] = OFF;
		LCD_data_tx(OFF);	
		}
		
		counter++; 	

		if(horizontal && right) { 
			(*column)++; 		
		} 
		
		if(horizontal && left) { 
			(*column)--; 
		} 
		
		if(vertical && up) { 
			(*row)--; 
		} 
		
		if(vertical && down) { 
			(*row)++; 
		} 

		if(UP_BUTTON) {
			vertical = ON; 
			horizontal = OFF; 
			up = ON;
			down = OFF; 
		}

		if(DOWN_BUTTON) {
			vertical = ON; 
			horizontal = OFF;
			down = ON;
			up = OFF;
		}
		
		if(LEFT_BUTTON)	{
			horizontal = ON; 
			vertical = OFF; 
			left = ON; 
			right = OFF;
		} 

		if(RIGHT_BUTTON) {
			horizontal = ON; 
			vertical = OFF;
			right = ON;		
			left = OFF;
		}

		if((*column)<MIN_COLUMN) {
			(*column) = MIN_COLUMN; 
		}
		
		if((*row)<MIN_ROW) { 
			(*row) = MIN_ROW; 
		}	

		if((*column)>=MAX_COLUMN) {
			(*column) = MAX_COLUMN - ONE; 
		}
		
		if((*row)>=MAX_ROW) { 
			(*row) = MAX_ROW - ONE; 
		}
		row_five = row_four;
		row_four = row_three; 
		row_three = row_two; 
		row_two = row_one; 
		row_one = (*row);
		column_five = column_four; 
		column_four = column_three; 
		column_three = column_two;
	    column_two = column_one; 
		column_one = (*column); 		
	
		byte page = (*row)/MAX_PIXEL;
		byte pixel = (*row)%MAX_PIXEL;
		select_page(page);
		select_column((*column));
		pixel = (_BV(pixel) | (frame_buffer[(*column)][page]));
		frame_buffer[(*column)][page] = pixel;
		LCD_data_tx(pixel);
		_delay_ms(SMALL_DELAY);
	}
}


/////////////////////////////////////////////////
void clear_frame_buffer(byte *row, byte *column, byte frame_buffer[MAX_COLUMN][MAX_PAGE]) 
{ 
		for((*row)=0; (*row)<MAX_ROW; (*row)++) {
			for((*column)=0; (*column)<MAX_COLUMN; (*column)++) {
				byte page_clear = (*row)/MAX_PIXEL;
				byte pixel_clear = (*row)%MAX_PIXEL;
				select_page(page_clear);
				select_column((*column));
				pixel_clear = FALSE;
				frame_buffer[(*column)][page_clear] = pixel_clear;
				LCD_data_tx(pixel_clear);
			}
		}
		(*row) = ROW_CENTRE;
		(*column) = COLUMN_CENTRE;
}


/////////////////////////////////////////////////
void LCD_select_1(void) 
{
	LCD_clear(); 
	LCD_write_pixel(3,51,ON); 
}


/////////////////////////////////////////////////
void LCD_select_2(void) 
{
	LCD_clear(); 
	LCD_write_pixel(3,51,ON); 	
	LCD_write_pixel(3,53,ON); 
}


/////////////////////////////////////////////////
void LCD_select_3(void) 
{
	LCD_clear(); 
	LCD_write_pixel(3,51,ON); 	
	LCD_write_pixel(3,53,ON); 
	LCD_write_pixel(3,55,ON); 
}


/////////////////////////////////////////////////
void PWM_initialise(void) {
	BACKLIGHT_DIR(OUT);
	//Fast PWM, Non-inverting mode, CLK (Prescale to clkIO/1)
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(1<<COM1B1)|(0<<COM1B0)|(0<<WGM11)|(1<<WGM10);
    TCCR1B = (0<<ICNC1)|(1<<ICES1)|(0<<WGM13)|(1<<WGM12)|(0<<CS12)|(0<<CS11)|(1<<CS10);
    TCNT1 = ALL;
    OCR1A = FALSE;
    OCR1B = ALL;

	_delay_ms(SMALL_DELAY); 
} 


/////////////////////////////////////////////////
void adjust_backlight(void) {

	int bright_val;
	bright_val = HIGH; 

	while(INFINITE_LOOP) {
		BAT_LOW_LED(OFF);	
		if(ACTION2_BUTTON) {
			bright_val=bright_val-BRIGHT_INCREMENT;
		}
		
		if(bright_val==MIN_BRIGHT) { 
			bright_val = OFF; 
		}

		if(bright_val<OFF) { 
			bright_val = MAX_BRIGHT;
		}
		
		if(ACTION1_BUTTON) {
			break; 
		}
		
		if(UP_BUTTON) {
			RAM_write(INIT_ADD_MSB, bright_val);
			BAT_LOW_LED(ON);
		}
		
		if(DOWN_BUTTON) {
			bright_val = RAM_read(INIT_ADD_MSB); 
		}
		 
		OCR1B = bright_val;
		_delay_ms(SMALL_DELAY);
	}
} 


/////////////////////////////////////////////////
void INT_initialise(void) { 
	cli();
	//Interrupt @ Rising Edge for INT1
	MCUCR = ((1<<ISC11)|(1<<ISC10));
	GICR = ((0<<INT0)|(1<<INT1)|(0<<INT2));
	sei(); 
}


/////////////////////////////////////////////////
ISR(INT1_vect) { 
	if(ACTION3_BUTTON) {  
		adjust_backlight(); 
	} 
}


/////////////////////////////////////////////////
void ADC_initialise(void) { 
	ADMUX = ((1<<REFS1)|(1<<REFS0));
	ADCSRA = ((1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
}


/////////////////////////////////////////////////
void ADC_BATTERY_CHECK(void) {

	ADMUX|= ((0<<MUX4)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0));
	// Start ADC Conversion
	ADCSRA|= (1<<ADSC); 
 	
	while(ADCSRA & (1<<ADSC)){};

	if(ADC<BAT_LOW_THRESHOLD) { 
		BAT_LOW_LED(ON);
	} else {
		BAT_LOW_LED(OFF);
	}

	ADCSRA|= (0<<ADSC);
}


/////////////////////////////////////////////////
void RAM_initialise(void) { 
	SPI_MasterInit();
	RAM_HOLD_SET(HIGH);
	RAM_WP_SET(HIGH); 
}


/////////////////////////////////////////////////
void RAM_write(unsigned int add, byte tx_byte) { 
	byte add_MSB = INITIAL;
	byte add_LSB = INITIAL;
	add_MSB = INIT_ADD_MSB;
	add_LSB = INIT_ADD_LSB; 

	RAM_CHIP_SELECT_SET(LOW);
	_delay_ms(TINY_DELAY); 
	SPI_MasterTransmit(WREN);	
	RAM_CHIP_SELECT_SET(HIGH);
	_delay_ms(TINY_DELAY); 

	RAM_CHIP_SELECT_SET(LOW); 
	_delay_ms(TINY_DELAY);
	SPI_MasterTransmit(WRITE);
	SPI_MasterTransmit(add_MSB);
	SPI_MasterTransmit(add_LSB);
	SPI_MasterTransmit(tx_byte);
	_delay_ms(TINY_DELAY);
	RAM_CHIP_SELECT_SET(HIGH);
	_delay_ms(TINY_DELAY);
} 


/////////////////////////////////////////////////
byte RAM_read(unsigned int add) { 
	byte add_MSB = INITIAL;
	byte add_LSB = INITIAL;
	add_MSB = INIT_ADD_MSB; //add >> 8; 
	add_LSB = INIT_ADD_LSB; 
	byte rx_byte = INITIAL;

	RAM_CHIP_SELECT_SET(LOW);
	_delay_ms(TINY_DELAY);
	SPI_MasterTransmit(READ); 
	SPI_MasterTransmit(add_MSB);
	SPI_MasterTransmit(add_LSB);
	SPI_MasterTransmit(rx_byte);
	rx_byte = SPDR;
	RAM_CHIP_SELECT_SET(HIGH);
	_delay_ms(TINY_DELAY);
	return(rx_byte);
} 


/////////////////////////////////////////////////
void RAM_frame_buffer_write(unsigned int add, byte frame_buffer[MAX_COLUMN][MAX_PAGE]) { 
	byte add_MSB = INITIAL;
	byte add_LSB = INITIAL;
	add_MSB = INIT_ADD_MSB;  
	add_LSB = INIT_ADD_LSB_FB; 

	RAM_CHIP_SELECT_SET(LOW);
	_delay_ms(TINY_DELAY); 
	SPI_MasterTransmit(WREN);	
	RAM_CHIP_SELECT_SET(HIGH);
	_delay_ms(TINY_DELAY); 
	RAM_CHIP_SELECT_SET(LOW); 
	_delay_ms(TINY_DELAY);
	SPI_MasterTransmit(WRITE);
	SPI_MasterTransmit(add_MSB);
	SPI_MasterTransmit(add_LSB);
	
	byte page = INITIAL;
	byte column = INITIAL;
	for(page=INITIAL; page<MAX_PAGE; page++) {
			for(column=INITIAL; column<MAX_COLUMN; column++) {
				SPI_MasterTransmit(frame_buffer[column][page]); 				
			}
		}
	
	_delay_ms(TINY_DELAY);

	RAM_CHIP_SELECT_SET(HIGH);
	_delay_ms(TINY_DELAY);
	BAT_LOW_LED(ON);
	_delay_ms(BIG_DELAY);
	BAT_LOW_LED(OFF);
} 


/////////////////////////////////////////////////
void RAM_frame_buffer_read(byte frame_buffer[MAX_COLUMN][MAX_PAGE]) { 
	byte add_MSB = INITIAL;
	byte add_LSB = INITIAL;
	add_MSB = INIT_ADD_MSB; 
	add_LSB = INIT_ADD_LSB_FB; 

	RAM_CHIP_SELECT_SET(LOW);
	_delay_ms(TINY_DELAY);
	SPI_MasterTransmit(READ); 
	SPI_MasterTransmit(add_MSB);
	SPI_MasterTransmit(add_LSB);
	
	byte page = INITIAL;
	byte column = INITIAL;
	for(page=INITIAL; page<MAX_PAGE; page++) 
	{
		for(column=INITIAL; column<MAX_COLUMN; column++) 
		{
			SPI_MasterTransmit(frame_buffer[column][page]); 
			frame_buffer[column][page] = SPDR;				
		}
	}

	RAM_CHIP_SELECT_SET(HIGH);
	_delay_ms(TINY_DELAY);
} 



/////////////////////////////////////////////////
void LCD_reload(byte frame_buffer[MAX_COLUMN][MAX_PAGE])
{
	int page; 
	int column; 
	
	for(page=INITIAL; page<MAX_PAGE; page++) {
		for(column=INITIAL; column<MAX_COLUMN; column++) {
			select_page(page); 
			select_column(column); 
			LCD_data_tx(frame_buffer[column][page]); 
		}
	}
}
