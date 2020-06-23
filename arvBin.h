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

#endif //ARVORE_ARVBIN_H
