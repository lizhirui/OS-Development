[BITS 16]
	BOOT_Addr EQU 7C00H
	BootLoader32_Segment_Addr EQU 3000H

	Partition_Msg_Addr EQU BOOT_Addr + 01BEH
	Partition_H EQU Partition_Msg_Addr + 0001H
	Partition_S EQU Partition_Msg_Addr + 0002H
	Partition_C EQU Partition_Msg_Addr + 0003H
	Partition_Type EQU Partition_Msg_Addr + 0004H
	Line_Num EQU 25
	Column_Num EQU 80
	Next_Line EQU 0AH
	Str_End EQU 00H
	RBR EQU 00H
	THR EQU 00H
	DLL EQU 00H
	IER EQU 01H
	DLM EQU 01H
	IIR EQU 02H
	FCR EQU 02H
	LCR EQU 03H
	MCR EQU 04H
	LSR EQU 05H
	MSR EQU 06H
	SCR EQU 07H
	COM1 EQU 03F8H
	COM1_BAUD EQU 115200
	COM1_DLL EQU (1843200/16/COM1_BAUD)&0xFF
	COM1_DLM EQU (1843200/16/COM1_BAUD)>>8
	Partition_Type_None EQU 00H
	Partition_Type_FAT16 EQU 06H
	Partition_Type_FAT32 EQU 0BH
	Partition_Type_EXT EQU 05H
	Partition_Type_NTFS EQU 07H
	Partition_Type_LBAEXT EQU 0FH
	
	SegmentDescriptor_Code_X EQU 1000B
	SegmentDescriptor_Code_RX EQU 1010B
	SegmentDescriptor_Code_Share_X EQU 1100B
	SegmentDescriptor_Code_Share_RX EQU 1110B
	SegmentDescriptor_Data_Up_R EQU 0000B
	SegmentDescriptor_Data_Up_RW EQU 0010B
	SegmentDescriptor_Data_Down_R EQU 0100B
	SegmentDescriptor_Data_Down_RW EQU 011B
	SegmentDescriptor_SystemSegment EQU 00000B
	SegmentDescriptor_UserSegment EQU 10000B
	SegmentDescriptor_DPL0 EQU 0000000B
	SegmentDescriptor_DPL1 EQU 0100000B
	SegmentDescriptor_DPL2 EQU 1000000B
	SegmentDescriptor_DPL3 EQU 1100000B
	SegmentDescriptor_Enable EQU 10000000B
	SegmentDescriptor_Disabled EQU 00000000B

	SegmentDescriptor_16Bit EQU 000000000000000B
	SegmentDescriptor_32Bit EQU 100000000000000B
	SegmentDescriptor_Byte EQU 0000000000000000B
	SegmentDescriptor_4KByte EQU 1000000000000000B
	SegmentDescriptor_DataRW EQU 0092H

	GDT_ADDR EQU 2000H
	
	%macro SegmentDescriptor 3;段描述符
		;用法：SegmentDescriptor Base,Limit,Attr
		;Base:32bit
		;Limit:20bit
		;Attr:16bit（高字节的低四位总是0）
		DW %2 & 0FFFFH;段界限1（2字节）
		DW %1 & 0FFFFH;段基址1（2字节）
		DB (%1 >> 16) & 0FFH;段基址2（1字节）
		DW ((%2 >> 8) & 0F00H) | (%3 & 0F0FFH);属性1+段界限2+属性2（2字节）
		DB (%1 >> 24) & 0FFH;段基址3（1字节）
	%endmacro;共8字节
	
	ORG 00000000H
	DB "BootLoaderCheckString";引导程序标识符
	;段寄存器初始化
	MOV AX,CS
	MOV DS,AX
	MOV ES,AX
	MOV SS,AX
	MOV SP,0000H
	MOV AX,0000H
	MOV FS,AX
	CALL ReadBootSector32;读入BootSector-32
	CALL DispStr_Init;初始化字符串显示
	CALL COM1_Init;初始化COM1
	MOV BP,BootLoaderVer;显示引导程序版本信息
	CALL DispStr
	CALL DispStr_NextLine
	CALL DispInterfaceAddr
	CALL DispDeviceTableMsg
	MOV AX,3000H
	MOV FS,AX
	MOV SI,3BB0H
	MOV DX,64
	CALL DispMem
	CALL DispStr_NextLine
	CALL DispPartition1Msg
	CALL COM1_Close
	;加载保护模式
	;关中断
	CLI
	;开启A20地址线
	IN AL,92H
	OR AL,02H
	OUT 92H,AL
