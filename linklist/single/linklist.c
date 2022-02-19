
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {

    int data;
    struct Node_t *next;
}Node;

void
insert_node_tail (Node **root , int element) {

    Node *ptr;
    Node *first = *root;
    ptr = (Node*)malloc (sizeof (Node));
    ptr->data = element;
    
    if (*root == NULL) {
       *root = ptr;
    } else {

        while ((first->next) != NULL) 
           first = first->next;

        first->next=ptr;              
    }

}

void
insert_node_head (Node **root , int element) {

    Node *ptr;
    ptr = (Node*)malloc (sizeof (Node));
    ptr->data = element;
    
    if (*root == NULL) {
       *root = ptr;
    } else {

        ptr->next = *root;
        *root = ptr;        
    }

}

void
delete_node (Node **root , int element) {

    printf ("Deleting ... %d \n",element);

    Node *prev = NULL;
    Node *cur = *root;
    int found = 0;
    
    /*search for the element */
    while (cur->next != NULL) {

        if (cur->data == element) {
            found = 1;
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    if (found == 1) {

        if (prev == NULL) {
            /* first element */
            *root = cur->next;
            free (cur);

        } else {
            prev->next = cur->next;
            free (cur);
        }

    } else {
        printf ("No elements found \n");
    }

}

void
display_node (Node *root) {

    while (root) {
        printf ("%d \t", root->data);
        root = root->next;
    }

    printf ("\n");
}


void
reverse_display_node (Node *root) {


    if (root) {
        reverse_display_node (root->next);
        printf ("%d \t", root->data);
    }

    printf ("\n");
}

void
reverse (Node **root) {

    printf ("Reversing \n");

    Node *prev = NULL;
    Node *cur = *root;
    Node *next = NULL;
    
    while (cur != NULL) {

        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *root = prev;
   

}


int main () {

    Node *root1 = NULL;
    Node *root2 = NULL;

    printf ("Single Linklist \n");


    insert_node_tail (&root1, 5);
    insert_node_tail (&root1, 10);
    insert_node_tail (&root1, 15);
    insert_node_tail (&root1, 20);

    display_node (root1);

    printf ("Reverse displaying \n");
    reverse_display_node (root1);

    reverse(&root1);
    display_node (root1);
      
    insert_node_head (&root2, 100);
    insert_node_head (&root2, 200);
    insert_node_head (&root2, 300);
    insert_node_head (&root2, 400);

    display_node (root2);  

    delete_node (&root2, 200);
    display_node (root2);

}