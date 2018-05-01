#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*Aqui declaramos o tipo nó para a pilha, composto de
ponteiro para o próximo nó e de um campo para dado
que no caso é o campo char dado[30];
*/
typedef struct no {
      
       char dado[30];
       char dado2[30];
       char dado3[30];
       struct no *proximo;
      
       } no;
      
no *topo = NULL; //Ponteiro para o topo da pilha
no *alocar; //Ponteiro para fazer alocação


/*Rotina que faz a inserção de elementos na pilha
O Parâmetro dado recebe um ponteiro para string
A função não retorna valor algum
*/
void insereElemento(char *dado, char *dado2, char *dado3) {
    
    alocar = (struct no *) malloc(sizeof(struct no)); //Faz alocação na memória
        
    if (!alocar) { //Se não for possível a alocação, sai do programa
       printf("Falta de memória\n");
       exit(0);
    }
    
    strcpy(alocar->dado, dado); //Copia o dado para o novo nó alocado
    strcpy(alocar->dado2, dado2);
    strcpy(alocar->dado3, dado3);
     if (!topo) { //Se não houver elemento ainda na pilha, insere
                  //na base, apontando o ponteiro de topo para o único
                  //elemento até então inserido
         topo = alocar;
         topo->proximo = NULL;
        
     }
    
     else //se não...
    
     {
         alocar->proximo = topo; //Aponta o próximo para o "antigo" topo da pilha
         topo = alocar;          //Aponta o ponteiro de topo para o dado que foi alocado
        
     }
}

/*
Rotina que retira elementos da pilha
O elemento retirado sempre é o que está no topo
*/
char * pop() {
    
    char *ponteiro = topo->dado;
    topo = topo->proximo;
    return ponteiro;

    
    }

/*Imprime todos os elementos da pilha na tela
na ordem de retirada
*/
void imprimir() {
     no *ponteiro = topo;
     while (ponteiro) {
           printf("\n%s", ponteiro->dado);
           printf("\n%s", ponteiro->dado2);
           printf("\n%s", ponteiro->dado3);
           ponteiro = ponteiro->proximo;
          }
     }


char buscarPorTitulo() {//Aqui buscamos o professor por titulo
	 char titul[30];
	 int retorno;
     no *ponteiro = topo;
     no *aux;
     aux=topo;
     printf("Digite a titulacao a ser buscada: ");
     scanf("%s", titul);
     if (topo==NULL){
		 printf("Pilha fazia!\n");
	 }else{
		while (aux!=NULL){
		retorno =((strcmp(aux->dado3,titul)));// a funcao strcm retorna um valor iteiro guardado em "retorno;"
		if (retorno == 0){
			printf("Professor encontrado: %s\n",aux->dado);
		}else{
				 printf("Nao ha mais professor com essa titulacao!\n");
			 }
			 aux = aux ->proximo;
		 }
	 }

    
}    

char buscarPorNome() {//Aqui buscamos o professor por titulo
	 char nome[30];
	 int retorno;
     no *ponteiro = topo;
     no *aux;
     aux=topo;
     printf("Digite o nome do professor a ser buscado: ");
     scanf("%s", nome);
     if (topo==NULL){
		 printf("Pilha fazia!\n");
	 }else{
		while (aux!=NULL){
		retorno =((strcmp(aux->dado,nome)));// a funcao strcm retorna um valor iteiro guardado em "retorno;
		if (retorno == 0){
			printf("Salario do professor(a) %s: %s\n",aux->dado,aux->dado2);
			printf("Titulacao do professor(a) %s: %s\n",aux->dado,aux->dado2);
		}else{
				 printf("Nao ha mais professor com esse nome!\n");
				 break;
			 }
			 aux = aux ->proximo;
		 }
	 }

    
} 
	   
int main() {//Funcao principal.
	char dado[30],dado2[30], dado3[30];
    int opcao;
    opcao=0;
    
    printf("---------MENU-------\n");
    printf("1. Cadastrar Professor\n");
    printf("2. Buscar Professor por titulacao: \n");
    printf("3. Buscar Professor por nome: \n");
    printf("4. Sair\n");
    do{
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);
    	if (opcao==1){
    	setbuf(stdin, NULL);
    	printf("Inserira o nome do Professor: ");
    	gets(dado);
    	setbuf(stdin, NULL);
    	printf("Inserira o salario do Professor: ");
    	gets(dado2);
    	setbuf(stdin, NULL);
    	printf("Inserira a titulacao do Professor: ");
    	gets(dado3);
    	setbuf(stdin, NULL);
    	insereElemento(dado, dado2, dado3);    		
		}else if(opcao==2){
			buscarPorTitulo();
		}else if (opcao==3){
			buscarPorNome();
		}else if(opcao==4){
			printf ("Saindo do programa...\n");
			break;
		}
	}while(opcao!=4);
    getchar();
}
