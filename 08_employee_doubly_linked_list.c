#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[20], name[10], dept[15], desig[10], phno[15];
    int sal;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;
NODE temp, FIRST = NULL, END = NULL;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

void read()
{
    temp = getnode();
    temp->llink = NULL;
    temp->rlink = NULL;

    printf("\tenter SSN:");
    scanf("%s", temp->ssn);

    printf("\tenter name:");
    scanf("%s", temp->name);

    printf("\tenter dept:");
    scanf("%s", temp->dept);

    printf("\tenter designation:");
    scanf("%s", temp->desig);

    printf("\tenter PhNo:");
    scanf("%s", temp->phno);

    printf("\tenter salary:");
    scanf("%d", &temp->sal);
}

void create()
{
    int n, i = 0;

    printf("\tenter the number of employee:");
    scanf("%d", &n);

    while(i != n)
    {
        i++;
        printf("\tenter the details of %d employ:\n", i);
        read();

        if(FIRST == NULL)
        {
            FIRST = temp;
            END = temp;
        }
        else
        {
            END->rlink = temp;
            temp->llink = END;
            END = temp;
        }
    }
    printf("\tcreation of DLL for employee %d is done\n", i);
}

void display()
{
    NODE temp1 = FIRST;
    int count = 1;

    printf("\templopyee details are:\n");

    if(temp1 == NULL)
        printf("\temployee details and count is %d\n", count - 1);
    else
    {
        printf("\tSSN\tNAME\tDEPARTMRNT\tDESIGNATION\tPHNO\tSALARY\n");

        while(temp1 != NULL)
        {
            count++;
            printf("\t%s\t%s\t%s\t\t%s\t\t%s\t%d\n",
                   temp1->ssn,
                   temp1->name,
                   temp1->dept,
                   temp1->desig,
                   temp1->phno,
                   temp1->sal);

            temp1 = temp1->rlink;
        }
        printf("\temployee count is %d\n", count - 1);
    }
}

void insertfront()
{
    printf("\tenter details of employee\n");
    read();

    if(FIRST == NULL)
    {
        FIRST = temp;
    }
    else
    {
        temp->rlink = FIRST;
        FIRST->llink = temp;
        FIRST = temp;
    }
}

void insertend()
{
    printf("\tenter the details of new employ\n");
    read();

    if(FIRST == NULL)
    {
        FIRST = temp;
        END = temp;
    }
    else
    {
        END->rlink = temp;
        temp->llink = END;
        END = temp;
    }
}

void deletefront()
{
    NODE temp2;

    if(FIRST == NULL)
    {
        printf("\tlist is empty\n");
    }
    else
    {
        temp2 = FIRST;
        printf("\tdeleted employ is %s\n", temp2->ssn);
        FIRST = FIRST->rlink;
        FIRST->llink = NULL;
        free(temp2);
    }
}

void deleteend()
{
    NODE temp2 = END;

    if(temp2 == NULL)
    {
        printf("\tlist is empty\n");
    }
    else if(FIRST == END)
    {
        printf("\tdeleted employee is %s\n", temp2->ssn);
        FIRST = NULL;
        END = NULL;
    }
    else
    {
        printf("\tdeleted employee is %s\n", temp2->ssn);
        END = END->llink;
        END->rlink = NULL;
        free(temp2);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\t1.creation DLL\n");
        printf("\t2.display DLL\n");
        printf("\t3.insertion at front\n");
        printf("\t4.insertion at end\n");
        printf("\t5.deletion at front\n");
        printf("\t6.deletion at end\n");
        printf("\t7.exit\n");

        printf("\tenter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insertfront();
                    break;
            case 4: insertend();
                    break;
            case 5: deletefront();
                    break;
            case 6: deleteend();
                    break;
            case 7: exit(0);
            default: printf("\tinvalid choice\n");
                     break;
        }
    }
}
