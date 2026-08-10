struct int_list {
  int head;
  struct int_list* tail;
};

struct int_list* IntList_append(struct int_list* xs, struct int_list* ys)
/*@ requires take L1 = IntList(xs);
             take L2 = IntList(ys);
    ensures take L3 = IntList(return);
            L3 == append(L1, L2); @*/
{
    if (xs == 0) {
        return ys;
    }    
    struct int_list* curr = xs;
    while (curr->tail != 0) {
        curr = curr->tail;
    }
    curr->tail = ys; 
    return xs; 
}