
#include <stdio.h>
#include <stdlib.h>
#include "lista-duplamente-encadeada.h"

Lista* criarLista() {
    Lista* l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
    return l;
}

void inserirInicio(Lista* l, TipoElemento elem) {
    No* novo = malloc(sizeof(No));
    novo->dado = elem;
    novo->ant = NULL;
    novo->prox = l->inicio;

    if (l->inicio)
        l->inicio->ant = novo;
    else
        l->fim = novo;

    l->inicio = novo;
    l->tamanho++;
}

void inserirFim(Lista* l, TipoElemento elem) {
    No* novo = malloc(sizeof(No));
    novo->dado = elem;
    novo->prox = NULL;
    novo->ant = l->fim;

    if (l->fim)
        l->fim->prox = novo;
    else
        l->inicio = novo;

    l->fim = novo;
    l->tamanho++;
}

int removerElemento(Lista* l, TipoElemento elem) {
    No* atual = l->inicio;
    while (atual && atual->dado != elem) {
        atual = atual->prox;
    }
    if (!atual) return 0;

    if (atual->ant)
        atual->ant->prox = atual->prox;
    else
        l->inicio = atual->prox;

    if (atual->prox)
        atual->prox->ant = atual->ant;
    else
        l->fim = atual->ant;

    free(atual);
    l->tamanho--;
    return 1;
}

void mostrarListaFrente(Lista* l) {
    No* atual = l->inicio;
    while (atual) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void mostrarListaTras(Lista* l) {
    No* atual = l->fim;
    while (atual) {
        printf("%d ", atual->dado);
        atual = atual->ant;
    }
    printf("\n");
}

void destruirLista(Lista* l) {
    esvaziarLista(l);
    free(l);
}

void esvaziarLista(Lista* l) {
    No* atual = l->inicio;
    while (atual) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}

int contarElementos(Lista* l) {
    return l->tamanho;
}

int obterPrimeiro(Lista* l, TipoElemento* elem) {
    if (l->inicio == NULL) return 0;
    *elem = l->inicio->dado;
    return 1;
}

int obterUltimo(Lista* l, TipoElemento* elem) {
    if (l->fim == NULL) return 0;
    *elem = l->fim->dado;
    return 1;
}

int obterElementoPosicao(Lista* l, int pos, TipoElemento* elem) {
    if (pos < 0 || pos >= l->tamanho) return 0;
    No* atual = l->inicio;
    for (int i = 0; i < pos; i++) {
        atual = atual->prox;
    }
    *elem = atual->dado;
    return 1;
}
