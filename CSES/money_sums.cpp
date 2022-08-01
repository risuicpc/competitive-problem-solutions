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
    cin >> n;
    set<int> s;
    rep(i, n)
    {
        cin >> x;
        if (i > 0)
        {
            for (auto it = (--s.end()); it != s.begin(); it--)
                s.insert(x + *it);
            s.insert(*s.begin() + x);
        }
        s.insert(x);
    }
    cout << s.size() << "\n";
    for (int i : s)
        cout << i << " ";
}