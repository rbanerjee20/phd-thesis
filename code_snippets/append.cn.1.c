#include "linked_list_def.h"

/*@
datatype seq {
    Nil {},
    Cons {i32 hd, datatype seq tl}
}

predicate [rec] (datatype seq) IntList (pointer p) {
    if (p == NULL) {
        return (Nil {});
    }
    else {
        take node = Owned<struct node>(p);
        take tl = IntList(node.next);
        return (Cons {hd: node.val, tl: tl});
    }
}
@*/

struct node* list_append(struct node* xs, struct node* ys)
/*@ requires take l1 = IntList(xs);
             take l2 = IntList(ys); @*/
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