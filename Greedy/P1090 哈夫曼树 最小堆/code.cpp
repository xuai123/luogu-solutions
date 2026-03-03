#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        p.push(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        int total = a + b;
        p.push(total);
        sum += total;
    }
    cout << sum << endl;
    return 0;
}