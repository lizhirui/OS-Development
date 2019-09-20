#include "common.h"
#include "PCI.h"

uchar PCI_databuf[200];

uint PCI_GetAddress(PCI_DEVICE Dev)
{
	return (((uint)(Dev.Function & 0x07)) << 8) | (((uint)(Dev.Device & 0x1F)) << 11) | (((uint)Dev.Bus) << 16) | 0x80000000;
}

void PCI_WriteData32(PCI_DEVICE Dev,uchar Offset,uint Data)
{
	uint t1,t2;
	uint addr;
	
	addr = PCI_GetAddress(Dev);
	
	if((Offset & 0x03) == 0)
	{
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)Offset));
		IO_Out32(PCI_CONFIG_DATA,Data);
		t2 = IO_In32(PCI_CONFIG_DATA);
		//Convert_DWordToChar(t2,PCI_databuf);
		//Video_DispStr(5,0,PCI_databuf,VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
	}
	else
	{
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)(Offset & 0xFC)));
		t1 = IO_In32(PCI_CONFIG_DATA);
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)((Offset & 0xFC) + 4)));
		t2 = IO_In32(PCI_CONFIG_DATA);
		//Convert_DWordToChar(t1,PCI_databuf);
		//Video_DispStr(3,0,PCI_databuf,VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
		//Convert_DWordToChar(t2,PCI_databuf);
		//Video_DispStr(3,9,PCI_databuf,VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
		t1 = (t1 & (~(0xFFFFFFFF << ((Offset & 0x03) << 3)))) | (Data << ((Offset & 0x03) << 3));
		t2 = (t2 & (0xFFFFFFFF << (32 - ((Offset & 0x03) << 3)))) | (Data >> (32 - ((Offset & 0x03) << 3)));
		//Convert_DWordToChar(t1,PCI_databuf);
		//Video_DispStr(4,0,PCI_databuf,VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
		//Convert_DWordToChar(t2,PCI_databuf);
		//Video_DispStr(4,9,PCI_databuf,VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)(Offset & 0xFC)));
		IO_Out32(PCI_CONFIG_DATA,t1);
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)((Offset & 0xFC) + 4)));
		IO_Out32(PCI_CONFIG_DATA,t2);
		
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)(Offset & 0xFC)));
		t1 = IO_In32(PCI_CONFIG_DATA);
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)((Offset & 0xFC) + 4)));
		t2 = IO_In32(PCI_CONFIG_DATA);
		//Convert_DWordToChar(t1,PCI_databuf);
		//Video_DispStr(5,0,PCI_databuf,VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
		//Convert_DWordToChar(t2,PCI_databuf);
		//Video_DispStr(5,9,PCI_databuf,VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
	}
}

uint PCI_ReadData32(PCI_DEVICE Dev,uchar Offset)
{
	uint t,r;
	uint addr;
	
	addr = PCI_GetAddress(Dev);
	
	if((Offset & 0x03) == 0)//若偏移能被4整除
	{
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)Offset));
		return IO_In32(PCI_CONFIG_DATA);
	}
	else
	{
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)(Offset & 0xFC)));
		t = IO_In32(PCI_CONFIG_DATA);
		r = t >> ((Offset & 0x03) << 3);
		IO_Out32(PCI_CONFIG_ADDRESS,addr | ((uint)((Offset & 0xFC) + 4)));
		t = IO_In32(PCI_CONFIG_DATA);
		r |= t << (32 - ((Offset & 0x03) << 3));
		return r;
	}
	
}

void PCI_WriteData16(PCI_DEVICE Dev,uchar Offset,uint Data)
{
	uint x;
	
	Data &= 0xFFFF;
	x = PCI_ReadData32(Dev,Offset);
	x &= 0xFFFF0000;
	x |= Data;
	PCI_WriteData32(Dev,Offset,x);
}

uint PCI_ReadData16(PCI_DEVICE Dev,uchar Offset)
{
	uint r;
	
	r = PCI_ReadData32(Dev,Offset);
	return r & 0xFFFF;
}

void PCI_WriteData8(PCI_DEVICE Dev,uchar Offset,uchar Data)
{
	uint x;
	
	x = PCI_ReadData32(Dev,Offset);
	x &= 0xFFFFFF00;
	x |= (uint)Data;
	PCI_WriteData32(Dev,Offset,x);
}

uchar PCI_ReadData8(PCI_DEVICE Dev,uchar Offset)
{
	uint r;
	
	r = PCI_ReadData32(Dev,Offset);
	return (uchar)(r & 0xFF);
}
