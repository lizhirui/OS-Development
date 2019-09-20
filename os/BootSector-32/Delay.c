#include "common.h"
#include "Delay.h"
#include "cpu.h"
#include "video.h"

void Delayns(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.FreqG * t;

	while((GetRDTSC() - x) < y);
}

void Delayus(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.FreqM * t;

	while((GetRDTSC() - x) < y);
}

void Delayms(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.FreqK * t;

	while((GetRDTSC() - x) < y);
}

void Delays(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y,z;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.Freq * (uint64)t;
	Video_printf((uchar *)"delays:%ul\n",y);
	Video_printf((uchar *)"RDTSCStart:%ul\n",x);
	z = GetRDTSC();

	while((z - x) < y)
	{
		z = GetRDTSC();
	}
	Video_printf((uchar *)"RDTSCEnd:%ul\n",GetRDTSC());
	Video_printf((uchar *)"x,y,z:%ul,%ul,%ul\n",x,y,z);

	if((z - x) < y)
	{
		Video_printf((uchar *)"mmmm\n");
	}
	else
	{
		Video_printf((uchar *)"nnnn\n");
	}
	
}

void Delaym(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.Freq * t * 60;

	while((GetRDTSC() - x) < y);
}

void Delayh(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.Freq * t * 3600;

	while((GetRDTSC() - x) < y);
}

void Delayd(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.Freq * t * 3600 * 24;

	while((GetRDTSC() - x) < y);
}

void Delayy(uint t)
{
	CPU_CPUMSG cpu;
	uint64 x,y;

	cpu = CPU_GetMsg();
	x = GetRDTSC();
	y = cpu.Freq * t * 3600 * 24 * 365;

	while((GetRDTSC() - x) < y);
}