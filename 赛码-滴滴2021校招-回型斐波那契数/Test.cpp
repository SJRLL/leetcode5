//题目描述：输入一个整数，输出逆时针打印斐波那契矩阵
3
34 21 13
1  1  8
2  3  5

#include<iostream>
#include<string> 
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long a[81 + 1];
void func()
{
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i<81; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
}
int main()
{
	func();
	/*
	for(int i=0;i<81;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	*/
	int n;
	cin >> n;
	long long **ans = new long long*[n];
	for (int i = 0; i<n; i++)
	{
		ans[i] = new long long[n];
	}
	int up = 0;
	int down = n - 1;
	int left = 0;
	int right = n - 1;
	int i, j;
	int k = n * 2 - 1;
	while (true)
	{
		for (i = left; i <= right; i++)
			ans[up][i] = a[k--];
		up++;
		if (up>down)
			break;

		for (j = up; j <= down; j++)
			ans[j][right] = a[k--];
		right--;
		if (right<left)
			break;

		for (i = right; i >= left; i--)
			ans[down][i] = a[k--];
		down--;
		if (down<up)
			break;
		for (j = down; j >= up; j--)
			ans[j][left] = a[k--];
		left++;
		if (left>right)
			break;
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}