Main_Stage1:
	;复制GDT到内存0x00020000处
	MOV AX,GDT_ADDR
	MOV ES,AX
	MOV DI,0000H
	MOV SI,GDT
	CLD
	MOV CX,GDT_LEN
	REP MOVSB
	;加载GDT
	LGDT [GDTPtr]
	;加载IDT
	LIDT [IDTPtr]
	;开启保护模式
	MOV EAX,CR0
	MOV EAX,1
	MOV CR0,EAX
	;跳转到32位代码段
	JMP $
	JMP DWORD Selector_Code32:0

Count: DW 0
ReadBootSector32:
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH ES
	MOV AX,BootLoader32_Segment_Addr
	MOV ES,AX
	MOV BX,0000H
	MOV AH,02H;读取BootLoader32
	MOV AL,1
	MOV DL,80H
	MOV WORD [LBAToCHS_Arr],21
	MOV WORD [Count],0
ReadBootSector32_Stage1:
	MOV AH,02H;读取BootLoader32
	MOV AL,1
	MOV DL,80H
	CALL LBAToCHS
	CALL CHSToReg
	INT 13H
	CALL AddressAdd
	INC WORD [LBAToCHS_Arr]
	INC WORD [Count]
	CMP WORD [Count],768
	JNZ ReadBootSector32_Stage1
	POP ES
	POP DX
	POP CX
	POP BX
	POP AX
	RET

LBAToCHS_Arr: DW 0
LBAToCHS_C: DW 0
LBAToCHS_H: DW 0
LBAToCHS_S: DW 0
LBAToCHS:
	;LBA放入LBAToCHS_Arr中
	PUSH AX
	PUSH BX
	PUSH DX
	MOV AX,[LBAToCHS_Arr];C=LBA DIV 16065
	MOV DX,0
	MOV BX,16065
	DIV BX
	MOV [LBAToCHS_C],AX
	MOV AX,[LBAToCHS_Arr];H=(LBA DIV 63) MOD 255
	MOV DX,0
	MOV BX,63
	DIV BX
	MOV DX,0
	MOV BX,255
	DIV BX
	MOV [LBAToCHS_H],DX
	MOV AX,[LBAToCHS_Arr];S=LBA MOD 63 + 1
	MOV DX,0
	MOV BX,63
	DIV BX
	INC DX
	MOV [LBAToCHS_S],DX
	POP DX
	POP BX
	POP AX
	RET

CHSToReg:
	;CHS装入寄存器，参数在LBAToCHS的各个内存空间内
	MOV DH,[LBAToCHS_H]
	MOV CH,[LBAToCHS_C]
	MOV CL,[LBAToCHS_C+1]
	SHL CL,6
	OR CL,[LBAToCHS_S]
	RET

AddressAdd_Arr: DW 512
AddressAdd:
	;增加ES:BX地址,增量放于AddressAdd_Arr中
	PUSH CX
	MOV CX,[AddressAdd_Arr]
AddressAdd_Stage1:
	CALL AddressInc
	LOOP AddressAdd_Stage1
	POP CX
	RET

AddressInc:
	;增加ES:BX地址
	CMP BX,0FFFFH
	JNZ AddressInc_Stage1
	MOV BX,0
	PUSH AX
	MOV AX,ES
	ADD AX,1000H
	MOV ES,AX
	POP AX
	JMP AddressInc_Exit
