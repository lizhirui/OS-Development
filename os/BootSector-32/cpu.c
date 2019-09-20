#include "common.h"
#include "cpu.h"

CPU_CPUMSG CPU_CPUMsg;

void CPU_Init()//��ʼ��CPU
{
	uint64 cycle;

	cycle = Get1sCycle();
	cycle += Get1sCycle();
	cycle >>= 1;
	CPU_CPUMsg.Freq = cycle;
	CPU_CPUMsg.FreqK = cycle /= 1000;
	CPU_CPUMsg.FreqM = cycle /= 1000;
	CPU_CPUMsg.FreqG = cycle /= 1000;
}

CPU_CPUMSG CPU_GetMsg()//��ȡCPU��Ϣ
{
	return CPU_CPUMsg;
}