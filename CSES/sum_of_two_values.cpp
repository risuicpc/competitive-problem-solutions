#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    map<int, vector<int>> a;
    for (int i = 1; i <= n; i++)
    {
        int X;
        cin >> X;
        a[X].push_back(i);
    }

    for (auto i : a)
    {
        if (i.first == x - i.first && i.second.size() > 1)
        {
            cout << i.second[0] << " " << i.second[1] << "\n";
            return 0;
        }
        else if (i.first != x - i.first && i.second.size() && a[x - i.first].size())
        {
            cout << i.second[0] << " " << a[x - i.first][0] << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}