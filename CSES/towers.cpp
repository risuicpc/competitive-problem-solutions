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
vi v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        int a;
        cin >> a;
        bool nr = 1;
        if (i > 0)
        {
            auto u = upper_bound(all(v), a);
            if (u != v.end())
            {
                nr = 0;
                v[u - v.begin()] = a;
            }
        }
        if (nr)
            v.pb(a);
    }
    cout << len(v) << "\n";
}