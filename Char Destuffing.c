#include<stdio.h>
#include<string.h>

int main()
{
	int i,k,j,n,p;
	char a[20],b[20];
	char c[] = {'D','L','E','S','T','X'};
	char d[] = {'D','L','E','E','T','X'};
	printf("Enter the size of frames: ");
	scanf("%d",&n);
	printf("Enter the chars: ");
	for(i=0;i<n;i++)
	{
		scanf("%s",&a[i]);
	}
	i = 0;
	
	while(i<n)
	{	for(i=0;i<n;i++)
		{
			if(a[i-2]=='D' && a[i-1]=='L' && a[i]=='E')
			{
				b[j] = a[i];
				j++;
				i = i+3;

			}
			else
			{
				b[j] = a[i];
				j++;
			}
		}
		
	}
printf("After De-Bit Stuffing :");

for(i=1;i<=j; i++)
    printf("%c",b[i]);

}
	
				

