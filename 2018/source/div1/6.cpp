#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
string str;
int n, m, ans;
pii st;
bool flg;
vector <vector<int>> room, dist;
int dx[] = {-1, 0, 1, 0,  -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1,  -1, 1, 1, -1};

bool func()
{
    int mx = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[i][j] == INT_MAX)
            {
                return false;
            }

            else if(mx < dist[i][j])
            {
                mx = dist[i][j];
                st = {i, j};
            }
        }
    }
    return true;
}

void q_seek(int a, int b, int d)
{
    queue <pii> que;
    int p, q;
    bool visited[1001][1001] = {false};
    que.push({a, b});
    visited[a][b] = true;

    while(!que.empty())
    {
        p = que.front().first;
        q = que.front().second;
        que.pop();

        for(int i=0;i<4;i++)
        {
            int nx = p + dx[i];
            int ny = q + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] != -1 && !visited[nx][ny])
            {
                dist[nx][ny] = dist[p][q]+1;
                visited[nx][ny] = true;
                que.push({nx, ny});
            }
        }
        for(int i=4; i<8; i++)
        {
            int nx = p + dx[i];
            int ny = q + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] != -1 && (dist[nx][q] != -1 || dist[p][ny] != -1) && !visited[nx][ny])
            {
                dist[nx][ny] = dist[p][q]+1;
                visited[nx][ny] = true;
                que.push({nx, ny});
            }
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    st.first = st.second =  -1;
    cin >> n >> m;
    room.resize(n);
    for(int i=0;i<n;i++)
        room[i].resize(m, INT_MAX);
    dist = room;
    for(int i=0;i<n;i++)
    {
        cin >> str;
        for(int j=0;j<m;j++)
        {
            if(str[j] == '#')
            {
                room[i][j] = dist[i][j] = -1;
            }
            if(st.first == -1 && str[j] == 'O')
            {
                st = {i, j};
            }
        }
    }

    dist[st.first][st.second] = 0;
    q_seek(st.first, st.second, 0);

    if(!func())
    {
        cout << "-1\n";
        return 0;
    }
    dist = room;
    dist[st.first][st.second] = 0;
    q_seek(st.first, st.second, 0);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[i][j] < INT_MAX && ans < dist[i][j])
                ans = dist[i][j];
        }
    }
    cout << (ans%2 == 1 ? ans/2+1 : ans/2) <<'\n';
}

