#include "../common.h"
#include "ICH7_USB.h"
#include "../PCI.h"
#include "../video.h"
#include "../Convert.h"
uchar USB_databuf[200];
PCI_DEVICE ICH7_USB_DEV_EHCI;

void ICH7_USB_EHCI_Init()
{
	uint x;
	uint MemAddr;
	
	//设置EHCI设备信息
	ICH7_USB_DEV_EHCI.Bus = 0;
	ICH7_USB_DEV_EHCI.Device = 29;
	ICH7_USB_DEV_EHCI.Function = 7;
	
	MemAddr = PCI_ReadData32(ICH7_USB_DEV_EHCI,ICH7_USB_EHCI_MEM_BASE) & 0xFFFFFC00;//读取EHCI控制器内存映射地址 FBFFBC00
	PCI_WriteData16(ICH7_USB_DEV_EHCI,ICH7_USB_EHCI_PCICMD,(1 << 10) | (1 << 2) | (1 << 1));//禁止USB中断，设置EHCI控制器为PCI主设备，开启内存映射
	WritePhysicsMemory32(ICH7_USB_EHCI_MEM_USB2_0_CMD,(0x08 << 16) | (1 << 1) | (0 << 0));//复位EHCI控制器，设置中断
	//读取EHCI控制器接口版本号
	x = ReadPhysicsMemory16(MemAddr + ICH7_USB_EHCI_MEM_HCIVERSION);
}