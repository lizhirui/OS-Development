[BITS 32]
	EXTERN CStart
	GLOBAL _start
	GLOBAL Test,SetDSSelector,SetESSelector,SetFSSelector,SetGSSelector,WritePhysicsMemory8,ReadPhysicsMemory8,WritePhysicsMemory16
	GLOBAL ReadPhysicsMemory16,WritePhysicsMemory32,ReadPhysicsMemory32,HideCursor,SetCursorLocation,SetI,ClrI,IO_In8,IO_Out8,IO_In16,Int
	GLOBAL IO_Out16,IO_In32,IO_Out32,GetESP,GetStackValue,GetRDTSC,Get1sCycle,IO_Delay,WriteSysConfigTable32,ReadSysConfigTable32
	Selector_Code32 EQU 1 << 3
	Selector_Data EQU 2 << 3
	Selector_Stack EQU 3 << 3
	Selector_Video EQU 4 << 3
	Selector_ParititionMsg EQU 5 << 3
	Selector_BootSector EQU 6 << 3
	Selector_PhysicsMemory EQU 7 << 3
	
	IO_Cursor_Addr EQU 03D4H
	IO_Cursor_Data EQU 03D5H

	IO_CMOS_Addr EQU 70H
	IO_CMOS_Data EQU 71H

	CMOS_Second EQU 00H
	
	Line_Num EQU 25
	Column_Num EQU 80

_start:
	MOV AX,Selector_Data
	MOV DS,AX
	MOV AX,Selector_Stack
	MOV SS,AX
	MOV ESP,5FFFFH
	MOV AX,Selector_PhysicsMemory
	MOV FS,AX
	MOV AX,Selector_Video
	MOV GS,AX
	MOV EDI,(80*10+0)*2
	MOV AH,0CH
	MOV AL,'P'
	MOV [GS:EDI],AX
	CALL CStart
	JMP $
Test_Mem:
	DQ 50
Test_Mem2:
	DQ 100
Test:
	FINIT
	MOV EAX,Test_Mem
	FILD QWORD [EAX]
	MOV EAX,Test_Mem2
	FILD QWORD [EAX]
	MOV EAX,Test_Mem
	FDIV ST1
	FISTP QWORD [EAX]
	JMP $

	RET

IO_In8:
	;读取IO数据，一个参数，地址
	PUSH EDX
	MOV EAX,0
	MOV DX,[ESP+8]
	IN AL,DX
	CALL IO_Delay
	POP EDX
	RET
	
IO_Out8:
	;输出IO数据，两个参数，地址和数据
	PUSH EAX
	PUSH EDX
	MOV DX,[ESP+12]
	MOV AL,[ESP+16]
	OUT DX,AL
	CALL IO_Delay
	POP EDX
	POP EAX
	RET
	
IO_In16:
	;读取IO数据，一个参数，地址
	PUSH EDX
	MOV EAX,0
	MOV DX,[ESP+8]
	IN AX,DX
	CALL IO_Delay
	POP EDX
	RET
	
IO_Out16:
	;输出IO数据，两个参数，地址和数据
	PUSH EAX
	PUSH EDX
	MOV DX,[ESP+12]
	MOV AX,[ESP+16]
	OUT DX,AX
	CALL IO_Delay
	POP EDX
	POP EAX
	RET
	
IO_In32:
	;读取IO数据，一个参数，地址
	PUSH EDX
	MOV EAX,0
	MOV DX,[ESP+8]
	IN EAX,DX
	CALL IO_Delay
	POP EDX
	RET
	
IO_Out32:
	;输出IO数据，两个参数，地址和数据
	PUSH EAX
	PUSH EDX
	MOV DX,[ESP+12]
	MOV EAX,[ESP+16]
	OUT DX,EAX
	CALL IO_Delay
	POP EDX
	POP EAX
	RET
	
SetI:
	STI
	RET

ClrI:
	CLI
	RET

Int:
	INT 80
	;JMP DWORD 0x08:0x6df
	RET

HideCursor:
	;隐藏光标
	MOV BX,0xFFFF
	MOV DX,IO_Cursor_Addr
	OUT DX,AL	
	CALL IO_Delay
	MOV AL,Bh
	MOV DX,IO_Cursor_Data
	OUT DX,AL	
	CALL IO_Delay
	MOV AL,0FH
	MOV DX,IO_Cursor_Addr
	OUT DX,AL	
	CALL IO_Delay
	MOV AL,BL
	MOV DX,IO_Cursor_Data
	OUT DX,AL
	CALL IO_Delay
	RET
	
