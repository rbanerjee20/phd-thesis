#include "linked_list_def.h"

struct node i3 = {.val = 3, .next = 0};
struct node i2 = {.val = 2, .next = &i3};
struct node i1 = {.val = 1, .next = &i2};