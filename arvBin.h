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

#endif //ARVORE_ARVBIN_H
