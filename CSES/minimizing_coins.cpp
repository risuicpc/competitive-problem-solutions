#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
int n, x;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    vector<int> v(n), pre(x + 1);
    rep(i, n) cin >> v[i];
    sort(all(v), greater<int>());

    pre[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        pre[i] = INT_MAX;
        rep(j, n)
        {
            if (v[j] <= i)
            {
                int rs = pre[i - v[j]];
                if (rs != INT_MAX && rs + 1 < pre[i])
                    pre[i] = rs + 1;
            }
        }
    }
    if (pre[x] == INT_MAX)
        cout << -1 << "\n";
    else
        cout << pre[x] << "\n";
}