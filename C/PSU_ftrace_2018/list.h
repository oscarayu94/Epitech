/*
** EPITECH PROJECT, 2019
** list
** File description:
** by oriol
*/

#ifndef LIST_H_
    #define LIST_H_


#include <err.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/user.h>
#include <sys/reg.h>
#include "ftrace.h"
# define RELCALL(opcode)	((opcode & 0xFF) == 0xe8)

typedef struct	s_prototype
{
  char		*name;
  int		param_nb;
  char		*params[6];
  char		*ret_type;
}		prototype_t;

extern prototype_t	g_syscalls[];

int    fork_comand_name(char **name);
void    print_syscall(int syscall_nb, struct user_regs_struct *registers);
int father_stuff(pid_t child_pid, char **name);
int max_syscalls(void);
void    handle_sig_int(int sig);
char	*get_path(char *initial_path);

elf_t get_elf(int fd);
void print_sym(elf_t elf);

#endif /* !LIST_H_ */