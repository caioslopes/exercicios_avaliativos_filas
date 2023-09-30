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
        enqueue(fila, el);
        printf("Entrou na roda: %s", el);
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

    printf("\nSobrevivente: %s\n", aux);
    free(aux);
    


    return 0;
}