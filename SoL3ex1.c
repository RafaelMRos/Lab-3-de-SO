#include <stdio.h>
#include <unistd.h>   // Para fork() e sleep()
#include <sys/types.h> // Para pid_t

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

        // O processo pai continua sem esperar o processo filho terminar
        printf("Processo pai continua sem esperar o filho.\n");
    }

    return 0;
}