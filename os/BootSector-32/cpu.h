#ifndef __CPU_H__
#define __CPU_H__
	
typedef struct CPU_CPUMSG{
	uint64 Freq;//��λHz
	uint64 FreqK;//��λKHz
	uint64 FreqM;//��λMhz
	uint64 FreqG;//��λGHz
}CPU_CPUMSG;

void CPU_Init();//��ʼ��CPU
CPU_CPUMSG CPU_GetMsg();//��ȡCPU��Ϣ

#endif