#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7 * 2; //최대 n-1개의 간선을 지나게 됨

//간선을 인접 행렬 그래프에 삽입
vector<vector<int>> fillGraph(int n, vector<vector<int>>& fares) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));//처음에는 INF로 초기화
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;//0으로 초기화

    for (int i = 0; i < fares.size(); i++) { //양방향 그래프
        graph[fares[i][0]][fares[i][1]] = fares[i][2];//4에서 1로 가는 거랑
        graph[fares[i][1]][fares[i][0]] = fares[i][2];//1에서 4로 가는 것의 요금은 같다
    }
    return graph;//그래프 리턴
}

void floydWarshall(vector<vector<int>>& graph, int n) {
    for (int k = 1; k <= n; k++) {//경유해서 가면 더 적은 요금을 낼 수 있는지
        for (int i = 1; i <= n; i++) {//i에서
            for (int j = 1; j <= n; j++) {//j로 가는 길
                int dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                graph[i][j] = min(graph[i][j], dist); //i->j와 i->k->j 중 더 짧은 경로
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> graph = fillGraph(n, fares);//행렬 그래프
    floydWarshall(graph, n);//최저 요금

    for (int i = 1; i <= n; i++) { //i번째 지점까지 합승
        //지금까지의 최단거리와 합승한 최단거리 비교
        //이동 불가능한 경우(INF)은 min 조건에 의해 자동으로 고려되지 않음
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);//s에서 같이 내리는 지점까지 요금+ a까지 걸리는 요금+b까지 걸리는 요금
    }
    return answer;//최저요금
}

/**
 * 합승할 수 있는 지점의 개수는 n개
 * 1. s인 경우는 합승을 하지 않을 때
 * 2. a인 경우는 A의 집까지 합승한 뒤, B 혼자 이동
 * 3. b인 경우는 B의 집까지 합승한 뒤, A 혼자 이동
 * 4. 나머지 경우는 특정 지점까지 합승한 뒤, 각자의 집으로 가는 것
 * -> 다익스트라를 사용하면 시간초과이므로 플로이드-워셜 알고리즘 사용
 *
 * 1. 플로이드-워셜 알고리즘으로 모든 지점들 사이의 최단 거리 계산
 * 2. n개의 지점에 대해 n번 지점까지 합승을 하고 각자의 집으로 가는 최단거리 계산
 */
int main() {
    vector<vector<int>> fares = { {4, 1, 10},//지점 ,지점간 방향
                                 {3, 5, 24},
                                 {5, 6, 2},
                                 {3, 1, 41},
                                 {5, 1, 24},
                                 {4, 6, 50},
                                 {2, 4, 66},
                                 {2, 3, 22},
                                 {1, 6, 25} };
    int ans = solution(6, 4, 6, 2, fares);//최저요금
    cout << ans;//출력
}