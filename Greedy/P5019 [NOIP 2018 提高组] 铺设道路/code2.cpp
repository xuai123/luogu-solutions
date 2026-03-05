#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n + 1); // 从1开始索引
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    long long ans = 0; // 用long long防止溢出
    int prev = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] > prev) {
            ans += h[i] - prev;
        }
        prev = h[i];
    }

    cout << ans << endl;
    return 0;
}