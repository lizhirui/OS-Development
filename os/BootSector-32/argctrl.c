#include "common.h"
#include "argctrl.h"

uint ArgCtrl_GetVarArgTableStackAddress(uint arg1)//��ȡ�ɱ������ջ���ַ��arg1���һ����֪������arg1ֻ����ָ��������ڽ���������
{
	return arg1 + 4;
}

uint ArgCtrl_GetVarArg_uint(uint ESP,uint n)//��ȡ�ɱ������ESPΪ��������ʼESP��nΪ�ڼ�����������0��ʼ
{
	ESP += n << 2;
	return GetStackValue(ESP);
}

uchar ArgCtrl_GetVarArg_uchar(uint ESP,uint n)//��ȡ�ɱ������ESPΪ��������ʼESP��nΪ�ڼ�����������0��ʼ
{
	ESP += n << 2;
	return (uchar)(GetStackValue(ESP) & 0xFF);
}

uchar * ArgCtrl_GetVarArg_ucharptr(uint ESP,uint n)//��ȡ�ɱ������ESPΪ��������ʼESP��nΪ�ڼ�����������0��ʼ
{
	ESP += n << 2;
	return (uchar *)(GetStackValue(ESP));
}