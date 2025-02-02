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

#include <stdlib.h>

// Constantes para representar valores lógicos
#define TRUE 1
#define FALSE 0

// Estrutura para o TAD Time
typedef struct {
    void* data;
    struct Time* next;
} Time;

typedef struct {
    Time* first;  // Ponteiro para o primeiro nó
} TimeList;


// Função para criar o TAD Genérico
TimeList *timeCreate();

// Função para destruir o TAD
int tadDestroy(TimeList *l);

// Função para inserir um item no TAD
int tadInsert(TimeList *l, void *data);

// Função para consultar se o item está no TAD
void *tadQuery(TimeList *l, void *data, int (*cmp)(void *, void *));

// Função para remover um item do TAD
int tadRemove(TimeList *l, void *data, int (*cmp)(void *, void *));

// Função para listar os elementos na coleção
void **tadList(TimeList* l);

// Função para esvaziar a coleção
int esvaziaTad(TimeList *l);

#endif // TIME_H
