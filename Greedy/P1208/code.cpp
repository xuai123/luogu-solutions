#include<iostream>
#include<algorithm>
using namespace std;
struct good
{
	int p;//单价
	int a;//数量
};
good milk[2000001];
bool cmp(good milk1, good milk2)
{
	return milk1.p < milk2.p;
}
int main()
{
	ios::sync_with_stdio(false);  // 关闭cin与stdio的同步
	cin.tie(nullptr);             // 解绑cin和cout（无需等待cout刷新）
	int n, m;//n表示总需求，m表示农民数
	int sum = 0;//花费的总金额
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> milk[i].p >> milk[i].a;
	}
	sort(milk, milk + m, cmp);
	for (int i = 0; i < m; i++)
	{
		if (n >= milk[i].a)
		{
			sum += milk[i].a * milk[i].p;
			n -= milk[i].a;
		}
		else
		{
			sum += n * milk[i].p;
			break;
		}
	}
	cout << sum << endl;
	return 0;
}