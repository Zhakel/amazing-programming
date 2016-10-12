// cow.cpp : 定义控制台应用程序的入口点。

#include<iostream>
using namespace std;


int main(void)
{
	int count = 1;//第一年
	int cow[4];
	cow[0] = 1;//出生，第一年
	cow[1] = 0;//第二年
	cow[2] = 0;//第三年
	cow[3] = 0;//第四年

	int year = 20;

	while (count < year)
	{
		int temp = 0;
		cow[3] += cow[2];//可以生奶牛的奶牛数
		cow[2] = cow[1];//三岁的奶牛
		cow[1] = cow[0];//两岁的奶牛
		cow[0] = cow[3];//新生奶牛
		count++;//加一年

	}
	int total = cow[0] + cow[1] + cow[2] + cow[3];//奶牛总数
	cout << "There will be "<<total <<" cows"<< endl;

	return 0;
}
