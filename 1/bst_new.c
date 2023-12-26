// Name: SANMAT SANJAYAKUMAR PAYAGOUDAR
// SRN: PES1UG20CS385
#include "bst.h"
#include <stdlib.h>


void init_bst(bst_t *bst)
{
    bst->root = NULL;
}


node_t* helpinsert(node_t *node , int key , int *countptr)
{
    if(node == NULL)
    {
        node_t *newnode = (node_t*)malloc(sizeof(node_t));
        newnode->key = key;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    else
    {
        if((node->key) > key)
        {
            *countptr = *countptr+1; countptr;
            node->left = helpinsert(node->left , key , countptr);
        }
        else
        {
            *countptr = *countptr+1;
            node->right = helpinsert(node->right , key , countptr);           
        }
    }
    return node;
}

void insert(bst_t *tree, int key, int *count_ptr)
{
    tree->root = helpinsert(tree->root , key , count_ptr);
}

node_t* helpdelete(node_t *r,int ele , int *countptr)
{
    node_t *temp,*p;
    if(r==NULL)
        return r;
    if(ele < r->key)
    {    
        *countptr = *countptr + 1;
        r->left = helpdelete(r->left,ele,countptr);
    }
    else if(ele > r->key)
    {
        *countptr = *countptr + 1; 
        r->right = helpdelete(r->right,ele,countptr);
    }
    else
    {
        if(r->left == NULL) 
        {
            *countptr = *countptr + 1; 
            temp=r->right;
            free(r);
            return temp;
        }
        else if(r->right == NULL) 
        {
            *countptr = *countptr + 1; 
            temp=r->left;
            free(r);
            return temp;
        }
        else
        { 
            p=r->right;
            while(p->left != NULL)
            p=p->left;
            r->key=p->key;
            r->right=helpdelete(r->right, p->key,countptr);
        }
    }
    return r;
}

void delete_element(bst_t *tree, int key, int *count_ptr)
{
    tree->root = helpdelete(tree->root , key , count_ptr);
}

int helpsearch(node_t *node , int key , int *count_ptr)
{
    if(node == NULL)
        return -1;
    else
    {
        if(node ->key == key)
        {
            *count_ptr = *count_ptr + 1; 
            return key;
        }
        else if(node->key < key)
        {
            *count_ptr = *count_ptr + 1; 
            return helpsearch(node->right , key , count_ptr);
        }
        else
        {
            *count_ptr = *count_ptr + 1; 
            return helpsearch(node->left , key , count_ptr);            
        }
    }
}
int search(const bst_t *tree, int key, int *count_ptr)
{
    return helpsearch(tree->root , key , count_ptr);
}

int helpfindmax(node_t *node , int *count_ptr)
{
    if(node == NULL)
        return -1;
    else
    {
        if(node->right == NULL)
        {
            *count_ptr = *count_ptr + 1; 
            return node->key;
        }
        else
        {
            return helpfindmax(node->right , count_ptr);
        }
    }
}
int find_max(const bst_t *tree, int *count_ptr)
{
    return helpfindmax(tree->root , count_ptr);
}

void helpfree(node_t *node)
{
    if(node==NULL)return;
    helpfree(node->left);
    helpfree(node->right);
    free(node);
}
void free_bst(bst_t *bst) 
{
    helpfree(bst->root);
    free(bst);
}

void clear_bst(bst_t *bst)
{
    helpfree(bst->root);
    bst->root = NULL;
}