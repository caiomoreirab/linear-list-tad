/*******************************************************
* Arquivo: time.h (Header)
* Descrição: Declaração das funções do TAD Lista Linear Simplesmente Encadeada (SLList)
* 
* Autor: Caio Bandeira Moreira
* Curso: Estrutura de Dados 1
* Professor: Anselmo Cardoso de Paiva
* Data: Fevereiro/2025
*******************************************************/
#ifndef TIME_H
#define TIME_H

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Definição da estrutura que armazena informações dos times
typedef struct {
    char nome[30];
    int anoFundacao;
    float numTorcedores;
} timeInfo;

// Definição da estrutura de um nó da lista encadeada
typedef struct Time {
    void* data;
    struct Time* next;
} Time;

// Definição da estrutura da lista encadeada
typedef struct {
    Time* first;
} TimeList;

// Protótipos das funções do TAD
TimeList *timeCreate();
int tadInsert(TimeList *l, void *data);
void *tadQuery(TimeList *l, void *data, int (*cmp)(void *, void *));
int tadRemove(TimeList *l, void *data, int (*cmp)(void *, void *));
void **tadList(TimeList *l);
int esvaziaTad(TimeList *l);
int tadDestroy(TimeList *l);

#endif
