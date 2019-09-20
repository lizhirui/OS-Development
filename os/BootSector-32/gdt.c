#include "common.h"
#include "gdt.h"

GDT_SegmentDescriptor GDT_ReadGDT(uint ID)
{
	GDT_SegmentDescriptor r;
	uchar gdt_buf[8];
	uint Addr;
	uint i;

	if((ID < GDT_ID_MIN) || (ID > GDT_ID_MAX)) //ID有效性检测
	{
		return r;
	}

	Addr = GDT_ADDR + ID * 8; //读取GDT

	for(i = 0;i < 8;i++)
	{
		gdt_buf[i] = ReadPhysicsMemory8(Addr + i);
	}

	//整理GDT数据结构

	r.BaseAddr = ((uint)gdt_buf[2]) | (((uint)gdt_buf[3]) << 8) | (((uint)gdt_buf[4]) << 16) | (((uint)gdt_buf[7]) << 24);
	r.Limit = ((uint)gdt_buf[0]) | (((uint)gdt_buf[1]) << 8) | ((((uint)gdt_buf[6]) << 16) & 0x0F);
	r.Attr = ((uint)gdt_buf[5]) | ((((uint)gdt_buf[6]) << 8) & 0xF0);
	return r;
}

void GDT_WriteGDT(uint ID,GDT_SegmentDescriptor s)
{
	uint Addr;

	if((ID < GDT_ID_MIN) || (ID > GDT_ID_MAX)) //ID有效性检测
	{
		return;
	}

	Addr = GDT_ADDR + ID * 8;
	WritePhysicsMemory8(Addr + 0,(uchar)(s.Limit & 0xFF));
	WritePhysicsMemory8(Addr + 1,(uchar)((s.Limit >> 8) & 0xFF));
	WritePhysicsMemory8(Addr + 2,(uchar)(s.BaseAddr & 0xFF));
	WritePhysicsMemory8(Addr + 3,(uchar)((s.BaseAddr >> 8) & 0xFF));
	WritePhysicsMemory8(Addr + 4,(uchar)((s.BaseAddr >> 16) & 0xFF));
	WritePhysicsMemory8(Addr + 5,(uchar)(s.Attr & 0xFF));
	WritePhysicsMemory8(Addr + 6,(uchar)(((s.Attr >> 8) & 0xF0) | ((s.Limit >> 16) & 0x0F)));
	WritePhysicsMemory8(Addr + 7,(uchar)((s.BaseAddr >> 24) & 0xFF));
}

void GDT_AddAttr(GDT_SegmentDescriptor *s,uint Attr)
{
	s -> Attr |= Attr;
}

void GDT_DelAttr(GDT_SegmentDescriptor *s,uint Attr)
{
	s -> Attr &= ~Attr;
}