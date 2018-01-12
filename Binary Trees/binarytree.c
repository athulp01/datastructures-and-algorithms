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
    if(root->parent == NULL)
    {
        root->key = key;
        return;
    }
    else
    if(root->left_child == NULL && key < root->key)
    {
        struct node* temp = create_node(root);
        root->left_child = temp;
        temp->key = key;
        return;
    }
    else
    if(root->right_child == NULL && key > root->key)
    {
        struct node* temp = create_node(root);
        root->right_child = temp;
        temp->key = key;
        return;
    }
    
    

    if(root->left_child!= NULL && key < root->key)
        return insert(root->left_child, key);
    else
        return insert(root->right_child, key); 
}

int main()
{
    struct node tree_root;
    tree_root.parent = NULL;
    insert(&tree_root, 10);
    printf("%d", tree_root.key);
    insert(&tree_root, 20);
    insert(&tree_root, 8);
    printf("%d %d", tree_root.left_child->key,tree_root.right_child->key );
}




