
#include <stdio.h>
#include <stdlib.h>

typedef struct avl_t {

    struct avl_t* left;
    int data;
    struct avl_t* right;
    int height;

}avl;

int max (int a, int b){
    return a > b ? a : b;
}

int height (avl *root) {
    if (root == NULL)
        return 0;

    printf ("%d \n",root->data);    

    printf ("computing height \n"); 
    return 1 + max (height (root->left), height (root->right));     
    printf ("computing height done \n"); 
}

int getBalance (avl *root) {

    if (root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh =  height(root->right);

    printf ("Balance of Node %d : Left height %d Right height %d \n",root->data,lh,rh);

    return  (lh - rh);

}

#if 0
       z
      / \
     y   T4
    / \ 
   x    T3
  / \    
 T1  T2

#endif 
avl* rightRotate (avl *z) {

       avl *y = z->left;
       avl *T3 = y->right;

       y->right = z;
       z->left = T3;

       z->height = height (z);
       y->height = height (y);

       return y;

}

#if 0
       z
      / \
    T1   y
        /  \
       T2   x
            / \
           T3  T4
#endif 
avl* leftRotate (avl *z) {

       avl *y = z->right;
       avl *T2 = y->left;

       y->left = z;
       z->right = T2;

       z->height = height (z);
       y->height = height (y);

       return y;      

}



avl* avl_insert (avl *root, int element) {

    avl* temp = NULL;
    printf ("Inserting %d \n ", element);
    if (root == NULL) {


       printf ("Allocating memory \n");
        temp = (avl*) malloc (sizeof (struct avl_t));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = element;
        temp->height = 0; // new node is initially added at leaf

        return temp;
    } else {

        if (element > root->data) {
            printf ("Switching to right %d \n",root->data);
            root->right = avl_insert(root->right, element);
        } else if (element < root->data) {
            printf ("Switching to left %d \n",root->data);
            root->left = avl_insert(root->left, element);
        } else {
            printf ("Same element alredy inserted to the tree \n");
            return root;
        }
    }

    /* compute the height */
    root->height = height (root);


    /* get the balance factor of the node */
    int balance = getBalance (root);

    printf ("Node %d balance %d \n",root->data,balance);

    /* left heavy */
    if ((balance > 1) && (element < root->left->data)) {
        printf ("left left case \n");
        /* left left case */
        /* right rotate */
        return rightRotate (root);
    }

    /* left heavy */
    if ((balance > 1) && (element > root->left->data)) {
        /* left right case */
        printf ("left right case \n");
        root->left =  leftRotate(root->left);
        return rightRotate (root);
    }

    /* right heavy */
    if ((balance < -1) && (element < root->right->data)) {
        /* right left case */
        /* left rotate */
         printf ("right left case \n");
         root->right =  rightRotate(root->right);
        return leftRotate (root);
    }

     /* right heavy */
    if ((balance < -1) && (element > root->right->data)) {
        /* right right case */
         printf ("right right case \n");        
        return leftRotate (root);
    }

    return root;
}



void preOrder(avl *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void inorder(avl *root)
{
    if(root != NULL)
    {
       
        inorder(root->left);
         printf("%d ", root->data);
        inorder(root->right);
    }
}

avl* minValueNode(avl* node)
{
    avl *current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    printf ("Inorder succesor %d \n",current->data);

    return current;
}

avl* avl_delete (avl *root, int element) {


    printf ("Deleting element %d \n",element);

    avl *node = NULL;

    if (root == NULL) {
        return root;
    }    

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( element < root->data )
        root->left = avl_delete(root->left, element);
 
    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( element > root->data )
        root->right = avl_delete(root->right, element);
 
    // if key is same as root's key, then This is
    // the node to be deleted
    else {

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
            free (root);
            return node;
        }

         /* only left child */ 
        if (root->right == NULL) {

             printf ("Case : One  children  LEFT \n");
            node = root->left;
            free (root);
            return node;
        }

        /* Both child exists */
        /* Find the inorder successor */

        printf ("Case : Both  children   \n");

        avl* temp = minValueNode(root->right);

        root->data = temp->data;

        avl_delete (root->right, temp->data);
    }

    printf ("Proceeding to balance \n");

    // If the tree had only one node then return
    if (root == NULL) {
      printf ("Returning as root is null \n");
      return root;
    } 

       printf ("Proceeding to balance 1 \n");
    
    /* compute the height */
    root->height = height (root);

     printf ("Proceeding to balance 2 \n");


    /* get the balance factor of the node */
    int balance = getBalance (root);

    printf ("Node %d balance %d \n",root->data,balance);

    /* left heavy */
    if ((balance > 1) && (element < root->left->data)) {
        printf ("left left case \n");
        /* left left case */
        /* right rotate */
        return rightRotate (root);
    }

    /* left heavy */
    if ((balance > 1) && (element > root->left->data)) {
        /* left right case */
        printf ("left right case \n");
        root->left =  leftRotate(root->left);
        return rightRotate (root);
    }

    /* right heavy */
    if ((balance < -1) && (element < root->right->data)) {
        /* right left case */
        /* left rotate */
         printf ("right left case \n");
         root->right =  rightRotate(root->right);
        return leftRotate (root);
    }

     /* right heavy */
    if ((balance < -1) && (element > root->right->data)) {
        /* right right case */
         printf ("right right case \n");        
        return leftRotate (root);
    }

    return root;
}

int main () {

   avl *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = avl_insert(root, 10);
  printf ("\n IO \n");
  inorder (root);
  printf ("\n");
  
  root = avl_insert(root, 20);
    printf ("\n IO \n");
  inorder (root);
   printf ("\n");
  
  root = avl_insert(root, 30);
    printf ("\n IO \n");
  inorder (root);
   printf ("\n");
  
  root = avl_insert(root, 40);
    printf ("\n IO \n");
  inorder (root);
   printf ("\n");
  
  root = avl_insert(root, 50);
    printf ("\n IO \n");
  inorder (root);
   printf ("\n");
  
  root = avl_insert(root, 25);
  printf ("\n IO \n");
  inorder (root);
   printf ("\n");

   printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
  printf ("\n");
  inorder (root);

printf ("\nDeleting 30 \n");
root = avl_delete (root,20);
  printf ("\n IO \n");
  inorder (root);
   printf ("\n");

    return 0;

}