

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned int uint32_t;

typedef struct  bst_t {
    struct bst_t * left;
    int32_t data;
    struct bst_t * right;
} bst;

typedef  struct queue_t {
    struct bst_t **data;
    int rear;
    int front;
    int size;
}queue;



int max (int a, int b) {

    return a > b ? a : b;
}

int min (int a, int b) {

    return a > b ? b : a;
}


bst*  bst_insert (bst *root, uint32_t element) {


    printf ("Inserting %d \n" , element);
    if (root == NULL) {

         printf ("Root is NULL \n");

        bst *node = (bst *)malloc (sizeof (struct  bst_t));

        node->data = element;

        node->left  = NULL;
        node->right = NULL;

        return node;
    }  else {

        if (element > root->data) {
            printf ("Going to right \n");
            root->right = bst_insert (root->right, element);
        } else if (element < root->data) {
            printf ("Going to left \n");
            root->left = bst_insert (root->left, element);
        }  else {
            printf ("Element already exists \n");
        }
    }  

    return root;
}


void bst_inorder (bst *root) {

    if (root == NULL) {
        return;
    } else {
         bst_inorder (root->left);
         printf ("%d \n",root->data);
         bst_inorder (root->right);
    }
}

void bst_preorder (bst *root) {

    if (root == NULL) {
        return;
    } else {
        printf ("%d \n",root->data);
        bst_preorder (root->left);         
        bst_preorder (root->right);
    }
}

void bst_postorder (bst *root) {

    if (root == NULL) {
        return;
    } else {
         bst_inorder (root->left);         
         bst_postorder (root->right);
         printf ("%d \n",root->data);
    }
}


void bst_search (bst *root, int element) {

    if (root == NULL) {
        printf ("Elemnt not found \n");
        return;
    }

    if (element > root->data) {
        bst_search (root->right, element);
    } else if (element < root->data )  {
        bst_search (root->left, element);
    } else {
        printf ("Element found \n");
    }
}

bst* minValueNode(bst* node)
{
    bst *current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    printf ("Inorder succesor %d \n",current->data);

    return current;
}


bst* bst_delete (bst *root, int element) {

    bst *node = NULL;

    if (root == NULL) {
        return root;
    } else if (element < root->data) {
        root->left = bst_delete (root->left, element);
    } else if (element > root->data) {
        root->right = bst_delete (root->right, element);
    }  else {

        printf ("Element found \n");

        /* No childeren */
        if ((root->left == NULL) && (root->right == NULL)) {
             printf ("Case : No children \n");
             free (root);
             return NULL;
        }

        /* only right child */ 
        if (root->left == NULL) {
            printf ("Case : One  children  RIGHT \n");
            node = root->right;
            return node;
        }

        /* only left child */ 
        if (root->right == NULL) {

             printf ("Case : One  children  LEFT \n");
            node = root->left;
            return node;
        }

        /* Both child exists */
        /* Find the inorder successor */

         printf ("Case : Both  children   \n");

        bst* temp = minValueNode(root->right);

        root->data = temp->data;

        bst_delete (root->right, temp->data);
    }  
    return root;
}


int bst_height (bst *root) {

    unsigned int lHeight = 0;
    unsigned int rHeight = 0;
    
    if (root == NULL) {
        return 0;
    } 


    lHeight = bst_height (root->left);
    rHeight = bst_height (root->right);

    int mH = max (lHeight, rHeight) + 1;
    printf ("Returning node %d height %d \n",root->data,mH);
    return mH;

}

int bst_min_height (bst *root) {

    unsigned int lHeight = 0;
    unsigned int rHeight = 0;
    
    if (root == NULL) {
        return 0;       
    } 

    if ((root->left == NULL)  && (root->right == NULL)) {
        return 1;       
    } 


    lHeight = bst_min_height (root->left);
    rHeight = bst_min_height (root->right);

    int mH = min (lHeight, rHeight) + 1;
    //printf ("Returning min height %d \n",mH);
    printf ("Returning node %d l %d r %d min height %d \n",root->data, lHeight, rHeight, mH);

    return mH;

}


int bst_count_nodes (bst *root) {

    if (root == NULL) {
        return 0;       
    } 

    int count = bst_count_nodes (root->left) + bst_count_nodes (root->right) + 1;

    return  count;

}    

int bst_count_leaf_nodes (bst *root) {

    if (root == NULL) {
        return 0;       
    } 

    if ((root->left == NULL) && (root->right == NULL)) {
        return 1;
    }

    int count = bst_count_leaf_nodes (root->left) + bst_count_leaf_nodes (root->right);

    return  count;

}  


