#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct st {
    int roll_num;
    char name[20];
    float marks;
    struct st *nxt;
};

//struct st *hptr = 0;

// Function declarations
void add_begin(struct st**);
int count(struct st*);
void print(struct st*);
void del_all(struct st **ptr);
void rev_print(struct st*ptr);
void save(struct st*);
void modify(struct st *);
void del_by_roll(struct st **, int );
void del_by_name(struct st **, const char *);
void del_by_marks(struct st **, float );
struct st* sort_name(struct st *);
struct st* sort_mark(struct st *);
struct st* sort_roll(struct st *);
struct st* copy_list(struct st* );
void free_list(struct st* );

