#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left_child,*right_child,*parent; 
    int key;
};

struct node* create_node(struct node* parent)
{
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->left_child = NULL;
    temp->right_child = NULL;
    temp->parent = parent;
    return temp;
};
void insert(struct node* root, int key)
{
    if(root->left_child == NULL && (key < root->key))
    {
        struct node *temp = create_node(root);
        root->left_child = temp;
        temp->key = key;
        return;
    }
    else
    if(root->right_child == NULL && (key > root->key))
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

void print_tree(struct node *root)
{
    printf("Right and left of %d are %d and %d viz.\n", root->key,root->right_child->key,root->left_child->key);
    if(root->right_child->right_child != NULL)
    print_tree(root->right_child);
    if(root->left_child->left_child!=NULL)
    print_tree(root->left_child);
}

int main()
{
    struct node tree_root;
    tree_root.parent = NULL;
    tree_root.key = 20;
   for (int i = 1; i < 16; i++) 
            insert(&tree_root,rand()%100);
    print_tree(&tree_root);
}




