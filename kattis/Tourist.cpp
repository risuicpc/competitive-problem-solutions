#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, int> mp;

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<vector<int>> an(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (v[i][j] != '#')
                {
                    an[i][j] = max(an[max(0, i - 1)][j], an[i][max(0, j - 1)]);
                    if (v[i][j] == '*')
                    {
                        an[i][j]++;
                        mp[an[i][j]]++;
                    }
                }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << an[i][j];
            cout << "\n";
        }
        for (auto i : mp)
            cout << i.first << " " << i.second << "\n";
        cout << "\n";
        mp.clear();
    }
}