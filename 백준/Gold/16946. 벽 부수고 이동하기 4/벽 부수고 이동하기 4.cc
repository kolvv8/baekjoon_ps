#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int mp[1001][1001];
int ans[1001][1001];

int check[1001][1001];

bool visited[1001][1001];
int n, m;
int checkNum;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void func(int x, int y) {
    vector<pair<int, int>>vec;
    queue<pair<int, int>>q;
    q.push({ x,y });
    visited[x][y] = true;
    int sum = 0;
    while (!q.empty()) {
        int bx = q.front().first;
        int by = q.front().second;
        vec.push_back({ bx,by });
        sum++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = bx + dx[i];
            int ny = by + dy[i];

            if (nx <= 0 || ny <= 0 || nx > n || ny > m || visited[nx][ny]) {
                continue;
            }
            else if (mp[nx][ny] == 1) {
                continue;
            }
            else {
                q.push({ nx,ny });
                visited[nx][ny] = true;
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        int kx = vec[i].first;
        int ky = vec[i].second;
        ans[kx][ky] = sum;
        check[kx][ky] = checkNum;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            mp[i][j] = (c - '0');
            ans[i][j] = (c - '0');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && mp[i][j] == 0) {
                checkNum++;
                func(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 1) {
                int sum = 1;
                unordered_map<int, bool>checkMap;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx <= 0 || ny <= 0 || nx > n || ny > m) {
                        continue;
                    }
                    else if (mp[nx][ny] == 1) {
                        continue;
                    }
                    else {
                        int num = check[nx][ny];
                        if (!checkMap[num]) {
                            checkMap[num] = true;
                            sum += ans[nx][ny];
                        }
                    }
                }
                cout << sum % 10;
            }
            else {
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}