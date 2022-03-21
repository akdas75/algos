

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

typedef struct  bst_t {

    struct bst_t * left;
    uint32_t data;
    struct bst_t * right;


} bst;


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


int main (void) {

    bst *root = NULL;

    root = bst_insert (root, 30);
    root = bst_insert (root, 20);
    root = bst_insert (root, 40);
    root = bst_insert (root, 70);
    root = bst_insert (root, 60);
    root = bst_insert (root, 80);


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
    

}