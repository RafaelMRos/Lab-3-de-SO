#include <stdio.h>
#include <unistd.h>   // Para fork(), execlp(), sleep()
#include <sys/types.h> // Para pid_t
#include <sys/wait.h>  // Para wait()

int main() {
    pid_t pid = fork();  // Cria o processo filho

    if (pid < 0) {
        // Caso ocorra um erro na criação do processo filho
        perror("Erro ao criar o processo filho");
        return 1;
    }
    else if (pid == 0) {
        // Este é o processo filho
        printf("Processo filho criado. PID do filho: %d\n", getpid());

        // Processo filho vai executar um novo programa (ex: ls -l)
        execlp("ls", "ls", "-l", NULL);

        // Caso execlp falhe, esta mensagem será impressa
        perror("Erro ao executar execlp");
        return 1;
    }
    else {
        // Este é o processo pai
        printf("Processo pai. PID do pai: %d, PID do filho: %d\n", getpid(), pid);

        // O processo pai espera o filho terminar
        wait(NULL);

        // Após o término do processo filho
        printf("Processo filho terminou. Processo pai continua.\n");
    }

    return 0;
}
