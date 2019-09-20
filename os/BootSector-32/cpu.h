#ifndef __CPU_H__
#define __CPU_H__
	
typedef struct CPU_CPUMSG{
	uint64 Freq;//单位Hz
	uint64 FreqK;//单位KHz
	uint64 FreqM;//单位Mhz
	uint64 FreqG;//单位GHz
}CPU_CPUMSG;

void CPU_Init();//初始化CPU
CPU_CPUMSG CPU_GetMsg();//获取CPU信息

#endif