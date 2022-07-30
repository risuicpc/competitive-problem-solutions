#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    int n, k;
    cin >> n;
    map<string, vector<int>> m;
    while (n--)
    {
        cin >> s >> k;
        m[s].push_back(k);
    }

    for (auto i : m)
        sort(m[i.first].begin(), m[i.first].end());
    cin >> n;
    while (n--)
    {
        cin >> s >> k;
        cout << m[s][k - 1] << "\n";
    }
}