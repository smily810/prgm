#include<stdio.h>
#define MAX 5
int ch, front = 0, rear = -1, count=0;
char q[MAX], item;
void insert()
{
if(count == MAX)
printf("\nQueue is Full");
else {
printf("\nEnter the character to be inserted:");
scanf(" %d", &item);
rear = (rear + 1) % MAX;
q[rear]=item;
count++;
 }
}
void delete()
{
if(count == 0)
 printf("\nQueue is Empty");
else if(front > rear && rear==MAX-1)
{
front=0;
rear=-1;
count=0;
}
else
{
item=q[front];
printf("\nDeleted item is: %d",item);
front = (front + 1) % MAX;
count--;
}

}
void display()
{
int i=front,j;
if(count == 0)
printf("\nQueue is Empty");
else
{
printf("The queue elements are\n");
for(j=count;j!=0;j--)
{
printf("%d\t",q[i]);
i=(i+1)%MAX;
}
}
}
void main()
{
while(1)
{
 printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
printf("\n Enter the choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: insert();
break;
case 2: delete();
break;
case 3: display();
break;
case 4: exit(0);
break;
}
}
}
