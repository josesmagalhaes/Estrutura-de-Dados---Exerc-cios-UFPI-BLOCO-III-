
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
    int info;
    struct no* esq;
    struct no* dir;
};
typedef struct no NoArv;

int qtd_arvore = 0;
int qtd_maior = 0;

NoArv* criaArvore (void)
{
    return NULL;
}

int arvoreVazia(NoArv *arvore){
    return arvore == NULL;
}


//exibir Em Ordem
void mostraArvore (NoArv* a) {

	if (a != NULL) {
        mostraArvore(a->esq);
        printf("%d\n",a->info);
        mostraArvore(a->dir);
    }
}

void contaMaior(NoArv* a, int e) {
	if (a != NULL) {
		if (a->info > e){
			qtd_maior++;
		}
        contaMaior(a->esq, e);
        contaMaior(a->dir, e);
    }
}

void contaArvoreMaior(NoArv* a) {
	if (a != NULL) {
		qtd_arvore++;
        contaArvoreMaior(a->esq);
        contaArvoreMaior(a->dir);
    }
}

NoArv* buscaElemento (NoArv* r, int v)
{
    if (r == NULL){
		 return NULL;
	}else{
        if (r->info > v){
			return buscaElemento (r->esq, v);
		}else{
       	   if (r->info < v){
				return buscaElemento (r->dir, v);  
			}else{
				return r;	
			}
                
		}
		
	}

}

NoArv* insereElemento (NoArv* a, int v)
{
    if (a == NULL) {
        a = (NoArv*)malloc(sizeof(NoArv));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else
        if (v < a->info)
            a->esq = insereElemento(a->esq,v);
    else
        if (v > a->info)
        a->dir = insereElemento(a->dir,v);
    return a;
}

bool buscaElemento2(NoArv *arvore, int valor){

    if (arvoreVazia(arvore))
        return 0;
    
    return arvore->info == valor || buscaElemento2(arvore->esq,valor) || buscaElemento2(arvore->dir, valor);
}

NoArv* removeElemento (NoArv* r, int v) {
    if (r == NULL){
        printf("elemento nao existe\n");
        return NULL;
        }
    else
        if (r->info > v)
        r->esq = removeElemento(r->esq, v);
    else
        if (r->info < v)
        r->dir = removeElemento(r->dir, v);
    else {          /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL) {
            free (r);
            r = NULL; }
        /* nó só tem filho à direita */
        else
            if (r->esq == NULL) {
                NoArv* t = r;
                r = r->dir;
                free (t);
            }
        /* só tem filho à esquerda */
        else if (r->dir == NULL) {
            NoArv* t = r;
            r = r->esq;
            free (t);
        }
        /* nó tem os dois filhos */
        else {
            NoArv* f = r->esq;
            while (f->dir != NULL)
            {
                f = f->dir;
            }
            r->info = f->info; /* troca as informações */
            f->info = v;
            r->esq = removeElemento(r->esq,v);
        }
    }
    return r;
}

void raizArvore(NoArv *arvore){
    printf("Raiz-> %d\n",arvore->info);

}

void numNos(NoArv *arvore,int num){
	if (arvore==NULL){
		printf("Arvore vazia!\n");
	}else{
		printf("Sua arvore possui %d nos folhas!\n",num-1);
	}
	
}

int nivelElemento(NoArv *pos, int ele, int nivel) {

	if (pos == NULL) {
		return -1;
	}

	if (ele == pos->info) {
		return nivel;
	}

	if (ele < pos->info) {
		return  (nivelElemento  (pos->esq, ele, nivel + 1));
	} else {
		return nivelElemento(pos->dir, ele, nivel + 1);
	}
}

int altura(NoArv * h) {

    int u, v;
    if (h == NULL) return -1;
    u = altura(h->esq);
    v = altura(h->dir);
    if (u > v) return u+1;
    else return v+1;
}

int main(){
    int num=0, elemento;
    int i=1;
    int op=0;
    int busca=0;
    int n=0;
    bool a;
    int h=0;
    int ele=0;
	srand(time(NULL));
    
    NoArv *arvore;
    
    arvore = criaArvore();
    printf("-------MENU-------\n");
    printf("1. Inserir elementos na Arvore\n");
    printf("2. Quantidade de nos folha na arvore\n");
    printf("3. Mostrar arvore\n");    
    printf("4. Buscar elemento\n");
	printf("5. Saber nivel do no\n");
	printf("6. Buscar maiores\n");
	printf("7. Arvore maior\n");
	printf("8. Sair\n");    
    do{
 	   printf("Digite a opcao desejada: ");
 	   scanf("%d", &op);
 	   if (op==1){
   	   	   printf("Quantos elementos sua arvore ira possuir? ");
    		scanf("%d", &num);
    
    		while(i<=num){
    		
    			printf("Digite um elemento para a arvore: ");
    			scanf("%d", &elemento);
    			
				arvore = insereElemento(arvore, elemento);
				i++;			
		}

	}else if(op==2){
		numNos(arvore,num);
	}else if(op==3){
		mostraArvore(arvore);
	}else if (op==4){
		printf("Digite o elemento a ser buscado: ");
		scanf("%d", &busca);
		a=buscaElemento2(arvore,busca);
		if (a==true){
			printf("True\n");
		}else{
			printf("False\n");
		}
	}else if (op==5){
		//h=altura(arvore);
		printf("Digite o elemento a ser pesquisado: ");
		scanf("%d", &ele);
		n = nivelElemento(arvore, ele, h);
		printf("E elemento encontra-se no nivel: %d\n", n);
	}else if (op==6){
		printf("Digite o elemento a ser pesquisado: ");
		scanf("%d", &ele);
		qtd_maior = 0;
		contaMaior(arvore, ele);
		printf("Maiores: %d\n", qtd_maior);
		qtd_maior = 0;
		break;
	}else if (op==7){
		qtd_arvore = 0;
		contaArvoreMaior(arvore->esq);
		int esq = qtd_arvore;
		qtd_arvore = 0;
		contaArvoreMaior(arvore->dir);
		int dir = qtd_arvore;
		
		if (esq	> dir){
			printf("esquerda maior %d elementos \n", esq);
		} else {
			printf("direita maior %d elementos \n", dir);
		}
		break;
	}else if (op==8){
		printf("Saindo do programa...\n");
		break;
	}
	
	
	}while(op!=6);

    

    /*
    arvore = insereElemento(arvore, 10);
    arvore = insereElemento(arvore, 24);
    arvore = insereElemento(arvore, 39);
    arvore = insereElemento(arvore, 43);
    arvore = insereElemento(arvore, 55);
    arvore = insereElemento(arvore, 49);
    arvore = insereElemento(arvore, 8);
    arvore = insereElemento(arvore, 15);
    
    arvore = removeElemento(arvore, 10);
    */
    
    
    return 0;
}












