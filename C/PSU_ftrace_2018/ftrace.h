/*
** EPITECH PROJECT, 2019
** PSU_ftrace_2018
** File description:
** elf
*/

#ifndef ELF_H_
#define ELF_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <zconf.h>

typedef struct elf_s {
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    Elf64_Sym *sym;
    char *symtab;
    int symsize;
    void *data;
} elf_t;

typedef struct trace_s {
    int	status;
    int	waitoptions;
    int max_syscall;
    int condition;
    pid_t child_pid;
    unsigned short peek_text_ret;
} trace_t;

void  print_call(int syscall_nb, struct user_regs_struct *registers, trace_t *tracer, char *type);

#endif /* !ELF_H_ */
