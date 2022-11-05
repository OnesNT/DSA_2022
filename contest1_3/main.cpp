#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <algorithm>

const int maxN = 10000;
const int INF = 1e9 + 7;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
int n;
char a[maxN];
std::vector <int> g[maxN];
std::vector <int> h[maxN];
int trace[maxN];
int s1, s2, v1, v2;
bool visit[maxN] , check;

//transfer from 2 dimesion to 1 dimension
int getID(int i, int j) {
    return (i - 1) * n + j;
}

// init
void reset() {
    std::fill_n(visit, n * n + 1, false);
    std::fill_n(trace, n * n + 1, 0);
}

void bfs(int sx, int sy) {
    std::queue <std::pair <int, int>> q;
    q.push({sx, sy});
    visit[getID(sx, sy)] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int u = x + moveX[i];
            int v = y + moveY[i];

            if (a[getID(u, v)] == 0) continue;
            if (u > n || u < 1) continue;
            if (v > n || v < 1) continue;

            if (!visit[getID(u, v)]) {
                visit[getID(u, v)] = true;
                if (u == v1 && v == v2) check = true;
                trace[getID(u, v)] =  getID(x, y) ;
//                std::cout << u << " " << v << " " << trace[getID(u, v)] << std::endl;
                q.push({u, v});
            }
        }
    }
}

void find(int vx, int vy) {
    std::stack <std::pair<int, int>> res;
    
    int come_back = getID(vx, vy); // trace from last come back to start
    
    while (come_back != getID(s1, s2)) {
        come_back = trace[come_back];
        float x1 = ceil(float(come_back) / n)  ;
        float x2 = come_back % n;
//        std::cout << ceil(float(8.0/3));
//        std::cout << come_back << std::endl;
        if (x2 == 0)
//            std::cout << x1 << " " << n << std::endl ;
            res.push({x1, n});
        else
//            std::cout << x1 << " " << x2 << std::endl;
            res.push({x1, x2});
    }
    while (!res.empty()) {
        int u1 = res.top().first;
        int u2 = res.top().second;
        std::cout << u1 << " " << u2 << std::endl;
        res.pop() ;
    }
    std::cout << vx << " " << vy << std::endl;
}

int main() {
    int temp;
    std:: cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            std::cin >> temp;
            a[getID(i, j)] = temp;
        }
    std::cin >> s1 >> s2;
    std::cin >> v1 >> v2;
    reset() ;
    bfs(s1, s2);
    if (check == true)
        find(v1, v2);
    else
        std::cout << "-1";
    return 0;
}

