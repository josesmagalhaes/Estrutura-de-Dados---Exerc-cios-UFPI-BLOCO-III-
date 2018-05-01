#include <stdio.h>
#include <stdlib.h>
#define TAM 100//Tamanho de nossa pilha.

int *criaPilha(){//Aqui criamos nossa Pilha
    int *pilha;
    pilha = (int*) malloc(sizeof(int)*TAM);
    return pilha;
}

void insereElemento(int *pilha, int valor, int *topo){//Aqui inserimos nossos elementos, uma vez que esteja no limite de nossa pilha.
    if (*topo < TAM) {
        *topo = *topo + 1;
        pilha[*topo] = valor;
        
    }
    else{
        printf("A pilha nao suporta mais elementos, aloque mais espaco\n");
    }
}

void mostrarPilha(int *pilha, int topo){//Aqui mostramos todos os elementos de nossa pilha.
	int i;
    if (topo == -1) {
        printf("Pilha vazia\n");
        exit(0);
    }
 
    for(i = 0; i <= topo ; i++){
        printf("Elemento da posicao [%d]:%d\n", i, pilha[i]);
    }
}

int removeElemento(int *pilha, int *topo){//Aqui remomovemos um elemento da nossa pilha.
    if (*topo == -1) {
        printf("Pilha vazia \n");
        return -1;
    }
    else{
        *topo = *topo - 1;//decrementando
        return *topo+1;
    }
}

int mostrarQuant(int *pilha,int topo){//Com o uso do laço for, somamos o percurso da variavel i e adicionamos a variavel soma, para obternmos a quantidade de elementos.
	int i, soma;
	soma=0;
    if (topo == -1) {
        printf("Pilha vazia \n");
        return -1;
    }
    else{
    	for(i = 0; i <= topo ; i++){
        	soma=topo+1;
    	}
    }
    printf("A pilha possui %d elementos.\n", soma);
}

void mostrarPilhaTopo(int *pilha, int topo){//Aqui, mostramos o elemento do topo da nossa pilha, imprimindo a a pilha na posicao [topo].
    if (topo == -1) {
        printf("Pilha vazia\n");
    }
    printf("Elemento do topo da pilha: %d\n",pilha[topo]);

}

void verificarVazia(int *pilha, int topo){//Verificamos se a pilha está vazia, sob a condicao de topo ser igual a -1.
    if (topo == -1) {
        printf("Pilha vazia\n");
        exit(0);
    }
    	printf("A fila possui elementos!\n");
}

int main(){
    
    int *pilha, *novaPilha,topo = -1, topo2 = -1,aux, elemento, opcao;
    novaPilha = criaPilha();//Criamos logo a pilha auxiliar.
    opcao=0;
    printf("-------------MENU-------------\n\n");//Menu do nosso programa.
    printf("1. Criar Pilha Estatica.\n");
    printf("2. Verificar se a Pilha esta vazia.\n");
    printf("3. Adicionar um novo elemento na Pilha.\n");
    printf("4. Desempilhar um elemento da Pilha.\n");
    printf("5. Informar qual o elemento do topo da Pilha.\n");
    printf("6. Informar a quantidade de elementos da Pilha.\n");
    printf("7. Imprimir todos os elementos da Pilha.\n");
    printf("8. Imprimir todos os elementos da Nova Pilha.\n");
    printf("9. Sair.\n\n");
    do {//Laço simples que para ao ser adicionao 8, nossa ultima opcao.
    	printf("Digite a opcao desejada: ");
    	scanf("%d", &opcao);
    	if (opcao==1){
    		pilha = criaPilha();
		}else if (opcao==2){
			verificarVazia(pilha, topo);
		}else if (opcao==3){
			printf("Digite um elemento a ser adicionado a sua fila: ");
			scanf("%d", &elemento);
			insereElemento(pilha, elemento, &topo);
		}else if(opcao==4){
			insereElemento(novaPilha, pilha[topo], &topo2);//Primeiro inserimos o elemtno do topo na pilha nova.
			aux = removeElemento(pilha, &topo);//Depois removemos esse elemento da piha antiga.
		}else if (opcao==5){
			mostrarPilhaTopo(pilha, topo);
		}else if (opcao==6){
			mostrarQuant(pilha, topo);
		}else if(opcao==7){
			mostrarPilha(pilha, topo);
		}else if (opcao==8){
			mostrarPilha(novaPilha, topo2);//Mostramos a nova pilha.
		}else if(opcao==9){
			printf("Saindao do programa...");
			break;
		}
	}while (opcao!=9);

    
    return 0;
    
}    

