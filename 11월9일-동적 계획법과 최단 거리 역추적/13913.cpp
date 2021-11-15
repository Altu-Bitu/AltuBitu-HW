//
// Created by BaeSuA on 2021-11-09.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5;//수빈이가 있을 수 있는 점 범위

//역추적
vector<int> back(int x, vector<int>& path) { //x: k(도착지점)부터
    vector<int> result(0); //정답 경로
    while (x != -1) {//경로가 없지 않을 때까지 계속해서
        result.push_back(x);//현재 정점 넣어주기
        x = path[x]; //다음 정점
    }
    return result;//최단 경로로 가는 배열
}

int bfs(int n, int k, vector<int>& path) {//최단경로
    vector<int> check(SIZE + 1, 0);//전체 점에 대해서 확인
    queue<int> q; //큐에 좌푯값 저장
    int ans = 0; //최단 시간

    check[n] = 1; //시작 노드 방문 체크
    q.push(n); //시작 노드 초기화
    while (!q.empty()) {//큐가 빌 때까지
        int x = q.front(); //현재 탐색하려는 위치
        q.pop();//큐에서 제거해주기

        if (x == k) { //동생 찾으면 탐색 종료.
            ans = check[x] - 1; //시작 노드 초기화를 1로 했기 때문에 1을 빼줌
            break;//반복문 나가기
        }

        vector<int> child = { x - 1, x + 1, x * 2 }; //자식노드
        for (int i = 0; i < 3; i++) {//자식 노드가 3개여서
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { //범위 내에 있고, 첫 방문이라면
                check[child[i]] = check[x] + 1;//현재까지 탐색하는 데 걸린 시간이 check[x]에 저장되어 있으므로 더해주기
                path[child[i]] = x; //경로 저장
                q.push(child[i]);//이후에 탐색해야하니까 큐에 넣어주기
            }
        }
    }
    return ans;//최단 경로로 걸리는 시간
}

/**
 * 최단거리(BFS) 역추적
 * - 기본 문제: 숨바꼭질
 */

int main() {
    vector<int> path(SIZE + 1, -1); //경로 저장 벡터
    int n, k;

    //입력
    cin >> n >> k;//수빈이의 위치 , 동생의 위치

    //연산
    int ans = bfs(n, k, path);//최단 경로 연산
    vector<int> result = back(k, path);//역추적

    //출력
    cout << ans << '\n';//최단 경로로 걸리는 시간
    for (int i = result.size() - 1; i >= 0; i--)//도착한 곳부터 반대로 출력
        cout << result[i] << ' ';
    return 0;//종료
}