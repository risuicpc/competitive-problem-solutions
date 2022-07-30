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
int ans = 0;

ll power(ll n, ll r, ll m)
{
    if (r == 1)
        return n % m;
    else
    {
        ll p = power(n, r / 2, m) % m;
        p = (p * p) % m;
        if (r % 2)
            return (n * p) % m;

        else
        {
            return p;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (c == 0)
            cout << a << "\n";
        else if (b == 0)
            cout << 1 << "\n";
        else if (a == 0)
            cout << 0 << "\n";
        else
            cout << power(a, power(b, c, mod - 1), mod) << "\n";
    }
}