#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Geheugenallocatie mislukt\n");
        exit(1);
    }
    newNode->data = _strdup(data);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToSortedList(struct Node** head, char* data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && strcmp(current->data, data) < 0) {
        current = current->next;
    }

    if (strcmp(current->data, data) >= 0) {
        if (current->prev == NULL) {
            newNode->next = current;
            current->prev = newNode;
            *head = newNode;
        }
        else {
            newNode->prev = current->prev;
            current->prev->next = newNode;
            newNode->next = current;
            current->prev = newNode;
        }
    }
    else {
        current->next = newNode;
        newNode->prev = current;
    }
}

void removeDuplicates(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->data, current->next->data) == 0) {
            struct Node* duplicate = current->next;
            current->next = duplicate->next;
            if (duplicate->next != NULL) {
                duplicate->next->prev = current;
            }
            free(duplicate->data);
            free(duplicate);
        }
        else {
            current = current->next;
        }
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    char* strings[] = { "b", "o", "o", "b", "i", "e", "s"};

    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); ++i) {
        addToSortedList(&head, strings[i]);
    }

    printf("Originele lijst: ");
    printList(head);

    removeDuplicates(&head);

    printf("Lijst zonder duplicaten: ");
    printList(head);

    freeList(head);

    return 0;
}
