


#include <stdio.h>
#include <stdlib.h>


/*
https://www.geeksforgeeks.org/circular-singly-linked-list-insertion/
*/
typedef struct cll_t {

    int data;
    struct cll_t *next;

} cll;

void
insert_node (cll **last, int element) {

     cll *temp = (cll *) malloc (sizeof (struct cll_t));

     temp->data = element;
     temp->next = NULL;

    if (*last == NULL) {

        temp->next = temp;
        *last = temp;

    } else {

        temp->next = (*last)->next;
        (*last)->next = temp;
        *last=temp;

    }

}

void display_node(cll *root)
{
    cll *p = root;
    if (root== NULL) {
        printf ("Empty list \n");
    } else {
        do {
            printf("%d \t", p->data);
            p = p->next;   
        } while (p != root); 
    }
    printf("\n");
}


int 
main (void) {

    printf ("Circular linklist implementation \n");

    cll *last = NULL;

    insert_node (&last, 10);
    insert_node (&last, 20);
    insert_node (&last, 30);

    display_node (last);


}