//
// Created by bullet on 17-12-27.
//

#ifndef PROJECT_MULTIBOOT_H
#define PROJECT_MULTIBOOT_H

#include "../include/type.h"

#define MULTIBOOT_MAGIC = 0x1BADB002
// 多重引导头
typedef struct multiboot_header {
    // Magic域, 必需的
    u32_t magic;    // 魔数
    u32_t flags;    // 位0-15指出需求,位16-31指出可选特性
    u32_t checksum; // 校验码, （magic + flags + checksum） = 0
    // 地址域, 如果flags位16被置位, 则有效； 指定可执行文件的物理地址信息, EOF文件不必提供
    u32_t header_addr;
    u32_t load_addr;
    u32_t load_end_addr;
    u32_t bss_end_addr;
    u32_t entry_addr;
    // 图形域, 如果flags位2被置位, 则有效； 指定OS启动后的图形模式
    u32_t mode_type;
    u32_t width;
    u32_t height;
    u32_t depth;
} multiboot_header_t;

typedef struct multiboot_info {
    // 指出其它域是否有效
    u32_t flags;
    // 位0控制, 指出低端和高端内存大小, 单位为K
    u32_t mem_lower;
    u32_t mem_upper;
    // 位1控制, 指出引导程序从哪个BIOS设备载入OS映像
    u32_t boot_device;
    // 位2控制, 包含要传送给内核的命令行参数的物理地址
    u32_t cmdline;
    // 位3控制, 指出辅助引导模块的个数和第一个辅助引导模块的地址
    u32_t mods_count;
    u32_t mods_addr;
    // 位4和位5互斥控制, 位4则表示在哪里可以找到a.out格式内核映像的符号表, 位5则表示ELF格式内核映像的section头表、项数和字符串表
    union {
        a_out_symbol_table_t a_out_sym;
        elf_section_header_table_t elf_sec;
    } symbols;
    // 位6控制, 指出保存由BIOS提供的内存分布的缓冲区的地址和长度
    u32_t mmap_length;
    u32_t mmap_addr;
    // 位7控制, 指出第一个驱动器结构的物理地址和大小
    u32_t drives_length;
    u32_t drives_addr;
    // 为8控制, 指出由 GET CONFIGURATION BIOS 调用返回的ROM配置表
    u32_t config_table;
    // 位9控制, 指出引导程序名字在物理内存中的地址
    u32_t boot_loader_name;
    // 位10控制, 指出APM表的物理地址
    u32_t apm_table;
    // 位11控制, 指出图图形表信息，前提是在multiboot_header_t中指定了一种图形模式
    u32_t vbe_control_info;
    u32_t vbe_mode_info;
    u32_t vbe_mode;
    u32_t vbe_interface_seg;
    u32_t vbe_interface_off;
    u32_t vbe_interface_len;
};

typedef struct elf_section_header_table {
    u32_t num;
    u32_t size;
    u32_t addr;
    u32_t sh_ndx;
} elf_section_header_table_t;

typedef struct a_out_symbol_table {
    u32_t tab_size;
    u32_t str_size;
    u32_t addr;
    u32_t reserved;
} a_out_symbol_table_t;

typedef struct module {
    u32_t mod_start;
    u32_t mod_end;
    u32_t string;
    u32_t reserved;
} module_t;

typedef struct memory_map {
    u32_t size;
    u32_t base_addr_low;
    u32_t base_addr_high;
    u32_t length_low;
    u32_t length_high;
    u32_t type;
} memory_map_t;


#endif //PROJECT_MULTIBOOT_H