int bst_count_non_leaf_nodes (bst *root) {

    if (root == NULL) {
        return 0;       
    } 

    /*leaf node */

    if ((root->left == NULL) && (root->right == NULL)) {
        return 0;
    }

    int count = bst_count_non_leaf_nodes (root->left) + bst_count_non_leaf_nodes (root->right) + 1;

    printf ("Node %d count %d \n",root->data, count);

    return  count;

} 


int check_if_bst (bst *root , int min, int max) {

      if (root == NULL) {
          return 1;
      }

      printf ("data %d min %d max %d \n",root->data, min,max);

      if (root->data > max) {
          printf ("Case 1 \n");
      }

      if (root->data < min) {
          printf ("Case 2 \n");
      }

      /* False case */
      if ((root->data > max)  || (root->data < min)) {
          printf ("Not sataisfying returning \n");
          return 0;
      }

      return (check_if_bst (root->left, min,root->data-1) &&
      check_if_bst (root->right, root->data+1,max));


}


void init_queue (queue **q, int size) {

    *q = (queue *)malloc (sizeof (struct queue_t));

    (*q)->rear = 0;
    (*q)->front = 0;
    (*q)->size = size;

    (*q)->data = (bst**)malloc (sizeof (bst*) * size);

}

void enqueue (queue **q, struct bst_t* ptr) {


    int rear = (*q)->rear;
    int size = (*q)->size;
    int front = (*q)->front;    

    if (((rear +1) % size) == front) {
        printf ("Queue is full \n");
    } else {
        printf ("Queueing element at rear %d \n",rear);
        rear = rear + 1;    
        rear = rear % size;
        (*q)->rear =  rear;
         printf ("Queueing element at rear %d \n",rear);
        (*q)->data [rear] = ptr;
    }    
}

bst* dequeue (queue **q) {   

     int rear = (*q)->rear;
    int size = (*q)->size;
    int front = (*q)->front;

    if (rear == front) {
        printf ("Queue is empty \n");
        return NULL;
    } else {
        front = front + 1;
        front = front % size;
         printf ("Dequeing element at rear %d \n",front);
        (*q)->front = front;
        return (*q)->data [front];
    }  
    
    return NULL;
}

void printLevelOrder (queue **q, bst *root) {

    bst *temp_node = root;

    while (temp_node != NULL) {

        printf("************************************ %d \n", temp_node->data);

        if (temp_node->left)
            enqueue(q,  temp_node->left);

        if (temp_node->right)
            enqueue(q, temp_node->right);    

        /*Dequeue node and make it temp_node*/
        temp_node = dequeue(q);
    }
}

int main (void) {

    bst *root = NULL;
    root = bst_insert (root, 15);
    root = bst_insert (root, 10);
    root = bst_insert (root, 20);
    root = bst_insert (root, 8);
    root = bst_insert (root, 12);
    root = bst_insert (root, 16);
    root = bst_insert (root, 25);


/*
      root = bst_insert (root, 3);
    root = bst_insert (root, 2);
    root = bst_insert (root, 20);
    root = bst_insert (root, 15);    
    root = bst_insert (root, 25);
*/

/*
    root = bst_insert (root, 1);
    root = bst_insert (root, 2);
    root = bst_insert (root, 3);
    root = bst_insert (root, 4);
    root = bst_insert (root, 5);
    root = bst_insert (root, 6);
    root = bst_insert (root, 8);
    root = bst_insert (root, 7);
*/

    int h = bst_height (root);
    printf ("Height of the tree %d \n",h);

    int mh = bst_min_height (root);
    printf ("Min Height of the tree %d \n",mh);


    int ct = bst_count_nodes (root);
    printf ("Node count of the tree %d \n",ct);

    

    int lct = bst_count_leaf_nodes (root);
    printf ("leaf Node count of the tree %d \n",lct);

    

    int nlct = bst_count_non_leaf_nodes (root);
    printf ("Non leaf Node count of the tree %d \n",nlct);


    int ifBst = check_if_bst (root, INT_MIN, INT_MAX);
    printf ("if BST %d \n",ifBst);

    printf ("Displaying inorder ..... \n");
      
    bst_inorder (root);

     printf ("Displaying preorder ..... \n");

    bst_preorder (root);

     printf ("Displaying postorder ..... \n");

    bst_postorder (root);


    printf ("Searching 100 \n");
    bst_search (root, 100);

    printf ("Searching 30 \n");
    bst_search (root, 30);

    printf ("Deleting 30 \n");
    bst_delete (root, 30);

    printf ("Displaying inorder ..... \n");
      
    bst_inorder (root);

    queue *q;
    init_queue (&q , 100);

    printf ("Displaying level order \n");

    printLevelOrder (&q, root);
    

}