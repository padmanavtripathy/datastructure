#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};
void insertnode(struct tree *p, int key);
void inorder(struct tree *root);
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