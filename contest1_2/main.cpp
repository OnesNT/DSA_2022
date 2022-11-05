#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;
bool visit[9][9];
int d[9][9];
int moveX[] = {-1, 1, -2, 2, -1, 1, -2, 2};
int moveY[] = {2, 2, -1, -1, -2, -2, 1, 1};

void reset() {
    for (size_t i = 1; i <= 8; ++i)
        std::fill_n(visit[i], 9, false);
    
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            d[i][j] = INF;
    }
}

void bfs(int sx, int sy) {
    d[sx][sy] = 0;
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    visit[sx][sy] = true;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 8; ++i) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            
            if (u > 8 || u < 1) continue;
            if (v > 8 || v < 1) continue;
            
            if (!visit[u][v]){
                d[u][v] = d[x][y] + 1;
                visit[u][v] = true;
                q.push({u, v});
            }
        }
    }
}

int main() {
    int s1, s2, v1, v2;
    std::cin >> s1 >> s2;
    std::cin >> v1 >> v2;
    reset() ;
    bfs(s1, s2);
    
    if (d[v1][v2] != INF)
        std::cout << d[v1][v2] ;
    else
        std::cout << "-1 ";
    return 0 ;
}
