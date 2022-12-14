#ifndef LIST_H 
#define LIST_H 
#include <stdlib.h>
#include <stdio.h>
#include "base.h"
typedef struct node node;
typedef struct node {
        node* next;
        void* data;
} node;
typedef struct list {
        base_t base;
        size_t n;
        node* head;
        node* tail;
} list;
typedef unsigned char byte;
typedef enum list_error_t {
        NO_MEMORY,
        NULL_LIST,
        NULL_FUNC,
        CHAR_ERROR,
} list_error_t;
void check_list_errors();
list* calloc_list();
list* create_list(void* arr, size_t n, size_t size, copy_t copy);
void proces_list(list* cont, f_t f);
void insert_list(list* cont, void* data);
void free_list(list* cont);
// list_up
void print_list(list* cont);
#endif