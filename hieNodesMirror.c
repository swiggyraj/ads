#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int height(struct Node* root) {
    if (root == NULL) {
        return -1; // Leaf node has height 0, hence returning -1 for leaf's child nodes
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void mirror(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Swap left and right subtrees recursively
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main() {
    struct Node* root = NULL;
    int numOfElements, data;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &numOfElements);

    printf("Enter the elements for BST insertion:\n");
    for (int i = 0; i < numOfElements; ++i) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Height of the BST: %d\n", height(root));
    printf("Total number of nodes in BST: %d\n", countNodes(root));

    printf("Mirror image of the BST: \n");
    mirror(root);
    // Display the mirror image
    // You can perform traversals or any other operation you need with the mirror image here

    return 0;
}