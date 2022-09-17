#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, bool> m;

ll add(ll a, ll b, char o)
{
    return (o == '+' ? a + b : o == '*' ? a * b
                                        : a - b);
}

bool comp(pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b)
{
    if (a.first.first == 0 && a.first.second == 0)
        return 1;
    if (b.first.first == 0 && b.first.second == 0)
        return 0;
    if (a.first.second == 0)
        return 1;
    if (b.first.second == 0)
        return 0;
    if (a.first.first == 0)
        return 1;
    if (b.first.first == 0)
        return 0;
    return a.first.first == b.first.first ? a.first.second < b.first.second : a.first.first < b.first.first;
}

int main()
{
    int n;
    cin >> n;
    vector<char> op(n), o = {'+', '-', '*'};
    vector<pair<pair<ll, ll>, int>> v;
    vector<pair<ll, ll>> u;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({{a, b}, i});
        u.push_back({a, b});
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++)
    {
        bool an = 1;
        ll a = v[i].first.first, b = v[i].first.second;
        for (char j : o)
        {
            ll sum = add(a, b, j);
            if (!m[sum])
            {
                op[v[i].second] = j;
                m[sum] = 1;
                an = 0;
                break;
            }
        }
        if (an)
        {
            cout << "impossible\n";
            return 0;
        }
    }
    // for (auto i : v)
    //     cout << i.first.first << " " << i.first.second << "\n";

    for (int i = 0; i < n; i++)
    {
        ll a = u[i].first, b = u[i].second;
        cout << a << " " << op[i] << " " << b << " = " << add(a, b, op[i]) << "\n";
    }
}