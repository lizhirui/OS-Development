#ifndef __GDT_H__
#define __GDT_H__

#define SegmentDescriptor_Code_X 0x08
#define SegmentDescriptor_Code_RX 0x0A
#define SegmentDescriptor_Code_Share_X 0x0C
#define SegmentDescriptor_Code_Share_RX 0x0E
#define SegmentDescriptor_Data_Up_R 0x00
#define SegmentDescriptor_Data_Up_RW 0x02
#define SegmentDescriptor_Data_Down_R 0x04
#define SegmentDescriptor_Data_Down_RW 0x03
#define SegmentDescriptor_SystemSegment 0x00
#define SegmentDescriptor_UserSegment 0x10
#define SegmentDescriptor_DPL0 0x00
#define SegmentDescriptor_DPL1 0x20
#define SegmentDescriptor_DPL2 0x40
#define SegmentDescriptor_DPL3 0x60
#define SegmentDescriptor_Enable 0x80
#define SegmentDescriptor_Disabled 0x00

#define SegmentDescriptor_16Bit 0x0000
#define SegmentDescriptor_32Bit 0x4000
#define SegmentDescriptor_Byte 0x0000
#define SegmentDescriptor_4KByte 0x8000
#define SegmentDescriptor_DataRW 0x92

#define GDT_ADDR 0x00020000

#define GDT_ID_MIN 1
#define GDT_ID_MAX 8191

typedef struct GDT_SegmentDescriptor{
	uint BaseAddr;
	uint Limit;
	uint Attr;
}GDT_SegmentDescriptor;

GDT_SegmentDescriptor GDT_ReadGDT(uint ID);
void GDT_WriteGDT(uint ID,GDT_SegmentDescriptor s);
void GDT_AddAttr(GDT_SegmentDescriptor *s,uint Attr);
void GDT_DelAttr(GDT_SegmentDescriptor *s,uint Attr);

#endif