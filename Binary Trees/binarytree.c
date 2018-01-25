#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left_child,*right_child,*parent; 
    int key;
};

struct node* create_node(struct node* parent)   // Creates a node and returns it's pointer
{
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->left_child = NULL;
    temp->right_child = NULL;
    temp->parent = parent;
    return temp;
};

void insert(struct node* root, int key)        // Insert a key to the given binary tree conforming to it's properties.
{
    if(root->left_child == NULL && (key <= root->key))
    {
        struct node *temp = create_node(root);
        root->left_child = temp;
        temp->key = key;
        return;
    }
    else
    if(root->right_child == NULL && (key >= root->key))
    {
        struct node* temp = create_node(root);
        root->right_child = temp;
        temp->key = key;
        return;
    }
    
    

    if(root->left_child!= NULL && (key < root->key))
        return insert(root->left_child, key);
    else
        return insert(root->right_child, key); 
}

int findMin( struct node* root)
{
    if(root->left_child == NULL)
        return root->key;
    else
        findMin(root->left_child);
}


int main()
{
    struct node tree_root;
    tree_root.parent = NULL;
    tree_root.key = 20;
   for (int i = 1; i < 6000000; i++) 
            insert(&tree_root,rand()%10000);

    int k = findMin(&tree_root);
    printf("Minumum is %d\n",k );
}




