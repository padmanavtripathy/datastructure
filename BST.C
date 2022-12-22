#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};
void insertnode(struct tree *p, int key);
void inorder(struct tree *root);
int max(struct tree *);
int minimum(struct tree *);
// int search(struct tree *p,int key);
void deletenode(struct tree *root,int key);
int  serch(struct tree *root,int key);
int main()
{
    struct tree *root;
    int no;
    int test = 1;
    printf("Enter the data for root : ");
    scanf("%d",&no);
    root = (struct tree * )malloc (sizeof(struct tree));
    root -> data = no;
    root ->left = root ->right = NULL;
    while (test == 1)
    {
        printf("Enter The Data :");
        scanf("%d",&no);
        insertnode(root,no);
        printf("1. Enter the data \n2. No data (EXIT) ");
        scanf("%d",&test);
    }
    inorder(root);
    int k = max(root);
    printf("\nThe Maximum of the BST is : %d", k);
    int key;
    printf("\n Enter the key you wants to find ");
    scanf("%d",&key);
    int p = serch(root,key);
    printf("%d", p);
    // int l= minimum(root);
    // printf("\nThe Minimum of the BST is : %d",l);
    // int key;
    // int m = search(root,key);
    // if (m == key)
    // {
    //     printf("\n%d is found",m);
    // }
    // else{
    //     printf("\nThe %d is not found ",key);
    // }
    // deletenode(root, 10);
}
void insertnode(struct tree *p, int key)
{
    int f = 1;
    struct tree *curr;
    curr = (struct tree *) malloc (sizeof(struct tree));
    curr -> data = key ;
    curr -> left = curr -> right = NULL;
    while(f == 1)
    {
        if (key < p ->data)
        {
            if (p ->left == NULL)
            {
                p -> left = curr;
                f = 0;
            }
            else 
            {
                p = p->left;
            }
        }
        else
        {
            if (p ->right == NULL)
            {
                p ->right = curr;
                f = 0;
            }
            else
            {
                p = p -> right;

            }
            
        }
    }

}
void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root ->left);
        printf("%5d",root ->data);
        inorder(root ->right);
    }
}
int max(struct tree *x)
{
    while(x -> right != NULL)
    {
        x = x -> right;
    }
    return x -> data ;
}
/*int minimum(struct tree *x)
{
    while(x -> left != NULL)
    {
        x = x -> left;
    }
    return x -> data ;
}*/
/*int search(struct tree *p,int key)
{
    if (p == NULL)
    {
        return -1;
    }
    if (key == p ->data)
    {
        return p -> data;
    }
    else if (key < p -> data)
    {
       return search(p -> left , key);
    }
    else 
    {
        return search(p ->right , key);
    }
}*/
/*int * maximum(struct tree *root,int key)
{
    struct tree *p, *q;
    if(p -> data == key)
    {
        return p;
    }
    else if(p -> data > key)
    {
        maximum(p ->left , key)
    }
    else
    {
        maximum(p -> right, key)
    }
}*/
int serch(struct tree *p,int key)
{
    struct tree *q;
    if(p == NULL)
    {

    }
    else if(p -> data > key)
    {
        q = p ;
        p = p -> left ;
        serch(p,key);
    }
    else if(p ->data <key)
    {
        q = p ; 
        p = p -> right ;
        serch(p,key);
    }
    else
    {
        // printf("%d",q->data);
        return p->data;
    }

}
