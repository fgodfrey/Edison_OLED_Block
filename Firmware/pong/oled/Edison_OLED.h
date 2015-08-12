/******************************************************************************
	Edison_OLED.h
	Header file for the Edison OLED Block C++ Library

	Jim Lindblom @ SparkFun Electronics
	January 8, 2014
	https://github.com/sparkfun/Edison_OLED_Block/tree/master/Firmware/

	This file defines the hardware interface for the Edison OLED Block

	This code was heavily based around the MicroView library, written by GeekAmmo
	(https://github.com/geekammo/MicroView-Arduino-Library), and released under
	the terms of the GNU General Public License as published by the Free Software
	Foundation, either version 3 of the License, or (at your option) any later
	version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#ifndef EDISON_OLED_H
#define EDISON_OLED_H

#include "../gpio/gpio.h"


#define swap(a, b) { unsigned char t = a; a = b; b = t; }

#define BLACK 0
#define WHITE 1

#define LCDWIDTH			96
#define LCDHEIGHT			64
#define FONTHEADERSIZE		6

#define NORM				0
#define XOR					1

#define PAGE				0
#define ALL					1

#define CMD_DRAW_LINE                       0x21
#define CMD_DRAW_RECTANGLE                  0x22
#define CMD_COPY_WINDOW                     0x23
#define CMD_DIM_WINDOW                      0x24
#define CMD_CLEAR_WINDOW                    0x25
#define CMD_FILL_WINDOW                     0x26
    #define DISABLE_FILL    0x00
    #define ENABLE_FILL     0x01
#define CMD_CONTINUOUS_SCROLLING_SETUP      0x27
#define CMD_DEACTIVE_SCROLLING              0x2E
#define CMD_ACTIVE_SCROLLING                0x2F

#define CMD_SET_COLUMN_ADDRESS              0x15
#define CMD_SET_ROW_ADDRESS                 0x75
#define CMD_SET_CONTRAST_A                  0x81
#define CMD_SET_CONTRAST_B                  0x82
#define CMD_SET_CONTRAST_C                  0x83
#define CMD_MASTER_CURRENT_CONTROL          0x87
#define CMD_SET_PRECHARGE_SPEED_A           0x8A
#define CMD_SET_PRECHARGE_SPEED_B           0x8B
#define CMD_SET_PRECHARGE_SPEED_C           0x8C
#define CMD_SET_REMAP                       0xA0
#define CMD_SET_DISPLAY_START_LINE          0xA1
#define CMD_SET_DISPLAY_OFFSET              0xA2
#define CMD_NORMAL_DISPLAY                  0xA4
#define CMD_ENTIRE_DISPLAY_ON               0xA5
#define CMD_ENTIRE_DISPLAY_OFF              0xA6
#define CMD_INVERSE_DISPLAY                 0xA7
#define CMD_SET_MULTIPLEX_RATIO             0xA8
#define CMD_DIM_MODE_SETTING                0xAB
#define CMD_SET_MASTER_CONFIGURE            0xAD
#define CMD_DIM_MODE_DISPLAY_ON             0xAC
#define CMD_DISPLAY_OFF                     0xAE
#define CMD_NORMAL_BRIGHTNESS_DISPLAY_ON    0xAF
#define CMD_POWER_SAVE_MODE                 0xB0
#define CMD_PHASE_PERIOD_ADJUSTMENT         0xB1
#define CMD_DISPLAY_CLOCK_DIV               0xB3
#define CMD_SET_GRAy_SCALE_TABLE            0xB8
#define CMD_ENABLE_LINEAR_GRAY_SCALE_TABLE  0xB9
#define CMD_SET_PRECHARGE_VOLTAGE           0xBB
#define CMD_SET_V_VOLTAGE                   0xBE

typedef enum CMD {
	CMD_CLEAR,			//0
	CMD_INVERT,			//1
	CMD_CONTRAST,		//2
	CMD_DISPLAY,		//3
	CMD_SETCURSOR,		//4
	CMD_PIXEL,			//5
	CMD_LINE,			//6
	CMD_LINEH,			//7
	CMD_LINEV,			//8
	CMD_RECT,			//9
	CMD_RECTFILL,		//10
	CMD_CIRCLE,			//11
	CMD_CIRCLEFILL,		//12
	CMD_DRAWCHAR,		//13
	CMD_DRAWBITMAP,		//14
	CMD_GETLCDWIDTH,	//15
	CMD_GETLCDHEIGHT,	//16
	CMD_SETCOLOR,		//17
	CMD_SETDRAWMODE		//18
} commCommand_t;

class edOLED {
public:
	edOLED();
	
	void begin(void);

	unsigned char write(unsigned char);
	unsigned char writeVert(unsigned char);
	void print(const char * c);
	void print(int d);
	void printVert(const char * c);
	void printVert(int d);

	// RAW LCD functions
	void command(unsigned char c);
	void data(unsigned char c);
	void setColumnAddress(unsigned char add);
	void setRowAddress(unsigned char add);
	
	// LCD Draw functions
	void clear(unsigned char mode);
	void clear(unsigned char mode, unsigned char c);
	void invert(unsigned char inv);
	void contrast(unsigned char contrast);
	void display(void);
	void setCursor(unsigned char x, unsigned char y);
	void pixel(unsigned char x, unsigned char y);
	void pixel(unsigned char x, unsigned char y, unsigned char color, unsigned char mode);
	void line(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1);
	void line(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char color, unsigned char mode);
	void lineH(unsigned char x, unsigned char y, unsigned char width);
	void lineH(unsigned char x, unsigned char y, unsigned char width, unsigned char color, unsigned char mode);
	void lineV(unsigned char x, unsigned char y, unsigned char height);
	void lineV(unsigned char x, unsigned char y, unsigned char height, unsigned char color, unsigned char mode);
	void rect(unsigned char x, unsigned char y, unsigned char width, unsigned char height);
	void rect(unsigned char x, unsigned char y, unsigned char width, unsigned char height, unsigned char color , unsigned char mode);
	void rectFill(unsigned char x, unsigned char y, unsigned char width, unsigned char height);
	void rectFill(unsigned char x, unsigned char y, unsigned char width, unsigned char height, unsigned char color , unsigned char mode);
	void circle(unsigned char x, unsigned char y, unsigned char radius);
	void circle(unsigned char x, unsigned char y, unsigned char radius, unsigned char color, unsigned char mode);
	void circleFill(unsigned char x0, unsigned char y0, unsigned char radius);
	void circleFill(unsigned char x0, unsigned char y0, unsigned char radius, unsigned char color, unsigned char mode);
	void drawChar(unsigned char x, unsigned char y, unsigned char c);
	void drawChar(unsigned char x, unsigned char y, unsigned char c, unsigned char color, unsigned char mode);
	void drawCharVert(unsigned char x, unsigned char y, unsigned char c);
	void drawCharVert(unsigned char x, unsigned char y, unsigned char c, unsigned char color, unsigned char mode);
	void drawBitmap(void);
	unsigned char getLCDWidth(void);
	unsigned char getLCDHeight(void);
	void setColor(unsigned char color);
	void setDrawMode(unsigned char mode);

	// Font functions
	unsigned char getFontWidth(void);
	unsigned char getFontHeight(void);
	unsigned char getTotalFonts(void);
	unsigned char getFontType(void);
	unsigned char setFontType(unsigned char type);
	unsigned char getFontStartChar(void);
	unsigned char getFontTotalChar(void);

	// LCD Rotate Scroll functions	
	void scrollRight(unsigned char start, unsigned char stop);
	void scrollLeft(unsigned char start, unsigned char stop);
	void scrollVertRight(unsigned char start, unsigned char stop);
	void scrollVertLeft(unsigned char start, unsigned char stop);
	void scrollStop(void);
	void flipVertical(unsigned char flip);
	void flipHorizontal(unsigned char flip);
	
	//void doCmd(unsigned char index);
	
private:
	unsigned char foreColor,drawMode,fontWidth, fontHeight, fontType, fontStartChar, fontTotalChar, cursorX, cursorY;
	unsigned int fontMapWidth;
	static const unsigned char *fontsPointer[];
					  
	// Communication
	void spiTransfer(unsigned char data);
	void spiTransferBulk(unsigned char *data, int len, PIN_VALUE dc_level);
	void spiSetup();
};
#endif
