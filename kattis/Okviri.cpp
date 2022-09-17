#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "..#..";
    string s2 = ".#.#.";
    string s3 = "#.X.#";

    string t1 = "..*..";
    string t2 = ".*.*.";
    string t3 = "*.X.*";

    string s, a1 = "", a2 = "", a3 = "";
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if ((i + 1) % 3 == 0)
        {
            a1 += t1.substr(1);
            a2 += t2.substr(1);
            t3[2] = s[i];
            a3 += t3.substr(1);
        }
        else
        {
            a1 += (i == 0 ? s1 : s1.substr(1));
            a2 += (i == 0 ? s2 : s2.substr(1));
            s3[2] = s[i];
            if ((i + 2) % 3 == 0 && s.size() > i + 1)
                s3[4] = '*';
            else
                s3[4] = '#';
            a3 += (i == 0 ? s3 : s3.substr(1));
        }
    }
    cout << a1 << "\n"
         << a2 << "\n"
         << a3 << "\n"
         << a2 << "\n"
         << a1 << "\n";
}