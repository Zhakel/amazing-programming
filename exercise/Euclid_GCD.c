#include<stdio.h>

//get GCD(greatest common divisor)
int euclid(int,int);

int main(void)
{
	int s =0;
	s = euclid(12,36);
	printf("%d\n", s);
	return 0;
}

int euclid(int a,int b)
{
	if(a==0||b==0)	return 0;//return 0 means error
	int temp=0;
	if(a<b)
	{
		return euclid(b,a);
	}
	if(a%b==0)
		return b;
	else
	{
		return euclid(b,a%b);
	}
}