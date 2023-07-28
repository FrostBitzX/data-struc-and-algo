#include <stdio.h>
#include <stdlib.h>

typedef struct header {
    int n;
    struct node* last;
    struct node* first;
}header;

typedef struct node {
    int data;
    struct node* next;
} node;

int main() {
    header* head = malloc(sizeof(header));
    head->n = 0;
    node* first = malloc(sizeof(node));
    first->data = 1;
    first->next = NULL;
    head->first = first;
    head->last = first;
    head->n++;

    node* second = malloc(sizeof(node));
    second->data = 2;
    first->next = second;
    second->next = NULL;
    head->last = second;
    head->n++;

    return 0;
}