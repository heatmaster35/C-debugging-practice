//#############################
//# Name: Leo Gomez           #
//# CruzID: legomez           #
//# Class: CMPS-12M           #
//# Date: Nov 12, 2014        #
//# filename: list.c          #
//# Details: a linked list for#
//# for INT values in C coding#
//#############################

#include <stdio.h>
#include <stdlib.h>

// A node in a singly-linked list
struct node {
    int value;
    struct node *next;
};

// Head of the linked list
struct node *head;

// Insert a value into linked list
void list_insert(int v) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->value = v;
    n->next = head;
    head = n;
}

// Insert two values at once into linked list
void list_insert2(int a, int b) {
  list_insert(a);
  list_insert(b);
}

// Remove an element from linked list
void list_remove(int v) {
    struct node *n = head;
    struct node *l;
    while(n && n->next && n->next->value != v) {
      n = n->next;
    }
    if(n && n->next && n->next->value == v) {
      l = n->next;
      n->next = n->next->next;
    }
    if(l)
      free(l);
}

// Print out all values in linked list
void list_printall(void) {
    struct node *p = head;
    int n = 0;
    while(p) {
        printf("%d ", p->value);
        p=p->next;
        n++;
        if(n > 100) break;
    }
    printf("\n");
}

// Deallocate all memory used in linked list
void list_destroy(void) {
  struct node *i = head;
  struct node *temp;
  while(i){
    temp = i->next;
    free(i);
    i = temp;
  }
}

int main(int argc, char *argv[]) {
    printf("Test linked lists\n");
    list_printall(); // Should print nothing
    list_insert(42);
    list_insert2(17, 10);
    list_insert(18);
    list_remove(10);
    list_printall(); // Should print 18 17 42
    // Cleanup memory
    list_destroy();
    return 0;
}
