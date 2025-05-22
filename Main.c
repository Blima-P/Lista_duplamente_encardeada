#include <stdio.h>
#include "lista.h"

int main() {
    Lista* l = criarLista();

    inserirOrdenado(l, 10);
    inserirOrdenado(l, 20);
    inserirOrdenado(l, 30);
    inserirOrdenado(l, 5);
    inserirOrdenado(l, 15);

    mostrarLista(l);

    TipoElemento valor;
    if (acessarElemento(l, 2, &valor)) {
        printf("Elemento na posição 2: %d\n", valor);
    }

    removerNaPosicao(l, 1);
    mostrarLista(l);

    destruirLista(l);
    return 0;
}
