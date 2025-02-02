#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "time.h"

#define TRUE 1
#define FALSE 0

typedef struct {
    char nome[30];
    int anoFundacao;
    float numTorcedores;
} timeInfo;

int cmp(void *a, void *b) {
    timeInfo *timeA = (timeInfo *)a;
    timeInfo *timeB = (timeInfo *)b;

    if (timeA != NULL && timeB != NULL) {
        if (strcmp(timeA->nome, timeB->nome) == 0 &&
            timeA->anoFundacao == timeB->anoFundacao &&
            fabs(timeA->numTorcedores - timeB->numTorcedores) < 0.0001) {
            return 1; // Iguais
        }
        return 0; // Diferentes
    }
    return -1; // Caso algum ponteiro seja NULL
}

int main() {
    TimeList *colecao = NULL;
    int opcao;

    while (1) {
        printf("\n=============================");
        printf("\n1 - Criar uma nova colecao");
        printf("\n2 - Inserir elementos");
        printf("\n3 - Listar elementos");
        printf("\n4 - Consultar elemento");
        printf("\n5 - Remover elemento");
        printf("\n6 - Limpar colecao");
        printf("\n7 - Sair");
        printf("\n=============================");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 7) {
            printf("Saindo...\n");
            break;
        }

        switch (opcao) {
            case 1:
                colecao = timeCreate();
                printf("Colecao criada com sucesso!\n");
                break;

            case 2:
                if (colecao == NULL) {
                    printf("Erro: Crie a colecao primeiro.\n");
                    break;
                }
                timeInfo *novoTime = (timeInfo *)malloc(sizeof(timeInfo));
                if (novoTime == NULL) {
                    printf("Erro ao alocar memoria para o novo time.\n");
                    break;
                }
                printf("Digite o nome do time: ");
                scanf(" %[^]", novoTime->nome);
                printf("Digite o ano de fundacao: ");
                scanf("%d", &novoTime->anoFundacao);
                printf("Digite o numero de torcedores: ");
                scanf("%f", &novoTime->numTorcedores);

                if (tadInsert(colecao, novoTime)) {
                    printf("Time adicionado com sucesso!\n");
                } else {
                    printf("Erro: Nao foi possivel adicionar o time.\n");
                    free(novoTime);
                }
                break;

            case 3:
                if (colecao == NULL || colecao->first == NULL) {
                    printf("Erro: Colecao vazia ou inexistente.\n");
                } else {
                    void **times = tadList(colecao);
                    if (times == NULL) {
                        printf("Erro ao listar os times.\n");
                        break;
                    }
                    int size = 0;
                    Time *atual = colecao->first;
                    while (atual != NULL) {
                        size++;
                        atual = atual->next;
                    }
                    for (int i = 0; i < size; i++) {
                        timeInfo *time = (timeInfo *)times[i];
                        printf("[%d] Nome: %s, Ano: %d, Torcedores: %.2f milhoes\n",
                               i + 1, time->nome, time->anoFundacao, time->numTorcedores);
                    }
                    free(times);
                }
                break;

            case 4:
                if (colecao == NULL || colecao->first == NULL) {
                    printf("Erro: Colecao vazia ou inexistente.\n");
                } else {
                    timeInfo busca;
                    printf("Digite o nome do time: ");
                    scanf(" %[^]", busca.nome);
                    printf("Digite o ano de fundacao: ");
                    scanf("%d", &busca.anoFundacao);
                    printf("Digite o numero de torcedores: ");
                    scanf("%f", &busca.numTorcedores);

                    timeInfo *resultado = (timeInfo *)tadQuery(colecao, &busca, cmp);
                    if (resultado != NULL) {
                        printf("Time encontrado: Nome: %s, Ano: %d, Torcedores: %.2f milhoes\n",
                               resultado->nome, resultado->anoFundacao, resultado->numTorcedores);
                    } else {
                        printf("Time nao encontrado.\n");
                    }
                }
                break;

            case 5:
                if (colecao == NULL || colecao->first == NULL) {
                    printf("Erro: Colecao vazia ou inexistente.\n");
                } else {
                    timeInfo remove;
                    printf("Digite o nome do time: ");
                    scanf(" %[^]", remove.nome);
                    printf("Digite o ano de fundacao: ");
                    scanf("%d", &remove.anoFundacao);
                    printf("Digite o numero de torcedores: ");
                    scanf("%f", &remove.numTorcedores);

                    if (tadRemove(colecao, &remove, cmp)) {
                        printf("Time removido com sucesso.\n");
                    } else {
                        printf("Time nao encontrado.\n");
                    }
                }
                break;

            case 6:
                if (colecao != NULL) {
                    esvaziaTad(colecao);
                    printf("Colecao esvaziada.\n");
                } else {
                    printf("Erro: Colecao nao existe.\n");
                }
                break;

            default:
                printf("Opcao invalida!\n");
        }
    }

    if (colecao != NULL) {
        tadDestroy(colecao);
    }

    return 0;
}

