#include "common.h"
#include "argctrl.h"

uint ArgCtrl_GetVarArgTableStackAddress(uint arg1)//获取可变参数堆栈表地址，arg1最后一个已知参数，arg1只能是指针或者是内建数据类型
{
	return arg1 + 4;
}

uint ArgCtrl_GetVarArg_uint(uint ESP,uint n)//获取可变参数，ESP为参数表起始ESP，n为第几个参数，从0开始
{
	ESP += n << 2;
	return GetStackValue(ESP);
}

uchar ArgCtrl_GetVarArg_uchar(uint ESP,uint n)//获取可变参数，ESP为参数表起始ESP，n为第几个参数，从0开始
{
	ESP += n << 2;
	return (uchar)(GetStackValue(ESP) & 0xFF);
}

uchar * ArgCtrl_GetVarArg_ucharptr(uint ESP,uint n)//获取可变参数，ESP为参数表起始ESP，n为第几个参数，从0开始
{
	ESP += n << 2;
	return (uchar *)(GetStackValue(ESP));
}