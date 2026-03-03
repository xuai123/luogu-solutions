#include<iostream>
#include<string>
using namespace std;
int main()
{
	string n;
	int k, sum = 0;//k表示总操作数，sum表示操作的次数
	cin >> n >> k;
	//每次删除首个逆序对，确保高位数最小
	while (sum < k)
	{
		bool deleted = 0;//检查是否进行了删除操作，如果没有进行说明是单增的
		for (int i = 0; i < n.size() - 1; i++)
		{
			if (n[i] > n[i + 1])
			{
				n.erase(i, 1);
				deleted = 1;
				sum++;
				break;
			}
		}
		//如果是单增数列就退出循环
		if (deleted == 0)break;
	}
	
	//如果还不够，删去后面几位
	if (sum < k)
	{
		int d = k - sum;
		n.erase(n.size() - d);
	}
	int m = 0;
	for (; n[m] == '0'; m++);
	if (m == n.size())cout << 0 << endl;
	else cout << &n[m] << endl;
	return 0;
}