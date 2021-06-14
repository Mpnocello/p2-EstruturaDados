#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
}lista; 

typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;

void quicksort(int *vet, int inicio, int final);
lista *lista_alocada()
{
    lista *novo;
    novo=(lista*)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

lista *registro_alocado()
{
    registro *novo;
    novo=(registro*)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void mostra_lista(lista* l)
{
    if(l->inicio)
    {
        registro * aux;
        aux = l->inicio;
        while(aux)
        {
            printf("%d", aux->valor);
            aux = aux->prox;
        }
    }
}

void incluir_numero(lista * l, int x);
int * retorna_vetor(lista *l);


int main
{
    lista *l1;
    int n, x;

    printf("\n Digite um numero n:");
    scanf("%d",&n);

    l1 = lista_alocada();

    for(int i = 0; i < n; i++)
    {
        printf("n%d:", i+1);
        scanf("%d",&x);
        void incluir_numero(l1, x);
    }

    int * vetor = retorna_vetor(l1);

    printf("Vetor ordenado com quick: ");
    for(int i = 0; i < l1->qtd; i++)
    {
        printf("%d", vetor[i]);
    }

    printf("\n")
    return 0;
}

int * retorna_vetor(lista * l)
{
    int * vetor;

    vetor = malloc(sizeof(int)*l->qtd);

    registro * aux;

    aux = l->inicio;

    int i;
    for(i = 0; i < l->qtd; i++)
    {
        vetor[i] = aux->valor;
        aux = aux->prox;
    }

    quicksort(vetor, 0, i-1);

    return vetor;
}

void incluir_numero(lista *l, int x)
{
    registro *novo, *aux;
    novo = registro_alocado();
    novo->valor = x;

    if(l->inicio != NULL)
    {
        aux = l->inicio;

        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }else
    {
        l->inicio = novo;
    }
    l->qtd += 1;
}

void quicksort(int * vet, int inicio, int final)
{
    int pivo, i, j, aux;

    if(inicio >= final)
    {
        return;
    }

    i = inicio;
    pivo = vet[i];

    j = final;

    while(j != i)
    {
        if(i > j)
        {
            if(vet[j] > pivo)
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

                aux = i;
                i = j;
                j = aux;

                j--;
            }else{
                j++
            }
        }else{
            if(vet[j] < pivo){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

                aux = i;
                i = j; 
                j = aux;

                j++;
            }else{
                j--;
            }
        }
    }
    quicksort(vet, inicio, i-1);
    quicksort(vet, i+1, final);

}
