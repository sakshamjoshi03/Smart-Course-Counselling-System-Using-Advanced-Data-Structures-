// search_retrieve.h
#define BST_KEY_LEN 100
typedef struct BSTNode{
    char key[BST_KEY_LEN]; struct BSTNode *left,*right;
}BSTNode;
BSTNode* newNode(const char* key);
BSTNode* insert(BSTNode* root,const char* key);
int search(BSTNode* root,const char* key);
void inorderBst(BSTNode* root);
