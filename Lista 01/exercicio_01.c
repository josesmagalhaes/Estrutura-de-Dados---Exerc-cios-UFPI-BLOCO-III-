#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct no{
	char info[180];
	struct no *prox;
};

typedef struct no No;

No* criaLista(){
	return NULL;
}

//Fun��o recebe uma lista e o texto como par�metros
No* insereElementoInicio(No* lista, char info_char[]){
    //inciamo uma vari�vel para representar o novo elemento
	No*  novo;
	// alocamos uma mem�ria para a vari�vel novo
	novo = (No*) malloc(sizeof(No));
	//adicionamos a string a estrutura
	strcpy(novo -> info, info_char);
	//o ponteiro da estrutura novo aponta para o priemiro elemento 
	novo -> prox = lista;
    //retornamos a estrutura novo que agora ser� o primeiro elemento da lista
	return novo;
}

//Fun�a� sem retorno que recebe uma lista como par�metro
void mostraLista(No* lista){
    //criamos um ponteiro para o prametro lista
	No* aux = lista;
	//verifica se a lista est� vazia
	if(aux == NULL){
		printf("\nLista vazia...\n");
	} 
	// se a lista n�o estiver vazia
	else{
	    //percorre todos os elementos da lista
		while( aux != NULL){
		    //imprime o elemento atual de cada ciclo do loop
			printf("Elemento -> %s\n", aux->info);
			// pega o pr�ximo elemento da lista
			aux = aux->prox;
		}
	}
    //libera aux
	free(aux);
}

//Fun��o rcebe uma lista e retorna ela com o menos um elemento
No* removeUlt(No *lista){
    //cria dois ponteiros e o segundo aponta para null
    No *aux, *ant=NULL;
    //aux recebe lista
    aux = lista;
    //
    while(aux->prox != NULL){
        ant = aux;
        aux = aux -> prox;
    }
    if(ant == NULL){ // Quando s� restar um �nico elemento, eu pego a lista e atribui NULL
        lista = NULL;
    } else ant -> prox = NULL;
    
    free(aux);
    return lista;
}


int main(){

	char entrada[180], comando[10] = "FIM";
	No* lista;

	lista = criaLista();

	printf("\nDigite \"FIM\" para encerrar o programa a qualquer momento.");

	while(1){

		printf("\nEntre com um elemento do tipo String: ");
		fgets(entrada, 180, stdin);

		entrada[ strlen(entrada) -1 ] = 0;

		printf("\n");

		if( !(strcmp(entrada, comando)) ){
		    while(lista != NULL){ 
		        lista = removeUlt(lista); 
		        printf("\nRemovendo ultimo elemento...\n");
		        mostraLista(lista);
		    }
		    free(lista);
			break;
		} else{
			lista = insereElementoInicio(lista, entrada);
			mostraLista(lista);
		}

	}

	return 0;
}

