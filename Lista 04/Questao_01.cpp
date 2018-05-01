#include <stdio.h>
#include <stdlib.h>

struct tree{
	int info, fb;
	tree *sae;
	tree *sad;
};

typedef struct tree arvore;
arvore *raiz = NULL;

int altura( arvore *aux){
	if(!aux){
		return 0;
	}
	int ae = altura(aux->sae);
	int ad = altura(aux->sad);
	return (ae > ad) ? ae + 1: ad + 1;
}

arvore* buscar(int n){
	arvore *aux;
	aux = raiz;
	while(aux && aux->info != n){
		if(n < aux->info){
	 	 	 aux = aux->sae;
}else{
	aux = aux->sad;
	}
}
	return aux;
}

void limpar_arvore( arvore *aux){
	if(aux->sae){
		limpar_arvore(aux->sae);
	}
	if(aux->sad){
		limpar_arvore(aux->sad);
}
	free(aux);
	raiz = NULL;
}
//rotacao simples a esquerda
arvore * rotacionar_dir_dir ( arvore * no ){
	arvore * temp = no;
	arvore * dir = temp->sad;
	temp->sad = dir->sae;
	dir->sae = temp;
	return dir;
}
//rotacao simples a direita
arvore * rotacionar_esq_esq ( arvore * no ){
	arvore * temp = no;
	arvore * esq = temp->sae;
	temp->sae = esq->sad;
	esq->sad = temp;
	return esq;
}
//rotacao dupla a direitra
arvore * rotationar_esq_dir ( arvore * no ){
	arvore * temp = no;
	arvore * esq = temp->sae;
	arvore * dir = esq->sad;
	temp->sae = dir->sad;
	esq->sad = dir->sae;
	dir->sae = esq;
	dir->sad = temp;
	return dir;
}
//rotacao dupla a esquerda
arvore * rotacionar_dir_esq ( arvore * no ){
	arvore * temp = no;
	arvore * dir = temp->sad;
	arvore * esq = dir->sae;
	temp->sad = esq->sae;
	dir->sae = esq->sad;
	esq->sad = dir;
	esq->sae = temp;
	return esq;
}

arvore * novoNo ( int valor ){
	arvore * no;
	no = (arvore*) malloc ( sizeof ( arvore ) );
	if ( no == NULL ){
	puts ( "o programa ficou sem memória\n" );
	system ( "pause" );
	}
	no->sae = NULL;
	no->sad = NULL;
	no->info = valor;
	return no;
}

int fator_bal ( arvore * no ){
	int fator = 0;
	if ( no->sae )
		fator -= altura ( no->sae );
	if ( no->sad )
		fator += altura ( no->sad );
	return fator;
}

arvore * balancear_node ( arvore * no ){
	arvore * node_balanceado = NULL;
	if ( no->sae )
		no->sae = balancear_node ( no->sae );
	if ( no->sad )
		no->sad = balancear_node ( no->sad );
	int fator = fator_bal ( no );
	no->fb = fator;
	if ( fator <= -2 ){
/* pesando pra esquerda */
	if ( fator_bal ( no->sae ) <= -1 )
		node_balanceado = rotacionar_esq_esq ( no );
	else
		node_balanceado = rotationar_esq_dir ( no );
	}
	else if ( fator >= 2 ){
/* pesando pra direita */
	if ( fator_bal ( no->sad ) >= 1 )
		node_balanceado = rotacionar_dir_dir ( no );
	else
		node_balanceado = rotacionar_dir_esq ( no );
	}
else{
	node_balanceado = no;
	}
	return node_balanceado;
}

void ajustaFB( arvore *aux){
	if(!raiz){
		printf("Arvore vazia!");
		return;
}
	if(aux){
		ajustaFB(aux->sae);
		aux->fb = fator_bal(aux);
		ajustaFB(aux->sad);
		aux->fb = fator_bal(aux);
	}
}

arvore* balancear_tree ( arvore * tree ){
	arvore * nova_raiz = NULL;
	nova_raiz = balancear_node ( tree );
	if ( nova_raiz != tree ){
		tree = nova_raiz;
	}
	ajustaFB(tree);
	return tree;
}

void inserir (int valor ){
	arvore * novo_no = NULL;
	arvore * proximo = NULL;
	arvore * ultimo = NULL;
	if ( raiz == NULL ){
		novo_no = novoNo ( valor );
		raiz = novo_no;
	}else{
		proximo = raiz;
	while ( proximo != NULL ){
		ultimo = proximo;
	if ( valor < proximo->info ){
		proximo = proximo->sae;
	}else if ( valor > proximo->info ){
		proximo = proximo->sad;
	}else if ( valor == proximo->info ){
		return;
	}
}
	novo_no = novoNo ( valor );
	if ( valor < ultimo->info )
		ultimo->sae = novo_no;
	if ( valor > ultimo->info )
		ultimo->sad = novo_no;
	}
	raiz = balancear_tree(raiz);
}

