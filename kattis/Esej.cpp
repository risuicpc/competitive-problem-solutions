#include <bits/stdc++.h>

using namespace std;
int an = 0, a, b;
void printcomb(char n, int k, vector<char> &v, char i)
{

    if (k == 0)
    {
        return;
    }
    if (i > n)
        return;

    v.push_back(i);
    for (char i : v)
        cout << i;
    cout << " ";
    an++;
    if (an == b)
        exit(0);
    if (v.size() > 1)
    {
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i];
        cout << " ";
        an++;
    }
    if (an == b)
        exit(0);
    printcomb(n, k - 1, v, i + 1);
    v.pop_back();
    printcomb(n, k, v, i + 1);
}

int main()
{
    vector<char> v;
    cin >> a >> b;
    printcomb('p', 9, v, 'a');
}