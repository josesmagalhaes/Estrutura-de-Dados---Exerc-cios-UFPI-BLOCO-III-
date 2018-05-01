#include <stdio.h>
#include <stdlib.h>
#define TAM 100//Define o tamanho e nossa pilha.

int *criaPilha(){//Com esta funcao, criamos nossa pilha.
    int *pilha;
    pilha = (int*) malloc(sizeof(int)*TAM);
    return pilha;
}

void insereElemento(int *pilha, int valor, int *topo){//Aqui, inserimos elementos na pilha.
    if (*topo < TAM) {
        *topo = *topo + 1;
        pilha[*topo] = valor;
        
    }
    else{
        printf("A pilha nao suporta mais elementos, aloque mais espeaco\n");
    }
}

void mostrarPilhaTopo(int *pilha, int topo){//Apos percorreros a pilha, podemos fazer sua impressao.
	int i;
    if (topo == -1) {
        printf("Impossivel inserir este tipo de elemento. Pilha vazia\n");
        exit(0);
    }
    printf("Elemento do topo da pilha: %d\n",pilha[topo]);
    
}

int removeElemento(int *pilha, int *topo){//Aqui removemos os elementos da pilha.
    if (*topo == -1) {
        printf("Pilha vazia \n");
        return -1;
    }
    else{
        *topo = *topo - 1;//Decrementando após a remoção.
        return *topo+1;
    }
}

int main(){//Funcao principal.
    
    int *pilha, topo = -1, aux, elemento;
    
    pilha = criaPilha();
    
    do{
    	printf("Digite um elemento para ser adicionado a Pilha: ");
    	scanf("%d", &elemento);
    	if (elemento<0){
    		mostrarPilhaTopo(pilha, topo);
		}
    	insereElemento(pilha, elemento, &topo);
    	if (elemento==-1){
    		printf("Foi digitado -1. Condicao nao permitida.\nSaindo do programa...\n");
    		break;
		}
	}while(elemento>0);
	

    return 0;
    
}
