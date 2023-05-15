#include<stdio.h>
#include<math.h>

int gcd(int a, int h)
{
	int temp;
	while(1)
	{
		temp = a%h;
		if(temp == 0)
		return h;
		a=h;
		h=temp;
	}
}

int main()
{
	double p=3;
	double q=7;
	double n=p*q;
	double count;
	double tot=(p-1)*(q-1);
	double e=2;
	while(e<tot)
	{
		count = gcd(e,tot);
		if(count==1)
		break;
		else
		e++;
	}
	double d;
	double k=2;
	d=(1+(k*tot))/e;
	double msg=12;
	double c=pow(msg,e);
	double m=pow(c,d);
	c=fmod(c,n);
	m=fmod(m,n);
	printf("Message Data = %lf",msg);
	printf("\n p = %lf",p);
	printf("\n q = %lf",q);
	printf("\n n = %lf",n);
	printf("\n totsent = %lf",tot);
	printf("\n e = %lf",e);
	printf("\n d = %lf",d);
	printf("\n Encrypted Data = %lf",c);
	printf("\n Decrypted Data = %lf",m);
}

