[BITS 16]
	BootLoader_Segment_Addr EQU 1000H
	ORG 7C00H
	
	JMP Start
	
	DB 01H,5AH,30H,62H,7BH,8DH,9AH,3CH,8DH,7CH,9DH,1AH,25H,36H,79H,20H ;引导程序ID

Start:
	MOV AX,CS
	MOV DS,AX
	MOV ES,AX
	MOV SS,AX
	MOV SP,7C00H
	CALL CLS
	MOV AX,MBRMessage
	CALL DispStr
	MOV AX,BootLoader_Segment_Addr
	MOV ES,AX
	MOV BX,0000H
	MOV AH,02H;读取BootLoader
	MOV AL,20
	MOV DL,80H
	MOV DH,00H
	MOV CH,00H
	MOV CL,02H
	INT 13H
	JNC BootLoader_Check
	CALL CLS
	MOV AX,0000H
	MOV ES,AX
	MOV AX,Read_BootLoader_Fail_Message;BootLoader读取失败
	CALL DispStr
	JMP $
BootLoader_Check:
	MOV BP,0000H
BootLoader_Check_Loop:
	MOV AL,[ES:BP]
	MOV BL,[DS:BootLoader_Check_String+BP]
	CMP AL,BL
	JNZ Load_BootLoader_Fail
	INC BP
	MOV AX,[DS:BootLoader_Check_String+BP]
	CMP AL,00H
	JNZ BootLoader_Check_Loop
	JMP BootLoader_Load
Load_BootLoader_Fail:
	CALL CLS
	MOV AX,0000H
	MOV ES,AX
	MOV AX,Load_BootLoader_Fail_Message;BootLoader加载失败
	CALL DispStr
	JMP $
BootLoader_Load:
	PUSH BootLoader_Segment_Addr
	PUSH BP
	RETF;跳转到BootLoader

CLS:
	PUSH DS
	MOV AX,0B000H
	MOV DS,AX
	MOV BP,0FFFFH
CLS_Loop:
	MOV BYTE [DS:BP-1],20H
	MOV BYTE [DS:BP],0FH
	SUB BP,02H
	CMP BP,799H
	JA CLS_Loop
	POP DS
	MOV AH,02H
	MOV BH,00H
	MOV DH,00H
	MOV DL,00H
	INT 10H
	RET
	
DispStr:
	;输入：AX - 字符串基址 ES:BP指向要显示的字符串
	
	MOV BP,AX
	MOV DI,0
Len_Find_Loop:
	MOV AL,[ES:BP+DI]
	INC DI
	CMP AL,00H
	JNZ Len_Find_Loop
	DEC DI
	MOV CX,DI
	MOV CH,00H
	MOV AX,01301H
	MOV BX,000FH
	MOV DL,00H
	INT 10H
	RET
	
MBRMessage DB "BootLoader Loading...",00H
Read_BootLoader_Fail_Message DB "Read BootLoader Fail!",00H
Load_BootLoader_Fail_Message DB "Load BootLoader Fail!",00H
BootLoader_Check_String DB "BootLoaderCheckString",00H

TIMES 510-($-$$) DB 0
DW 0AA55H