#include "linked_list_def.h"

struct node* list_append(struct node* xs, struct node* ys)
{
    if (xs == 0) {
        return ys;
    }    
    struct node* curr = xs;
    while (curr->next != 0) {
        curr = curr->next;
    }
    curr->next = ys; 
    return xs; 
}