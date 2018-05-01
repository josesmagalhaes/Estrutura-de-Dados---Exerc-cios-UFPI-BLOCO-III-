#include <stdio.h>
#include <stdlib.h>
#define TAM 100

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

int mostrarQuant(int *pilha,int topo){//Com o uso do laço for, somamos o percurso da variavel i e adicionamos topo+1 a variavel soma, para obternmos a quantidade de elementos.
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

int maiorEle(int *pilha, int *topo){//Com um laço de retição for, comparamos as posicoes dos elementos e encontramos o maior.
	int i, maior;
	if (topo == -1) {
        printf("Nao e possivel realizar esta operacao!\nPilha vazia!\n");
        return -1;
    }
    else{
    	maior=pilha[0];
    	for(i = 1; i <= topo ; i++){
        	if (pilha[i]>maior){
        		maior=pilha[i];
			}
   		}
    }
    printf ("O maior elemento de nossa Pilha e: %d\n", maior);
}

int menorEle(int *pilha, int *topo){//Com um laço de retição for, comparamos as posicoes dos elementos e encontramos o menor.
	int i, menor;
	if (topo == -1) {
        printf("Nao e possivel realizar esta operacao!\nPilha vazia!\n");
        return -1;
    }
    else{
    	menor=pilha[0];
    	for(i = 1; i <= topo ; i++){
        	if (pilha[i]<menor){
        		menor=pilha[i];
			}
   		}
    }
    printf ("O maior elemento de nossa Pilha e: %d\n", menor);
}

int mediaEle(int *pilha,int topo){//Com dois laços for, podemos criar duas somas, uma de elementos e outra dos elementos, dpois basta fazermos a divisões dos mesmos para tirar a media.
	int i;
	float media, soma, somaele;
	soma=0;
	somaele=0;
	media=0;
    if (topo == -1) {
        printf("Nao e possivel realizar esta operacao!\nPilha vazia!\n");
        return -1;
    }
    else{
    for(i = 0; i <= topo ; i++){
        soma+=pilha[i];
        }
  	for(i = 0; i <= topo ; i++){
  		somaele=topo+1;
    	}
    }
    printf("soma %.1f\n", soma);
    printf("soma %.1f\n", somaele);
    media=soma/somaele;
    printf("A media dos elementos digitados e %.1f.\n", media);
}

int main(){//Funcao principal.
    
    int *pilha, topo = -1, aux, elemento, opcao;
    opcao=0;
    
	printf("-------------MENU-------------\n\n");//Menu do nosso programa.
    printf("1. Criar Pilha Estatica.\n");
    printf("2. Verificar se a Pilha esta vazia.\n");
    printf("3. Adicionar um novo elemento na Pilha.\n");
    printf("4. Remover um elemento da Pilha.\n");
    printf("5. Informar qual o elemento do topo da Pilha.\n");
    printf("6. Informar a quantidade de elementos da Pilha.\n");
    printf("7. Informar o maior elemento da Pilha.\n");
    printf("8. Informar o menor elemento da Pilha.\n");
    printf("9. Informar a media dos elementos da Pilha.\n");
    printf("10. Imprimir todos os elementos da Pilha.\n");
    printf("11. Sair.\n\n");
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
			aux = removeElemento(pilha, &topo);
		}else if (opcao==5){
			mostrarPilhaTopo(pilha, topo);
		}else if (opcao==6){
			mostrarQuant(pilha, topo);
		}else if (opcao==7){
			maiorEle(pilha, topo);
		}else if (opcao==8){
			menorEle(pilha, topo);
		}else if (opcao==9){
			mediaEle(pilha, topo);
		}else if(opcao==10){
			mostrarPilha(pilha, topo);
		}else if(opcao==11){
			printf("Saindao do programa...");
			break;
		}else{
			printf("Opcao invalida!\n");
		}
	}while (opcao!=11);

    
    return 0;
    
}    

