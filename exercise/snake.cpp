// snake.cpp 
//let our numbers sorted like a snake in a matrix

#include<stdio.h>

void printss(int ss[],int n);

//to realize our function 
void snake(int ss[],int n)
{
	int init = n - 1;
	int temp = n;
	int z = 0;
	while (z <= n*n)
	{
		z++;

		if (ss[init] != 0)
		{
			init = init - temp;
			if (temp == 1)
			{
				temp = n;
			}
			else if (temp == n)
			{
				temp = -1;
			}
			else if (temp == -1)
			{
				temp = -n;
			}
			else if (temp == -n)
			{
				temp = 1;
			}
			init = init + temp;

		}

		ss[init] = z;

		init = init + temp;

	}


}


int main()
{
	const int n = 7;//it is the matirix dimension
	int ss[n*n] = {0};
	snake(ss, n);
	printss(ss, n);
    return 0;
}

//just used to print our matrix
void printss(int ss[],int n)
{
	for (int j = 0;j < n*n;j++)
	{
		if (j % n == 0) printf("\n");
		printf("%d\t", ss[j]);

	}
	printf("\n");
}