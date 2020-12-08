#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct Node
{
    int x;
    int y;
} Node;

int m, n;
int puz[1000][1000], visit[1000][1000];

void BFS()
{
    int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<Node> que;
    Node node;
    node.x = node.y = 0;
    que.push(node);
    visit[0][0] = 0;
    while (!que.empty())
    {
        node = que.front();
        que.pop();
        if (node.x == m - 1 && node.y == n - 1)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = node.x + move[i][0];
            int dy = node.y + move[i][1];
            if ((dx >= 0 && dx <= m - 1) && (dy >= 0 && dy <= n - 1) && !puz[dx][dy] && visit[dx][dy] == -1)
            {
                visit[dx][dy] = visit[node.x][node.y] + 1;
                node.x = dx;
                node.y = dy;
                que.push(node);
            }
        }
    }
    cout << visit[m-1][n-1];
    return;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> puz[i][j];
            visit[i][j] = -1;
        }
    }
    BFS();
    return 0;
}
