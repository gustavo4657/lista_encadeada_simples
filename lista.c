#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo   = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo       = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: lista vazia ou posicao invalida\n");
        return;
    }
    q        = p->Prox;
    *Item    = q->Item;
    p->Prox  = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("%d\n", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void RetiraUltimo(TipoLista *Lista, TipoItem *Item) {
    /* IMPLEMENTAR */
    TipoApontador Aux, Ultimo;
    if (Lista->Primeiro == Lista->Ultimo) {
        return 0;
    }
    Aux = Lista->Primeiro;
    
    while (Aux->Prox != Lista->Ultimo) {
        Aux = Aux->Prox;
    }
    Ultimo = Lista->Ultimo;
    *Item = Ult->Item;
    Aux->Prox = NULL;
    Lista->Ultimo = Aux;
    free(Ultimo);
    return 1;
}

void InsereInicio(TipoItem x, TipoLista *Lista) {
    /* IMPLEMENTAR */
    TipoApontador novo;
    novo = (TipoApontador) malloc(sizeof(TipoCelula));
    if (Nova == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }
    novo->Item = x;
    novo->Prox = Lista->Primeiro->Prox;
    Lista->Primeiro->Prox = novo;
    if (Lista->Ultimo == Lista->Primeiro) {
        Lista->Ultimo = novo;
    }
}

void Inverte(TipoLista *Lista) {
    /* IMPLEMENTAR */
    TipoApontador Ant, Atual, Prox;

    if (Lista->Primeiro->Prox == NULL || Lista->Primeiro->Prox->Prox == NULL) {
        return;
    }
    Ant = NULL;
    Atual = Lista->Primeiro->Prox;

    Lista->Ultimo = Atual;

    while (Atual != NULL) {
        Prox = Atual->Prox;
        Atual->Prox = Ant;
        Ant = Atual;
        Atual = Prox;
    }
    Lista->Primeiro->Prox = Ant;
}

int Tamanho(TipoLista *Lista) {
    /* IMPLEMENTAR */
        int count = 0;
    TipoApontador Aux = Lista->Primeiro->Prox;
    while (Aux != NULL) {
        count++;
        Aux = Aux->Prox;
    }
    return count;
}
