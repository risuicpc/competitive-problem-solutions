#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1501
vector<int> c[N];
vector<pair<int, int>> r;
vector<string> v;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == '1')
                r.push_back({i + 1, j + 1});
            else if (v[i][j] == '3')
                c[i + 1].push_back(j + 1);

    for (int i = 1; i <= n; i++)
        sort(c[i].begin(), c[i].end());

    int an = 0;
    for (auto i : r)
    {
        int mn = 30000;
        for (int j = i.first; j <= n; j++)
        {
            if (j - i.first > mn || an > mn)
                break;
            auto k = lower_bound(c[j].begin(), c[j].end(), i.second);
            int ind = k - c[j].begin();
            if (k != c[j].end())
            {
                mn = min(mn, abs(i.first - j) + abs(i.second - c[j][ind]));
            }
            if (k != c[j].begin())
            {
                mn = min(mn, abs(i.first - j) + abs(i.second - c[j][ind - 1]));
            }
        }
        for (int j = i.first - 1; j > 0; j--)
        {
            if (i.first - j > mn || an > mn)
                break;
            auto k = lower_bound(c[j].begin(), c[j].end(), i.second);
            int ind = k - c[j].begin();
            if (k != c[j].end())
            {
                mn = min(mn, abs(i.first - j) + abs(i.second - c[j][ind]));
            }
            if (k != c[j].begin())
            {
                mn = min(mn, abs(i.first - j) + abs(i.second - c[j][ind - 1]));
            }
        }
        an = max(an, mn);
    }
    cout << an << "\n";
}