AddressInc_Stage1:
	INC BX
AddressInc_Exit:
	RET

DispPartition1Msg:
	;显示分区1信息
	PUSH AX
	PUSH BX
	PUSH BP
	MOV BYTE [Current_FontStyle],0CH
	MOV BP,Msg_Partition1
	CALL DispStr
	CALL DispStr_NextLine
	MOV BYTE [Current_FontStyle],0FH
	MOV BP,Msg_Partition1_Type
	CALL DispStr
	MOV BL,[FS:Partition_Type]
	CMP BL,Partition_Type_None
	JZ DispDeviceTableMsg_None
	CMP BL,Partition_Type_FAT16
	JZ DispDeviceTableMsg_FAT16
	CMP BL,Partition_Type_FAT32
	JZ DispDeviceTableMsg_FAT32
	CMP BL,Partition_Type_EXT
	JZ DispDeviceTableMsg_EXT
	CMP BL,Partition_Type_NTFS
	JZ DispDeviceTableMsg_NTFS
	CMP BL,Partition_Type_LBAEXT
	JZ DispDeviceTableMsg_LBAEXT
	JMP DispDeviceTableMsg_Unknown

DispDeviceTableMsg_None:
	MOV BP,Msg_Type_None
	JMP DispPartition1Msg_Exit

DispDeviceTableMsg_FAT16:
	MOV BP,Msg_Type_FAT16
	JMP DispPartition1Msg_Exit

DispDeviceTableMsg_FAT32:
	MOV BP,Msg_Type_FAT32
	JMP DispPartition1Msg_Exit

DispDeviceTableMsg_EXT:
	MOV BP,Msg_Type_EXT
	JMP DispPartition1Msg_Exit

DispDeviceTableMsg_NTFS:
	MOV BP,Msg_Type_NTFS
	JMP DispPartition1Msg_Exit

DispDeviceTableMsg_LBAEXT:
	MOV BP,Msg_Type_LBAEXT
	JMP DispPartition1Msg_Exit

DispDeviceTableMsg_Unknown:
	MOV BP,Msg_Type_Unknown
	JMP DispPartition1Msg_Exit
	
DispPartition1Msg_Exit:
	CALL DispStr
	CALL DispStr_NextLine
	POP BP
	POP BX
	POP AX
	RET

DispDeviceTableMsg:
	PUSH AX
	PUSH BX
	PUSH BP
	;显示设备编码表信息
	MOV AX,[FS:0410H]
	
	;输出串口数量
	MOV BL,AH
	SHR BL,1
	AND BL,07H
	MOV BP,Msg_ComNumber
	CALL DispStr
	MOV BH,00H
	PUSH AX
	MOV AX,BX
	MOV BP,DataBuf
	CALL Convert_WordToIntChar
	POP AX
	CALL DispStr
	CALL DispStr_NextLine
	
	;检测软驱
	MOV BX,AX
	AND BX,0001H
	CMP BX,0001H
	JZ DispDeviceTableMsg_Stage1;检测到软驱
	MOV BP,Msg_FloppyNotFound;软驱未检测到
	CALL DispStr
	CALL DispStr_NextLine
	JMP DispDeviceTableMsg_Stage2
	
DispDeviceTableMsg_Stage1:
	MOV BP,Msg_FloppyNumber
	CALL DispStr
	MOV BL,AL
	SHR BL,6
	AND BL,03H
	MOV BH,00H
	PUSH AX
	MOV AX,BX
	INC AX
	CALL Convert_WordToIntChar
	POP AX
	CALL DispStr
	CALL DispStr_NextLine
	
DispDeviceTableMsg_Stage2:
	;检测X87
	MOV BL,AL
	SHR BL,1
	AND BL,01H
	CMP BL,01H
	JZ DispDeviceTableMsg_Stage3;检测到X87
	MOV BP,Msg_X87NotFound;检测不到X87
	CALL DispStr
	CALL DispStr_NextLine
	JMP DispDeviceTableMsg_Stage4
	
