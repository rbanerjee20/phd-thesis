/*@
predicate (datatype seq) IntList (pointer p) {
    if (p == NULL) {
        return (Nil {});
    }
    else {
        take node = Owned<struct node>(p);
        take tl = IntList(node.next);
        return (Cons {hd: node.head, tl: tl});
    }
}
@*/
struct node {
  int head;
  struct node* next;
};

/*@ 
datatype seq {
    Nil {},
    Cons {i32 hd, datatype seq tl}
}
@*/