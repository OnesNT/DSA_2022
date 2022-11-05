#include <iostream>
#include <vector>
#include <stack>
const int maxN = 99998;

int n, m;
int visit[maxN], ans[maxN];
std::vector <int> g[maxN];
std::stack <int> topo;

void dfs(int u) {
    visit[u] = 1;
    for (auto v : g[u]) {
        if (!visit[v])
            dfs(v);
    }
    topo.push(u);
    visit[u] = 2;
}

int main() {
    std::cin >> n >> m;
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i)
        if (!visit[i])
            dfs(i);

    int cnt = 0;
    while (!topo.empty()) {
        ans[topo.top()] = ++cnt;
        topo.pop();
    }

    for (int i = 0; i < n; ++i)
        std::cout << ans[i] << ' ';
}
