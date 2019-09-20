#ifndef __COMMON_H__
#define __COMMON_H__

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define int64 long long
#define uint64 unsigned long long

#define Selector_Code32 1 << 3
#define Selector_Data 2 << 3
#define Selector_Stack 3 << 3
#define Selector_Video 4 << 3
#define Selector_ParititionMsg 5 << 3
#define Selector_BootSector 6 << 3
#define Selector_PhysicsMemory 7 << 3

#define PRG_BASEADDR 0x00030000
#define BOOTADDRESS 0x7C00

#define TRUE 1
#define FALSE 0

void SetDSSelector(uint Selector);
void SetESSelector(uint Selector);
void SetFSSelector(uint Selector);
void SetGSSelector(uint Selector);
void WritePhysicsMemory8(uint Address,uchar Value);
uchar ReadPhysicsMemory8(uint Address);
void WritePhysicsMemory16(uint Address,uint Value);
uint ReadPhysicsMemory16(uint Address);
void WritePhysicsMemory32(uint Address,uint Value);
uint ReadPhysicsMemory32(uint Address);

void SetCursorLocation(uchar Line,uchar Column);
void HideCursor();

void SetI();
void ClrI();

uint GetESP();//获取ESP寄存器的值
uint GetStackValue(uint ESP);//获取堆栈值

uint64 GetRDTSC();//读取CPU内部计时器
uint64 Get1sCycle();//读取CPU1s的计时数

uchar IO_In8(uint Addr);
void IO_Out8(uint Addr,uchar Dat);
uint IO_In16(uint Addr);
void IO_Out16(uint Addr,uint Dat);
uint IO_In32(uint Addr);
void IO_Out32(uint Addr,uint Dat);

void Int(uchar n);

void IO_Delay();

void WriteSysConfigTable32(uint Offset,uint Value);
uint ReadSysConfigTable32(uint Offset);

void Sys_Log(uchar *str);//系统日志记录

void GetBootID(uchar *buf);//取引导程序ID

uint Test();

int64 __divdi3(int64 a,int64 b);//有符号64位整数除法
uint64 __udivdi3(uint64 a,uint64 b);//无符号64位整数除法
uint64 __umoddi3(uint64 a,uint64 b);//无符号64位整数取余

#define SegmentSelector_DPL0 0x00
#define SegmentSelector_DPL1 0x01
#define SegmentSelector_DPL2 0x02
#define SegmentSelector_DPL3 0x03
#define SegmentSelector_GDT 0x00
#define SegmentSelector_LDT 0x04

typedef struct SegmentSelector{
	uint ID;
	uint Attr;
}SegmentSelector;

uint SetSegmentSelector(SegmentSelector s);
SegmentSelector GetSegmentSelector(uint Value);
void Sys_Log(uchar *str);

#endif