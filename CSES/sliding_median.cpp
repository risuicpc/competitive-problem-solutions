#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
using namespace std;
typedef long long ll;
multiset<int> s1, s2;
int n, k;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    rep(i, n)
    {
        if (len(s1) + len(s2) == k)
        {
            auto it = s1.find(v[i - k]);
            if (it == s1.end())
                s2.erase(s2.find(v[i - k]));
            else
                s1.erase(it);
        }
        if (len(s1) < len(s2))
            s1.insert(v[i]);
        else
            s2.insert(v[i]);
        if (len(s1) && len(s2))
        {
            int l = *(--s1.end()), r = *s2.begin();
            if (l > r)
            {
                s1.erase(--s1.end());
                s2.erase(s2.begin());
                s1.insert(r);
                s2.insert(l);
            }
        }
        if (len(s1) + len(s2) == k)
        {
            if (k % 2)
                cout << *s2.begin() << " ";
            else
                cout << *(--s1.end()) << " ";
        }
    }
}