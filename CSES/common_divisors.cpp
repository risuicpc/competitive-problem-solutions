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
vi v(N);
vector<bool> pri(1000000);

int main()
{
    for (int i = 2; i * i <= 1000000; i++)
        if (!pri[i])
            for (int j = 2 * i; j <= 1000000; j += i)
                if (!pri[j])
                    pri[j] = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
}