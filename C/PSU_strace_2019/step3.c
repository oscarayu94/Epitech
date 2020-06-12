
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

int tracer(char *av)
{
	pid_t breastfeeding_child;
    breastfeeding_child = fork();
    int	stat = 0;
    char* const* p = NULL;
    char* const* pe = NULL;
    if (breastfeeding_child > 0) { // Eso significa proceso padre
        breastfeeding_child = waitpid(breastfeeding_child, &stat, 0);
        ptrace(PTRACE_SYSCALL, breastfeeding_child, NULL, NULL);
    }
    if (breastfeeding_child	== 0) {	// Eso significa proceso hijo
        ptrace(PTRACE_SYSCALL, 0, NULL, NULL);
        execve(av, p, pe);
        exit(0);
    }
    printf("The child tracing is now done\n");
    return(69);
}

// int main()
// {   pid_t child;
//     long orig_eax;
//     child = fork();
//     if(child == 0) {
//         ptrace(PTRACE_TRACEME, 0, NULL, NULL);
//         execl("/bin/ls", "ls", NULL);
//     }
//     else {
//         wait(NULL);
//         orig_eax = ptrace(PTRACE_PEEKUSER,
//                           child, 4 * ORIG_EAX,
//                           NULL);
//         printf("The child made a "
//                "system call %ld\n", orig_eax);
//         ptrace(PTRACE_CONT, child, NULL, NULL);
//     }
//     return 0;
// }

int main(int ac, char **av)
{
    tracer(av[1]);
    return(1);
}