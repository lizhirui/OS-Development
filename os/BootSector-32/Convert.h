#ifndef __CONVERT_H__
#define __CONVERT_H__

uchar Convert_4BitToChar(uchar x);
void Convert_ByteToStr(uchar x,uchar *buf);
void Convert_WordToStr(uint x,uchar *buf);
void Convert_DWordToStr(uint x,uchar *buf);
void Convert_UintToStr(uint x,uchar *buf);
void Convert_IntToStr(int x,uchar *buf);
void Convert_Uint64ToStr(uint64 x,uchar *buf);
void Convert_Int64ToStr(int64 x,uchar *buf);

#endif