#include "common.h"
#include "video.h"
#include "string.h"
#include "log.h"
#include "argctrl.h"
#include "Convert.h"

VIDEO_CURMSG Video_CurMsg;

void Video_Init()
{
	Video_Cls();
}

void Video_Cls()
{
	uint i;
	
	HideCursor();
	
	Video_SetCurPosition(0,0);
	Video_SetCurFontStyle(VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
	
	for(i = 0;i < VIDEO_SIZE;i += 2)
	{
		WritePhysicsMemory8(VIDEO_ADDRESS + i,0x20);//写入空格
		WritePhysicsMemory8(VIDEO_ADDRESS + i + 1,0x0F);//写入样式
	}
}

void Video_WriteChar(uchar Line,uchar Column,uchar Value,uchar FontStyle)
{
	if((Line >= VIDEO_LINE_NUM) || (Column >= VIDEO_COLUMN_NUM))
	{
		Log_Error((uchar *)"Video_WriteStr",(uchar *)"Invalid Line or Column");
		return;
	}
		
	WritePhysicsMemory8(VIDEO_ADDRESS + (Line * VIDEO_COLUMN_NUM + Column) * 2,Value);
	WritePhysicsMemory8(VIDEO_ADDRESS + (Line * VIDEO_COLUMN_NUM + Column) * 2 + 1,FontStyle);
}

void Video_DispStr(uchar Line,uchar Column,uchar *str,uchar FontStyle)
{
	uint i;
	
	if((Line >= VIDEO_LINE_NUM) || (Column >= VIDEO_COLUMN_NUM))
	{
		Log_Error((uchar *)"Video_DispStr",(uchar *)"Invalid Line or Column");
		return;
	}

	for(i = 0;i < String_GetLen(str);i++)
	{	
		if(Column >= VIDEO_COLUMN_NUM)
		{
			Column = 0;
			Line++;
		}
		
		if(Line >= VIDEO_LINE_NUM)
		{
			return;
		}
		
		Video_WriteChar(Line,Column,str[i],FontStyle);
		Column++;
	}	
}

void Video_NextLine()
{
	uint i;

	if(Video_CurMsg.CurrentLine == (VIDEO_LINE_NUM - 1)) //屏幕已满，上移一行
	{
		for(i = VIDEO_COLUMN_NUM * 2;i < (VIDEO_COLUMN_NUM * VIDEO_LINE_NUM *2);i++)
		{
			WritePhysicsMemory8(VIDEO_ADDRESS + (i - VIDEO_COLUMN_NUM * 2),ReadPhysicsMemory8(VIDEO_ADDRESS + i));
		}

		Video_CurMsg.CurrentColumn = 0;
		
		//清空最后一行
		
		for(i = 0;i < VIDEO_COLUMN_NUM * 2;i += 2)
		{
			WritePhysicsMemory8(VIDEO_ADDRESS + (VIDEO_LINE_NUM - 1) * VIDEO_COLUMN_NUM * 2 + i,STRING_STR_BLANK);
			WritePhysicsMemory8(VIDEO_ADDRESS + (VIDEO_LINE_NUM - 1) * VIDEO_COLUMN_NUM * 2 + i + 1,Video_CurMsg.CurrentFontStyle);
		}
	}
	else
	{
		Video_CurMsg.CurrentLine++;
		Video_CurMsg.CurrentColumn = 0;
	}
}

void Video_WriteStr(uchar *str)
{
	uint i;
	uint offset;

	if(str[0] != STRING_STR_END)
	{
		//若当前行已满，且第一个字符不为\n则创建新行
		if((Video_CurMsg.CurrentColumn == VIDEO_COLUMN_NUM) && (str[0] != STRING_STR_NEXTLINE))
		{
			Video_NextLine();
		}

		for(i = 0;i < String_GetLen(str);i++)
		{
			if(str[i] != '\n')
			{
				offset = (Video_CurMsg.CurrentLine * VIDEO_COLUMN_NUM + Video_CurMsg.CurrentColumn) * 2;
				WritePhysicsMemory8(VIDEO_ADDRESS + offset,str[i]);
				WritePhysicsMemory8(VIDEO_ADDRESS + offset + 1,Video_CurMsg.CurrentFontStyle);
				Video_CurMsg.CurrentColumn++;
			}
			else
			{
				Video_NextLine();
			}

			if(str[i + 1] == STRING_STR_END)
			{
				break;
			}

			if((Video_CurMsg.CurrentColumn == VIDEO_COLUMN_NUM) && (str[i + 1] != STRING_STR_NEXTLINE))
			{
				Video_NextLine();
			}
		}
	}
}

void Video_printf(uchar *str,...)
{
	int ESP;
	int i;
	int argindex;
	uchar buf[2];
	uchar buf2[20];
	uint64 t;

	ESP = ArgCtrl_GetVarArgTableStackAddress((uint)&str);
	buf[1] = 0;
	argindex = 0;
	
	for(i = 0;i < String_GetLen(str);i++)
	{
		if(str[i] != '%')
		{
			buf[0] = str[i];
			Video_WriteStr(buf);
		}
		else
		{
			switch(str[i + 1])
			{
				case VIDEO_PRINTF_NONE:
					i++;
					break;

				case VIDEO_PRINTF_ORIGINAL:
					buf[0] = '%';
					Video_WriteStr(buf);
					i++;
					break;

				case VIDEO_PRINTF_INT:
					Convert_IntToStr((int)ArgCtrl_GetVarArg_uint(ESP,argindex++),buf2);
					Video_WriteStr(buf2);
					i++;
					break;

				case VIDEO_PRINTF_UINT:

					switch(str[i + 2])
					{
						case VIDEO_PRINTF_INT64:
							t = ArgCtrl_GetVarArg_uint(ESP,++argindex);
							t <<= 32;
							t |= ArgCtrl_GetVarArg_uint(ESP,argindex-1);
							argindex++;
							Convert_Uint64ToStr(t,buf2);
							Video_WriteStr(buf2);
							i++;
							break;

						default:
							Convert_UintToStr(ArgCtrl_GetVarArg_uint(ESP,argindex++),buf2);
							Video_WriteStr(buf2);
							break;

					}
					
					i++;
					break;
				
				case VIDEO_PRINTF_UCHAR:
					buf[0] = ArgCtrl_GetVarArg_uchar(ESP,argindex++);
					Video_WriteStr(buf);
					i++;
					break;

				case VIDEO_PRINTF_UCHARPTR:
					Video_WriteStr(ArgCtrl_GetVarArg_ucharptr(ESP,argindex++));
					i++;
					break;

				case VIDEO_PRINTF_BYTE:
					Convert_ByteToStr(ArgCtrl_GetVarArg_uint(ESP,argindex++),buf2);
					Video_WriteStr(buf2);
					i++;
					break;

				case VIDEO_PRINTF_WORD:
					Convert_WordToStr(ArgCtrl_GetVarArg_uint(ESP,argindex++),buf2);
					Video_WriteStr(buf2);
					i++;
					break;

				case VIDEO_PRINTF_DWORD:
					Convert_DWordToStr(ArgCtrl_GetVarArg_uint(ESP,argindex++),buf2);
					Video_WriteStr(buf2);
					i++;
					break;

				case VIDEO_PRINTF_INT64:
					t = ArgCtrl_GetVarArg_uint(ESP,++argindex);
					t <<= 32;
					t |= ArgCtrl_GetVarArg_uint(ESP,argindex-1);
					argindex++;
					Convert_Int64ToStr((int64)t,buf2);
					Video_WriteStr(buf2);
					i++;
					break;
			}
		}
	}
}

void Video_SetCurPosition(uchar Line,uchar Column)
{
	if((Line >= VIDEO_LINE_NUM) || (Column >= VIDEO_COLUMN_NUM))
	{
		Log_Error((uchar *)"Video_SetCurPosition",(uchar *)"Invalid Line or Column");
		return;
	}

	Video_CurMsg.CurrentLine = Line;
	Video_CurMsg.CurrentColumn = Column;
}

void Video_SetCurFontStyle(uchar Style)
{
	Video_CurMsg.CurrentFontStyle = Style;
}