#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 200010
using namespace std;
typedef long long ll;
vector<ll> V;
int n, k;

void binary(ll l, ll r)
{
    if (l == r)
    {
        cout << l << "\n";
        return;
    }
    ll m = (l + r) / 2;
    int c = 1;
    ll sum = 0;
    rep(i, n)
    {
        if (sum + V[i] <= m)
            sum += V[i];
        else
        {
            c++;
            sum = V[i];
        }
    }
    if (c <= k)
        binary(l, m);
    else
        binary(m + 1, r);
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll mx = 0, sum = 0;
    rep(i, n)
    {
        ll x;
        cin >> x;
        mx = max(x, mx);
        sum += x;
        V.pb(x);
    }
    binary(mx, sum);
}