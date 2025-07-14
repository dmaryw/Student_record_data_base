#include "header.h"
struct st* sort_roll(struct st *head) {
    if (head == NULL || head->nxt == NULL)
        return head;

    int swapped;

    do {
        swapped = 0;
        struct st *curr = head;
        struct st *prev = NULL;

        while (curr->nxt != NULL) {
            struct st *next = curr->nxt;

            if (curr->roll_num > next->roll_num) {
                swapped = 1;
                curr->nxt = next->nxt;
                next->nxt = curr;

                if (prev == NULL) {
                    head = next;
                } else {
                    prev->nxt = next;
                }
                prev = next;
            } else {
                prev = curr;
                curr = curr->nxt;
            }
        }
    } while (swapped);

    return head;
}

struct st* sort_mark(struct st *head) {
    if (head == NULL || head->nxt == NULL)
        return head;

    int swapped;

    do {
        swapped = 0;
        struct st *curr = head;
        struct st *prev = NULL;

        while (curr->nxt != NULL) {
            struct st *next = curr->nxt;

            if (curr->marks > next->marks) {
                swapped = 1;
                curr->nxt = next->nxt;
                next->nxt = curr;

                if (prev == NULL) {
                    head = next;
                } else {
                    prev->nxt = next;
                }
                prev = next;
            } else {
                prev = curr;
                curr = curr->nxt;
            }
        }
    } while (swapped);

    return head;
}

struct st* sort_name(struct st *head) {
    if (head == NULL || head->nxt == NULL)
        return head;

    int swapped;

    do {
        swapped = 0;
        struct st *curr = head;
        struct st *prev = NULL;

        while (curr->nxt != NULL) {
            struct st *next = curr->nxt;

            if (strcmp(curr->name, next->name) > 0) {
                swapped = 1;

                // Swap nodes
                curr->nxt = next->nxt;
                next->nxt = curr;

                if (prev == NULL) {
                    head = next;
                } else {
                    prev->nxt = next;
                }
                prev = next;
            } else {
                prev = curr;
                curr = curr->nxt;
            }
        }
    } while (swapped);

    return head;
}

struct st* copy_list(struct st* head) {
    if (head == NULL) return NULL;

    struct st* new_head = NULL;
    struct st* new_tail = NULL;

    while (head) {
        // Allocate a new node
        struct st* new_node = (struct st*)malloc(sizeof(struct st));
        if (!new_node) {
            perror("malloc failed");
            exit(1);
        }
        // Copy data
        new_node->roll_num = head->roll_num;
        new_node->marks = head->marks;
        strcpy(new_node->name, head->name);
        new_node->nxt = NULL;

        // Append to new list
        if (new_head == NULL) {
            new_head = new_tail = new_node;
        } else {
            new_tail->nxt = new_node;
            new_tail = new_node;
        }

        head = head->nxt;
    }

    return new_head;
}

void free_list(struct st* head) {
    struct st* tmp;
    while (head) {
        tmp = head;
        head = head->nxt;
        free(tmp);
    }
}

