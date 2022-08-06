#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

char a[8][8];
int board[8][8];
int an = 0;

bool isPossible(int n, int row, int col)
{
    if (a[row][col] == '*')
        return false;

    for (int i = row - 1; i >= 0; i--)
        if (board[i][col] == 1)
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}
void queen(int n, int row)
{
    if (row == n)
    {
        an++;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isPossible(n, row, j))
        {
            board[row][j] = 1;
            queen(n, row + 1);
        }
        board[row][j] = 0;
    }
    return;
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i, 8) rep(j, 8) cin >> a[i][j];
    queen(8, 0);
    cout << an << "\n";
    return 0;
}
