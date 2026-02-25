#include<iostream>
#include<algorithm>
using namespace std;
struct race
{
	int begin = 0;
	int end = 0;
};
race t[1000001];
bool cmp(const race& a, const race& b) 
{
	return a.end < b.end;   // 按结束时间升序
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i].begin >> t[i].end;
	sort(t, t + n, cmp);
	int sum = 1;
	int last = t[0].end;
	for (int i = 1; i < n; i++)
	{
		if (t[i].begin >= last)
		{
			sum++;
			last = t[i].end;
		}
	}
	cout << sum << endl;
	return 0;
}