env = DefaultEnvironment()
env['CFLAGS'] = "-c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include"

env['AS'] = "nasm"
env['ASFLAGS'] = "-f elf -g -F stabs"
env['LINKFLAGS'] = "-T ./scripts/kernel.lds -m elf_i386 -nostdlib"
env['LINK'] = "ld"

Object("./build/boot", "./boot/boot.asm")
Object("./build/kernel", "./kernel/kernel.c")
Program("./build/hx_kernel", ["./build/boot.o", "./build/kernel.o"])