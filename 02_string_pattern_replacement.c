#include<stdio.h>
#include<string.h>
void main()
{
char instr[50],pat[50],rep[50],outstr[50];
int i,j,k,m;
int found=0;
printf("enter the text\n");
gets(instr);
printf("enter the pattern\n");
gets(pat);
printf("enter the replace string\n");
gets(rep);
m=0;
for(i=0;instr[i]!='\0';i++)
{
 for(j=0;pat[j]!='\0';j++)
 {
 if(instr[i++]==pat[j])
 continue;
 else
 break;
 }
 if(pat[j]=='\0')
 {
 for(k=0;rep[k]!='\0';k++)
 outstr[m++]=rep[k];
 i--;
 found=1;
 }
 else
 {
 i=i-j-1;
 outstr[m++]=instr[i];
 }
}
outstr[m]='\0';
puts(instr);
puts(outstr);
if(found==0)
printf("pattern does not exist\n");
}
