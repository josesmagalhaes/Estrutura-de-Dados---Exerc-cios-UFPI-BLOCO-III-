#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
	char info[180];
	struct no *ant;
	struct no *prox;
};

typedef struct no No;

No* criaLista(){
	return NULL;
}

No* insereInicio(No* lista, char info_char[]){
	No *novo;
	novo = (No*) malloc(sizeof(No));

	strcpy(novo -> info, info_char);
	novo -> ant = NULL;
	novo -> prox = lista;

	if(lista != NULL){
		lista -> ant = novo;
	}

	return novo;
}

/* No* insertOrd(No* lista, char info_char[]){
	No *novo, *aux;

	aux = lista;

	novo = (No*) malloc(sizeof(No));
	strcpy(novo -> info, info_char);
	novo -> ant = NULL;
	novo -> prox = NULL;

	if(lista != NULL){

		while( aux =! NULL){
			aux = aux -> prox;
		}

		aux -> prox = novo;
		novo -> ant = aux;

	}

	return novo;
}*/ // TODO fazer com  que a adição no final também funcione;

void mostraLista(No* lista){
	No* aux = lista;
	if(aux == NULL){
		printf("\nLista vazia...\n");
	} else{
		while(aux != NULL){
			printf("Elemento -> %s\n", aux -> info);
			aux = aux -> prox;
		}
	}
}

void mostraListaInverso(No* lista){ //exibe na ordem inversa
        No* aux = lista;
        if(aux == NULL){
                printf("\nLista vazia\n");
        } else{
                while(aux -> prox != NULL){
                        aux = aux -> prox;
                }
                while(aux != NULL){
                        printf("Elemento -> %s\n", aux -> info);
                        aux = aux -> ant;
                }
        }
}


No* busca(No* lista, char termo[]){
	No *aux;
	aux = lista;

	if(aux == NULL){
		printf("\nLista vazia.\n");
	}
	else{
		while( (aux != NULL) && ( strcmp(termo, aux -> info) ) ){
			aux = aux -> prox;
		}
		
		if ( aux == NULL){
			printf("\n------");
			printf("\nElemento nao econtrado.\n");
			printf("------\n");
			return NULL;
		} else{
			printf("\n------\n");
			printf("O elemento \"%s\", foi encontrado\n", aux -> info );
			printf("------\n");
			return aux;
		}
	}

}


int contarElementos(No* lista){
        No* aux;
        int contador = 0;
        aux = lista;

        while(aux != NULL){
                aux = aux -> prox;
                contador ++;
        }

        return contador;
}



No* removeElemento(No* lista, char str_remover[]){
	No *aux, *ant = NULL;

	aux = busca(lista, str_remover);

	if(aux == NULL){
		printf("\nO elemento nao foi encontrado.\n");
		return lista;
	}
	if(contarElementos(lista)==0){
		return lista;
	}

	if(contarElementos(lista) == 1){
		lista = NULL;
		return lista;
	}

	if(lista == aux){
		lista = aux -> prox;
		lista -> ant = NULL;
	}
	else aux -> ant -> prox = aux->prox;

	if(aux->prox != NULL){
		aux -> prox -> ant = aux -> ant;
	}
	free(aux);
	return lista;
}




No* removeUlt(No *lista){
	No *aux, *ant=NULL;
	aux = lista;
	if(lista == NULL){
		printf("Lista vazia.");
		return lista;
	}

	while(aux->prox != NULL){
		ant = aux;
		aux = aux -> prox;
	}
	if(ant == NULL){ 
		lista = NULL;
	} else ant -> prox = NULL;

	free(aux);
	return lista;
}


int main(){
	int n_elemento = 0;
	char entrada[180], comando[10] = "FIM";
	No* lista;

	lista = criaLista();

	while(1){
		printf("\n--------------Menu------------\n");
		printf("1. Inserir objetos na lista.\n");
		printf("2. Imprimir lista.\n");
		printf("3. Imprimir lista na ordem inversa.\n");
		printf("4. Buscar objeto.\n");
		printf("5. Remover um elemento.\n");
		printf("6. Contar elementos.\n");
		printf("7. Remover todos os elementos da lista.\n");
		printf("Ou digite \"FIM\" para encerrar o programa.\n\n");
		printf("\tEntre com o numero da opcao desejada: ");
		fgets(entrada, 180, stdin);
		entrada[strlen(entrada) - 1] = 0;

		if( !(strcmp(entrada, "1")) ){
			printf("Entre com uma nova cadeia de caracteres: ");
			fgets(entrada, 180, stdin);
			entrada[strlen(entrada) - 1] = 0;
			lista = insereInicio(lista, entrada);
			printf("\n------\nElemento inserido com sucesso!\n------\n");
		}
		else if( !(strcmp(entrada, "2")) ){
			printf("\n\nElementos:\n------\n");
			mostraLista(lista);
			printf("\n");
		}
		else if( !(strcmp(entrada, "3")) ){
			printf("\n\nElementos (ordem inversa):\n------\n");
			mostraListaInverso(lista);
			printf("\n");
		}
		else if( !(strcmp(entrada, "4")) ){
			printf("Entre com o termo a ser buscado: ");
			fgets(entrada, 180, stdin);
			entrada[strlen(entrada) - 1] = 0;
			busca(lista, entrada);
		}
		else if( !(strcmp(entrada, "5")) ){
			printf("Digite o conteudo do elemento que deseja remover: ");
			fgets(entrada, 180, stdin);
			entrada[strlen(entrada) -1] = 0;
			lista = removeElemento(lista, entrada);
		}
		else if( !(strcmp(entrada, "6")) ){
			n_elemento = contarElementos(lista);
			printf("\nA lista contem %d elementos.\n", n_elemento);
		}
		else if( !(strcmp(entrada, "7")) || ( !(strcmp(entrada, comando)) ) ){
			while(lista != NULL){
			lista = removeUlt(lista);
			}
			printf("\nTodos os elementos da lista froram removidos.");
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

