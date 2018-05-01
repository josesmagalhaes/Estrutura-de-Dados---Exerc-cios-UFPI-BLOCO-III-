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

No* insertOrd(No* lista, char info_char[]){
    No* novo;
    
    novo = (No*) malloc(sizeof(No));
    strcpy(novo -> info, info_char);
    
    if(lista == NULL){
        novo -> prox = lista;
        lista = novo;
    } else{
        No* ant = NULL;
        No* aux = lista;
        
        while(aux != NULL && ( (int)(aux->info[0]) < (int)(info_char[0]) ) ){
            ant = aux;
            aux = aux -> prox;
        }
        if(ant == NULL){
            novo -> prox = aux;
            lista = novo;
        }
        else{
            ant -> prox = novo;
            novo -> prox = aux;
        }
        
    }
    
    return lista;
}

//Função recebe uma lista e o texto como parâmetros
No* insereElementoInicio(No* lista, char info_char[]){
    //inciamo uma variável para representar o novo elemento
	No*  novo;
	// alocamos uma memória para a variável novo
	novo = (No*) malloc(sizeof(No));
	//adicionamos a string a estrutura
	strcpy(novo -> info, info_char);
	//o ponteiro da estrutura novo aponta para o priemiro elemento 
	novo -> prox = lista;
    //retornamos a estrutura novo que agora será o primeiro elemento da lista
	return novo;
}

//Funçaõ sem retorno que recebe uma lista como parâmetro
void mostraLista(No* lista){
    //criamos um ponteiro para o prametro lista
	No* aux = lista;
	//verifica se a lista está vazia
	if(aux == NULL){
		printf("\nLista vazia...\n");
	} 
	// se a lista não estiver vazia
	else{
	    //percorre todos os elementos da lista
		while( aux != NULL){
		    //imprime o elemento atual de cada ciclo do loop
			printf("Elemento -> %s\n", aux->info);
			// pega o próximo elemento da lista
			aux = aux->prox;
		}
	}
    //libera aux
	free(aux);
}

No* busca(No* lista, char termo[]){
	No *aux;
	aux = lista;

	if(aux == NULL){
		printf("\nA lista esta vazia.\n");
	}
	else{
		while( (aux != NULL) && ( strcmp(termo, aux -> info) ) ){
			aux = aux -> prox;
		}
		
		if ( aux == NULL){
			printf("\nElemento nao encontrado.\n");
			return NULL;
		} else{
			printf("O elemento \"%s\", foi encontrado\n", aux -> info );
			return aux;
		}
	}

}

//Função rcebe uma lista e retorna ela com o menos um elemento
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
    if(ant == NULL){ // Quando só restar um único elemento, eu pego a lista e atribui NULL
        lista = NULL;
    } else ant -> prox = NULL;
    
    free(aux);
    return lista;
}


int main(){

	char entrada[180], comando[10] = "FIM";
	No* lista;

	lista = criaLista();


	while(1){
		printf("\n--------------Menu------------\n");
		printf("1. Inserir objetos na lista.\n");
		printf("2. Imprimir lista.\n");
		printf("3. Buscar objeto.\n");
		printf("4. Remover todos os elementos da lista.\n");
		printf("Ou digite \"FIM\" para encerrar o programa.\n\n");
		printf("\tEntre com o numero da opcao desejada: ");
		fgets(entrada, 180, stdin);
		entrada[strlen(entrada) - 1] = 0;

		if( !(strcmp(entrada, "1")) ){
			printf("Entre com uma nova cadeia de caracteres: ");
			fgets(entrada, 180, stdin);
			entrada[strlen(entrada) - 1] = 0;
			lista = insertOrd(lista, entrada);
			printf("\n------\nElemento inserido com sucesso!\n------\n");
		}
		else if( !(strcmp(entrada, "2")) ){
			printf("\n\nElementos:\n------\n");
			mostraLista(lista);
			printf("\n");
		}
		else if( !(strcmp(entrada, "3")) ){
			printf("Entre com o termo a ser buscado: ");
			fgets(entrada, 180, stdin);
			entrada[strlen(entrada) - 1] = 0;
			busca(lista, entrada);
		}
		else if( !(strcmp(entrada, "4")) || ( !(strcmp(entrada, comando)) ) ){
			while(lista != NULL){
			lista = removeUlt(lista);
			}
			printf("\nTodos os elementos da lista foram removidos.");
			if( !(strcmp(entrada, comando)) ){
				free(lista);
				printf(" Memoria liberada.\n");
				exit(1);
			}
			printf("\n");
		}

	}


	return 0;
}

