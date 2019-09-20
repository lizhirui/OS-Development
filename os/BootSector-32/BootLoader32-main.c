#include "common.h"
#include "string.h"
#include "argctrl.h"
#include "Convert.h"
#include "cpu.h"
#include "Delay.h"
#include "video.h"
#include "gdt.h"
#include "idt.h"
#include "Interrupt.h"
#include "PCI.h"
#include "ICH7Driver/ICH7_USB.h"
#include "ICH7Driver/ICH7_8259.h"

uchar BootID[16];
uchar databuf[200];

void CStart()
{
	uchar x,y;
	uint i;
	uint j;
	CPU_CPUMSG cpu;
	SegmentSelector segsel;
	IDT_SegmentDescriptor idts;
	GetBootID(BootID);
	Video_Init();
	Video_SetCurFontStyle(VIDEO_BACK_BLACK | VIDEO_FORE_WHITE);
	Video_printf((uchar *)"BootLoader32 Ver 1.0 By LiZhirui 20160320\n");
	Video_printf((uchar *)"8259_Init...\n");
	ICH7_8259_Init();
	Video_printf((uchar *)"Interrupt_Init...\n");
	Interrupt_Init();
	SetI();
	Video_printf((uchar *)"CPU_Init...\n");
	CPU_Init();
	//ClrI();
	cpu = CPU_GetMsg();
	Video_printf((uchar *)"CPU Freq:%l FreqK:%l FreqM:%l FreqG:%l \n",cpu.Freq,cpu.FreqK,cpu.FreqM,cpu.FreqG);
	WritePhysicsMemory32(0xFEE00030,0xAAAABBBB);
	Video_printf((uchar *)"APIC Version:%x\n",ReadPhysicsMemory32(0xFEE00030));
	//while(1);
	//i /= 0;

	for(i = 0;i < 2;i++)
	{
		Video_printf((uchar *)"\n%u",i);
		Delays(1);
	}
	while(1);
	x = 0;
	ICH7_USB_EHCI_Init();
	while(1);
}