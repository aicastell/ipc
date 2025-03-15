#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex; // Declaramos el mutex
int contador = 0;      // Recurso compartido

void* incrementar(void* arg)
{
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex); // Bloqueo del mutex
        contador++; // Sección crítica
        pthread_mutex_unlock(&mutex); // Desbloqueo del mutex
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL); // Inicializar el mutex

    pthread_create(&thread1, NULL, incrementar, NULL);
    pthread_create(&thread2, NULL, incrementar, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex); // Liberar el mutex

    printf("Valor final del contador: %d\n", contador);
    return 0;
}

