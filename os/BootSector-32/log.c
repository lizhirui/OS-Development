#include "common.h"
#include "log.h"
#include "video.h"

void Log_Output(uchar *str)
{
	Video_printf(str);
}

void Log_Error(uchar *FunctionName,uchar *ErrorStr)
{
	Log_Output((uchar *)"Error(");
	Log_Output((uchar *)FunctionName);
	Log_Output((uchar *)"):");
	Log_Output(ErrorStr);
	Log_Output((uchar *)"\n");
}