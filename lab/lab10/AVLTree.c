#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* ins(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data >= root->data) {
        root->right = ins(root->right, data);
    } else {
        root->left = ins(root->left, data);
    }

    return root;
}

int max(int x, int y) { 
   return (x >= y) ? x : y;
}

int height(struct Node* node) {
    if(node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right ));
}

int AVL(struct Node *root) {
    int lh;
    int rh;

    if (root == NULL)
        return 1;

    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && AVL(root->left) && AVL(root->right)) 
     return 1;

   return 0;
}

int main() {
    struct Node* root = NULL;
    int n, data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = ins(root, data);
    }

    printf("%s", AVL(root) ? "YES" : "NO");

    return 0;
}