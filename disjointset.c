#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
    struct node *repr;
};
struct sets
{
    struct node *head;
    struct node *tail;
}set[10];
struct Edge
{
    int i,j;
};
int v[]={0,1,2,3,4,5,6,7,8},n=9,m=9;
struct Edge e[14]={{0,1},{0,3},{1,3},{0,2},{2,3},{4,5},{4,6},{5,6},{7,8}};
int nset=0;
struct node* makeset(int v);
int findset(int v);
void union(int,int);
int main()
{
    struct Edge S[10];
    int k,x,y;
    for(int k=0;k<n;k++)
    {
        set[k].head=set[k].tail=makeset(k);
    }
    for(int k=0;k<m;k++)
    {
        printf("%d---%d",e[k].i,e[k].j);
        if(findset(e[k].i) != findset(e[k].j))
        {
            union(e[k].i,e[k].j);
        }
        else
        {
            printf("union not possible same set");
        }
    }
}
struct node* makeset(int v)
{
    struct node* curr;
    curr = (struct node *)malloc (sizeof(struct node));
    curr->data = v;
    curr -> next = NULL;
    curr -> repr = curr;
    nset++;
    return curr;
}
int findset(int v)
{
    struct node *curr;
    for(int i=0;i<n;i++)
    {
        curr = set[i].head;
        while(curr != NULL)
        {
            if(curr->data==v)
            {
                return i;
            }
            curr = curr->next;
        }
    }
    return -1;
}
void union(int u,int v)
{
    struct node *t,*p;
    i = findset(u);
    j = findset(v);
    t = set[i].tail;
    t->next = set[j].head;
    p=set[j].head;
    while(p!=NULL)
    {
        p->repr = set[i].head;
        p = p->next;
    }
    set[i].tail=set[j].tail;
    set[i].head = set[j].tail = NULL;
    nset--;
}