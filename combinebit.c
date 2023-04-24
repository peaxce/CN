#include<stdio.h>
#include<string.h>

int main()
{
	int a[20],b[20],i,k,j,n,l,g,h,x;
	int c[]={0,1,1,1,1,1,1,0};
	printf("Enter the size of frames: ");
	scanf("%d",&n);
	printf("Enter the bits in 1 and 0 form: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	i = 0;
	int count = 1;
	j = 0;
	
	while(i<n)
	{
		if(a[i]==1)
		{
			b[j] = a[i];
			for(k=i+1;a[k]==1 && count<5 && k<n;k++)
			{
				j++;
				b[j]=a[k];
				count++;
				if (count == 5)
				{
					j++;
					b[j]=0;
				}
				i=k;
			}
		}
		else
		{
			b[j] = a[i];
		}
		i++;
		j++;
	}
	printf("After Bit Stuffing :");
	for(i=0; i<j; i++)
    	printf("%d",b[i]);
    printf(" ");
    
    g = 0;
	count = 1;
	h = 0;
	l = sizeof(b);
	int d[100];
	
	while(g<l)
	{
		if(b[g]==1)
		{
			d[h] = b[g];
			for(k=g+1;b[k]==1 && count<5 && k<l;k++)
			{
				h++;
				d[h]=b[k];
				count++;
				if (count == 5)
				{
					k++;
					count = 0; 
				}
				g=k;
			}
		}
		else
		{
			d[h] = b[g];
		}
		g++;
		h++;
	}
	printf("After Bit De-Stuffing :");	
	for(x=0; x<n; x++)
	{
		printf("%d",d[x]);
	}
    	
	return 0;
}



