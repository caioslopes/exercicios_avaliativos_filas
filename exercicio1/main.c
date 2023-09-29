#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue fila;
    Queue temp;
    Element el;
    Element aux;

    printf("Digite os números:\n");
    init(&fila);
    while(!is_full(fila)){
        scanf("%d", &el);
        printf("Enqueue %d: %s.\n", el, enqueue(fila, el) ? "OK" : "ERRO");
    }

    init(&temp);
    while(!is_empty(fila)){
        aux = dequeue(fila);
        if(aux % 2 != 0){
            enqueue(temp, aux);
        }
    }

    if(!is_empty(temp)){
        printf("\n*** Fila Resultante ***\n");
        int count = 1;
        while(!is_empty(temp)){
            aux = dequeue(temp);
            enqueue(fila, aux);
            printf("Fila[%d]: %d.\n", count, aux);
            count++;
        }
    }



    return 0;
}