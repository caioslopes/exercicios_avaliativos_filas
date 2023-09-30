#include "queue.h"

void sistema_fila(Element opc, Element *prioridade, Queue *fila_prioridade, Queue *fila_normal, Element *num);

int main(int argc, char const *argv[])
{
    Queue fila_prioridade;
    Queue fila_normal;
    Element opc;
    Element prioridade = 0;
    Element num = 1;

    init(&fila_prioridade);
    init(&fila_normal);

    do{
        printf("\n** Menu **\n");
        printf("1 - Retirar ficha prioritária\n");
        printf("2 - Retirar ficha comum\n");
        printf("3 - Chamar próximo cliente\n");
        printf("0 - Encerrar programa\n\n");

        scanf("%d", &opc);
        sistema_fila(opc, &prioridade, &fila_prioridade, &fila_normal, &num);

    }while(opc != 0);
    
    return 0;
}

void sistema_fila(Element opc, Element *prioridade, Queue *fila_prioridade, Queue *fila_normal, Element *num){
    Element caixa;
    switch (opc){
        case 1:
            if(!is_full(*fila_prioridade))
                printf("\nCódigo: %d | %s.\n", *num, enqueue(*fila_prioridade, *num) ? "Ficha Prioritária Retirada" : "ERRO");
                *prioridade += 1;
                *num += 1;
            break;
        case 2:
            if(!is_full(*fila_normal))
                printf("\nCódigo: %d | %s.\n", *num, enqueue(*fila_normal, *num) ? "Ficha Comum Retirada" : "ERRO");
                *num += 1;
            break;
        case 3:
            printf("Número do Caixa: \n");
            scanf("%d", &caixa);

            printf("\n#############\n");
            printf("# Caixa: %d #", caixa);
            printf("\n#############\n\n");

            if(!is_empty(*fila_prioridade) || !is_empty(*fila_normal)){
                if(caixa >= 1 && caixa <= 3){
                    if(*prioridade != 0){
                        if(!is_empty(*fila_prioridade))
                            printf("-> Código: %d | Fila Prioritária\n", dequeue(*fila_prioridade));
                            *prioridade -= 1;
                    }else{
                        if(!is_empty(*fila_normal))
                            printf("-> Código: %d | Fila Comum\n", dequeue(*fila_normal));
                    }
                }else{
                    if(!is_empty(*fila_normal))
                        printf("-> Código: %d | Fila Comum\n", dequeue(*fila_normal));
                }
            }else{
                printf("-> Não há ningúem na fila.\n");
            }
            break;
        }
}