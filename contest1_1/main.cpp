#include<iostream>
#include<vector>
#include<queue>

const int maxN = 99999 ;
int n; // Số lượng đỉnh của đồ thị
int m;
int d[maxN], par[maxN];
bool visit[maxN];
std::vector <int> g[maxN];

void bfs(int s) { // Với s là đỉnh xuất phát (đỉnh nguồn)
    std::fill_n(d, n + 1, 0);
    std::fill_n(par, n + 1, -1);
    std::fill_n(visit, n + 1, false);

    std::queue <int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!visit[v]) {
                d[v] = d[u] + 1;
                par[v] = u;
                visit[v] = true;
                q.push(v);
            }
        }
    }
}
int main() {
    int e , f, s, v ;
    std::cin >> n;
    std::cin >> m;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> e >> f;
        g[e].push_back(f);
    }
    std::cin >> s >> v;
    bfs(s);
    if (d[v] != 0)
        std::cout << d[v] << " ";
    else
        std::cout << "-1";
    
}

