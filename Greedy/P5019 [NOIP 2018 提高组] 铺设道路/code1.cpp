#include<iostream>
#include<algorithm>
using namespace std;
int res[100001];
int f(int start, int end)
{
	if (start > end)return 0;
	while (start <= end && res[start] == 0)start++;
	while (start <= end && res[end] == 0)end--;
	if (start > end)return 0;
	int min = 10001;
	int j = start;
	for (int i = start; i <= end; i++)
	{
		if (res[i] < min)
		{
			min = res[i];
			j = i;
		}
	}
	for (int i = start; i <= end; i++)res[i] -= min;
	return min + f(start, j - 1) + f(j + 1, end);
}
int main()
{
	ios::sync_with_stdio(false);  // 关闭cin与stdio的同步
	cin.tie(nullptr);             // 解绑cin和cout（无需等待cout刷新）
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> res[i];
	cout << f(1, n);
	return 0;
}