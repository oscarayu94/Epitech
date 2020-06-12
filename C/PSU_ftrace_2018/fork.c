/*
** EPITECH PROJECT, 2019
** fork
** File description:
** by oriol
*/

#include "list.h"
#include "ftrace.h"

int child_stuff(char **name)
{
    int ptrace_ret;
    int fd;

    fd = open("/dev/null", O_WRONLY);
    if (fd == -1 || dup2(fd, 1) == -1)
        return(84);
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1)
        return (84);
    if (execvp(*name, name) == -1)
        fprintf(stderr, "error in execvp\n");
    warn("execvp error");
    return (0);
}

int use_registers(trace_t *tracer)
{
    struct user_regs_struct registers;

    if (ptrace(PTRACE_GETREGS, tracer->child_pid, NULL, &registers) == -1)
        return (84);
    tracer->peek_text_ret = ptrace(PTRACE_PEEKTEXT, tracer->child_pid, registers.rip, NULL);
    if (tracer->peek_text_ret == 0xFFFF)
        return (84);
    if ((int)(registers.rax) <= tracer->max_syscall &&
     (tracer->peek_text_ret == 0x80CD || tracer->peek_text_ret == 0x50F))
        print_syscall(registers.rax, &registers);
    if ((tracer->peek_text_ret & 0xFF) == 0xe8 )
        print_call(registers.rax, &registers, tracer, "relative");
    return (0);
}

void init_tracer(trace_t *tracer, pid_t child_pid)
{
    tracer->status = 0;
    tracer->waitoptions = 0;
    tracer->max_syscall = max_syscalls();
    tracer->child_pid = child_pid;
}

int father_stuff(pid_t child_pid, char **name)
{
    trace_t tracer;
    elf_t elf;

    init_tracer(&tracer, child_pid);
    elf = get_elf(open(*name, O_RDONLY));
    print_sym(elf);
    if (waitpid(child_pid, &(tracer.status), 0) == -1)
        return (84);
    for (tracer.condition = 1; tracer.condition >= 0;
     tracer.condition = tracer.condition) {
        if (use_registers(&tracer) == 84)
            return (84);
        if (ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL) == -1)
            return (0);
        if (waitpid(child_pid, &(tracer.status), 0) == -1)
            return (84);
    }   
    return (0);
}

int fork_comand_name(char **name)
{
    pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		exit(84);
	if (child_pid == 0)
        exit(child_stuff(name));
    if(child_pid > 0)
        father_stuff(child_pid, name);
	return (0);
}
