#include<iostream>
#include<iomanip>
using namespace std;
struct rate
{
	double imp = 0.0000;
	int index = 0;
};
double w[110], v[110];
rate r[110];
void Swap(rate &r1, rate &r2)
{
	rate r3 = r1;
	r1 = r2;
	r2 = r3;
}
int main()
{
	double N, T;//N表示堆数,T表示容量
	double value = 0.000;
	cin >> N >> T;
	for (int i = 1; i <= N; i++)
	{
		cin >> w[i] >> v[i];
		r[i].imp = 1.0000 * v[i] / w[i];
		r[i].index = i;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (r[j].imp > r[i].imp)Swap(r[j], r[i]);
		}
	}
	//开始拿金币，先拿最有价值的
	for (int i = 1; i <= N; i++)
	{
		if (T <= 0)break;
		int j = r[i].index;
		if (T >= w[j])
		{
			value += v[j] * 1.0000;
			T -= w[j];
			
		}
		else
		{
			value += double(T * 1.0000) * r[i].imp;
			T = 0;
		}
	}
	cout << fixed << setprecision(2) << value << endl;
	return 0;

}