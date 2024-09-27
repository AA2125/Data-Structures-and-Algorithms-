#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// stuff needed for background: Linked lists, recursive function and binary trees
// i will need to create a function to create nodes
// sources used: https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/#:~:text=In%20C%20language%2C%20a%20linked,address%20of%20the%20next%20node.
// and:https://www.scaler.com/topics/binary-search-tree-program-in-c/
// source for reucusion: https://www.youtube.com/watch?v=ngCos392W4w// okay so this was very helpfl https://www.codesdope.com/blog/article/binary-search-tree-in-c/


 struct Tree_Node* noddy(char data)
{
    Tree_Node* k = (Tree_Node*)malloc(sizeof(struct Tree_Node));
    k -> data = data;
    k-> left = NULL;
    k -> right = NULL;
    return k;
      
   
}



// need a few if statements 
// i hate this
// node will traverse the tree for reasons unkown
// recall binary tree (basics)

void tree_insert(Tree_Node** root, char data)
{
    
    if(*root == NULL) // free tree
    {
        *root = noddy(data);
        
    }
    else if(data > (*root)-> data)
    {
        tree_insert(&(*root)-> left , data);
    }
    else
    {
        tree_insert(&(*root)-> right , data);
    }

    
} 


// Needs to terminate when /0 is mentioned 
//for loop making a comeback? (no way bruh)
//this helped https://www.youtube.com/watch?v=hfwwaNNJ-0A 
//also this:https://thispointer.com/create-a-binary-search-tree-from-an-array/
//also this for code termenation:https://copyprogramming.com/howto/how-to-enter-a-letter-to-quit-a-program-in-c
// while loop seems better since in the examples we have 2 var here only 1

Tree_Node* create_bst (char data[])
{
   
    struct Tree_Node *root;
    int i = 0;
    while(data[i] != '\0') // use '' not ""
    {
      tree_insert(&root, data[i]);
      i++;
    }
    return root;

}

//This helped:https://www.prepbytes.com/blog/tree/searching-in-binary-search-tree-in-c/
// and this one again:https://www.codesdope.com/blog/article/binary-search-tree-in-c/
    
Tree_Node* tree_search(Tree_Node* root, char data){
    
    if(root == NULL)
    {
     return NULL;
    }
    else if(root ->data == data)
    {
        return root;
    }
    else if(data > root->data ) // note to self: stop being a dumbass
    {
        return tree_search(root->left,data);
    }
    else
    {
        return tree_search(root->right,data);
    }
    

    
}

//java example but the idea is similer:https://www.educative.io/answers/how-to-print-the-nodes-of-a-binary-tree-in-sorted-order
// and also this but a C example:https://www.codesdope.com/blog/article/binary-search-tree-in-c/

void tree_print_sorted(Tree_Node* root){
    
    if(root == NULL)
    {
     return; // nothing
       
    } 
    else{
    tree_print_sorted(root-> right);
    printf("%c", root->data); //simple
    tree_print_sorted(root->left);
    }
    
   
    

   

}

void tree_delete(Tree_Node* root){
    //again same source:https://www.codesdope.com/blog/article/binary-search-tree-in-c/
    // the goal is to delete all nodes (no children)
    //in this example:https://www.programiz.com/dsa/binary-search-tree they go over all cases we could make this very simple
    if(root == NULL)
    {
     return; // retrun nothing
     
    }
    else
    {
    tree_delete(root-> left);
    tree_delete(root-> right);
    free(root); // will free the memorey 
    }
    
    
    
        
     
}