DispDeviceTableMsg_Stage3:
	MOV BP,Msg_X87Found
	CALL DispStr
	CALL DispStr_NextLine
	
DispDeviceTableMsg_Stage4:
	MOV BP,Msg_HardNumber;显示硬盘数量
	CALL DispStr
	MOV BP,DataBuf
	MOV AL,[FS:0475H]
	MOV AH,00H
	CALL Convert_WordToIntChar
	CALL DispStr
	CALL DispStr_NextLine
	POP BP
	POP BX
	POP AX
	RET

DispInterfaceAddr:
	;显示接口地址
	PUSH AX
	PUSH BP
	MOV BP,Msg_Addr;显示接口地址
	CALL DispStr
	CALL DispStr_NextLine
	;串口
	MOV BYTE [Msg_Com + 3],'1'
	MOV BP,Msg_Com
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:0400H]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	
	MOV BYTE [Msg_Com + 3],'2'
	MOV BP,Msg_Com
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:0402H]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	
	MOV BYTE [Msg_Com + 3],'3'
	MOV BP,Msg_Com
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:0404H]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	
	MOV BYTE [Msg_Com + 3],'4'
	MOV BP,Msg_Com
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:0406H]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	
	;并口
	MOV BYTE [Msg_Lpt + 3],'1'
	MOV BP,Msg_Lpt
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:0408H]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	
	MOV BYTE [Msg_Lpt + 3],'2'
	MOV BP,Msg_Lpt
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:040AH]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	
	MOV BYTE [Msg_Lpt + 3],'3'
	MOV BP,Msg_Lpt
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:040CH]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	
	MOV BYTE [Msg_Lpt + 3],'4'
	MOV BP,Msg_Lpt
	CALL DispStr
	MOV BP,Msg_Hex
	CALL DispStr
	MOV AX,[FS:040EH]
	MOV BP,DataBuf
	CALL Convert_WordToChar
	CALL DispStr
	CALL DispStr_NextLine
	POP BP
	POP AX
	RET
	
COM1_Init:
	;COM1初始化
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV DX,[FS:0400H]
	ADD DX,IER
	MOV AL,00H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,LCR
	MOV AL,80H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,DLL
	MOV AL,COM1_DLL
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,DLM
	MOV AL,COM1_DLM
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,FCR
	MOV AL,07H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,MCR
	MOV AL,00H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,LCR
	MOV AL,03H
	OUT DX,AL
	POP DX
	POP CX
	POP BX
	POP AX
	RET
	
COM1_Close:
	;COM1关闭
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV DX,[FS:0400H]
	ADD DX,IER
	MOV AL,00H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,LCR
	MOV AL,80H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,DLL
	MOV AL,00H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,DLM
	MOV AL,00H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,FCR
	MOV AL,00H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,MCR
	MOV AL,00H
	OUT DX,AL
	MOV DX,[FS:0400H]
	ADD DX,LCR
	MOV AL,00H
	OUT DX,AL
	POP DX
	POP CX
	POP BX
	POP AX
	RET
	
COM1_SendChar:
	;COM1发送一字节 待发送字节放置于AL中
	PUSH AX
	PUSH BX
	PUSH DX
	PUSH FS
	MOV BX,0000H
	MOV FS,BX
	
COM1_SendChar_Stage1:
	MOV BX,AX
	MOV DX,[FS:0400H]
	ADD DX,LSR
	IN AL,DX
	SHR AL,5
	AND AL,01H
	CMP AL,01H
	JNZ COM1_SendChar_Stage1
	MOV DX,[FS:0400H]
	ADD DX,THR
	MOV AL,BL
	OUT DX,AL
	
COM1_SendChar_Stage2:
	MOV DX,[FS:0400H]
	ADD DX,LSR
	IN AL,DX
	SHR AL,5
	AND AL,01H
	CMP AL,01H
	JNZ COM1_SendChar_Stage2
	POP FS
	POP DX
	POP BX
	POP AX
	RET
	
