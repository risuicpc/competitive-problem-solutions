#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
bool vis[7][7];
int an = 0, n = 7;
string s;

bool visit(int i, int j)
{
    if (i < 0 || j < 0 || i == n || j == n)
        return 1;
    return vis[i][j];
}

void recursive(int i, int j, int c)
{
    if (i == 6 && j == 0)
    {
        if (c == 48)
            an++;
        return;
    }
    if (visit(i - 1, j) == visit(i + 1, j) && visit(i, j - 1) == visit(i, j + 1))
        return;

    vis[i][j] = 1;
    if (s[c] == '?')
    {
        if (i > 0 && !vis[i - 1][j] && j != 6)
            recursive(i - 1, j, c + 1);
        if (i < 6 && !vis[i + 1][j])
            recursive(i + 1, j, c + 1);
        if (j > 0 && !vis[i][j - 1] && !(i == 5 && !visit(i + 1, j)))
            recursive(i, j - 1, c + 1);
        if (j < 6 && !vis[i][j + 1] && !(i == 1 && !visit(i - 1, j)))
            recursive(i, j + 1, c + 1);
    }
    else if (s[c] == 'U' && i > 0 && !vis[i - 1][j] && j != 6)
        recursive(i - 1, j, c + 1);
    else if (s[c] == 'D' && i < 6 && !vis[i + 1][j])
        recursive(i + 1, j, c + 1);
    else if (s[c] == 'L' && j > 0 && !vis[i][j - 1] && !(i == 5 && !visit(i + 1, j)))
        recursive(i, j - 1, c + 1);
    else if (s[c] == 'R' && j < 6 && !vis[i][j + 1] && !(i == 1 && !visit(i - 1, j)))
        recursive(i, j + 1, c + 1);
    vis[i][j] = 0;
}

int main()
{
    // clock_t t;
    // t = clock();
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    recursive(0, 0, 0);
    cout << an << "\n";
    // t = clock() - t;
    // cout << t << "\n";
}