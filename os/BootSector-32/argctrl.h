#ifndef __ARGCTRL_H__
#define __ARGCTRL_H__

uint ArgCtrl_GetVarArgTableStackAddress(uint arg1);//��ȡ�ɱ������ջ���ַ��arg1���һ����֪������arg1ֻ����ָ��������ڽ���������
uint ArgCtrl_GetVarArg_uint(uint ESP,uint n);//��ȡ�ɱ������ESPΪ��������ʼESP��nΪ�ڼ�����������0��ʼ
uchar ArgCtrl_GetVarArg_uchar(uint ESP,uint n);//��ȡ�ɱ������ESPΪ��������ʼESP��nΪ�ڼ�����������0��ʼ
uchar * ArgCtrl_GetVarArg_ucharptr(uint ESP,uint n);//��ȡ�ɱ������ESPΪ��������ʼESP��nΪ�ڼ�����������0��ʼ

#endif