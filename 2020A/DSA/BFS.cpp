#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

typedef struct Node
{
    int x, y, step;
    Node *pre;
} Node;

int m, n;
int puz[1000][1000] = {1}, vst[1000][1000] = {0};
int movelist[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int sum = 0;

void printAll(Node *p)
{
    int step = p->step;
    cout << "最短路线长度: " << step << endl;
    stack<Node> temp;
    while (p->pre != NULL)
    {
        temp.push(*p);
        p = p->pre;
    }
    temp.push(*p);
    cout << "最短路线: ";
    while (temp.size() > 1)
    {
        cout << "(" << temp.top().x << "," << temp.top().y << ")"
             << "->";
        temp.pop();
    }
    cout << "(" << temp.top().x << "," << temp.top().y << ")" << endl;
    return;
}

void BFS()
{
    int min = INT_MAX;
    queue<Node> que;
    Node node = {0, 0, 0, NULL};
    que.push(node);
    while (!que.empty())
    {
        node = que.front();
        que.pop();
        puz[node.x][node.y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int dx = node.x + movelist[i][0];
            int dy = node.y + movelist[i][1];
            Node next = {dx, dy, 0, NULL};
            if ((dx >= 0 && dx < m) && (dy >= 0 && dy < n) && !puz[dx][dy])
            {
                Node *temp = new Node;
                memcpy(temp, &node, sizeof(Node));
                next.pre = temp;
                next.step = node.step + 1;
                puz[next.x][next.y] = 1;
                if (next.x == m - 1 && next.y == n - 1)
                {
                    printAll(&next);
                    return;
                }
                que.push(next);
            }
        }
    }
}

void DFS(int x, int y)
{
    if (x == m - 1 && y == n - 1)
    {
        sum++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int dx = x + movelist[i][0];
        int dy = y + movelist[i][1];
        if ((dx >= 0 && dx < m) && (dy >= 0 && dy < n) && !puz[dx][dy] && !vst[dx][dy])
        {
            vst[dx][dy] = 1;
            DFS(dx, dy);
            vst[dx][dy] = 0;
        }
    }
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
        }
    }
    DFS(0, 0);
    cout << "总路线数量: " << sum << endl;
    BFS();
    return 0;
}
