OBJS_BOOTPACK = #.obj

TOOLPATH = ../tools/
INCPATH  = ../include

MAKE     = $(TOOLPATH)make.exe -r
NASK     = $(TOOLPATH)nask.exe
NASM    = $(TOOLPATH)nasm.exe -f bin
NASMOBJ    = $(TOOLPATH)nasm.exe -f elf
CC1      = $(TOOLPATH)cc1.exe -I$(INCPATH) -Os -Wall -quiet
GAS2NASK = $(TOOLPATH)gas2nask.exe -a
OBJ2BIM  = $(TOOLPATH)obj2bim.exe
MAKEFONT = $(TOOLPATH)makefont.exe
BIN2OBJ  = $(TOOLPATH)bin2obj.exe
BIM2COS  = $(TOOLPATH)bim2cos.exe
RULEFILE = $(TOOLPATH)os/os.rul
EDIMG    = $(TOOLPATH)edimg.exe
IMGTOL   = $(TOOLPATH)imgtol.com
LD       = $(TOOLPATH)ld.exe
GCC      = $(TOOLPATH)gcc.exe
OBJCOPY  = $(TOOLPATH)objcopy.exe
COPY     = copy
DEL      = del

BootSector-32 = BootSector-32/common.h BootSector-32/video.h BootSector-32/string.h BootSector-32/gdt.h BootSector-32/idt.h \
				BootSector-32/Convert.h BootSector-32/log.h BootSector-32/PCI.h BootSector-32/ICH7Driver/ICH7_USB.h BootSector-32/ICH7Driver/ICH7_8259.h \
				BootSector-32/argctrl.h BootSector-32/cpu.h BootSector-32/Delay.h BootSector-32/Interrupt.h BootSector-32/APIC.h \
				BootSector-32/common.c BootSector-32/BootLoader32-main.c BootSector-32/video.c BootSector-32/string.c BootSector-32/gdt.c \
				BootSector-32/idt.c BootSector-32/Convert.c BootSector-32/log.c BootSector-32/PCI.c BootSector-32/ICH7Driver/ICH7_USB.c \
				BootSector-32/argctrl.c BootSector-32/cpu.c BootSector-32/Delay.c BootSector-32/Interrupt.c BootSector-32/APIC.c \
				BootSector-32/ICH7Driver/ICH7_8259.c
BootSector-32-obj = BootSector-32/BootLoader32.obj BootSector-32/Interrupt.obj BootSector-32/BootLoader32-main.obj
BootSector-32-c = ../os/BootSector-32/common.c ../os/BootSector-32/BootLoader32-main.c ../os/BootSector-32/video.c ../os/BootSector-32/string.c \
				  ../os/BootSector-32/gdt.c ../os/BootSector-32/idt.c ../os/BootSector-32/Convert.c ../os/BootSector-32/log.c ../os/BootSector-32/PCI.c \
				  ../os/BootSector-32/ICH7Driver/ICH7_USB.c ../os/BootSector-32/argctrl.c ../os/BootSector-32/cpu.c ../os/BootSector-32/Delay.c \
				  ../os/BootSector-32/Interrupt.c ../os/BootSector-32/APIC.c ../os/BootSector-32/ICH7Driver/ICH7_8259.c
# -------------------

default :
	$(MAKE) img

# -------------------

BootSector-16/boot.bin : BootSector-16/boot.asm Makefile
	$(NASM) BootSector-16/boot.asm -o BootSector-16/boot.bin
BootSector-16/BootLoader.bin : BootSector-16/BootLoader.asm Makefile
	$(NASM) BootSector-16/BootLoader.asm -o BootSector-16/BootLoader.bin
BootSector-32/BootLoader32.obj : BootSector-32/BootLoader32.asm Makefile
	$(NASMOBJ) BootSector-32/BootLoader32.asm -o BootSector-32/BootLoader32.obj
BootSector-32/Interrupt.obj : BootSector-32/Interrupt.asm Makefile
	$(NASMOBJ) BootSector-32/Interrupt.asm -o BootSector-32/Interrupt.obj
BootSector-32/BootLoader32-main.obj : $(BootSector-32) BootSector-32/BootLoader32-main.c Makefile
	cd ..\tools && gcc -O0 -c $(BootSector-32-c) -o ../os/BootSector-32/BootLoader32-main.obj	
BootSector-32/BootLoader32.elf : $(BootSector-32-obj) Makefile
	$(LD) -o BootSector-32/BootLoader32.elf -Ttext 0x00000000 $(BootSector-32-obj)
BootSector-32/BootLoader32.bin: BootSector-32/BootLoader32.elf Makefile
	$(OBJCOPY) -R .note -R .comment -S -O binary BootSector-32/BootLoader32.elf BootSector-32/BootLoader32.bin

os.img : BootSector-16/boot.bin BootSector-16/BootLoader.bin BootSector-32/BootLoader32.bin Makefile
		
#		imgout:os.img


	$(TOOLPATH)newimg ..\os\os.img 10 MB
#	
	$(TOOLPATH)dd.exe if=harddisk.bin of=os.img seek=0 bs=512 count=20480 conv=notrunc
	$(TOOLPATH)dd.exe if=BootSector-16/boot.bin of=os.img seek=0 bs=1 count=446 conv=notrunc
	$(TOOLPATH)dd.exe if=BootSector-16/BootLoader.bin of=os.img seek=1 bs=512 count=20 conv=notrunc
	$(TOOLPATH)dd.exe if=BootSector-32/BootLoader32.bin of=os.img seek=21 bs=512 count=768 conv=notrunc
	
# -------------------

img :
	$(MAKE) os.img

run :
	$(MAKE) img
	$(MAKE) -C ../tools/qemu

clean :
	-$(DEL) *.bin
	-$(DEL) *.lst
	-$(DEL) *.obj
	-$(DEL) os.map
	-$(DEL) os.bim
	-$(DEL) os.cos
	-$(DEL) os.sys

