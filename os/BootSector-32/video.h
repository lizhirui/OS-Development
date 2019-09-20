#ifndef __VIDEO_H__
#define __VIDEO_H__

#define VIDEO_LINE_NUM 25
#define VIDEO_COLUMN_NUM 80

#define VIDEO_ADDRESS 0x000B8000
#define VIDEO_SIZE 0x00007FFF

#define VIDEO_FORE_RED 0x0C
#define VIDEO_FORE_GREEN 0x0A
#define VIDEO_FORE_BLUE 0x09
#define VIDEO_FORE_BROWN 0x06
#define VIDEO_FORE_YELLOW 0x0E
#define VIDEO_FORE_BLACK 0x00
#define VIDEO_FORE_WHITE 0x0F
#define VIDEO_BACK_RED 0xC0
#define VIDEO_BACK_GREEN 0xA0
#define VIDEO_BACK_BLUE 0x90
#define VIDEO_BACK_BLACK 0x00
#define VIDEO_BACK_WHITE 0xF0

#define	VIDEO_PRINTF_NONE 'n'
#define VIDEO_PRINTF_ORIGINAL '%'
#define VIDEO_PRINTF_INT 'd'
#define VIDEO_PRINTF_UINT 'u'
#define VIDEO_PRINTF_UCHAR 'c'
#define VIDEO_PRINTF_UCHARPTR 's'
#define VIDEO_PRINTF_BYTE 'b'
#define VIDEO_PRINTF_WORD 'w'
#define VIDEO_PRINTF_DWORD 'x'
#define VIDEO_PRINTF_INT64 'l'

void Video_Init();//初始化
void Video_Cls();//清屏
void Video_WriteChar(uchar Line,uchar Column,uchar Value,uchar FontStyle);//显示字符
void Video_DispStr(uchar Line,uchar Column,uchar *str,uchar FontStyle);//显示字符串
void Video_NextLine();
void Video_WriteStr(uchar *str);
void Video_printf(uchar *str,...);
void Video_SetCurPosition(uchar Line,uchar Column);
void Video_SetCurFontStyle(uchar Style);

typedef struct VIDEO_CURMSG{
	uchar CurrentLine;
	uchar CurrentColumn;
	uchar CurrentFontStyle;
}VIDEO_CURMSG;

#endif