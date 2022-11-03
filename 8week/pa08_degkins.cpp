#include <iostream>
#include <vector>
#define max 1000

using namespace std;

vector <string> adj[max];
bool visit[max] = {false};
int depth[max]; // 깊이를 저장
int parents[max]; // 각 노드들의 부모를 저장
int E;
// 노드들의 깊이와 부모를 설정해주는 DFS 함수
void DFS(int node,int dep){
    visit[node] = true;
    depth[node] = dep;
    for(int i = 0;i<adj[node].size();i++){
        int next_node = adj[node][i];
        if(visit[next_node]){continue;} // 만약 방문만 정점이면 탐색x
        parents[next_node] = node; // 다음노드의 부모는 현재노드가 된다. (위에서 부터 탐색하므로)
        DFS(next_node,dep+1); // 다음노드와 깊이를 +1해준다.
    }
}
int LCA(int node_a,int node_b){
    if(node_a == node_b){return node_a;} // 만약 두 노드가 같으면 노드 반환
    if(depth[node_a] == depth[node_b]){return LCA(parents[node_a],parents[node_b]);} //두 노드의 깊이가 같을 때 
    else if(depth[node_a]>depth[node_b]){return LCA(parents[node_a],node_b);} //만약 node_a가 더 깊이가 깊을 때
    else{return LCA(node_a,parents[node_b]);} // 만약 node_b가 더 깊이가 깊을 때
}
int main(void)
{
    cin >> E;
    // 인접 리스트 생성
    
    for(int i = 0;i<E;i++){
        string a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1,0); // 1이 루트이므로 1 먼저 탐색하여 깊이를 구해준다.

    int a, b;
    cin >> a >> b;
    int res = depth[a] + depth[b] - 2 * depth[LCA(a, b)];
    cout << res; //노드4와 노드7의 최소 공통 조상 출력
}
