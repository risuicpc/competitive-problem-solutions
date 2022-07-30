#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define len(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define N 200010
using namespace std;
typedef long long ll;
int n, m, k, x;
int ans = 1;
vi v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    map<int, int> y;
    int j = 0;
    rep(i, n)
    {
        cin >> x;
        if (y.count(x))
        {
            if (x == v[v.size() - 1])
                j = i;
            else
                j = max(j, y[x] + 1);
        }
        ans = max(ans, i + 1 - j);
        y[x] = i;
        v.pb(x);
    }
    cout << ans << "\n";
}