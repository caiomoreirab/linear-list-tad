# 📌 TAD Lista Encadeada - Time de Futebol

## 📖 Descrição do Projeto
Este projeto implementa um **Tipo Abstrato de Dados (TAD) Lista Encadeada para Times de Futebol**, fornecendo uma API para manipulação de uma coleção de times. O programa permite criar, inserir, remover, consultar, listar e destruir a coleção de forma eficiente, utilizando uma estrutura de lista simplesmente encadeada.

## 🖥️ Ambiente de Execução
- **🖥️ Sistema Operacional:** Windows
- **🛠️ Compilador:** GCC

## 📌 Estrutura de Dados
A estrutura utilizada no projeto contém os seguintes campos:
- **⚽ char[30]** - Nome do time de futebol.
- **📅 int** - Ano de fundação do time.
- **👥 float** - Número de torcedores (em milhões).

## ⚙️ Funcionalidades Implementadas
A API do TAD Lista Encadeada de Times de Futebol contém as seguintes operações:
- ✅ **Criar uma coleção de times**
- ✅ **Inserir um time** na coleção
- ✅ **Remover um time** identificado pelo `char`, `int` e `float`
- ✅ **Consultar um time** na coleção pelo `char`, `int` e `float`
- ✅ **Listar todos os times** da coleção
- ✅ **Esvaziar a coleção**
- ✅ **Destruir a coleção** (se estiver vazia)

### ❗ Regras Importantes
- **⚠️ O arquivo `time.c` não pode conter `printf`, `scanf` ou similares** (todas as operações de entrada e saída devem ser feitas no programa principal).
- **📌 O trabalho é individual.**

## 🔄 Roteiro para Teste
1️⃣ Criar uma coleção de times.
2️⃣ Inserir três times na coleção.
3️⃣ Listar os times da coleção.
4️⃣ Consultar um dos times na coleção.
5️⃣ Remover o segundo time inserido na coleção.
6️⃣ Listar os times da coleção.
7️⃣ Esvaziar a coleção.
8️⃣ Listar os times da coleção.

## 📂 Estrutura do Projeto
O arquivo comprimido enviado para avaliação deve conter:
- 📄 `README.md` (este arquivo)
- 📌 `time.h` (arquivo de cabeçalho com a definição da API)
- 🖥️ `time.c` (implementação do TAD Lista Encadeada para Times de Futebol)
- 🎯 `main.c` (programa principal para testes e interação com o usuário)
- 🔧 Pasta do projeto: `TAD-Time`
- 🔧 Executável do programa (`.exe` para Windows)

## 🚀 Compilação e Execução
Para compilar e executar o programa manualmente via terminal:

```sh
# Compilar o programa
gcc -o programa main.c time.c -Wall

# Executar
./programa
```

## 👨‍💻 Autor
- **Nome:** Caio Moreira
- **Curso:** Estruturas de Dados I, Ciências da Computação - UFMA

