#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    int size;
    Node *head;
} List;

void initList(List *list);

// index == -1 means add as the last element
void insert_node(List *list, int data, int index);

// index == -1 means delete the last element
void delete_node(List *list, int index);

void print_list(List *list);

void free_list(List *list);

Node *getNode(List *list, int index);

int main() {
    List *list = malloc(sizeof(List));
    initList(list);

    insert_node(list, 1, -1);
    insert_node(list, 6, -1);
    insert_node(list, 7, -1);

    delete_node(list, 0);
    delete_node(list, -1);

    print_list(list);

    free_list(list);
    free(list);
    return 0;
}

void initList(List *list) {
    list->head = NULL;
    list->size = 0;
}

Node *getNode(List *list, int index) {
    if (index >= list->size || index < 0) {
        return NULL;
    }

    Node *cur = list->head;
    for (int i = 0; i < index; ++i) {
        cur = cur->next;
    }
    return cur;
}

void insert_node(List *list, int data, int index) {
    // index == -1 means add as the last element
    if (index == -1) index = list->size;
    if (index < 0 || index > list->size) {
        return;
    }

    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;

    } else {
        Node *push_after = getNode(list, index - 1);
        new_node->next = push_after->next;
        push_after->next = new_node;

    }
    ++(list->size);

}

void delete_node(List *list, int index) {
    // index == -1 means delete the last element
    if (index == -1) index = list->size - 1;
    if (index < 0 || index >= list->size) {
        return;
    }

    --(list->size);

    if (index == 0) {
        Node *first = list->head;
        list->head = list->head->next;
        free(first);
    } else {
        Node *prev = getNode(list, index - 1);
        Node *delete = prev->next;
        Node *next = delete->next;

        prev->next = next;
        free(delete);
    }
}

void print_list(List *list) {
    Node *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void free_list(List *list) {
    Node *cur = list->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}