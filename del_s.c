#include "header.h"
void del_by_roll(struct st **ptr, int n) {
    struct st *tmp = *ptr;
    struct st *prev = NULL;
    while (tmp != NULL) {
        if (tmp->roll_num == n) {
            if (tmp == *ptr)
                *ptr = tmp->nxt;
            else
                prev->nxt = tmp->nxt;
            free(tmp);
            printf("Record with roll number %d deleted.\n", n);
            return;
        }
        prev = tmp;
        tmp = tmp->nxt;
    }
    printf("No node matching roll number %d.\n", n);
}

void del_by_name(struct st **ptr, const char *name) {
    struct st *tmp = *ptr;
    int count = 0;

    printf("Matching records:\n");
    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0) {
            printf("%d %s %.2f\n", tmp->roll_num, tmp->name, tmp->marks);
            count++;
        }
        tmp = tmp->nxt;
    }

    if (count == 0) {
        printf("No node matching name \"%s\".\n", name);
        return;
    }
    else if (count == 1) {
        tmp = *ptr;
        struct st *prev = NULL;
        while (tmp != NULL) {
            if (strcmp(tmp->name, name) == 0) {
                printf("Deleting this record: %d %s %.2f\n", tmp->roll_num, tmp->name, tmp->marks);
                if (tmp == *ptr)
                    *ptr = tmp->nxt;
                else
                    prev->nxt = tmp->nxt;
                free(tmp);
                printf("Record deleted.\n");
                return;
            }
            prev = tmp;
            tmp = tmp->nxt;
        }
    }
    else {
        printf("Multiple records found with name \"%s\".\n", name);
        char choice;
        printf("Do you want to delete by roll number instead? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            int roll_num;
            printf("Enter roll number to delete: ");
            scanf("%d", &roll_num);
            del_by_roll(ptr, roll_num);
        }
        else {
            printf("Deletion cancelled.\n");
        }
    }
}



void del_by_marks(struct st **ptr, float marks) {
    struct st *tmp = *ptr;
    int count = 0;

    printf("Matching records:\n");
    while (tmp != NULL) {
        if (tmp->marks == marks) {
            printf("%d %s %.2f\n", tmp->roll_num, tmp->name, tmp->marks);
            count++;
        }
        tmp = tmp->nxt;
    }

    if (count == 0) {
        printf("No node matching marks %.2f.\n", marks);
        return;
    }
    else if (count == 1) {
        // Only one match, delete it
        tmp = *ptr;
        struct st *prev = NULL;
        while (tmp != NULL) {
            if (tmp->marks == marks) {
                printf("Deleting this record: %d %s %.2f\n", tmp->roll_num, tmp->name, tmp->marks);
                if (tmp == *ptr)
                    *ptr = tmp->nxt;
                else
                    prev->nxt = tmp->nxt;
                free(tmp);
                printf("Record deleted.\n");
                return;
            }
            prev = tmp;
            tmp = tmp->nxt;
        }
    }
}
