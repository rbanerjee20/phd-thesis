#include "linked_list_def.h"

struct node* list_append(struct node* xs, struct node* ys);

int main(void)
{
  struct node i1 = {.val = 2, .next = 0};
  struct node i3 = {.val = 4, .next = 0};
  struct node i2 = {.val = 3, .next = &i3};

  struct node *res = list_append(&i1, &i2);
}
