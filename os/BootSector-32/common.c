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

void GetBootID(uchar *buf)//ȡ��������ID
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
	uint64 r;//��¼��� 
	uint j;//��¼�̵�ǰ��д��λ�� 
	ClrI();
	if(a == 0)
	{
		return (uint64)0;
	}

	if(b == 0)//����Ϊ0
	{
		return (uint64)0;
	}
	
	if(a < b)
	{
		return (uint64)0;
	}
	
	//�Ӵ˴���ʼ,a>=b ��lena>=lenb 
	
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
	
	b <<= lena - lenb;//����ʹa��b�����
	
	r = 0;
	
	j = lena - lenb;
	
	for(i = 0;i < (lena - lenb + 1);i++)
	{
		if(a >= b)
		{
			r |= (uint64)1 << j;//�˴�ע�⽫1ת��Ϊuint64�����Է�ֹC���������䵱��32bit�������� 
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

	if(b == 0)//����Ϊ0
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
	uint64 r;//��¼��� 
	uint j;//��¼�̵�ǰ��д��λ�� 
	
	if(a == 0)
	{
		return 0;
	}

	if(b == 0)//����Ϊ0
	{
		return 0;
	}

	if(a < b)
	{
		return a;
	}
	//�Ӵ˴���ʼ,a>=b ��lena>=lenb 
	
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
	
	b <<= lena - lenb;//����ʹa��b�����
	
	r = 0;
	
	j = lena - lenb;
	
	for(i = 0;i < (lena - lenb + 1);i++)
	{
		if(a >= b)
		{
			r |= (uint64)1 << j;//�˴�ע�⽫1ת��Ϊuint64�����Է�ֹC���������䵱��32bit�������� 
			a -= b;
		}
		
		b >>= 1;
		j--;
	}
	
	return a;
}
