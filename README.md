# Algoritmos e Tipos Abstratos de Dados | Enunciado

## Lab 10 + Template | Avaliado

Este repositório foi criado a partir de:

- [https://github.com/estsetubal-atad/CProgram_Template](https://github.com/estsetubal-atad/CProgram_Template) 

Consulte o seu README se tiver dúvidas sobre a sua utilização.

----

**Objetivos**:

- Especificação e implementação de um ADT do género *coleção*: `ADT Deque`

**Referências**:

- *Tipos Abstratos de Dados, Linguagem C. Bruno Silva* (disponível no Moodle).

---

### Nível 1 (Duração estimada: 15min)

1. Conhecendo apenas a especificação do `ADT Deque`, complete o código no `main`, utilizando as operações de inserção para obter o seguinte estado para essa instância:

    - `<frente> 4, 6, 8, 13, 1, 7, 2 <cauda>`

2. Adicione o código necessário para mostrar o conteúdo do *deque* (i.e., `dequePrint`) e mostrar o seu tamanho (i.e., `dequeSize`)

    - Ainda não conseguirá testar o programa, pois as implementações existentes estão incompletas.

### Nível 2 (Duração estimada: 30min)

Neste nível vamo-nos focar na implementação do *ADT Deque* baseada em *array list* - ficheiro `dequeArrayList.c`. Se necessitar de suporte, pode consultar o livro, nomeadamente o Capítulo 3 que inclui todos os algoritmos necessários de manipulação desta estrutura de dados.

3. Finalize a implementação das operações `dequeCreate`, `dequeDestroy`, `dequeAddFront`, `dequeRemoveFront` e `dequeFront`.

    - Note que, nesta implementação, o elemento na **frente** do *deque* deverá encontrar-se no índice `0` do array de elementos; se olhar para o código existente, verá que o elemento na **cauda** do deque encontra-se no índice `size - 1`.

4. Compile o programa utilizando `make` ou `make arraylist` (veja o conteúdo do *makefile*). Teste o programa, verificando que os elementos inseridos encontram-se pela ordem pretendida no Nível 1. Caso contrário, verifique a sua implementação.

### Nível 3 (Duração estimada: 30min)

Neste nível vamo-nos focar na implementação do *ADT Deque* baseada em *linked list*  - ficheiro `dequeLinkedList.c`. Consulte o livro se necessário.

5. Finalize a implementação das operações `dequeCreate`, `dequeAddFront`, `dequeRemoveRear` e `dequeRear`.

    - Note que, nesta implementação, o elemento na **frente** do *deque* deverá encontrar-se no nó adjacente ao nó *header*. Contrariamente, a **cauda** estará no nó adjacente ao nó *trailer*.

6. Compile o programa utilizando `make linkedlist`. Teste o programa, verificando que os elementos inseridos encontram-se pela ordem pretendida no Nível 1. Caso contrário, verifique a sua implementação.

### Nível 4 (Duração estimada: 10min)

7. Chegado aqui, certamente notou uma diferença de *performance* entre estas duas implementações. Preencha a seguinte tabela, relativamente à complexidade algorítmica das operações implementadas, que o ajudará a entender o "porquê" - veja o código da função `stressTest`.

Operação           | Array List | Linked List
-------------------|------------|------------
`dequeAddFront`    | ?          | ?
`dequeAddRear`     | O(1)       | ?
`dequeRemoveFront` | ?          | ?
`dequeRemoveRear`  | O(1)       | ?

Por qual implementação optaria no "mundo real"?

### Nível 5 (Duração estimada: 15min)

8. Na implementação baseada em *linked list*, altere o código da função `dequeDestroy` de forma a que esta invoque internamente a função `dequeClear` para tratar da libertação de memória dos nós internos da lista ligada.

9. Compile com ambas as implementações e execute o programa através do *valgring* para verificar a correta gestão de memória dinâmica (heap).  
