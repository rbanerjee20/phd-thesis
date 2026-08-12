#define CN_INSTRUMENT
#include <cn-executable/cerb_types.h>
#include <cn-executable/utils.h>

struct node *list_append(struct node *xs, struct node *ys)
/*@ requires take l1 = IntList(xs);
             take l2 = IntList(ys); @*/
{
  struct node *__cn_ret;
  ghost_stack_depth_incr();
  cn_pointer *xs_cn = convert_to_cn_pointer(xs);
  cn_pointer *ys_cn = convert_to_cn_pointer(ys);
  /* EXECUTABLE CN PRECONDITION */
  struct seq *l1_cn = IntList(xs_cn, PRE, 0);
  struct seq *l2_cn = IntList(ys_cn, PRE, 0);

  /* C OWNERSHIP */
  c_add_to_ghost_state((&xs), sizeof(struct node *), get_cn_stack_depth());
  c_add_to_ghost_state((&ys), sizeof(struct node *), get_cn_stack_depth());

  if (CN_LOAD(xs) == 0) {
    { __cn_ret = CN_LOAD(ys);
      goto __cn_epilogue; }
  }
  struct node *curr = CN_LOAD(xs);
  c_add_to_ghost_state((&curr), sizeof(struct node *), get_cn_stack_depth());

  while (CN_LOAD(CN_LOAD(curr)->next) != 0) {
    CN_STORE(curr, CN_LOAD(CN_LOAD(curr)->next));
  }
  CN_STORE(CN_LOAD(curr)->next, CN_LOAD(ys));
  { __cn_ret = CN_LOAD(xs);
    c_remove_from_ghost_state((&curr), sizeof(struct node *));
    goto __cn_epilogue; }

  c_remove_from_ghost_state((&curr), sizeof(struct node *));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  /* C OWNERSHIP */
  c_remove_from_ghost_state((&xs), sizeof(struct node *));
  c_remove_from_ghost_state((&ys), sizeof(struct node *));

  { cn_pointer *return_cn = convert_to_cn_pointer(__cn_ret);
    ghost_stack_depth_decr();
    cn_postcondition_leak_check(); }

  return __cn_ret;
}