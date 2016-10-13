#include<stdio.h>

//get GCD(greatest common divisor)
int euclid(int,int);
int fabonacci(int);
int smallnum(int,int);
//Lame (small number of euclid is greater than fabonacci(count))
int count = 0;
int main(void)
{
	int s =0;
	int a=14;
	int b =26;
	s = euclid(a,b);
	printf("%d\n", s);
	printf("smallnum is:%d\n", smallnum(a,b));
	printf("fabonacci is :%d\n", fabonacci(count));
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
	{
		count++;
		return b;
	}
	else
	{
		count++;
		return euclid(b,a%b);
	}
}

int fabonacci(int a)
{
	if(a==1||a==0)
		return 1;
	else
		return fabonacci(a-1)+fabonacci(a-2);
}

int smallnum(int a,int b)
{
	if(a>=b)
		return b;
	else
		return a;
}