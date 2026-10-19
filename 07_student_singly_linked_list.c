#include<stdio.h>
#include<stdlib.h>

struct node
{
    char usn[10], name[10], branch[10], phno[10];
    int sem;
    struct node *link;
};

typedef struct node *NODE;
NODE temp;
NODE FIRST = NULL;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

void read()
{
    temp = getnode();
    temp->link = NULL;

    printf("enter the usn\n");
    scanf("%s", temp->usn);

    printf("enter the name\n");
    scanf("%s", temp->name);

    printf("enter the branch\n");
    scanf("%s", temp->branch);

    printf("enter the phno\n");
    scanf("%s", temp->phno);

    printf("enter the sem\n");
    scanf("%d", &temp->sem);
}

void create()
{
    int n;
    int i = 0;

    printf("enter the no. of students\n");
    scanf("%d", &n);

    while(i != n)
    {
        i++;
        printf("enter the student data\n");
        read();

        if(FIRST == NULL)
            FIRST = temp;
        else
        {
            temp->link = FIRST;
            FIRST = temp;
        }
    }
}

void display(NODE FIRST)
{
    NODE temp1 = FIRST;
    int count = 0;

    printf("student details \n");
    printf("USN\tname\tbranch\tphno\tsem\n");

    if(temp1 == NULL)
    {
        printf("student details is NULL and count is %d", count);
    }
    else
    {
        count = 1;
        while(temp1->link != NULL)
        {
            count++;
            printf("%s\t%s\t%s\t%s\t%d\n",
                   temp1->usn,
                   temp1->name,
                   temp1->branch,
                   temp1->phno,
                   temp1->sem);
            temp1 = temp1->link;
        }

        printf("%s\t%s\t%s\t%s\t%d\n",
               temp1->usn,
               temp1->name,
               temp1->branch,
               temp1->phno,
               temp1->sem);

        printf("\nstudent count:%d\n", count);
        return;
    }
}

NODE insertend(NODE FIRST)
{
    NODE last = FIRST;

    printf("enter the details of student\n");
    read();

    if(last != NULL)
    {
        while(last->link != NULL)
        {
            last = last->link;
        }
        last->link = temp;
    }
    else
    {
        FIRST = temp;
    }
    return FIRST;
}

void deletefront()
{
    NODE temp2 = FIRST;

    if(temp2 == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Deleted element is %s\n", temp2->usn);
        FIRST = temp2->link;
        free(temp2);
    }
    return;
}

void main()
{
    int choice;

    while(1)
    {
        printf("....MENU....\n");
        printf("press 1 for creating sll\n");
        printf("press 2 for display sll\n");
        printf("press 3 for insertion at end of sll\n");
        printf("press 4 for deletion at front of sll\n");
        printf("press 5 for exit\n");

        printf("enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create();
                    break;
            case 2: display(FIRST);
                    break;
            case 3: FIRST = insertend(FIRST);
                    break;
            case 4: deletefront();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
