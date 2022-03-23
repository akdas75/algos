
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

    return 1 + max (height (root->left), height (root->right));     
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

    return 0;

}