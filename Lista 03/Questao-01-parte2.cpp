#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
    int info;
    struct no* esq;
    struct no* dir;
};
typedef struct no NoArv;

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

NoArv* buscaElemento (NoArv* r, int v)
{
    if (r == NULL)
        return NULL;
    else
        if (r->info > v)
            return buscaElemento (r->esq, v);
        else
            if (r->info < v)
                return buscaElemento (r->dir, v);
            else
                return r;
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

int buscaElemento2(NoArv *arvore, int valor){

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

int main(){
    int num, elemento;
    int i=1;
	srand(time(NULL));
    
    NoArv *arvore;
    
    arvore = criaArvore();
    printf("Quantos elementos sua arvore ira possuir? ");
    scanf("%d", &num);
    
    while(i<=num){
    	printf("Digite um elemento para a arvore: ");
    	scanf("%d", &elemento);
		arvore = insereElemento(arvore, elemento);
		i++;
	}
    
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
    mostraArvore(arvore);
    
    return 0;
}












