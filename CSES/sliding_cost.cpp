#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
using namespace std;
typedef long long ll;
multiset<ll> s1, s2;
int n, k;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll sum1 = 0, sum2 = 0;
    rep(i, n)
    {
        if (len(s1) + len(s2) == k)
        {
            auto it = s1.find(v[i - k]);
            if (it == s1.end())
            {
                s2.erase(s2.find(v[i - k]));
                sum2 -= v[i - k];
            }
            else
            {
                s1.erase(it);
                sum1 -= v[i - k];
            }
        }
        if (len(s1) < len(s2))
        {
            sum1 += v[i];
            s1.insert(v[i]);
        }
        else
        {
            s2.insert(v[i]);
            sum2 += v[i];
        }
        if (len(s1) && len(s2))
        {
            ll l = *(--s1.end()), r = *s2.begin();
            if (l > r)
            {
                s1.erase(--s1.end());
                s2.erase(s2.begin());
                s1.insert(r);
                s2.insert(l);
                sum2 += (l - r);
                sum1 += (r - l);
            }
        }
        if (len(s1) + len(s2) == k)
        {
            ll m = *s2.begin();
            if (k % 2 == 0)
                m = *(--s1.end());
            cout << len(s1) * m - sum1 + sum2 - len(s2) * m << " ";
        }
    }
}