#include <stdio.h>
#define MAXSIZE 5
char stack[MAXSIZE];
int top=-1;
void push(void);
void pop(void);
void display(void);
int palindrome(void);
void main()
{
int choice;
while(1)
{
printf("STACK OPERATION\n");
printf("1:PUSH\n");
printf("2:POP\n");
printf("3:DISPLAY\n");
printf("4:PALINDROME\n");
printf("5:EXIT\n");
printf("\n Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4:if(palindrome()==0)
printf("\nStack contents are palindrome\n");
else
printf("\nStack contents are not palindrome\n");
break;
case 5: exit(0);
default:printf("Enter a valid choice");
}
 }
}
void push()
{
int ele;
if(top>=(MAXSIZE-1))
{
printf("Stack Overflow\n");
}
else
{
printf("Enter the element to be pushed:");
scanf("%d",&ele);
top=top+1;
stack[top]=ele;
}
}
void pop ()
{
int ele;
if(top==-1)
{
printf("Stack Underflow\n");
}
else
{
ele=stack[top];
top=top-1;
printf("poped element : %d\n",ele);
}

}
void display ()
{
int i;
if(top==-1)
{
printf ("Stack Empty\n");
}
else
{
 printf ("The stack contents are:\n");
 for(i=0;i<=top;i++)
 printf ("%d\n",stack[i]);
}
}
int palindrome()
{
int rev[MAXSIZE];
int i,j=0;
for (i=top;i>=0;i--)
{
 rev[j]=stack[i];
 j=j+1;
}
printf("reversed content\n");
for(i=0;i<j;i++)
printf("%d\t ",rev[i]);
printf("\nstack content\n");
for(i=0;i<=top;i++)
printf("%d\t",stack[i]);
for(i=0;i<=top;i++)
{
 if (rev[i]==stack[i])
 continue;
 else
 return -1;
}
return 0;
}
