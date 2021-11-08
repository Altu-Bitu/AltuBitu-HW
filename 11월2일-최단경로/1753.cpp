//
// Created by iw040 on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;//3개의 정보를 저장하기 위해서 pair을 써야함
const int INF = 1e5 * 2; //최대 V-1개의 간선을 지나게 됨

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph) {//정점, 시작점
    vector<int> dist(vertex + 1, INF);//1부터 시작하기 때문에
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점

    //시작 위치 초기화
    dist[start] = 0;
    pq.push({ 0, start });//0으로 초기화

    while (!pq.empty()) {//큐가 빌때까지
        int weight = pq.top().first;//시작점에서부터의 가중치
        int node = pq.top().second;//정점
        pq.pop();

        if (weight > dist[node]) //이미 확인했던 정점
            continue;//다음으로 바로 넘어가기,중복을 줄이기 위해
        for (int i = 0; i < graph[node].size(); i++) {//연결되어 있는 모든 정점에 대해 확인
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight;//가중치 갱신하기
                pq.push({ next_weight, next_node });//새로 큐에 넣기
            }
        }
    }
    return dist;//최단 경로값 반환
}

int main() {
    int vertex, edge, k, u, v, w;//입력 받기

    //입력
    cin >> vertex >> edge >> k;
    vector<vector<ci>> graph(vertex + 1, vector<ci>(0)); //인접 리스트
    while (edge--) {//edge의 수만큼 입력 받기
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); //방향 그래프
    }

    //연산
    vector<int> ans = dijkstra(vertex, k, graph);

    //출력
    for (int i = 1; i <= vertex; i++) {//마지막 정점까지
        if (ans[i] == INF)//경로가 없으면
            cout << "INF";
        else
            cout << ans[i];//아니면 최단 경로의 경로값 출력
        cout << '\n';
    }
}