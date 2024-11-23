#include <stdio.h>
#include "teste.h"

int main()
{
    int i;
    int r, a, b; 
    tFila fila; 
    inicializar(&fila);

    imprimeFila(&fila);    
    for(i=0;i<7;i++){
        inserir(&fila, i);
        printf("inserindo %d. ",i);
        imprimeFila(&fila);
    }

    while(tamanho(&fila)>1){
        remover(&fila,&a);
        remover(&fila,&b);
        r = a+b;
        inserir(&fila, r);
        imprimeFila(&fila); 
    }
    return 0;
}