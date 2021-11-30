#include <iostream>
#include <vector>

using namespace std;

//단절점, 단절선 파악 함수
string isTrue(int t, int k, vector<vector<int>>& tree) {
    if (t == 2)
        return "yes";//모든 간선은 단절선이므로 yes
    if (tree[k].size() >= 2)
        return "yes";//k번 정점에 연결된 정점이 연결된 간선이 2개면  yes
    return "no";//아니면no
}

/**
 * 부모 노드를 알 수 없기에 트리를 양방향 그래프로 저장
 * 단절점: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 연결된 간선이 2개 이상이면 단절점
 * 단절선: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 모든 간선이 단절선
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, q, t, k;

    //입력
    cin >> n;
    vector<vector<int>> tree(n + 1, vector<int>(0));//시작이 1번인 트리
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);//트리 간선 정보 입력
        tree[b].push_back(a);//트리 간선 정보 입력
    }
    cin >> q;
    while (q--) {
        cin >> t >> k;//질문 , 정점 혹은 간선
        cout << isTrue(t, k, tree) << '\n';//출력
    }
    return 0;//종료
}