COM1_SendStr:
	;COM1发送一个字符串 DS:BP指向字符串
	PUSH AX
	PUSH BP
	
COM1_SendStr_Stage1:
	CMP BYTE [BP],00H
	JZ COM1_SendStr_Exit
	CMP BYTE [BP],0AH
	JZ COM1_SendStr_Stage2
	MOV AL,[BP]
	CALL COM1_SendChar
	INC BP
	JMP COM1_SendStr_Stage1
	
COM1_SendStr_Stage2:
	CALL COM1_NextLine
	INC BP
	JMP COM1_SendStr_Stage1
	
COM1_SendStr_Exit:
	POP BP
	POP AX
	RET
	
COM1_NextLine:
	;COM1发送一个换行符
	PUSH AX
	MOV AL,0AH
	CALL COM1_SendChar
	POP AX
	RET
	
DispMem:
	;显示内存，FS:SI为目标内存起始地址，DX为显示字节数
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BP
	PUSH SI
	MOV BX,0
	MOV CX,0
	MOV BYTE [Current_FontStyle],0CH
	MOV BP,Msg_DataBaseAddress
	CALL DispStr
	MOV AX,FS
	MOV BX,SI
	MOV BP,DataBuf
	CALL Convert_AddressToChar
	CALL DispStr 
	CALL DispStr_NextLine
	;显示表头
	MOV BP,Msg_DispMemTableTop
	CALL DispStr
	CALL DispStr_NextLine
	;显示地址
	MOV BP,DataBuf
	MOV AX,0000H
	MOV BX,0
	CALL Convert_AddressToChar
	CALL DispStr 
	MOV BP,Msg_Blank
	CALL DispStr
	MOV BYTE [Current_FontStyle],0FH
DispMem_Stage1:
	CMP BX,DX
	JZ DispMem_Stage3
	CMP CX,16
	JNZ DispMem_Stage2
	CALL DispStr_NextLine
	MOV CX,0
	;显示地址
	MOV BYTE [Current_FontStyle],0CH
	MOV BP,DataBuf
	MOV AX,0000H
	CALL Convert_AddressToChar
	CALL DispStr 
	MOV BP,Msg_Blank
	CALL DispStr
	MOV BYTE [Current_FontStyle],0FH
	
DispMem_Stage2:
	MOV BP,DataBuf
	MOV AL,[FS:SI]
	CALL Convert_ByteToChar
	MOV BYTE [BP+2],00H
	CALL DispStr
	MOV BYTE [BP],' '
	MOV BYTE [BP+1],00H
	CALL DispStr
	INC SI
	INC CX
	INC BX
	JMP DispMem_Stage1
	
DispMem_Stage3:
	CMP CX,0
	JZ DispMem_Stage4
	CALL DispStr_NextLine
	
DispMem_Stage4:
	POP SI
	POP BP
	POP DX
	POP CX
	POP BX
	POP AX
	RET
	
Convert_WordToIntChar:
	;字转十进制数，AX为待转换字，DS:BP为目标内存地址，DX为文本长度，目标内存至少要有2字节空间，最多要有6字节空间，结尾自动补0
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH BP
	;计算十进制数位数，为计算内存地址做准备
	PUSH AX
	MOV BX,0 ;默认位数
	
Convert_WordToIntChar_Stage1:
	CMP AX,0
	JZ Convert_WordToIntChar_Stage2
	JMP Convert_WordToIntChar_Stage3
Convert_WordToIntChar_Stage2:
	MOV BX,1
	MOV BYTE [BP],'0'
	INC BP
	POP AX
	PUSH BX
	JMP Convert_WordToIntChar_Stage4
	
Convert_WordToIntChar_Stage3:
	CMP AX,0
	JZ Convert_WordToIntChar_Stage5
	INC BX
	MOV CX,10
	MOV DX,0
	DIV CX
	MOV [BP],DL
	ADD BYTE [BP],'0'
	INC BP
	JMP Convert_WordToIntChar_Stage3
	
