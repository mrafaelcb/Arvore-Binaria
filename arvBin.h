//
// Created by Mayco on 23/06/2020.
//

#ifndef ARVORE_ARVBIN_H
#define ARVORE_ARVBIN_H

#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

/**
 * Estrutura da Árvore
 */
struct arvBin {
    int chave;
    arvBin *esq, *dir;
};

/**
 * Função responsável por iniciar à árvore
 *
 * @return arvBin
 */
arvBin **iniciaArv() {
    arvBin **ptrRaiz = new arvBin *;
    if (*ptrRaiz != NULL) {
        *ptrRaiz = NULL;
    }

    return ptrRaiz;
}

/**
 * Função responsável por verificar se à árvore está alocada
 *
 * @param **ptrRaiz
 * @return true|false
 */
bool isAlocada(arvBin **ptrRaiz) {
    if (ptrRaiz == NULL) {
        return false;
    } else {
        return true;
    }
}

/**
 * Função responsável por verificar se à árvore está vazia
 *
 * @param **ptrRaiz
 * @return true|false
 */
bool isVazia(arvBin **ptrRaiz) {
    if (isAlocada(ptrRaiz)) {
        if (*ptrRaiz == NULL) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

/**
 * Função responsável por adicionar nó na árvore
 *
 * @param **ptrRaiz
 * @param valor
 * @return true|false
 */
bool adicionarNoArv(arvBin **ptrRaiz, int valor) {
    arvBin *novoNo = new arvBin;

    if (novoNo == NULL || !isAlocada(ptrRaiz)) {
        return false;
    }

    novoNo->chave = valor;
    novoNo->dir = NULL;
    novoNo->esq = NULL;

    if (*ptrRaiz == NULL) {
        *ptrRaiz = novoNo;
        
        return true;
    } else {
        arvBin *atualNo = *ptrRaiz;
        arvBin *anteriorNo = NULL;
        while (atualNo != NULL) {
            anteriorNo = atualNo;

            if (valor == atualNo->chave) {
                delete novoNo;

                return false;
            }

            if (valor > atualNo->chave) {
                atualNo = atualNo->dir;
            } else {
                atualNo = atualNo->esq;
            }
        }

        if (valor > anteriorNo->chave) {
            anteriorNo->dir = novoNo;

        } else {
            anteriorNo->esq = novoNo;
        }

        return true;
    }
}

/**
 * Função responsável por imprimir a árvore em ordem
 *
 * @param *ptrRaiz
 */
void imprimirEmOrdem(arvBin *ptrRaiz) {
    if (ptrRaiz != NULL) {
        imprimirEmOrdem(ptrRaiz->esq);
        printf(" %d", ptrRaiz->chave);
        imprimirEmOrdem(ptrRaiz->dir);
    }
}

/**
 * Função responsável por retornar maior valor da árvore
 *
 * @param *ptrRaiz
 * @param numero
 * @return int
 */
int maiorNumeroArv(arvBin *ptrRaiz) {
    arvBin *aux = new arvBin;
    aux = ptrRaiz;
    int numero = 0;

    while (aux != NULL) {
        if (numero < aux->chave) {
            numero = aux->chave;
            aux = aux->dir;
            if (aux == NULL) {
                return numero;
            }
        }
    }
}

/**
 * Função responsável por retornar menor valor da árvore
 *
 * @param *ptrRaiz
 * @param numero
 * @return int
 */
int menorNumeroArv(arvBin *ptrRaiz) {
    arvBin *aux = new arvBin;
    aux = ptrRaiz;
    int numero = aux->chave;

    while (aux != NULL) {
        if (numero >= aux->chave) {
            numero = aux->chave;
            if (aux->esq == NULL) {
                return numero;
            }
        }
        aux = aux->esq;
    }
}

/**
 * Função responsável por retornar a altura da árvore
 *
 * @param ptrRaiz
 * @return
 */
int alturaArv(arvBin *ptrRaiz) {
    int alturaEsquerda, alturaDireita;

    if (ptrRaiz == NULL) {
        return 0;
    }

    alturaEsquerda = alturaArv(ptrRaiz->esq);
    alturaDireita = alturaArv(ptrRaiz->dir);

    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}

void menu(){
    printf("==============================================\n");
    printf("\t0 - Sair.\n");
    printf("\t1 - Struct da Árvore.\n");
    printf("\t2 - Alocação da árvore.\n");
    printf("\t3 - Verificação se a árvore foi alocada.\n");
    printf("\t4 - Verificação se a árvore está vazia.\n");
    printf("\t5 - Adicionar um novo nó na árvore.\n");
    printf("\t6 - Imprimir nós da árvore em ordem.\n");
    printf("\t7 - Imprimir nó com maior valor da árvore.\n");
    printf("\t8 - Imprimir nó com menor valor da árvore.\n");
    printf("\t9 - Imprimir altura da árvore.\n");
    printf("==============================================\n");
}

#endif //ARVORE_ARVBIN_H
