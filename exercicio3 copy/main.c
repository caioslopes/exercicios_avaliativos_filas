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
        el = malloc(sizeof(char)*20);
        fgets(el, 20, stdin);
        printf("Enqueue %s: %s.\n", el, enqueue(fila, el) ? "OK" : "ERRO");
    }

    while(!is_empty(fila)){
        aux = dequeue(fila);
        
        if(flag < 2){
            enqueue(fila, aux);
            flag++;
        }else {
            flag = 0;
            if(!is_empty(fila))
                free(aux);
        }
    }

    printf("\n** %s **\n", aux);
    free(aux);
    


    return 0;
}