arvore* removeElemento (arvore* r, int v) {
	if (r == NULL){
		printf("\nO elemento %d nao existe na arvore!\n", v);
		return NULL;
	}else
		if (r->info > v)
		r->sae = removeElemento(r->sae, v);
	else
	if (r->info < v)
		r->sad = removeElemento(r->sad, v);
	else { /* achou o noì a remover */
/* noì sem filhos */
	if (r->sae == NULL && r->sad == NULL) {
		free (r);
		r = NULL;
//balancear_tree(r);
	}
/* noì soì tem filho aÌ direita */
	else
	if (r->sae == NULL) {
		arvore* t = r;
		r = r->sad;
		free (t);
	}
/* soì tem filho aÌ esquerda */
	else if (r->sad == NULL) {
		arvore* t = r;
		r = r->sae;
		free (t);
	}
/* noì tem os dois filhos */
	else {
		arvore* f = r->sae;
		while (f->sad != NULL){
			f = f->sad;
		}
		r->info = f->info; /* troca as informac.oÞes */
		  	f->info = v;
	   	r->sae = removeElemento(r->sae,v);
		}
	}
	return r;
}
//Exibe em ordem
void exibir_ordenado( arvore *aux){
	if(!raiz){
		printf("Arvore vazia!");
		return;
	}
	if(aux){
		exibir_ordenado(aux->sae);
//aux->fb = fator_bal(aux);
		printf("%d(%d) ", aux->info, aux->fb);
		exibir_ordenado(aux->sad);
	}
}
//Exibe em Pré Ordem
void exibir_Preordem( arvore *aux){
	if(!raiz){
		printf("Arvore vazia!");
		return;
	}
	if(aux){
		printf("%d(%d) ", aux->info, aux->fb);
		exibir_Preordem(aux->sae);
//aux->fb = fator_bal(aux);
		exibir_Preordem(aux->sad);
	}
}
//Exibe em Pos Ordem
void exibir_Posordem( arvore *aux){
	if(!raiz){
		printf("Arvore vazia!");
		return;
	}
	if(aux){
		exibir_Posordem(aux->sae);
//aux->fb = fator_bal(aux);
		exibir_Posordem(aux->sad);
		printf("%d(%d) ", aux->info, aux->fb);
	}
}
/*Funcao que busca determinado elemento*/
void busca(arvore *arv, int elemento){
	if(arv != NULL){
	if(arv->info > elemento){
		printf("%d,",arv->info);
		busca(arv->sae, elemento);
	}else {
		if(arv->info < elemento)
	{
	printf("%d,",arv->info);
	busca(arv->sad, elemento);
	}else {
		if(arv->info == elemento)
	{
		printf("%d,",arv->info);
		printf("\nO elemento %d foi encontrado na arvore!\n", elemento);
		   	}
		}
	}
	}else{
		printf("\nO elemento %d nao foi encontrado na arvore!\n", elemento);
	}
}

int main(){
//int vet[3] = {3,2,1}; // provoca rotacao a simples a direita
//int vet[3] = {1,2,3}; // provoca rotacao a simples a esquerda
//int vet[3] = {3,1,2}; // provoca rotacao a dupla a direita
//int vet[3] = {1,3,2}; // provoca rotacao a dupla a esquerda
	int altura_arvore, elemento,op;
	printf("----------MENU----------\n");
	printf("1 - Inserir elemento.\n");
	printf("2 - Mostrar arvore em Pre-ordem.\n");
	printf("3 - Mostrar arvore em Pos-ordem.\n");
	printf("4 - Mostrar arvore em Em-ordem.\n");
	printf("5 - Altura da arvore.\n");
	printf("6 - Buscar No.\n");
	printf("7 - Excluir No.\n");
	printf("8 - Limpar arvore.\n");
	printf("9 - Sair.\n");
	do {
		printf("\nEscolha uma opcao: ");
		scanf("%d",&op);
		switch (op){
		case 1:
		printf("Insira um elemento na arvore: ");
		scanf("%d",&elemento);
		inserir(elemento);
		break;
		case 2:
		exibir_Preordem(raiz);
		break;
		case 3:
		exibir_Posordem(raiz);
		break;
		case 4:
		exibir_ordenado(raiz);
		break;
		case 5:
		altura_arvore = altura(raiz);
		printf("\nA altura da arvore e: %d\n", altura_arvore);
		break;
		case 6:
		printf("Informe o elemento a ser buscado na arvore: ");
		scanf("%d",&elemento);
		busca(raiz,elemento);
		break;
		case 7:
		printf("Informe o elemento a ser excluido a arvore: ");
		scanf("%d",&elemento);
		raiz = removeElemento(raiz, elemento);
		raiz = balancear_tree(raiz);
		break;
		case 8:
		limpar_arvore(raiz);
		break;
		default:
		if (op > 9){
			printf("Opcao invalida!\n");
		}
	}
}while(op != 9);

	return 0;
}	