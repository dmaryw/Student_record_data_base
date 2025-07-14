#include "header.h"
void del_all(struct st **ptr){
    struct st *tmp;
    while(*ptr!=0){
        tmp =*ptr;
        *ptr = tmp->nxt;
        free(tmp);
    }
}
