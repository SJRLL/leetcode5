//��Ŀ��������һ����������������ڶ�������n�粻�ظ��Ĵ�д��ĸ������Զ�ɼ�������������n�����ظ���д��ĸ������߳ɼ�
 //         �����ú����ɼ�����

//10 
//A B C D E F X H I J
//A C I X E F J H D B

#include<iostream>
#include<string> 
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char* a = new char[n];
	char* b = new char[n];
	for (int i = 0; i<n; i++)
		cin >> a[i];
	for (int i = 0; i<n; i++)
		cin >> b[i];
	int tmpA[26];
	int tmpB[26];
	memset(tmpA, 0, sizeof(tmpA));
	memset(tmpB, 0, sizeof(tmpB));
	int i = 0;
	while (a[i] != 'X' && i<n)
	{
		tmpA[a[i] - 'A']++;
		i++;
	}
	i++;
	while (i<n)
	{
		tmpB[a[i] - 'A']++;
		i++;
	}
	int j = 0;
	while (b[j] != 'X' && j<n)
	{
		tmpA[b[j] - 'A']++;
		j++;
	}
	j++;
	while (j<n)
	{
		tmpB[b[j] - 'A']++;
		j++;
	}
	int zuihao = 0;
	int zuihuai = 0;
	for (int i = 0; i<26; i++)
	{
		//cout<<tmpA[i]<<" "; 
		if (tmpA[i] == 2)
			zuihao++;
	}
	//  cout<<endl;
	for (int i = 0; i<26; i++)
	{
		//cout<<tmpB[i]<<" "; 
		if (tmpB[i] == 2)
			zuihuai++;
	}
	//  cout<<endl;
	cout << zuihao + 1 << " " << n - zuihuai << endl;
	system("pause");
	return 0;
}
