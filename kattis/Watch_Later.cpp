#include <bits/stdc++.h>

using namespace std;
map<char, int> m;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int an = 1;
    while (true)
    {
        string t = "";
        for (int i = 0; i < s.size(); i++)
            if (i == 0 || s[i] != s[i - 1])
                t += s[i];
        if (t.size() == 1)
            break;
        m.clear();
        for (auto i : t)
            m[i]++;
        pair<char, int> ch = {m.begin()->first, m.begin()->second};
        for (auto i : m)
            if (ch.second > i.second)
                ch = i;

        an++;
        s = "";
        bool remove = false;
        for (int i = 0; i < t.size(); i++)
            if (t[i] != ch.first || remove)
                s += t[i];
            else
                remove = true;
    }
    cout << an << "\n";
}