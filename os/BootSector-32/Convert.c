#include "common.h"
#include "Convert.h"
#include "string.h"

uchar Convert_4BitToChar(uchar x)
{
	x &= 0x0F;
	
	if(x >= 0x0A)
	{
		return x - 0x0A + 'A';
	}
	else
	{
		return x + '0';
	}
}

void Convert_ByteToStr(uchar x,uchar *buf)
{
	uchar t;
	
	t = Convert_4BitToChar(x >> 4);
	buf[0] = t;
	t = Convert_4BitToChar(x);
	buf[1] = t;
	buf[2] = STRING_STR_END;
}

void Convert_WordToStr(uint x,uchar *buf)
{
	x &= 0xFFFF;
	Convert_ByteToStr((uchar)(x >> 8),buf);
	Convert_ByteToStr((uchar)(x & 0xFF),buf + 2);
	buf[4] = STRING_STR_END;
}

void Convert_DWordToStr(uint x,uchar *buf)
{
	Convert_WordToStr(x >> 16,buf);
	Convert_WordToStr(x,buf + 4);
	buf[8] = STRING_STR_END;
}

void Convert_UintToStr(uint x,uchar *buf)
{
	uint i;
	uint len;
	uint t;

	if(x == 0)
	{
		buf[0] = '0';
		buf[1] = STRING_STR_END;
	}
	else
	{
		len = 0;
		t = x;

		//计算数值位数
		while(t > 0)
		{
			t /= 10;
			len++;
		}

		//写入缓冲区
		i = len - 1;

		while(x > 0)
		{
			buf[i--] = (x % 10) + '0';
			x /= 10;
		}

		buf[len] = STRING_STR_END;
	}
}

void Convert_IntToStr(int x,uchar *buf)
{
	if(x < 0)
	{
		buf[0] = '-';
		Convert_UintToStr(-x,buf + 1);
	}
	else
	{
		Convert_UintToStr(x,buf);
	}
}

void Convert_Uint64ToStr(uint64 x,uchar *buf)
{
	uint i;
	uint len;
	uint64 t;
	
	if(x == 0)
	{
		buf[0] = '0';
		buf[1] = STRING_STR_END;
	}
	else
	{
		len = 0;
		t = x;

		//计算数值位数
		while(t > 0)
		{
			t /= 10;
			len++;
		}

		//写入缓冲区
		i = len - 1;

		while(x > 0)
		{
			buf[i--] = (x % 10) + '0';
			x /= 10;
		}

		buf[len] = STRING_STR_END;
	}
}

void Convert_Int64ToStr(int64 x,uchar *buf)
{
	if(x < 0)
	{
		buf[0] = '-';
		Convert_Uint64ToStr(-x,buf + 1);
	}
	else
	{
		Convert_Uint64ToStr(x,buf);
	}
}