Convert_WordToIntChar_Stage4:
	MOV BYTE [BP],00H
	JMP Convert_WordToIntChar_Exit
	
Convert_WordToIntChar_Stage5:	
	POP AX
	PUSH BX
	MOV BYTE [BP],00H
	DEC BP
	
Convert_WordToIntChar_Stage6:
	CMP AX,0
	JZ Convert_WordToIntChar_Exit
	MOV CX,10
	MOV DX,0
	DIV CX
	MOV [BP],DL
	ADD BYTE [BP],'0'
	DEC BP
	JMP Convert_WordToIntChar_Stage6
	
Convert_WordToIntChar_Exit:
	POP DX
	POP BP
	POP CX
	POP BX
	POP AX
	RET
	
Convert_4BitToChar:
	;半字节转字符，AL低4位为待转换半字节，DS:BP为目标内存地址，目标内存至少要有2字节空间，结尾自动补0
	PUSH AX
	AND AL,0x0F
	CMP AL,0x0A
	JB Convert_4BitToChar_Number
	MOV [BP],AL
	ADD BYTE [BP],'A'-0x0A
	JMP Convert_4BitToChar_Exit
	
Convert_4BitToChar_Number:
	MOV [BP],AL
	ADD BYTE [BP],'0'
	
Convert_4BitToChar_Exit:
	MOV BYTE [BP+1],00H
	POP AX
	RET

Convert_ByteToChar:
	;字节转字符，AL为待转换字节，DS:BP为目标内存地址，目标内存至少要有3字节空间，结尾自动补0
	PUSH AX
	PUSH BX
	MOV BX,AX
	MOV BYTE [BP+2],00H
	SHR AL,4
	CALL Convert_4BitToChar
	INC BP
	MOV AX,BX
	CALL Convert_4BitToChar
	DEC BP
	POP BX
	POP AX
	RET

Convert_WordToChar:
	;字转字符，AX为待转换字，DS:BP为目标内存地址，目标内存至少要有5字节空间，结尾自动补0
	PUSH AX
	PUSH BX
	MOV BX,AX
	MOV BYTE [BP+4],00H
	MOV AL,AH
	CALL Convert_ByteToChar
	MOV AX,BX
	ADD BP,2
	CALL Convert_ByteToChar
	SUB BP,2
	POP BX
	POP AX
	RET
	
Convert_AddressToChar:
	;地址转字符，AX为段地址，BX为段偏移，DS:BP为目标内存地址，目标内存至少要有10字节空间，结尾自动补0
	PUSH AX
	PUSH BX
	CALL Convert_WordToChar
	MOV BYTE [BP+4],':'
	ADD BP,5
	MOV AX,BX
	CALL Convert_WordToChar
	SUB BP,5
	POP BX
	POP AX
	RET

DispStr_Init:
	;初始化显存地址
	PUSH AX
	MOV AX,0B800H
	MOV GS,AX
	POP AX
	CALL CLS
	MOV BYTE [Current_Line],0
	MOV BYTE [Current_Column],0
	MOV BYTE [Current_FontStyle],0FH
	CALL DispStr_SetCursor
	RET

CLS:	
	PUSH AX
	PUSH BP
	PUSH DX
	PUSH DS
	MOV AX,0B000H
	MOV DS,AX
	MOV BP,0FFFFH
	
CLS_LOOP:
	MOV BYTE [DS:BP-1],20H
	MOV BYTE [DS:BP],0FH
	SUB BP,02H
	CMP BP,799H
	JA CLS_LOOP
	POP DS
	MOV AH,02H
	MOV BH,00H
	MOV DH,00H
	MOV DL,00H
	INT 10H
	POP DX
	POP BP
	POP AX
	RET

