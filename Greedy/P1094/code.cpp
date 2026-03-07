#include<iostream>
#include<algorithm>
using namespace std;
int res[30010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w, n;//w表示上限，n表示个数
	cin >> w >> n;
	int sum = n;//sum表示总组数
	for (int i = 0; i < n; i++)
	{
		cin >> res[i];
	}
	sort(res, res + n);
	int i = 0, j = n - 1;
	while (i < j)
	{
		//固定i
		if (res[i] + res[j] > w)
		{
			j--;
		}
		else
		{
			sum--;//两个已经配对，组数-1
			i++;
			j--;
		}

	}
	cout << sum << endl;
	return 0;
}