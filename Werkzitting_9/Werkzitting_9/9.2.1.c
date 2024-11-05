#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node* left;
    Node* right;
};

void addChild(Node* parent, Node* child) {

    if (parent->data > child->data) {
        if (parent->left != NULL) {
            addChild(parent->left, child);
        }
        else {
            parent->left = child;
        }
    }
    else {
        if (parent->right != NULL) {
            addChild(parent->right, child);
        }
        else {
            parent->right = child;
        }
    }
}

void printTree(Node* root, int depth) {
    if (root == NULL) {
        return;
    }
    int newDepth = depth + 1;
    printTree(root->right, newDepth);
    printf("Depth: %d | Data: %d \n", depth, root->data);
    printTree(root->left, newDepth);
}

void explodeChild(Node* root, Node* victim) {
    if (root == NULL) {
        return;
    }

    while(root->data != victim->data){
        if (victim->data > root->data){
            root = root->right;
        }
        else {
            root = root->right;
        }
    }
    if (root->data == victim->data) {
        explodeChild(victim->left, victim->left);
        explodeChild(victim->right, victim->right);
        free(victim);
    }
}


Node* makeNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    return node;
}


int main() {
    Node* node1 = makeNode(10);
    Node* node2 = makeNode(20);
    Node* node3 = makeNode(30);
    Node* root = makeNode(40);
    Node* node5 = makeNode(50);
    Node* node6 = makeNode(60);

    addChild(root, node3);
    addChild(root, node5);
    addChild(root, node2);
    addChild(root, node6);
    addChild(root, node1);

    printTree(root, 0);

    explodeChild(root, node5);
    printTree(root, 0);
    return 1;
}