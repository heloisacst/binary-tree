#include <stdio.h>
#include <stdlib.h>

struct noArv {
    int valor;
    struct noArv* esq;
    struct noArv* dir;
};

typedef struct noArv Arv;

void imprimeOrdenado(Arv* a)
{
     if (a != NULL) {
         imprimeOrdenado(a->esq); // recursividade
         printf("%d ",a->valor);
         imprimeOrdenado(a->dir);
     }
	
}

Arv* insere(Arv* a, int valor)
{
    if (a == NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->valor = valor;
        a->esq = a->dir = NULL;
    }else if (valor < a->valor){
        a->esq = insere(a->esq,valor);
    }else if (valor > a->valor){
        a->dir = insere(a->dir,valor);
    }

    return a;
}

Arv* removeValor(Arv* r, int valor)
{
    if (r == NULL){
        return NULL;
    }else if (r->valor > valor){
        r->esq = removeValor(r->esq, valor);
    }else if (r->valor < valor){
        r->dir = removeValor(r->dir, valor);
    }else {
            if (r->esq == NULL && r->dir == NULL) {
                free (r);
                r = NULL;
            }
            else if (r->esq == NULL) {
                Arv* aux = r;
                r = r->dir;
                free (aux);
            }
            else if (r->dir == NULL) {
                Arv* aux = r;
                r = r->esq; 
                free(aux);
            }
            else{
            	Arv* aux = r;
                r = r->esq;
                r->dir = aux->dir;
                free(aux);
        }
 	return r;
	}
}

void main()
{

Arv* a =  NULL;
	
	int valor;

a = insere(a,20);
a = insere(a,11);
a = insere(a,9);
a = insere(a,5);
a = insere(a,22);
a = insere(a,14);
a = insere(a,2);
a = insere(a,10);

printf("Valores:\n ");
imprimeOrdenado(a);

printf("\nInforme o valor a ser removido\n");
scanf("%d", &valor);

a = removeValor(a, valor);

printf("\nDepois de remover o %d:\n ", valor);
imprimeOrdenado(a);

}

