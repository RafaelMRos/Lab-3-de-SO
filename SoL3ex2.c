#include <stdio.h>
#include <unistd.h>   // Para fork() e sleep()
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

        // Loop que imprime uma mensagem 5 vezes, com 1 segundo de intervalo
        for (int i = 0; i < 5; i++) {
            printf("Processo filho, iteração %d\n", i + 1);
            sleep(1);  // Intervalo de 1 segundo
        }
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
