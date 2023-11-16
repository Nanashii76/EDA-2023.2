#include <stdio.h>
#include <stdlib.h>

// criando o tipo de lista base inteiro
typedef struct simple_node {
    int val;
    struct simple_node *next;
} SimpleNode;

// Nó inicial da lista (HEAD)
typedef struct linked_list {
    SimpleNode *begin;
} LinkedList;

// Função para criar uma nova lista

// criar um novo nó
SimpleNode *SimpleNode_create(int val){
    SimpleNode *simpleNode = (SimpleNode*)calloc(1,sizeof(SimpleNode));
    simpleNode->val = val;
    simpleNode->next = NULL;
}

//criar um cabeçalho HEAD
LinkedList *LinkedList_create(){
    LinkedList *new = (LinkedList*)malloc(sizeof(LinkedList)); 
    new->begin = NULL;

    return new;
}





