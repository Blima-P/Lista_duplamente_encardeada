
#include <stdio.h>
#include "lista-duplamente-encadeada.h"

int main() {
    Lista* l = criarLista();

    inserirFim(l, 10);
    inserirFim(l, 20);
    inserirInicio(l, 5);
    inserirFim(l, 30);

    printf("Frente: ");
    mostrarListaFrente(l);

    printf("Verso reversa: ");
    mostrarListaTras(l);

    removerElemento(l, 10);
    printf("Após remover 10: ");
    mostrarListaFrente(l);

    TipoElemento val;
    printf("Tamanho: %d\n", contarElementos(l));
    if (obterPrimeiro(l, &val)) printf("Primeiro: %d\n", val);
    if (obterUltimo(l, &val)) printf("Último: %d\n", val);
    if (obterElementoPosicao(l, 1, &val)) printf("Posição 1: %d\n", val);

    esvaziarLista(l);
    printf("Após esvaziar, tamanho: %d\n", contarElementos(l));

    destruirLista(l);
    return 0;
}
