#include "header.h"
void save(struct st *ptr){
    FILE*fp =fopen("records.txt","w");
    while(ptr!=0){
        fprintf(fp,"%d %s %f",ptr->roll_num,ptr->name,ptr->marks);
        ptr=ptr->nxt;
    }
    fclose(fp);
}
