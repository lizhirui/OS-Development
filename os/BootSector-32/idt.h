#ifndef __IDT_H__
#define __IDT_H__

#define IDT_SegmentDescriptor_DPL0 0x00
#define IDT_SegmentDescriptor_DPL1 0x01
#define IDT_SegmentDescriptor_DPL2 0x02
#define IDT_SegmentDescriptor_DPL3 0x03
#define IDT_SegmentDescriptor_Enable 0x04
#define IDT_SegmentDescriptor_Disabled 0x00
#define IDT_SegmentDescriptor_16Bit 0x00
#define IDT_SegmentDescriptor_32Bit 0x08

#define IDT_ADDR 0x00010000

#define IDT_ID_MIN 0
#define IDT_ID_MAX 255

typedef struct IDT_SegmentDescriptor{
	SegmentSelector SegSel;
	uint Offset;
	uint Attr;
}IDT_SegmentDescriptor;

IDT_SegmentDescriptor IDT_ReadIDT(uint ID);
void IDT_WriteIDT(uint ID,IDT_SegmentDescriptor s);
void IDT_AddAttr(IDT_SegmentDescriptor *s,uint Attr);
void IDT_DelAttr(IDT_SegmentDescriptor *s,uint Attr);

#endif