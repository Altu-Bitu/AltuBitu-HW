//
// Created by BaeSuA on 2021-11-09.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e8;//비용*도시 개수

//역추적
vector<int> back(int x, vector<int>& path) { //x: 도착정점 부터
    vector<int> result(0);//0으로 초기화
    while (x != 0) {//0으로 해줘도 경로가 없는 거여서 0으로 해도 괜찮다
        result.push_back(x);//배열에 현재 정점 넣어주기
        x = path[x]; //다음 정점
    }
    return result;//최단 경로까지 가는 배열
}

int dijkstra(int n, int s, int e, vector<vector<ci>>& graph, vector<int>& path) {
    vector<int> dist(n + 1, INF);//비용 초기화
    priority_queue<ci, vector<ci>, greater<>> pq;

    //시작 위치 초기화
    dist[s] = 0;//시작 도시는 비용 0
    pq.push({ 0, s });//가중치 , 시작 정점

    while (!pq.empty()) {//큐가 빌 때까지
        int weight = pq.top().first;//가중치
        int node = pq.top().second; //중간 정점
        pq.pop();//큐에서 제거

        if (weight > dist[node]) //이미 탐색한 정점 (이 코드 없으면 시간초과)
            continue;//건너 뛰고 다음으로

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로
                dist[next_node] = next_weight;//더 짧은 걸로 바꿔주기
                path[next_node] = node; //경로 저장
                pq.push({ next_weight, next_node });//가중치와 다음 노드를 넣어주기
            }
        }
    }
    return dist[e];//도착점까지의 최단경로
}

/**
 * 다익스트라 역추적
 * - 기본 문제: 최소 비용 구하기
 */

int main() {
    int n, m, a, b, c, s, e;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접 리스트
    vector<int> path(n + 1, 0); //경로 저장
    while (m--) {
        cin >> a >> b >> c;//출발 도시 , 도착 도시 , 비용
        graph[a].push_back({ b, c }); //단방향 그래프
    }
    cin >> s >> e;//출발 도시 , 도착 도시

    //연산
    int ans = dijkstra(n, s, e, graph, path);
    vector<int> result = back(e, path);//역추적 

    //출력
    cout << ans << '\n' << result.size() << '\n';//최소비용 , 거쳐가는 도시 개수
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';//경로
    return 0;//종료
}