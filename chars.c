#include<stdio.h>
#include<conio.h>
#define DLE 16
#define STX 2
#define ETX 3
int main()
{
char ch,arr[50]={DLE,STX},rec[50];
int len=2,i,j;
//clrscr();
printf("enter the data stream:ctrl+p->DLE ctrl+b->STX ctrl+c->ETX \n");
while((ch=getch())!='\r')
{
if(ch==DLE)
{
arr[len++]=DLE;
printf("DLE");
}
else if(ch==STX)
printf("STX");
else if(ch==ETX)
printf("ETX");
else printf("%c",ch);
arr[len++]=ch;
}
arr[len++]=DLE;
arr[len++]=ETX;
printf("\n the stuffed stream is:\n");
for(i=0;i<len;i++)
{
ch=arr[i];
if(ch==DLE)
printf("DLE");
else if(ch==STX)
printf("STX");
else if(ch==ETX)
printf("ETX");
else printf("%c",ch);
}
//destuffing
printf("\n the destuffed data dtream is:\n");
for(j=2;j<len-2;j++)
{
ch=arr[j];
if(ch==DLE)
{
printf("DLE");
j++;
}
else if(ch==STX)
printf("STX");
else if(ch==ETX)
printf("ETX");
else printf("%c",ch);
}
system("pause");
getch ();
return 0;
}
