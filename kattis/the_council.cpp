#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, ll>> e;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        e.push_back({{a, b}, c});
    }
    sort(e.begin(), e.end(), comp);

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        if (v[e[i].first.first] > v[e[i].first.second])
            an[e[i].first.first] += e[i].second,
                an[e[i].first.second] -= e[i].second;
        else if (v[e[i].first.first] < v[e[i].first.second])
            an[e[i].first.first] -= e[i].second,
                an[e[i].first.second] += e[i].second;
        else
        {
            if (an[e[i].first.first] < an[e[i].first.second])
                an[e[i].first.first] += e[i].second,
                    an[e[i].first.second] -= e[i].second;
            else
                an[e[i].first.first] -= e[i].second,
                    an[e[i].first.second] += e[i].second;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += v[i] * an[i];
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << " ";
        cout << an[i];
    }
}