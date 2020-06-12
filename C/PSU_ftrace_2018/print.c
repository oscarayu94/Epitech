/*
** EPITECH PROJECT, 2019
** print
** File description:
** by oriol
*/

#include "list.h"
#include "ftrace.h"

long long int arg_nb_to_register(int arg_nb, struct user_regs_struct *registers)
{
    if (arg_nb == -1)
        return (registers->rax);
    if (arg_nb == 0)
        return (registers->rdi);
    if (arg_nb == 1)
        return (registers->rsi);
    if (arg_nb == 2)
        return (registers->rdx);
    if (arg_nb == 3)
        return (registers->rcx);
    if (arg_nb == 4)
        return (registers->r8);
    if (arg_nb == 5)
        return (registers->r9);
    return (0);
}

void print_arg(char *type, int arg_nb, struct user_regs_struct *registers)
{
    long long int register_value;

    register_value = arg_nb_to_register(arg_nb, registers);
    if (register_value == 0)
        printf( "NULL");
    else
        printf("%p", (void*)register_value);
}

void print_function(int syscall_nb, struct user_regs_struct *registers,
                       prototype_t g_syscalls[])
{
    printf("Syscall %s(", g_syscalls[syscall_nb].name);
    for (int i = 0; i < g_syscalls[syscall_nb].param_nb; i++) {
        print_arg(g_syscalls[syscall_nb].params[i], i, registers);
        if (i + 1 != g_syscalls[syscall_nb].param_nb)
            printf( ", ");
    }
    printf( ") = %lld\n", registers->rax);
}

int max_syscalls(void)
{
    int max_syscalls;

    for (max_syscalls = 0; strcmp(g_syscalls[max_syscalls].name, "END") != 0; max_syscalls++);
    return (max_syscalls);
}

void print_syscall(int syscall_nb, struct user_regs_struct *registers)
{
    print_function(syscall_nb, registers, g_syscalls);
}

void print_call(int syscall_nb, struct user_regs_struct *registers,
                            trace_t *tracer, char *type)
{
    __extension__ unsigned long long int addr = 0;
    int offset;
    
    offset = (int)((tracer->peek_text_ret) >> 8);
    if (strcmp(type, "relative") == 0)
        addr = registers->rip + offset+ 5;
    printf("Entering function main at 0x%llx\n", addr);
}
