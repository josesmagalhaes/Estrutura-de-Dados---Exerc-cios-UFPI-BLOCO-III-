#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no *prox;
};

typedef struct no No;

struct f{
    No* inicio;
    No* fim;
};

typedef f Fila;



Fila *criaFila(){//Funcao para criar a fila;
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    fi->inicio = NULL;
    fi->fim = NULL;
    return fi;
}

void insereElemento(Fila* fila, int info){//Funcao para inseriri elemento.
    No* novo;
    novo = (No*) malloc(sizeof(No));
   
    novo->info = info;
    novo->prox = NULL;
    
    if (fila->fim != NULL)//Se a fila ja possui elementos
        fila->fim->prox = novo;
     else
         fila->inicio = novo;
    
    fila->fim = novo;
}

bool filaVazia(Fila *fila){//Funcao que retorna vazio;
    if (fila->inicio == NULL)
        return true;
    else
        return false;
}

int removeElemento(Fila *fila){//Funcao para remover elemento;
    int valor;
    No *aux;
    
    if (filaVazia(fila)){
        printf("Fila esta vazia! \n");
        exit(-1);
    }
    
    aux = fila->inicio;
    valor = aux->info;
    fila->inicio = aux->prox;
    
    if( fila->inicio == NULL)
        fila->fim = NULL;
    
    free(aux);
    return valor;
}

//mostra elementos da fila
void mostraLista(Fila *fila){
    
    No *aux;
    if (filaVazia(fila))
        printf("Fila esta vazia!\n");
    else{
        aux = fila->inicio;
        
        printf("Inicio: %d \n", fila->inicio->info);
        printf("Fim: %d \n", fila->fim->info);
        
        printf("Demais valores: ");
        for (aux = aux->prox; aux->prox != NULL; aux = aux->prox) {
            printf("%d ", aux->info);
        }
        printf("\n");
        printf("\n");
    }
    
}

//libera a memoria alocada
void liberaFila(Fila *fila){
    No *aux;
    aux = fila->inicio;
    while (aux->prox != NULL) {
        No* t;
        t = aux->prox;
        free(aux);
        aux = t;
    }
    free(fila);
}

void filaEle(Fila *fila){//Funcao que busca o elemento.
	int elemento, achou=0;
	No *aux;
	
	printf("Digite um elemento a ser buscado: ");
	scanf("%d", &elemento);
	for(aux = fila->inicio; aux != NULL ; aux = aux->prox){
		if(elemento == aux->info){
			achou++;
		} 
	
	}
	if(achou > 0){
		printf("true");
	} else {
		printf("false");
	}
}

int main(){//Funcao principal.
    Fila *fila;
    
    fila = criaFila();
    
    insereElemento(fila,12);
    insereElemento(fila,65);
    insereElemento(fila,23);
    insereElemento(fila,43);
    insereElemento(fila,11);
    insereElemento(fila,21);
    insereElemento(fila,23);
    insereElemento(fila,98);
    insereElemento(fila,10);
    insereElemento(fila,9);
    
    mostraLista(fila);


    filaEle(fila);
    return 0;
}

