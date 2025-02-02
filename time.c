/*******************************************************
* Arquivo: time.c (Implementação)
* Descrição: Implementação das funções do  TAD Lista Linear Simplesmente Encadeada (SLList)
* 
* Autor: Caio Bandeira Moreira
* Curso: Estrutura de Dados 1
* Professor: Anselmo Cardoso de Paiva
* Data: Fevereiro/2025
*******************************************************/


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    void* data;
    struct Time* next
} Time;

typedef struct {
    Time* first;  // Ponteiro para o primeiro nó
} TimeList;


// Função para criar o Tad List
TimeList *timeCreate() {
    TimeList *l;
    l = (TimeList *)malloc(sizeof(TimeList));
    if (l != NULL) {
        l->first = NULL;
        return l;
    }
    return NULL;
}


// Função para destruir o TAD;
int tadDestroy(TimeList *l) {
    if (l != NULL) {
        if (l->first == NULL) {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}


// Função para inserir um item no TAD
int tadInsert(TimeList *l, void *data) {
    if (l != NULL) {
        Time *newnode = (Time *)malloc(sizeof(Time));
        if (newnode != NULL) {
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode; 
            return TRUE;
        }
    }
    return FALSE;
}

// Função para consultar se o item está no TAD
void *tadQuery(TimeList *l, void *data, int (*cmp)(void *, void *)) {

    if (l != NULL && l->first != NULL && data != NULL && cmp != NULL) {

    Time* atual = l->first;  // Começa do primeiro nó
    while (atual != NULL) {           
         if (cmp(atual->data, data) == 1) { // Compara o item atual
                return atual->data; // Retorna o item encontrado
            }
            atual = atual->next; 
        }
    }
    return NULL; 
}


// Função para remover um item do TAD
int tadRemove(TimeList *l, void *data, int (*cmp)(void *, void *)) {
    int i = 0;
    if (l != NULL && l->first != NULL && data != NULL && cmp != NULL) {

        Time* atual = l->first;  // Começa do primeiro nó
        Time *anterior = NULL;

    while (atual != NULL) {
        // Compara o dado do nó atual com o dado a ser removido
        if (cmp(atual->data, data) == 1) { // Se os dados forem iguais
            if (anterior == NULL) {
                // Caso especial: estamos removendo o primeiro nó
                l->first = atual->next;
            } else {
                // Removendo um nó no meio ou final da lista
                anterior->next = atual->next;
            }
            free(atual->data);
            free(atual); // Libera o nó removido
            return 1; // Sucesso
        }
    }
        anterior = atual; // Atualiza o anterior
        atual = atual->next; // Avança para o próximo nó
    }

    return 0; // Retorna 0 se o elemento não foi encontrado
}


// Função para listar os elementos na coleção
void **tadList(TimeList *l) {
    if (l != NULL && l->first != NULL ) {

        Time* atual = l->first;
        int cont = 0;
        while(atual != NULL){
            cont ++;
            atual = atual-> next;
        }

        void **times = (void **)malloc(cont * sizeof(void *));
        if (times == NULL) {
        return NULL; // Falha na alocação de memória
        }

        atual = l->first;
        for (int i = 0; i < cont; i++) {
        times[i] = atual->data; // Armazena o ponteiro para o dado do nó
        atual = atual->next;
        }
        return times;
    }
    return NULL;
}


//Função para esvaziar a colecão
int esvaziaTad(TimeList *l) {
    if (l == NULL) {
        return 0;
    }
    Time* atual = l->first;  // Começa do primeiro nó
    while (atual != NULL) {       
    Time* temp = atual;  // Guarda referência do nó atual para liberar memória
    atual = atual->next; // Avança para o próximo nó
    free(temp);          // Libera o nó atual
    }
    l-> first = NULL;
    return 1;
}

