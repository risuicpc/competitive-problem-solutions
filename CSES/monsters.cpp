#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000
int n, m;
vector<string> v(N);
queue<pair<pair<int, int>, int>> q;

void niber(int i, int j, int d, vector<vector<int>> &a)
{
    if (i < 0 || j < 0 || i == n || j == m)
        return;
    if (a[i][j] || v[i][j] == '#')
        return;
    q.push({{i, j}, d});
    a[i][j] = d;
}

bool check(int i, int j, int d, vector<vector<int>> &a)
{
    if (i < 0 || j < 0 || i == n || j == m)
        return 0;
    if (a[i][j] == -1 || (a[i][j] && a[i][j] + 1 == d))
        return 1;
    return 0;
}

int main()
{

    cin >> n >> m;
    pair<int, int> a;
    vector<vector<int>> M(n, vector<int>(m, 0));
    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'M')
                q.push({{i, j}, 0}), M[i][j] = -1;
            else if (v[i][j] == 'A')
                a = {i, j};

    while (!q.empty())
    {
        int i = q.front().first.first, j = q.front().first.second;
        niber(i - 1, j, q.front().second + 1, M);
        niber(i + 1, j, q.front().second + 1, M);
        niber(i, j - 1, q.front().second + 1, M);
        niber(i, j + 1, q.front().second + 1, M);
        q.pop();
    }
    A[a.first][a.second] = -1;
    q.push({a, 0});
    while (!q.empty())
    {
        int i = q.front().first.first, j = q.front().first.second;
        niber(i - 1, j, q.front().second + 1, A);
        niber(i + 1, j, q.front().second + 1, A);
        niber(i, j - 1, q.front().second + 1, A);
        niber(i, j + 1, q.front().second + 1, A);
        q.pop();
    }
    a = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (A[i][0] && (A[i][0] < M[i][0] || !M[i][0]))
        {
            a = {i, 0};
            break;
        }
        if (A[i][m - 1] && (A[i][m - 1] < M[i][m - 1] || !M[i][m - 1]))
        {
            a = {i, m - 1};
            break;
        }
    }
    if (a.first == -1)
    {
        for (int i = 0; i < m; i++)
        {
            if (A[0][i] && (A[0][i] < M[0][i] || !M[0][i]))
            {
                a = {0, i};
                break;
            }
            if (A[n - 1][i] && (A[n - 1][i] < M[n - 1][i] || !M[n - 1][i]))
            {
                a = {n - 1, i};
                break;
            }
        }
    }
    if (a.first == -1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << (A[a.first][a.second] == -1 ? 0 : A[a.first][a.second]) << "\n";
        string t = "";
        int i = a.first, j = a.second;
        for (int k = 0; k < A[a.first][a.second]; k++)
        {
            if (check(i - 1, j, A[i][j], A))
            {
                t += "D";
                i--;
            }
            else if (check(i + 1, j, A[i][j], A))
            {
                t += "U";
                i++;
            }
            else if (check(i, j - 1, A[i][j], A))
            {
                t += "R";
                j--;
            }
            else if (check(i, j + 1, A[i][j], A))
            {
                t += "L";
                j++;
            }
        }
        reverse(t.begin(), t.end());
        if (A[a.first][a.second] != -1)
            cout << t << "\n";
    }
}