#include "header.h"

void add_begin(struct st **ptr) {
    static int roll_counter = 1;   

    struct st *tmp = (struct st *)malloc(sizeof(struct st));
    if (!tmp) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter name and marks:\n");
    scanf("%s %f", tmp->name, &tmp->marks);

    tmp->roll_num = roll_counter; 
    roll_counter++;               

    tmp->nxt = *ptr;
    *ptr = tmp;
}

