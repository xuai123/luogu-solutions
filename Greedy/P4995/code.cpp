#include<iostream>
#include<algorithm>
using namespace std;
long long res[500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;//n表示个数
	cin >> n;
	long long sum = 0;//sum表示总体力值
	for (int i = 1; i <= n; i++)
	{
		cin >> res[i];
	}
	sort(res, res + n + 1);
	int i = 0, j = n, time = 0;
	while (i < j)
	{
		sum += (res[i] - res[j]) * (res[i] - res[j]);
		if (time % 2 == 0)i++;
		else j--;
		time++;
	}
	cout << sum << endl;
	return 0;
}