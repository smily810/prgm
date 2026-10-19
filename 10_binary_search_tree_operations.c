#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE root = NULL;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;

    temp = getnode();
    temp->data = item;
    temp->llink = NULL;
    temp->rlink = NULL;

    if(root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        prev = NULL;
        cur = root;

        while(cur != NULL)
        {
            prev = cur;
            cur = (temp->data < cur->data) ? cur->llink : cur->rlink;
        }

        if(temp->data < prev->data)
            prev->llink = temp;
        else
            prev->rlink = temp;
    }
    return root;
}

void pre(NODE root)
{
    if(root)
    {
        printf("%d\t", root->data);
        pre(root->llink);
        pre(root->rlink);
    }
}

void in(NODE root)
{
    if(root)
    {
        in(root->llink);
        printf("%d\t", root->data);
        in(root->rlink);
    }
}

void post(NODE root)
{
    if(root)
    {
        post(root->llink);
        post(root->rlink);
        printf("%d\t", root->data);
    }
}

void traversal(NODE root)
{
    if(root == NULL)
    {
        printf("tree is empty\n");
        return;
    }

    printf("\npreorder traversal....\n");
    pre(root);

    printf("\ninorder traversal....\n");
    in(root);

    printf("\npostorder traversal....\n");
    post(root);
}

NODE search(NODE root)
{
    int item, i = 0;

    printf("enter the element to be searched\n");
    scanf("%d", &item);

    while(root != NULL)
    {
        if(item == root->data)
        {
            i++;
            printf("key found in tree\n");
        }

        if(item < root->data)
            root = root->llink;
        else
            root = root->rlink;
    }

    if(i == 0)
        printf("key not found\n");

    return root;
}

void main()
{
    int choice, item, i, n;

    while(1)
    {
        printf("\n\t 1 - insert\n");
        printf("\t 2 - traversal\n");
        printf("\t 3 - search\n");
        printf("\t 4 - exit\n");

        printf("\tenter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("enter the number of elements to insert\n");
                scanf("%d", &n);

                for(i = 0; i < n; i++)
                {
                    printf("enter item to be inserted\n");
                    scanf("%d", &item);
                    root = insert(item, root);
                }
                break;

            case 2:
                traversal(root);
                break;

            case 3:
                search(root);
                break;

            case 4:
                exit(0);

            default:
                printf("\n\tenter proper choice....\n");
        }
    }
}
