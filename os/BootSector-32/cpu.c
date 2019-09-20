#include "common.h"
#include "cpu.h"

CPU_CPUMSG CPU_CPUMsg;

void CPU_Init()//初始化CPU
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

CPU_CPUMSG CPU_GetMsg()//获取CPU信息
{
	return CPU_CPUMsg;
}