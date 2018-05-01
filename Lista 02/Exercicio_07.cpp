#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{//No de nossa fila.
    char nome[50];
    float salario;
    struct no *prox;
};

typedef struct no No;

struct f{
    No* inicio;
    No* fim;
};

typedef f Fila;



Fila *criaFila(){//Aqui, se cria a fila.
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    fi->inicio = NULL;
    fi->fim = NULL;
    return fi;
}

void insereElemento(Fila* fila, char nome[], float salario){//Inserindo elemento da fila.
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
	strcpy(novo -> nome, nome);
    novo->salario = salario;
    novo->prox = NULL;
    
    if (fila->fim != NULL)//Se a fila ja possui elementos
        fila->fim->prox = novo;
     else
         fila->inicio = novo;
    
    fila->fim = novo;
}

bool filaVazia(Fila *fila){//Verificando se a fila esta vazia.
    if (fila->inicio == NULL)
        return true;
    else
        return false;
}
void mostraLista(Fila *fila){//Mopstrando a fila, aprensentando os funcionarios ja cadastrados.
    
    No *aux;
    printf("Funcionarios cadastrados\n");
	printf("-------------------------\n");   
    if (filaVazia(fila))
        printf("Fila esta vazia!\n");
    else{
        aux = fila->inicio;
        
        printf("Nome: %s \n", fila->inicio->nome);
        printf("Salario: %.2f \n", fila->inicio->salario);        
        printf("Nome: %s \n", fila->fim->nome);
        printf("Salario: %.2f \n", fila->fim->salario);
		        
        for (aux = aux->prox; aux->prox != NULL; aux = aux->prox) {
            printf("Nome: %s \n", aux->nome);
            printf("Salario: %.2f\n ", aux->salario);            
        }
    }
 	printf("-------------------------\n\n"); 
}

int maiorSalario(Fila *fila){//Verificando o maior salario, e atribuindo o nome na funcao.
	float maior;
	char nome[50];
	No *aux;
    aux = fila->inicio;
    if (fila->inicio == NULL){
		printf("Operacao impossivel! Fila Vazia!\n");
	}else{
		maior=fila->inicio->salario;
		while (aux!= NULL) {
			if ((aux->salario)>maior){
				maior=aux->salario;
				strcpy(nome,aux->nome); 
		        
        	}
		aux = aux ->prox;
		}

	}
	printf ("O funcionario que possui maior salario e: %s\n", nome);
}

int menorSalario(Fila *fila){//Verificando o menor salario, e atribuindo o nome na funcao.
	float menor;
	char nome[50];
	No *aux;
    aux = fila->inicio;
    if (fila->inicio == NULL){
		printf("Operacao impossivel! Fila Vazia!\n");
	}else{
		menor=fila->fim->salario;
		while (aux != NULL) {
			if (aux->salario<menor){
				menor=aux->salario;
				strcpy(nome,aux->nome); 
		        
        	}
		aux = aux ->prox;
		}

	}
	printf ("O funcionario que possui menor salario e: %s\n", nome);
}

void mediaSalarial(Fila *fila){//Verificando a media salarial de todos os funcionarios, uando um laço while.
	int i=0;
	float media = 0;

	No *aux;

    if (filaVazia(fila)){
		printf("Operacao impossivel! Fila Vazia!\n");
	}else{
		aux = fila->inicio;
		while (aux) {
			media+=aux->salario;
			i++;
			aux = aux->prox;
		}
		media=media/i;
		printf("media %.2f\n", media);
	}
}	 

int main(){//Funcao principal.
    int opcao;
    opcao=0;
    
    Fila *fila;
    
    fila = criaFila();
    //atribição direta dos dados.
    insereElemento(fila,"Jose de Sousa Magalhaes",1800.51);
    insereElemento(fila,"Carlos Alberto Silva",2000.5);
	insereElemento(fila,"Pedro Alcantara Meneses",3000.55);  
    insereElemento(fila,"Alice Pinho Sousa",954);
    insereElemento(fila,"ConsoeloPererira Soares",1200.34);
	insereElemento(fila,"Simone Souza Pontes",9000.34); 
    insereElemento(fila,"Adalberto Soares Lima",10200.12);
	insereElemento(fila,"Patricia Ciqueira Pontes",15000.34);		   
    mostraLista(fila);//mostrando os funcionarios existentes.

	printf("-----------MENU-----------\n");
	printf("1. Nome do funcionario que possui maior salario: \n");
	printf("2. Nome do funcionario que possui menor salario: \n");
	printf("3. Media salarial de todos os funcionarios: \n");	
	printf("4. Sair: \n");		
	do{
		printf("\nDigite a opcao desejada: ");
		scanf("%d", &opcao);
		if (opcao==1){
			maiorSalario(fila);
		}else if(opcao==2){
			menorSalario(fila);
		}else if(opcao==3){
			mediaSalarial(fila);
		}else if (opcao==4){
			printf("Saindo do programa...");
			break;
		}else{
			printf("Opcao invalida!\n");
		}
		
	}while(opcao!=4);
	
    return 0;
}

