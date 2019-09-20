#include "common.h"

uint SetSegmentSelector(SegmentSelector s)
{
	return (s.ID << 3) | (s.Attr & 0x07);
}

SegmentSelector GetSegmentSelector(uint Value)
{
	SegmentSelector s;

	s.ID = Value >> 3;
	s.Attr = Value & 0x07;
	return s;
}

void GetBootID(uchar *buf)//取引导程序ID
{
	uint i;
	uchar x;
	
	for(i = 0;i < 16;i++)
	{
		buf[i] = ReadPhysicsMemory8(BOOTADDRESS + i + 3);
	}
}

uint64 __udivdi3(uint64 a,uint64 b)
{
	uint i;
	uint64 t;
	uint lena,lenb;
	uint64 r;//记录结果 
	uint j;//记录商当前的写入位置 
	ClrI();
	if(a == 0)
	{
		return (uint64)0;
	}

	if(b == 0)//除数为0
	{
		return (uint64)0;
	}
	
	if(a < b)
	{
		return (uint64)0;
	}
	
	//从此处开始,a>=b 即lena>=lenb 
	
	t = a;
	lena = 0;
	
	for(i = 0;i < 63;i++)
	{
		if((t & 0x01) != 0)
		{
			lena = i + 1;
		}
		
		t >>= 1;
	}
	
	t = b;
	lenb = 0;
	
	for(i = 0;i < 63;i++)
	{
		if((t & 0x01) != 0)
		{
			lenb = i + 1;
		}
		
		t >>= 1;
	}
	
	b <<= lena - lenb;//左移使a与b左对齐
	
	r = 0;
	
	j = lena - lenb;
	
	for(i = 0;i < (lena - lenb + 1);i++)
	{
		if(a >= b)
		{
			r |= (uint64)1 << j;//此处注意将1转换为uint64类型以防止C编译器将其当作32bit整数处理 
			a -= b;
		}
		
		b >>= 1;
		j--;
	}
	SetI();
	return r;
}

int64 __divdi3(int64 a,int64 b)
{
	int f;
	int64 r;

	if(a == 0)
	{
		return 0;
	}

	if(b == 0)//除数为0
	{
		return 0;
	}

	f = 0;

	if(a < 0)
	{
		a = -a;
		f++;
	}

	if(b < 0)
	{
		b = -b;
		f++;
	}

	r = (int64)((uint64)a / (uint64)b);

	if((f & 0x01) == 1)
	{
		return -r;
	}
	else
	{
		return r;
	}
}

uint64 __umoddi3(uint64 a,uint64 b)
{
	uint i;
	uint64 t;
	uint lena,lenb;
	uint64 r;//记录结果 
	uint j;//记录商当前的写入位置 
	
	if(a == 0)
	{
		return 0;
	}

	if(b == 0)//除数为0
	{
		return 0;
	}

	if(a < b)
	{
		return a;
	}
	//从此处开始,a>=b 即lena>=lenb 
	
	t = a;
	lena = 0;
	
	for(i = 0;i < 63;i++)
	{
		if((t & 0x01) != 0)
		{
			lena = i + 1;
		}
		
		t >>= 1;
	}
	
	t = b;
	lenb = 0;
	
	for(i = 0;i < 63;i++)
	{
		if((t & 0x01) != 0)
		{
			lenb = i + 1;
		}
		
		t >>= 1;
	}
	
	b <<= lena - lenb;//左移使a与b左对齐
	
	r = 0;
	
	j = lena - lenb;
	
	for(i = 0;i < (lena - lenb + 1);i++)
	{
		if(a >= b)
		{
			r |= (uint64)1 << j;//此处注意将1转换为uint64类型以防止C编译器将其当作32bit整数处理 
			a -= b;
		}
		
		b >>= 1;
		j--;
	}
	
	return a;
}
