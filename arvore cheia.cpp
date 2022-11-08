#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int chave;
    struct Node *esquerda, *direita;
};

struct Node *novoNo(char k){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->chave = k;
    node->direita = node->esquerda = NULL;
    return node;
}

bool arvoreCheia (struct Node* root){
    if (root == NULL)
        return true;

    if (root->esquerda == NULL && root->direita == NULL)
        return true;

    if ((root->esquerda) && (root->direita))
    return (arvoreCheia(root->esquerda) && arvoreCheia(root->direita));
    
    return false;
}

int main(){
    struct Node* root = NULL;
    root = novoNo(10);
    root->esquerda = novoNo(20);
    root->direita = novoNo(30);
    
    root->esquerda->direita = novoNo(40);
    root->esquerda->esquerda = novoNo(50);
    root->direita->esquerda = novoNo(60);
    root->direita->direita = novoNo(70);
    
    root->esquerda->esquerda->esquerda = novoNo(80);
    root->esquerda->esquerda->direita = novoNo(90);
    root->esquerda->direita->esquerda = novoNo(80);
    root->esquerda->direita->direita = novoNo(90);
    root->direita->esquerda->esquerda = novoNo(80);
    root->direita->esquerda->direita= novoNo(90);
    root->direita->direita->esquerda = novoNo(80);
    root->direita->direita->direita = novoNo(90);
    
    if (arvoreCheia(root))
        printf("arvore binaria cheia");
    else
        printf("a arvore nao cheia");
    
    return (0);
}    
