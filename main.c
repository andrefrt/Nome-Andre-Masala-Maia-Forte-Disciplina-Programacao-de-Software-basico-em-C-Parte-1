#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void print_pid_pai(pid_t pid) {
    printf("pid do Pai: %d\n", pid);
}

void print_pid_filho() {
    printf("pid do Filho: %d\n", getpid());
}

int main(void) {
    int i;
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        print_pid_filho();
    } else {
        print_pid_pai(pid);
    }
    printf("Este print sera executada por ambos processos\n\n");
    exit(0);
}
