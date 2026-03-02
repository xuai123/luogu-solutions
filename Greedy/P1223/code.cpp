#include<iostream>
#include<iomanip>
using namespace std;
struct Time
{
	int time = 0;
	int index = 0;
};
Time t[1010];
void Swap(Time &t1, Time &t2)
{
	Time t3 = t1;
	t1 = t2;
	t2 = t3;
}
int main()
{
	double N, total = 0, cmp = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> t[i].time;
		t[i].index = i;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (t[j].time < t[i].time)Swap(t[j], t[i]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << t[i].index << " ";
		if (i < N)
		{
			cmp += t[i].time;
			total += cmp;
		}
	}
	cout << endl;
	cout << fixed << setprecision(2) << total / N << endl;
	return 0;

}