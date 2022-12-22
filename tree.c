#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};
struct stack
{
    struct tree *tr;
    struct stack *next;
};
struct tree  *curr,*root,*ptr;
struct stack *tr,*s,*top=NULL;
void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("%5d",root ->data);
        preorder(root ->left);
        preorder(root ->right);
    }
}
int main()
{
    int no,f=1,k;
    int l;
    char chl,chr;
    printf("Enter The NUmber : ");
    scanf("%d",&no);
    root = (struct tree *) malloc (sizeof(struct tree));
    root -> data = no;
    root -> left = root ->right = NULL;
    ptr = root;
    while (f == 1)
    {
        printf("\n %d has left child : ",ptr -> data);
        scanf("%d",&k);
        if (k)
        {
            printf("Enter The Left subchild : ");
            scanf("%d",&no);
            curr = (struct tree *)malloc(sizeof(struct tree));
            curr -> data = no;
            curr -> left = curr -> right =NULL;
            ptr -> left = curr;
        }
        printf("\n %d has the right subchild : ",ptr -> data);
        scanf("%d",&l);
        if (l)
        {
            printf("Enter the right subchild : ");
            scanf("%d",&no);
            curr = (struct tree *)malloc(sizeof(struct tree));
            curr -> data = no;
            curr -> left = curr -> right =NULL;
            ptr -> right = curr;
            s = (struct stack *)malloc(sizeof(struct stack));
            s -> tr = curr;
            s -> next = NULL;
            if (top == NULL)
            {
                top = s;
            }
            else
            {
                s -> next = top;
                top = s;
            }
        }
        if (!k && !l && top == NULL )
        {
            f = 0 ;
        }
        else if (!k)
        {
            s  = top;
            ptr = top -> tr;
            top = top -> next;
            free (s);
        }
        else
        {
            ptr = ptr -> left;
        }

        }
        preorder(root);

}
