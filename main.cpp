#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include "arvBin.h"

using namespace std;

int main() {
    arvBin **ptrRaiz;
    int escolha = 1;

    while (escolha != 0) {
        printf("Escolha a opção:");
        scanf("%d ", &escolha);
        switch (escolha) {
            case 0: {
                printf("Adeus.\n");
            }
                break;
            case 1: {
                printf("struct arvBin{\n");
                printf("\tint chave;\n\tarvBin *esq, *dir;\n}\n");
            }
                break;
            case 2: {
                if (ptrRaiz != NULL) {
                    printf("Arvore ja inicializada!\n");
                } else {
                    ptrRaiz = iniciaArv();
                    printf("Arvore inicializada com sucesso!\n");
                }
            }
                break;
        }
    }

    return 0;
}

