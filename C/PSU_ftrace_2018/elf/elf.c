/*
** EPITECH PROJECT, 2019
** PSU_ftrace_2018
** File description:
** elf
*/

#include "../list.h"
#include "../ftrace.h"

void print_sym(elf_t elf)
{
    for (int i = 0; i < elf.symsize; i++) {
        if (ELF64_ST_TYPE(elf.sym[i].st_info) != 3 \
        && ELF32_ST_TYPE(elf.sym[i].st_info) != 4 \
        && elf.sym[i].st_shndx != 65521 && elf.sym[i].st_name != 0) {
            // printf("0x%llx", (unsigned long long int)elf.sym[i].st_value);
            // printf("\t%s\n", &elf.symtab[elf.sym[i].st_name]);
        }
    }
}

elf_t get_elf(int fd)
{
    elf_t elf;
    int size = lseek(fd, 0, SEEK_END);

    elf.data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (elf.data != NULL) {
        elf.ehdr = (Elf64_Ehdr*)(elf.data);
        elf.shdr = (Elf64_Shdr*)(elf.data + elf.ehdr->e_shoff);
        for (int i = 0; i < elf.ehdr->e_shnum; i++) {
            if (elf.shdr[i].sh_type == SHT_SYMTAB) {
                elf.sym = (Elf64_Sym*)(elf.data + elf.shdr[i].sh_offset);
                elf.symtab = (char*)(elf.data + elf.shdr[i + 1].sh_offset);
                elf.symsize = (int)(elf.shdr[i].sh_size / sizeof(Elf64_Sym));
            }
        }
    }
    return (elf);
}
