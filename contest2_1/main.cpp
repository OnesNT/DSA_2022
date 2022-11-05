#include <iostream>
#include <queue>

const int maxN = 100000;
int m, n;
std::vector <int> q[maxN];
bool visit[maxN];
bool check_res = false;
int level[maxN];
int position = 0;

void reset() {
    std::fill_n(visit, n + 1, false);
    std::fill_n(level, n + 1, 0);

}

void DFS(int i){
    visit[i] = true;
    level[i] = position;
    for (auto v : q[i])
        if (visit[v] && level[v] == level[i]) {
            check_res = true;
            break;
    }
    
    for (auto v : q[i])
        if (!visit[v] && check_res == false)
            DFS(v);
            
}

int main() {
    int e, f;
    std::cin >> n >> m;
    reset();
    for (size_t i = 0; i < m; ++i) {
        std::cin >> e >> f;
        q[e].push_back(f) ;
    }
    for (size_t i = 1; i <= n; ++i)
        if (!visit[i] && check_res == false) {
            position++;
            level[i] = position;
            DFS(i);
        }
            
    
    if (check_res == true) std::cout << "YES";
    else std::cout << "NO";
}
