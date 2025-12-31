#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void insert(int a[MAX], int num)
{
    int i, key, index;
    key = num % MAX;

    if(a[key] == -1)
        a[key] = num;
    else
    {
        printf("Collision detected and avoided successfully using LINEAR PROBING\n");

        for(i = 0; i < MAX; i++)
        {
            index = (key + i) % MAX;
            if(a[index] == -1)
                break;
        }

        if(a[index] == -1)
            a[index] = num;
        else
            printf("\n Hash table is full");
    }
}

void display(int a[MAX])
{
    int i;
    printf("\n the hash table is\n");

    for(i = 0; i < MAX; i++)
    {
        printf(" %d \t %d \n", i, a[i]);
    }
}

int main()
{
    int a[MAX], num, key, i;
    int ans = 1;

    printf(" Hash Table demo with collision handling by linear probing : \n");

    for(i = 0; i < MAX; i++)
        a[i] = -1;

    do
    {
        printf("\n Enter the data to insert into hash table:");
        scanf("%d", &num);

        insert(a, num);

        printf("\n Do you wish to continue ? (1/0) ");
        scanf("%d", &ans);

    } while(ans);

    display(a);
}
