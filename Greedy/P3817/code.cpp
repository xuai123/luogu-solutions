#include<iostream>
using namespace std;
long long a[100001];
int main()
{
	long long n, x, sum = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int s = a[i] + a[i - 1];
		if (s > x)
		{
			int d = s - x;
			if (a[i] >= d)
			{
				a[i] -= d;		
			}
			else
			{
				a[i - 1] -= d - a[i];
				a[i] = 0;
			}
			sum += d;
		}
	}
	cout << sum << endl;
	return 0;
}