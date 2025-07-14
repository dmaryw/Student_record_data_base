#include "header.h"

void print(struct st *ptr) {
    printf("Printing the records:\n");
    while (ptr != 0) {
        printf("%d %s %.2f\n", ptr->roll_num, ptr->name, ptr->marks);
        ptr = ptr->nxt;
    }
}

