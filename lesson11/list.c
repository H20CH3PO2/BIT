#include "list.h"
#define tprint(A) \
{\
        static int b = 0;\
        b++;\
        printf("%s\n", A);\
}
void proces_error_list(list_error_t error)
{
        // LOGIC
}
void check_list_errors()
{
        if(sizeof(unsigned char) != 1) {
                proces_error_list(CHAR_ERROR);
                exit(CHAR_ERROR);
        }
}
list* calloc_list()
{
        list* res = calloc(1, sizeof(list));
        set_base(res, print_list, free_list, calloc_list, NULL);
        if (res == NULL) {
                proces_error_list(NO_MEMORY);
                return NULL;
        }
        return res;
}
list* create_list(void* arr, size_t n, size_t size, copy_t copy)
{
        if (arr == NULL || n == 0 || size == 0)
                return NULL;
        list* res = (list*) calloc_list();
        set_base(res, print_list, free_list, calloc_list, NULL);
        byte* byte_p = (byte*) arr;
        for (size_t i = 0; i < n; i++)
                insert_list(res, byte_p + i * size);
        return res;
}
void proces_list(list* cont, f_t f)
{
        if (cont == NULL) {
                proces_error_list(NULL_LIST);
                return;
        }
        node* elem = cont->head;
        while (elem != NULL)
        {
                f(elem->data);
                elem = elem->next;
        }
        
}
void free_list(list* cont)
{
        if (cont == NULL)
                return;
        node* elem = cont->head, *cur = NULL;
        while (elem)
        {
                cur = elem;
                elem = elem->next;
                free_base(cur->data); 
                free(cur);
        }
        free(cont);
}
void print_node(node* nod)
{
        print_base(nod->data);
}
void insert_list(list* cont, void* data)
{
        if (cont == NULL) {
                proces_error_list(NULL_LIST);
                return;
        }
        node* new_node = (node*) calloc(1, sizeof(node));
        new_node->data = copy_base(data);
        new_node->next = NULL;
        cont->n = cont->n + 1;
        // head = tail = NULL
        if (cont->head == NULL) {
                cont->head = new_node;
                cont->tail = new_node;
                return;
        }
        // head = tail != NULL
        if (cont->head == cont->tail) {
                cont->head->next = new_node;
                cont->tail = new_node;
                return;
        }
        // head != NULL, tail != NULL, head != tail
        cont->tail->next = new_node;
        cont->tail = new_node;
        return;
}