DispStr_SetCursor:
	PUSH AX
	PUSH BX
	PUSH DX
	MOV AH,02H
	MOV BH,00H
	MOV DH,[Current_Line]
	MOV DL,[Current_Column]
	INT 10H
	POP DX
	POP BX
	POP AX
	RET

DispStr_NextLine:
	CALL COM1_NextLine
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BP
	PUSH SI
	PUSH DI
	CMP BYTE [Current_Line],Line_Num-1
	JNZ DispStr_NextLine_Next
	;屏幕已满，上移一行
	MOV DI,Column_Num*2
	
DispStr_NextLine_Loop:	
	MOV AL,[GS:DI]
	MOV SI,DI
	SUB SI,Column_Num*2
	MOV [GS:SI],AL
	INC DI
	CMP DI,Column_Num*Line_Num*2
	JNZ DispStr_NextLine_Loop
	MOV BYTE [Current_Column],0
	;清空最后一行
	MOV DI,(Line_Num-1)*Column_Num*2
	MOV CX,Column_Num
	MOV AL,[Current_FontStyle]
	
DispStr_NextLine_Next_Clr_Line_Loop:
	MOV BYTE [GS:DI],0x20
	MOV [GS:DI+1],AL
	ADD DI,2
	LOOP DispStr_NextLine_Next_Clr_Line_Loop
	JMP DispStr_NextLine_Exit
	
DispStr_NextLine_Next:
	INC BYTE [Current_Line]
	MOV BYTE [Current_Column],0
	
DispStr_NextLine_Exit:	
	POP DI
	POP SI
	POP BP
	POP DX
	POP CX
	POP BX
	POP AX
	CALL DispStr_SetCursor
	RET

DispStr:
	;输入：DS:BP指向要显示的字符串
	CALL COM1_SendStr
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BP
	PUSH SI
	PUSH DI
	;若当前行已满，且第一个字符不为0AH则创建新行
	CMP BYTE [BP],Str_End
	JZ DispStr_Exit
	CMP BYTE [Current_Column],Column_Num
	JNZ DispStr_Stage1
	CMP BYTE [BP],Next_Line
	JZ DispStr_Stage1
	CALL DispStr_NextLine
	
DispStr_Stage1:
	;将字符串复制到内存，遇到0AH则换行，若当前行已满且下一个字符不为0AH且不为00H则换行，如果遇到00H则结束
	CMP BYTE [BP],Next_Line
	JNZ DispStr_Stage2
	CALL DispStr_NextLine
	JMP DispStr_Stage3
	
DispStr_Stage2:
	;Offset=Current_Line*Column_Num+Current_Column
	MOV AL,[Current_Line]
	MOV AH,00H
	MOV BX,Column_Num
	MUL BX
	MOV CL,[Current_Column]
	MOV CH,00H
	ADD AX,CX
	MOV BX,2
	MUL BX
	MOV DI,AX
	MOV AL,[BP]
	MOV [GS:DI],AL
	MOV BL,[Current_FontStyle]
	MOV [GS:DI+1],BL
	INC BYTE [Current_Column]
	
DispStr_Stage3:
	INC BP
	CMP BYTE [BP],Str_End
	JZ DispStr_Exit
	CMP BYTE [Current_Column],Column_Num
	JNZ DispStr_Stage1
	CMP BYTE [BP],Next_Line
	JZ DispStr_Stage1
	CALL DispStr_NextLine
	JMP DispStr_Stage1
	
DispStr_Exit:
	POP DI
	POP SI
	POP BP
	POP DX
	POP CX
	POP BX
	POP AX
	CALL DispStr_SetCursor
	RET

