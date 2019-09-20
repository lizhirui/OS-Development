#include "common.h"
#include "idt.h"

IDT_SegmentDescriptor IDT_ReadGDT(uint ID)
{
	IDT_SegmentDescriptor r;
	uchar idt_buf[8];
	uint Addr;
	uint i;

	if((ID < IDT_ID_MIN) || (ID > IDT_ID_MAX)) //ID有效性检测
	{
		return r;
	}

	Addr = IDT_ADDR + ID * 8; //读取IDT

	for(i = 0;i < 8;i++)
	{
		idt_buf[i] = ReadPhysicsMemory8(Addr + i);
	}

	//整理IDT数据结构

	r.SegSel = GetSegmentSelector((((uint)idt_buf[3]) << 8) | ((uint)idt_buf[2]));
	r.Offset = (((uint)idt_buf[7]) << 24) | (((uint)idt_buf[6]) << 16) | (((uint)idt_buf[1]) << 8) | ((uint)idt_buf[0]);
	r.Attr = (uint)(idt_buf[5] >> 5) | (uint)(((idt_buf[5] >> 3) & 0x01) << 3);
	return r;
}

void IDT_WriteIDT(uint ID,IDT_SegmentDescriptor s)
{
	uint Addr;
	uint Value;

	if((ID < IDT_ID_MIN) || (ID > IDT_ID_MAX)) //ID有效性检测
	{
		return;
	}

	Addr = IDT_ADDR + ID * 8;
	Value = SetSegmentSelector(s.SegSel);
	WritePhysicsMemory8(Addr + 0,(uchar)(s.Offset & 0xFF));
	WritePhysicsMemory8(Addr + 1,(uchar)((s.Offset>> 8) & 0xFF));
	WritePhysicsMemory8(Addr + 2,(uchar)(Value & 0xFF));
	WritePhysicsMemory8(Addr + 3,(uchar)((Value >> 8) & 0xFF));
	WritePhysicsMemory8(Addr + 4,0x00);
	WritePhysicsMemory8(Addr + 5,(uchar)(((s.Attr & 0x07) << 5) | (s.Attr & 0x08) | 0x06));
	WritePhysicsMemory8(Addr + 6,(uchar)((s.Offset >> 16) & 0xFF));
	WritePhysicsMemory8(Addr + 7,(uchar)((s.Offset >> 24) & 0xFF));
}

void IDT_AddAttr(IDT_SegmentDescriptor *s,uint Attr)
{
	s -> Attr |= Attr;
}

void IDT_DelAttr(IDT_SegmentDescriptor *s,uint Attr)
{
	s -> Attr &= ~Attr;
}