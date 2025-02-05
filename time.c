/*******************************************************
* Arquivo: time.c (Implementação)
* Descrição: Implementação das funções do  TAD Lista Linear Simplesmente Encadeada (SLList)
* 
* Autor: Caio Bandeira Moreira
* Curso: Estrutura de Dados 1
* Professor: Anselmo Cardoso de Paiva
* Data: Fevereiro/2025
*******************************************************/
#include "time.h"
#include <stdlib.h>
#include <string.h>  // Para memcpy()
#define TRUE 1
#define FALSE 0


// Função para criar a lista
TimeList *timeCreate() {
    TimeList *l = (TimeList *)malloc(sizeof(TimeList));
    if (l != NULL) {
        l->first = NULL;
    }
    return l;
}

// Função para destruir a lista
int tadDestroy(TimeList *l) {
    if (l != NULL && l->first == NULL) {
        free(l);
        return TRUE;
    }
    return FALSE;
}

// Função para inserir um item na lista
int tadInsert(TimeList *l, void *data) {
    if (l != NULL) {
        Time *newnode = (Time *)malloc(sizeof(Time));
        if (newnode != NULL) {
            timeInfo *novoTime = (timeInfo *)malloc(sizeof(timeInfo));
            if (novoTime == NULL) {
                free(newnode);
                return FALSE;
            }
            memcpy(novoTime, data, sizeof(timeInfo));

            newnode->data = novoTime;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

// Função para consultar um item na lista
void *tadQuery(TimeList *l, void *data, int (*cmp)(void *, void *)) {
    if (l != NULL && l->first != NULL && data != NULL && cmp != NULL) {
        Time* atual = l->first;
        while (atual != NULL) {           
            if (cmp(atual->data, data) == 1) {  
                return atual->data;
            }
            atual = atual->next; 
        }
    }
    return NULL; 
}

// Função para remover um item da lista
int tadRemove(TimeList *l, void *data, int (*cmp)(void *, void *)) {
    if (l != NULL && l->first != NULL && data != NULL && cmp != NULL) {
        Time* atual = l->first;
        Time *anterior = NULL;

        while (atual != NULL) {
            if (cmp(atual->data, data) == 1) {  
                if (anterior == NULL) {
                    l->first = atual->next;
                } else {
                    anterior->next = atual->next;
                }
                free(atual->data);
                free(atual);
                return 1;
            }
            anterior = atual;
            atual = atual->next;
        }
    }
    return 0;
}

// Função para listar os elementos
void **tadList(TimeList *l) {
    if (l != NULL && l->first != NULL) {
        Time* atual = l->first;
        int cont = 0;
        while (atual != NULL) {
            cont++;
            atual = atual->next;
        }

        void **times = (void **)malloc(cont * sizeof(void *));
        if (times == NULL) {
            return NULL;
        }

        atual = l->first;
        for (int i = 0; i < cont; i++) {
            times[i] = atual->data;
            atual = atual->next;
        }
        return times;
    }
    return NULL;
}

// Função para esvaziar a lista
int esvaziaTad(TimeList *l) {
    if (l == NULL) return 0;
    Time* atual = l->first;
    while (atual != NULL) {
        Time* temp = atual;
        atual = atual->next;
        free(temp->data);
        free(temp);
    }
    l->first = NULL;
    return 1;
}
