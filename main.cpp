#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <bits/stdc++.h>
#include "arvBin.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    arvBin **ptrRaiz;
    int escolha = 1;

    while (escolha != 0) {
        menu();
        printf("Escolha a opção: ");
        scanf("%d", &escolha);
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
                    printf("Árvore já inicializada.\n");
                } else {
                    ptrRaiz = iniciaArv();
                    printf("Árvore inicializada com sucesso.\n");
                }
            }
                break;
            case 3: {
                if (isAlocada(ptrRaiz)) {
                    printf("Árvore Alocada.\n");
                } else {
                    printf("Árvore não alocada.\n");
                }
            }
                break;
            case 4: {
                if (isVazia(ptrRaiz)) {
                    printf("Árvore está vazia.\n");
                } else {
                    printf("Árvore não está vazia.\n");
                }
            }
                break;
            case 5: {
                int valor;

                printf("Informe valor para o novo nó: ");
                scanf("%d", &valor);

                if (adicionarNoArv(ptrRaiz, valor)) {
                    printf("Nó adicionado com sucesso na árvore.\n");
                } else {
                    printf("Nó não adicionado na árvore.\n");
                }
            }
                break;
            case 6: {
                if (isAlocada(ptrRaiz)) {
                    if (!isVazia(ptrRaiz)) {
                        imprimirEmOrdem(*ptrRaiz);
                        printf("\n");
                    } else {
                        printf("Árvore está vazia.\n");
                    }
                } else {
                    printf("Árvore não alocada.\n");
                }
            }
                break;
            case 7: {
                if (isAlocada(ptrRaiz)) {
                    if (!isVazia(ptrRaiz)) {
                        printf("%d\n", maiorNumeroArv(*ptrRaiz));
                    } else {
                        printf("Árvore está vazia.\n");
                    }
                } else {
                    printf("Árvore não alocada.\n");
                }
            }
                break;
            case 8: {
                if (isAlocada(ptrRaiz)) {
                    if (!isVazia(ptrRaiz)) {
                        printf("%d\n", menorNumeroArv(*ptrRaiz));
                    } else {
                        printf("Árvore está vazia.\n");
                    }
                } else {
                    printf("Árvore não alocada.\n");
                }
            }
                break;
            case 9: {
                if (isAlocada(ptrRaiz)) {
                    if (!isVazia(ptrRaiz)) {
                        printf("%d\n", alturaArv(*ptrRaiz));
                    } else {
                        printf("Árvore está vazia.\n");
                    }
                } else {
                    printf("Árvore não alocada.\n");
                }
            }
                break;
        }
    }

    return 0;
}

