/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: rafael
 *
 * Created on 14 de Abril de 2017, 09:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

typedef struct node {
    struct node * left;
    char val;
    struct node * right;
} NODE;

struct node *root;
struct node *alloc;

void insert (char *val) {
    alloc = (struct node *) malloc(sizeof(struct node));
    
    if(!alloc) {
        printf("A memoria disponivel nao foi suficiente."); 
        exit(0);
    }
    strcpy(alloc->val, val);
    
    if(!root) { //Primeiro elemento na arvore, o elemento inserdo se torna raiz
        root = alloc;
    }else {
       struct node *pointer; 
       struct node *lastPointer;
       pointer = root;
       lastPointer = NULL;
       
       while (pointer) { //Procura um lugar para inserir o novo no
           lastPointer = pointer;
           if (strcmp(val, pointer->val) > 0) {
               pointer = pointer->right;
           }else {
               pointer = pointer->left;
           }
       }
       
       if (lastPointer->right == NULL) {
              lastPointer->right = alloc; 
              //o elemento que alocado vai para o ponteiro da direita do elemento anterior
            }  
       else if (lastPointer->left == NULL){
              lastPointer->left = alloc; 
              //o elemento que alocado vai para o ponteiro da esquerda do elemento anterior
            }
    }
    
}

NODE* insert2(char *val, struct node * rootP) {
    alloc = (struct node *)malloc(sizeof(struct node));
    if (!rootP) {
        alloc->val = val;
        alloc->left = NULL;
        alloc->right = NULL;
        root = alloc;
        printf("UAHUSHAUS");
    } else if(alloc->left == NULL) {
        alloc->left = insert2(val, alloc->left);
    } else {
        alloc->right = insert2(val, alloc->right);
    }
}


void inOrder(struct node *pointer) {
    
    if (pointer) { 
        
        inOrder(pointer->left);
        printf("\n%s", pointer->val);
        inOrder(pointer->right);
    }
}
//
//void postOrder(struct node *pointer) {
//    if (pointer) {   
//        postOrder(pointer->left);
//        postOrder(pointer->right);
//        printf("\n%s", pointer->val);
//    }
//}

int main(int argc, char** argv) {
    struct node * node;
    int n, count;
    node = (struct node *) malloc(sizeof(struct node));
//    root = NULL;
    printf("Entre com o tamanho da notacao: ");
    scanf("%d", &n);
    char expression[n];
    for (count = 0; count < n; count++) { 
        printf("Digite o elemento da notacao: ");
        scanf("%s", expression);
        insert2(expression, root);
        printf("%s \n", expression);
    }
    printf("EM ORDEM\n");
    inOrder(root);
//    printf("POS ORDEM\n");
//    postOrder(root);
//    buscar(root);
    
    return (EXIT_SUCCESS);
}

