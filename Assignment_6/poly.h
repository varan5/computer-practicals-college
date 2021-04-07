#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int coef, exp;
    struct node *next;
} node;
void display(node *head)
{
    node *temp;
    printf("the elements are:\n");
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%dx^%d+ ", temp->coef, temp->exp);
    }
}
void create(node *head)
{
    int n, count;
    node *last, *newnode;
    printf("How many nodes");
    scanf("%d", &n);
    last = head;
    for (count = 1; count <= n; count++)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        printf("\n enter the coef and exponent");
        scanf("%d %d", &newnode->coef, &newnode->exp);
        last->next = newnode;
        last = newnode;
    }
}
void add1(node *p1, node *p2, node *p3)
{
    node *t1 = p1->next, *t2 = p2->next, *t3 = p3, *newnode;
    int i;
    while (t1 != NULL && t2 != NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        if (t1->exp > t2->exp)
        {
            newnode->exp = t1->exp;
            newnode->coef = t1->coef;
            t1 = t1->next;
        }
        else if (t1->exp < t2->exp)
        {
            newnode->exp = t2->exp;
            newnode->coef = t2->coef;
            t2 = t2->next;
        }
        else
        {
            newnode->exp = t2->exp;
            newnode->coef = t2->coef + t1->coef;
            t1 = t1->next;
            t2 = t2->next;
        }
        t3->next = newnode;
        t3 = newnode;
    }
    while (t1 != NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->exp = t1->exp;
        newnode->coef = t1->coef;
        t1 = t1->next;
        t3->next = newnode;
        t3 = newnode;
    }

    while (t2 != NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->exp = t2->exp;
        newnode->coef = t2->coef;
        t2 = t2->next;
        t3->next = newnode;
        t3 = newnode;
    }
}
void multiply(node *p1, node *p2, node *p3, node *p4)
{
    node *t1 = p1->next, *t2 = p2->next, *t3 = p3, *newnode;
    while (t1 != NULL)
    {
        while (t2 != NULL)
        {
            newnode = (node *)malloc(sizeof(node));
            newnode->next = NULL;
            newnode->exp = t1->exp + t2->exp;
            newnode->coef = t1->coef * t2->coef;
            t3->next=newnode;
            t2 = t2->next;
            t3 = newnode;
        }
        t3 = p4;
        t1 = t1->next;
        t2=p2->next;
    }
}

void add(node *p3, node *p4, node *p5)
{
    node *t1 = p3->next, *t2 = p4->next, *t3 = p5, *newnode;
    int i;
    while (t1 != NULL && t2 != NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        if (t1->exp > t2->exp)
        {
            newnode->exp = t1->exp;
            newnode->coef = t1->coef;
            t1 = t1->next;
        }
        else if (t1->exp < t2->exp)
        {
            newnode->exp = t2->exp;
            newnode->coef = t2->coef;
            t2 = t2->next;
        }
        else
        {
            newnode->exp = t2->exp;
            newnode->coef = t2->coef + t1->coef;
            t1 = t1->next;
            t2 = t2->next;
        }
        t3->next = newnode;
        t3 = newnode;
    }
    while (t1 != NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->exp = t1->exp;
        newnode->coef = t1->coef;
        t1 = t1->next;
        t3->next = newnode;
        t3 = newnode;
    }

    while (t2 != NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->exp = t2->exp;
        newnode->coef = t2->coef;
        t2 = t2->next;
        t3->next = newnode;
        t3 = newnode;
    }
}