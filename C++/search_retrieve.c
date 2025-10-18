// search_retrieve.c
#include "search_retrieve.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
BSTNode* newNode(const char* key){
    BSTNode *n=(BSTNode*)malloc(sizeof(BSTNode));
    strcpy(n->key,key); n->left=n->right=NULL; return n;
}
BSTNode* insert(BSTNode* root,const char* key){
    if(!root) return newNode(key);
    if(strcmp(key,root->key)<0) root->left=insert(root->left,key);
    else if(strcmp(key,root->key)>0) root->right=insert(root->right,key);
    return root;
}
int search(BSTNode* root,const char* key){
    if(!root)return 0;
    if(strcmp(key,root->key)==0) return 1;
    else if(strcmp(key,root->key)<0) return search(root->left,key);
    else return search(root->right,key);
}
void inorderBst(BSTNode* root){
    if(root){ inorderBst(root->left); printf("%s\n",root->key); inorderBst(root->right);}
}
