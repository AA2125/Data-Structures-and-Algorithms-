#ifndef BST_H_
#define BST_H_

typedef struct Tree_Node // node will store data
{
    //TODO
    char data; //i used int and that was a pain
    struct Tree_Node* left;  // both are pointers 
    struct Tree_Node* right;
    
}Tree_Node;

// ez that's just the simple part



void tree_insert ( Tree_Node** root, char data );
Tree_Node* create_bst (char data[]);
Tree_Node* tree_search ( Tree_Node* root, char data );
void tree_print_sorted ( Tree_Node* root );
void tree_delete ( Tree_Node* root );


#endif