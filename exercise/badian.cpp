#include<iostream>
/*
找出一个二维数组中的靶点，即该位置上的元素在该行上最大、在该列上最小。也有可能没有靶点。
int a[5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};//有靶点  靶点是5
int a[5][5]={1,2,3,4,55,6,7,8,9,40,11,12,13,14,30,16,17,18,19,30,21,22,23,24,25};//有靶点 靶点是25
int a[5][5]={1,2,3,15,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};;//没有靶点
*/

using namespace std;


int max(int *a,int num);
int min(int *a,int num);
const int row =5;
const int col =5;


int main()
{


	int a[row][col]={100,200,300,100,100,11,11,11,11,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	for(int i = 0;i <row;i++)
	{
		int maxrow = max(a[i],row);
		int maxrownum = a[i][maxrow];

		for(int j=0;j<col;j++)
		{
			if(a[i][j]==maxrownum)
			{
				int mincol = min(*a+j,col);
				int mincolnum = a[mincol][j];
				if(a[i][j]==mincolnum)
					{
						cout<<"靶点大小为："<<a[i][j]<<",是数组中的第"<<i<<"行第"<<j<<"列"<<endl;
					}
			}
		}
	
	}



	return 0;
}


int max(int *a,int num)
{
	int max =0;
	for(int i=0;i<num;i++)
	{
		if(a[i]>=a[max])
		{
			max =i;
		}
	}
//	cout<<max<<endl;
	return max;
}

int min(int *a,int num)
{
	int min =0;
	for(int i=0;i<row*col;i=i+col)
	{
		if(a[i]<=a[min])
		{
			min =i;
		}
	}
//	cout<<min/col<<endl;
	return min/col;
}

