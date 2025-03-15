#include <stdio.h>
#include <pthread.h>

int contador = 0; // Recurso compartido

void* incrementar(void* arg)
{
    for (int i = 0; i < 1000000; i++) {
        contador++; // Modificacion sin proteccion
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, incrementar, NULL);
    pthread_create(&thread2, NULL, incrementar, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Valor final del contador: %d\n", contador);
    return 0;
}
