#include<iostream>
#include<algorithm>
using namespace std;
int x[5001], y[5001];
const int infinite = 101;
int main()
{
	int n, s, a, b;
	cin >> n >> s >> a >> b;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		if (x[i] > a + b)y[i] = infinite;
	}
	sort(y, y + n);
	int j = 0;
	while (j < n)
	{
		if (s < y[j])break;
		s -= y[j];
		j++;
	}
	cout << j << endl;
	return 0;
}