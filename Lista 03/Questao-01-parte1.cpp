#include <stdio.h>
#include <stdlib.h>

struct no {
    char info;
    struct no* esq;
    struct no* dir;
};

typedef no NoArv;

//esses prototipos das funcoes
NoArv* criaArvoreVazia(void);
NoArv* criaComSubArvores(char c, NoArv* e, NoArv* d);
NoArv* arv_libera(NoArv* a);
int arv_vazia(NoArv* a);
int arv_pertence(NoArv* a, char c);
void mostraArvore(NoArv* a);


NoArv* criaArvoreVazia(void)
{
    return NULL;
}


NoArv* criaComSubArvores (char c, NoArv* sae, NoArv* sad) {//Funcao que cria suarvores
    
    NoArv* p = (NoArv*)malloc(sizeof(NoArv));
    
    if(p == NULL)
        exit(1);
    
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

NoArv* arv_libera (NoArv* a){//funcao que libera a arvore
    if (!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_vazia (NoArv* a)//verifica se a arvore esta vazia
{
    return a==NULL;
}

int arv_pertence (NoArv* a, char c) {
    if (arv_vazia(a))
        return 0; /* árvore vazia não encontrou */
    else
        return a->info == c || arv_pertence(a->esq,c) || arv_pertence(a->dir,c);
}

void mostraArvore(NoArv* a) {
    printf("<");
    if (!arv_vazia(a)){
        printf(" %c ",a->info);
        mostraArvore(a->esq);
        mostraArvore(a->dir);
    }
    printf("> ");
}

int main(){
    
    //Exemplo:<a<b<><d<><>>><c<e<><>><f<><>>>>
    int op, opcao;
    char a, b, c, d, e, f;
    char x, y, w, z;
    
    printf("-------MENU-------\n");
    printf("1. Preencher arvore de cima para baixo: \n");
    printf("2. Preencher arvore de baixo para cima: \n");
    printf("Digite a opcao que deseja ");
    scanf("%d", &op);
    if(op == 1){
    printf("Digite o elemento do topo da arvore: ");
    setbuf(stdin, NULL);
	scanf("%c", &a);
	setbuf(stdin, NULL);
	printf("O elemento %c tem elementos a sua esquerda!\nDigite o elemento da esquerda: ", a);
	scanf("%c", &b);
	setbuf(stdin, NULL);
	printf("O elemento %c tem elementos a sua direita!\nDigite o elemento da direita: ", b);
	scanf("%c", &d);
	setbuf(stdin, NULL);		
 	printf("Ramificacao encerrada!\nO elemento %c possui elemento a direita!\nDigite o elemento da direita: ", a);
	scanf("%c", &c);
	setbuf(stdin, NULL);
	printf("O elemento %c possui elementos a sua esquerda!\nDigite o elemento da esquerda: ", c);
	scanf("%c", &e);
	setbuf(stdin, NULL);
	printf("O elemento %c possui elementos a sua direita!\nDigite o elemento da direita: ", c);		       
	scanf("%c", &f);
	setbuf(stdin, NULL);
	printf("Preencehendo arvore...\n");       
        NoArv* arvore2 = criaComSubArvores(a,
                            criaComSubArvores(b,
                                        criaArvoreVazia(),
                                        criaComSubArvores(d, criaArvoreVazia(),criaArvoreVazia()) ),
                            criaComSubArvores(c,
                                              criaComSubArvores(e, criaArvoreVazia(), criaArvoreVazia()),
                                              criaComSubArvores(f, criaArvoreVazia(), criaArvoreVazia())));
                                           
    printf("Arove montada!\n");    
                mostraArvore(arvore2);
    }
    else{
    		printf("Digite a ultima folha da arvore: ");
    		setbuf(stdin, NULL);
    		scanf("%c", &d);
    		printf("O elemento %c nao possui nenhum elemento nem a esquerda nem a direita!\nDigite o elemento da subarvore anteiror: ",d);
  			setbuf(stdin, NULL);		
			scanf("%c", &b);
    		printf("O elemento %c possui elementos a sua direita! Adicionando elemento %c a folha...\n",b,d);
    		printf("Nenhum elemento a ser adicionado a mais!\nDigite o ultimo elemento da arvore/(lado-esquerdo): ");
    		setbuf(stdin, NULL);
			scanf("%c", &e);
			printf("Nenhum elemento a ser adicionado a mais!\nDigite o ultimo elemento da arvore/(lado-direito): ");
   			setbuf(stdin, NULL);	
			scanf("%c", &f);
    		printf("Digite o elemento da subarvore: ");
 			setbuf(stdin, NULL);
			scanf("%c", &c);
    		printf("O elemento %c possui elementos a direita e esqueda!\nFazendo arranjos necessairos...",c);
    		printf("\nDigite o elemento do topo da arvore: ");
    		setbuf(stdin, NULL);
			scanf("%c", &a);
			printf("Preenchendo arvore...\n");
            NoArv* a1= criaComSubArvores(d,criaArvoreVazia(),criaArvoreVazia()); /* sub-árvore 'b' */
            NoArv* a2= criaComSubArvores(b,criaArvoreVazia(),a1);
            /* sub-árvore 'e' */
            NoArv* a3= criaComSubArvores(e,criaArvoreVazia(),criaArvoreVazia()); /* sub-árvore 'f' */
            NoArv* a4= criaComSubArvores(f,criaArvoreVazia(),criaArvoreVazia()); /* sub-árvore 'c' */
            NoArv* a5= criaComSubArvores(c,a3,a4);
            /* árvore 'a' */
            printf("Arvore montada!\n");
			NoArv* arvore = criaComSubArvores(a,a2,a5 );
			mostraArvore(arvore);
			
			printf("\nDeseja aumentar esta arvore?\nConsidere 1 para SIM e 0 para nao!: ");
			scanf("%d", &opcao);
			if (opcao==1){
				printf("Criando nova arvore...\n");
				printf("Digite o elemento do topo da nova arvore: ");
				setbuf(stdin, NULL);
				scanf("%c", &x);
				printf("O elemento %c possui elementos a direita e esquerda!\nDigite o elemento da esquerda: ", x);
				setbuf(stdin, NULL);
				scanf("%c", &y);
				printf("O elemento %c possui elementos a esquerda!\nDigite o elemento a esquerda: ", y);
				setbuf(stdin, NULL);
				scanf("%c", &w);
				printf("O elemento %c nao possui elementos nem a direita nem a esquerda!\nRetornando...", w);
				printf("Digite o elemento a direia de %c:" , y);
				setbuf(stdin, NULL);
				scanf("%c", &z);
				printf("Preenchendo nova arvore...\n");
				printf("Unindo arvores...\n");			        
        		arvore->esq->esq = criaComSubArvores(x,
                                             criaComSubArvores(y,
                                                               criaComSubArvores(w, criaArvoreVazia(), criaArvoreVazia()),
                                                               criaArvoreVazia()),
                                             criaComSubArvores(z,
                                                               criaArvoreVazia(), criaArvoreVazia())
                                             );
				mostraArvore(arvore);
			}else if (opcao==2){
				printf("Saindo do programa...");
				exit(0);
			}

        
                    
    }
    
    
    return 0;
}


