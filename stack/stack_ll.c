#include <stdio.h>
#include <stdlib.h>

typedef struct stack_data_t {
    struct stack_data_t *next; 
    int data;
}stack_data;

typedef struct stack_t {  
    
    stack_data *data;
} stack;

void 
initilalize_stack (stack **st) {

    stack *temp = NULL;

    if ((*st) == NULL) {

        temp = ( stack *)malloc (sizeof (stack) );
        if (temp == NULL) {
            printf ("No memory \n");
        } else {

            temp->data = NULL;          
            *st = temp;
        }
     }

       
}

void 
push (stack **st , int element) {

     
    if ((*st) == NULL) {
         printf ("Stack not initialize \n");
    }
    
    stack_data *temp = NULL;
    temp = (stack_data *) malloc (sizeof (stack_data ));

    temp->data = element;
    temp->next = NULL;

    if (((*st)->data) == NULL) {
        /* First element */
        (*st)->data = temp;       
    } else {
        temp->next = (*st)->data;
        (*st)->data = temp;
    }
}

int 
pop (stack **st ) {

    int element = -1;
     
    if ((*st) == NULL) {
         printf ("Stack not initialize \n");
    }


    if (((*st)->data) == NULL) {
        printf ("stack empty \n");      
    } else {
        element  = (*st)->data->data;
        (*st)->data = (*st)->data->next;
    }

    return element;
}


int 
main (void) {

    printf ("Stack implementing with linklist \n");

    stack *st = NULL;

    initilalize_stack (&st);

    push (&st, 10);

    printf ("%d \n",pop(&st));
     printf ("%d \n",pop(&st));

}