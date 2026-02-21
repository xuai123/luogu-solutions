#include<iostream>
#include<cstring>
using namespace std;
char res[2000][2000];
void copy(int n, int a2, int b2)
//将数组的左上角层度为n级的一块矩形拷贝到左上角为(a2,b2)的区域
{
	const int width = 1 << n;//待复制区域的纵向宽度
	const int length = 1 << (n + 1);//待复制区域的横向长度
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			res[a2 + i][b2 + j] = res[i][j];
		}
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	const int x = 1 << n;
	const int y = 1 << (n + 1);
	memset(res, ' ', sizeof(res));
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			res[0][0] = ' ';
			res[0][1] = '/';
			res[0][2] = '\\';
			res[1][0] = '/';
			res[1][1] = '_';
			res[1][2] = '_';
			res[1][3] = '\\';
		}
		else
		{
			copy(i - 1, 1 << (i - 1), 0);
			copy(i - 1, 1 << (i - 1), 1 << i);
		}
	}
	const int num = (1 << n) - 2;
	for (int i = 0; i < x; i++)
	{
		int k = num - (i / 2) * 2;
		for (int l = 1; l <= k; l++)
		{
			cout << ' ';
		}
		for (int j = 0; j <= y; j++)
		{
			cout << res[i][j];
		}
		cout << "\n";
	}

	return 0;
}