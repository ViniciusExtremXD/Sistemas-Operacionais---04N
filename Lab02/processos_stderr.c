#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t childpid = 0;
    int i, n;

    printf("Digite o número de processos: ");
    scanf("%d", &n);

    for (i = 1; i < n; i++)
        if (childpid = fork())
            break;

    fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
        i, (long)getpid(), (long)getppid(), (long)childpid);
    return 0;
}

