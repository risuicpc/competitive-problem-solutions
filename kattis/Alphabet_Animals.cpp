#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> v;
map<char, int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string w, s;
    cin >> w;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        a[s[0]]++;
        if (s[0] == w[w.size() - 1])
            v.emplace_back(s);
    }
    if (v.size() == 0)
        cout << "?\n";
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            int j = a[v[i][v[i].size() - 1]];
            if (v[i][0] == v[i][v[i].size() - 1])
                j--;
            if (j <= 0)
            {
                cout << v[i] << "!\n";
                return 0;
            }
        }
        cout << v[0] << "\n";
    }
}