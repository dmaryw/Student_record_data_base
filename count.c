#include "header.h"

int count(struct st *ptr) {
    int c = 0;
    while (ptr != 0) {
        ++c;
        ptr = ptr->nxt;
    }
    return c;
}


