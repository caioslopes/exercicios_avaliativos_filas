#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue fila;
    Element el;
    Element aux;
    int flag = 0;

    printf("Digite os nomes:\n");
    init(&fila);
    while(!is_full(fila)){
        scanf("%c", &el);
        fflush(stdin);
        printf("Enqueue %c: %s.\n", el, enqueue(fila, el) ? "OK" : "ERRO");
    }

    while(!is_empty(fila)){
        aux = dequeue(fila);
        if(flag < 2){
            enqueue(fila, aux);
            flag++;
        }else {
            flag = 0;
        }
    }

    printf("\n** %c **\n", aux);


    return 0;
}