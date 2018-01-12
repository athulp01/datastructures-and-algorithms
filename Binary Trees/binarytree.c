#include <stdio.h>

struct node
{
    struct node *left_child = NULL,*right_child = NULL,*parent=NULL; 
    int key;
};

struct node* create_node(struct node* parent)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node))
    return temp;
}
void insert(struct node* root, int key)
{
    if(root->left_child = NULL && key < root->key)
    {
        temp = create_node(root)
        root->left_child = temp;
        temp->key = key;
        return;
    }
    
    if(root->right_child = NULL && key > root->key)
    {
        temp = create_node(root)
        root->right_child = temp;
        temp->key = key;
        return;
    }
    
    if(node->parent = NULL)
    {
        temp = create_node(root)
        root->right_child = temp;
        temp->key = key;
        return;
    }

    if(root->left_child!= NULL && key < root->key)
        return insert(root->left_child, key);
    else
        return insert(root->right_child, key); 
}





