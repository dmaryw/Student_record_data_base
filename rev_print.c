#include "header.h"
void rev_print(struct st *ptr){
    if(ptr!=0){
        rev_print(ptr->nxt);
	printf("%d %s %f\n",ptr->roll_num,ptr->name,ptr->marks);
    }
}
