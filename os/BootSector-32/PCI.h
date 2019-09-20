#ifndef __PCI_H__
#define __PCI_H__

#define PCI_CONFIG_ADDRESS 0x0CF8
#define PCI_CONFIG_DATA 0x0CFC

typedef struct PCI_DEVICE{
	uchar Bus;
	uchar Device;
	uchar Function;
}PCI_DEVICE;

uint PCI_GetAddress(PCI_DEVICE Dev);//PCI获取地址
void PCI_WriteData32(PCI_DEVICE Dev,uchar Offset,uint Data);//PCI写数据
uint PCI_ReadData32(PCI_DEVICE Dev,uchar Offset);//PCI读数据
void PCI_WriteData16(PCI_DEVICE Dev,uchar Offset,uint Data);
uint PCI_ReadData16(PCI_DEVICE Dev,uchar Offset);
void PCI_WriteData8(PCI_DEVICE Dev,uchar Offset,uchar Data);
uchar PCI_ReadData8(PCI_DEVICE Dev,uchar Offset);

#endif