SetCursorLocation:
	;设置光标位置
	MOV EAX,0
	MOV EBX,0
	MOV AL,[ESP+4]
	MOV BL,[ESP+8]
	CMP AL,Line_Num
	JNB SetCursorLocation_Exit
	CMP BL,Column_Num
	JNB SetCursorLocation_Exit
	MOV CL,Column_Num
	MUL CL
	ADD BX,AX
	MOV AL,0EH
	MOV DX,IO_Cursor_Addr
	OUT DX,AL	
	CALL IO_Delay
	MOV AL,Bh
	MOV DX,IO_Cursor_Data
	OUT DX,AL	
	CALL IO_Delay
	MOV AL,0FH
	MOV DX,IO_Cursor_Addr
	OUT DX,AL	
	CALL IO_Delay
	MOV AL,BL
	MOV DX,IO_Cursor_Data
	OUT DX,AL
	CALL IO_Delay
	
SetCursorLocation_Exit:

	RET
	
WritePhysicsMemory8:
	;写物理内存
	PUSH EAX
	PUSH EBX
	MOV EBX,[ESP+12]
	MOV AL,[ESP+16]
	MOV [FS:EBX],AL
	POP EBX
	POP EAX
	RET
	
ReadPhysicsMemory8:
	;读物理内存
	PUSH EBX
	MOV EAX,0
	MOV EBX,[ESP+8]
	MOV AL,[FS:EBX]
	POP EBX
	RET
	
WritePhysicsMemory16:
	;写物理内存
	PUSH EAX
	PUSH EBX
	MOV EBX,[ESP+12]
	MOV AX,[ESP+16]
	MOV [FS:EBX],AX
	POP EBX
	POP EAX
	RET
	
ReadPhysicsMemory16:
	;读物理内存
	PUSH EBX
	MOV EAX,0
	MOV EBX,[ESP+8]
	MOV AX,[FS:EBX]
	POP EBX
	RET
	
WritePhysicsMemory32:
	;写物理内存
	PUSH EAX
	PUSH EBX
	MOV EBX,[ESP+12]
	MOV EAX,[ESP+16]
	MOV [FS:EBX],EAX
	POP EBX
	POP EAX
	RET
	
ReadPhysicsMemory32:
	;读物理内存
	PUSH EBX
	MOV EBX,[ESP+8]
	MOV EAX,[FS:EBX]
	POP EBX
	RET

SetDSSelector:
	;设置DS选择子
	PUSH EAX
	MOV DWORD EAX,[ESP+8]
	MOV DS,AX
	POP EAX
	RET

SetESSelector:
	;设置ES选择子
	PUSH EAX
	MOV DWORD EAX,[ESP+8]
	MOV ES,AX
	POP EAX
	RET
	
SetFSSelector:
	;设置FS选择子
	PUSH EAX
	MOV DWORD EAX,[ESP+8]
	MOV FS,AX
	POP EAX
	RET
	
SetGSSelector:
	;设置GS选择子
	PUSH EAX
	MOV DWORD EAX,[ESP+8]
	MOV GS,AX
	POP EAX
	RET

GetESP:
	;获取ESP寄存器的值
	MOV EAX,ESP
	ADD EAX,4 ;去除CALL近调用对于ESP的影响
	RET;

GetStackValue:
	;获取堆栈值
	PUSH EBP
	MOV EBP,[ESP+8]
	MOV EAX,[SS:EBP]
	POP EBP
	RET

GetRDTSC:
	;读取CPU内部计时器
	;MFENCE
	PUSH EBX
	PUSH ECX
	CPUID
	RDTSC
	POP ECX
	POP EBX
	RET

IO_Delay:
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	RET

Get1sCycle:
	;读取CPU1s的计时数
	MOV DWORD [Sys_Config_Table_ClockCnt],0
	MOV EBX,Internal_Timer_Period
	RDTSC;获取起始时间
	PUSH EDX
	PUSH EAX
Get1sCycle_Stage1:
	CMP EBX,[Sys_Config_Table_ClockCnt]
	JNZ Get1sCycle_Stage1;等待1s
	RDTSC
	SUB EAX,[ESP];64Bit减法运算
	SBB EDX,[ESP+4]
	ADD ESP,8;平衡堆栈
	RET

WriteSysConfigTable32:
	;Offset,Value(32bit)
	PUSH EAX
	PUSH EBX
	MOV EBX,[ESP+12]
	MOV EAX,[ESP+16]
	MOV [EBX+Sys_Config_Table],EAX
	POP EBX
	POP EAX
	RET

ReadSysConfigTable32:
	;Offset
	PUSH EBX
	MOV EBX,[ESP+8]
	MOV EAX,[EBX+Sys_Config_Table]
	POP EBX
	RET

Internal_Timer_Period EQU 18
Sys_Config_Table:
	Sys_Config_Table_ClockCnt DD 0