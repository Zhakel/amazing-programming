// abcdefghi.cpp : 定义控制台应用程序的入口点。
//用来寻找三个三位数a,b,c;满足b=2a,c=3a;并且a,b,c所有位上的数字正好是1到9
#include<time.h>
#include<stdio.h>
#include<iostream>

using namespace std;

void findsth();
//简洁的代码，十分美观
void result(int num, int &result_add, int &result_mul)
{
	int i, j, k;

	i = num / 100;        //百位
	j = num / 10 % 10;    //十位
	k = num % 10;         //个位

	result_add += i + j + k;    //分解出来的位数相加
	result_mul *= i * j * k;    //相乘
}
void officemain()
{
	int i, j, k;
	int result_add, result_mul;

	for (i = 123; i <= 329; i++)//最小那个数的范围是123到987/3之间，然后进行便利
	{
		j = i * 2;
		k = i * 3;

		result_add = 0;
		result_mul = 1;



		result(i, result_add, result_mul);
		result(j, result_add, result_mul);
		result(k, result_add, result_mul);

		if (result_add == 45 && result_mul == 362880)
			;//printf("%d %d %d\n", i, j, k);
	}
}
//朋友的版本1
void findshen()
{
	int a[10];
	int temp = 0;
	for (int i = 123; i <= 329; i++)
	{
		temp = i;
		for (int m = 0;m < 10;m++)
			a[m] = 0;
		int j = i * 2;
		int k = i * 3;
		a[i / 100] = 1;
		i = i - i / 100 * 100;
		a[i / 10] = 1;
		i = i - i / 10 * 10;
		a[i] = 1;
		a[j / 100] = 1;
		j = j - j / 100 * 100;
		a[j / 10] = 1;
		j = j - j / 10 * 10;
		a[j] = 1;
		a[k / 100] = 1;
		k = k - k / 100 * 100;
		a[k / 10] = 1;
		k = k - k / 10 * 10;
		a[k] = 1;
		for (int m = 1;m < 10;m++)
			if (a[m] == 0)
				a[0] = 1;
		if (a[0] == 0)
			cout << i << "," << j << "," << k << endl;
		i = temp;
	}
}
//朋友的版本2
void findshen2()
{
	int a[10];
	int temp = 0;
	for (int i = 123; i <= 329; i++)
	{
		temp = i;
		for (int m = 0;m < 10;m++)
			a[m] = 0;
		int j = i * 2;
		int k = i * 3;
		a[i / 100] = 1;
		a[(i - i / 100 * 100) / 10] = 1;
		a[i % 10] = 1;
		a[j / 100] = 1;
		a[(j - j / 100 * 100) / 10] = 1;
		a[j % 10] = 1;
		a[k / 100] = 1;
		a[(k - k / 100 * 100) / 10] = 1;
		a[k % 10] = 1;
		for (int m = 1;m < 10;m++)
			if (a[m] == 0)
				a[0] = 1;
		if (a[0] == 0)
			cout << i << "," << j << "," << k << endl;
		i = temp;
	}
}

int main()
{  
	for (int z = 0;z < 1;z++)
	{//无聊的测试运行时间
		printf("a\tb\tc\n");
		findsth();
	}
	
	printf("running time is %lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

//我那好长的代码，但是跑起来很快
void findsth()
{
	int a = 1;
	int b = 1;
	int c = 1;
	int d = 1;
	int e = 1;
	int f = 1;
	int g = 1;
	int h = 1;
	int i = 1;
	int num1 = 123;
	int temp = num1;
	int num2 = 0;
	int num3 = 0;
	for (;num1 < 333;)
	{
		num2 = num1 * 2;
		num3 = num1 * 3;
		a = num1/100;
		c = num1 % 10;
		b = num1 / 10 % 10;

		//if ((a == b) || (a == c) || (b == c)) continue;
		d = num2/100;
		f = num2 % 10;
		e = num2 / 10 % 10;

		//if ((d == e) || (d == f) || (e == f)) continue;
		g = num3/100;
		i = num3 % 10;
		h = num3 / 10 % 10;

		//if ((g == h) || (g == i) || (h == i)) continue;


		if (a != b&&a!=c&&a != d&&a != e&&a != f&&a != g&&a != h&&a != i)
		{
			if (b != c&&b != d&&b != e&&b != f&&b != g&&b != h&&b != i)
			{
				if (c != d&&c != e&&c != f&&c != g&&c != h&&c != i)
				{
					if (d != e&&d != f&&d != g&&d != h&&d != i)
					{
						if (e != f&&e != g&&e != h&&e != i)
						{
							if (f != g&&f != h&&f != i)
							{
								if (g != h&&g != i)
								{
									if (h != i)
									{
										printf("%d%d%d\t%d%d%d\t%d%d%d\n", a, b, c, d, e, f, g, h, i);
									}
								}
							}
						}
					}
				}
			}
			
		}


		num1 = temp;
		temp++;


	}
	



}
