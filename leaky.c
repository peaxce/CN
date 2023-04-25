#include<stdio.h>
#define min(x,y) ((x) < (y) ? (x) :(y))
#define MAX 25
int main()
{
   int cap, oprt, nsec, cont, i=0,dr=0, inp[MAX]={0}, ch, x;
    printf("\n\nLEAKY BUCKET ALGORITHM\n");
    printf("\nEnter bucket size : ");
    scanf("%d",&cap);
    printf("\nEnter output rate (no..of pkts/sec): ");
    scanf("%d",&oprt);
     do{
     printf("\nEnter the no..of packets entering at second %d: ",i+1);
     scanf("%d",&inp[i++]);
     printf("Enter 1 to insert packets or 0 to quit : ");
     scanf("%d",&ch);
     }while(ch);
   nsec=i;
   printf("\nSecond: Packets sent: Packets recvd: In bucket: Dropped\n");
   for(cont=i=0; cont || (i<nsec); i++)
   {
    printf(" (%d) :",i+1);
    printf(" (%d)\t: ",/*nsec?*/inp[i]/*:0*/);
    printf(" (%d)\t: ",min(cont+inp[i],oprt));
    if((x=cont+inp[i]-oprt)>0)
    if(x>cap)
    {
    cont=cap;
    dr=x-cap;
    }
    else
    {
    cont=x;
    dr=0;
    }
    else
    cont=0;
    printf(" %d\t:",cont);
    printf(" %d\n",dr);
  }
  return 0;
}
