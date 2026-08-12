#define __CN_INSTRUMENT
#include <cn-executable/utils.h>
#include <cn-executable/cerb_types.h>

struct node {
  signed int val;
  struct node* next;
};

/* CN VERSIONS OF C STRUCTS */
struct node_cn {
  cn_bits_i32* val;
  cn_pointer* next;
};

/* CN DATATYPES */
enum seq_tag {
  NIL,
  CONS
};

struct nil { ; };

struct cons {
  struct seq* tl;
  cn_bits_i32* hd;
};

union seq_union {
  struct nil* nil;
  struct cons* cons;
};

struct seq {
  enum seq_tag tag;
  union seq_union u;
};

/* CN PREDICATES */

static struct seq* IntList(cn_pointer* p, enum spec_mode, ...)
{
  if (convert_from_cn_bool(cn_pointer_equality(p, convert_to_cn_pointer(0)))) {
    struct seq* a_621 = (struct seq*) cn_bump_malloc(sizeof(struct seq));
    a_621->tag = NIL;
    return a_621;
  }
  else {
    struct node_cn* node = owned_struct_node(p, spec_mode, ...);
    struct seq* tl = IntList(node->next, spec_mode, ...);
    struct seq* a_633 = (struct seq*) cn_bump_malloc(sizeof(struct seq));
    a_633->tag = CONS;
    a_633->u.cons = (struct cons*) cn_bump_malloc(sizeof(struct cons));
    a_633->u.cons->hd = node->val;
    a_633->u.cons->tl = tl;
    return a_633;
  }
}

/*
for all datatypes and CN structs
- default value functions
- map get functions (that use default value functions)
- bespoke equality functions

for all user-defined C types
- conversion functions to and from C type
- deref and owned functions

rest defined in runtime library
*/