BootLoaderVer DB "BootLoader Ver 1.0 By LiZhirui 20160310",00H
Msg_Hex DB "0x",00H
Msg_Addr DB "Address Message:",00H
Msg_Com DB "COMx:",00H
Msg_Lpt DB "LPTx:",00H
Msg_X87Found DB "X87 CPU Found",00H
Msg_X87NotFound DB "X87 CPU Not Found",00H
Msg_FloppyNotFound DB "Floppy Not Found",00H
Msg_FloppyNumber DB "FloppyNumber:",00H,
Msg_ComNumber DB "ComNumber:",00H
Msg_HardNumber DB "HardNumber:",00H
Msg_NotSupportProtectMode DB "Your CPU don't support the X86 Protect Mode!",00H
Msg_DataBaseAddress DB "                DataBaseAddress --------- ",00H
Msg_DispMemTableTop DB "          00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F",00H
Msg_Blank DB " ",00H
Msg_Partition1 DB "Partition1Message:",00H
Msg_Partition1_Type DB "FileSystem:",00H
Msg_Type_None DB "None",00H
Msg_Type_FAT16 DB "FAT16",00H
Msg_Type_FAT32 DB "FAT32",00H
Msg_Type_EXT DB "EXT",00H
Msg_Type_NTFS DB "NTFS",00H
Msg_Type_LBAEXT DB "LBAEXT",00H
Msg_Type_Unknown DB "Unknown",00H
Current_Line DB 00H
Current_Column DB 00H
Current_FontStyle DB 00H
DataBuf TIMES 12 DB 00H
;GDT定义
GDT:SegmentDescriptor 0,0,0;不使用
GDT_CODE32:SegmentDescriptor 00030000H,05FFFFH,SegmentDescriptor_Code_RX | SegmentDescriptor_32Bit | SegmentDescriptor_DPL0 | SegmentDescriptor_UserSegment | SegmentDescriptor_Byte | SegmentDescriptor_Enable
GDT_DATA:SegmentDescriptor 00030000H,05FFFFH,SegmentDescriptor_Data_Up_RW | SegmentDescriptor_32Bit | SegmentDescriptor_DPL0 | SegmentDescriptor_UserSegment | SegmentDescriptor_Byte | SegmentDescriptor_Enable
GDT_STACK:SegmentDescriptor 00030000H,05FFFFH,SegmentDescriptor_Data_Up_RW | SegmentDescriptor_32Bit | SegmentDescriptor_DPL0 | SegmentDescriptor_UserSegment | SegmentDescriptor_Byte | SegmentDescriptor_Enable
GDT_VIDEO:SegmentDescriptor 0B8000H,0FFFFH,SegmentDescriptor_Data_Up_RW | SegmentDescriptor_32Bit | SegmentDescriptor_DPL0 | SegmentDescriptor_UserSegment | SegmentDescriptor_Byte | SegmentDescriptor_Enable
GDT_PARTITIONMSG:SegmentDescriptor 7DBEH,3FH,SegmentDescriptor_Data_Up_R | SegmentDescriptor_32Bit | SegmentDescriptor_DPL0 | SegmentDescriptor_UserSegment | SegmentDescriptor_Byte | SegmentDescriptor_Enable
GDT_BOOTSECTOR:SegmentDescriptor 7C00H,1FFH,SegmentDescriptor_Data_Up_RW | SegmentDescriptor_32Bit | SegmentDescriptor_DPL0 | SegmentDescriptor_UserSegment | SegmentDescriptor_Byte | SegmentDescriptor_Enable
GDT_PHYSICSMEMORY:SegmentDescriptor 0000H,0FFFFFH,SegmentDescriptor_Data_Up_RW | SegmentDescriptor_32Bit | SegmentDescriptor_DPL0 | SegmentDescriptor_UserSegment | SegmentDescriptor_4KByte | SegmentDescriptor_Enable
GDT_END:
GDT_LEN EQU GDT_END - GDT + 1

GDTPtr:
	DW 0xFFFF
	DD 00020000H

IDTPtr:
	DW 0xFFFF
	DD 00010000H

Selector_Code32 EQU 1 << 3
Selector_Data EQU 2 << 3
Selector_Stack EQU 3 << 3
Selector_Video EQU 4 << 3
Selector_ParititionMsg EQU 5 << 3
Selector_BootSector EQU 6 << 3
Selector_PhysicsMemory EQU 7 << 3