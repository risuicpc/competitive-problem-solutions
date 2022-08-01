#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;
map<ll, ll> pre;
ll n, a, an = 0, sum = 0;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, n)
    {
        cin >> a;
        sum += a;
        if (sum % n == 0)
            an++;

        if (pre.find(sum % n) != pre.end())
            an += (pre[sum % n]);

        if (sum > 0 && pre.find(sum % n - n) != pre.end())
            an += (pre[sum % n - n]);
        else if (sum < 0 && pre.find(n + sum % n) != pre.end())
            an += (pre[n + sum % n]);
        pre[sum % n]++;
    }
    cout << an << "\n";
    return 0;
}