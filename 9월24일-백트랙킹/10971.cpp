#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

vector<bool> visited;
vector<vector<int>> matrix;
int ans = INF;//최솟값을 얻기 위해 초기값 설정

/**
 * 모든 도시를 방문한 뒤 돌아올 수 있는 모든 경우 탐색
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
void backtracking(int n, int start_city, int cur_city, int cnt, int cost) {//도시 개수, 출발도시,현재 도시, 순회한도시 수, 비용
    if (cost >= ans) //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return;//비용이 이미 최솟값보다 높다면 더 이상 알아볼 필요가 없음
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][start_city] != 0)//현재도시에서 출발도시로 돌아오는 비용이 0이 아니라면
            ans = min(ans, cost + matrix[cur_city][start_city]);//기존비용과 두 도시간의 비용을 더한 다음의 기존의 최솟값과 비교해서 더 작은 값을 최솟값에 넣음
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; //방문 처리
            backtracking(n, start_city, i, cnt + 1, cost + matrix[cur_city][i]);//현재도시,순회한 도시 수 1증가,비용도 방금 지난 도시 추가해서
            visited[i] = false; //미방문 처리
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * !주의! 모든 도시를 방문 후 시작 도시로 돌아와야 하기 때문에 어떤 도시에서 출발했는지 알고 있어야 함.
 */
int main() {
    int n;

    //입력
    cin >> n;
    visited.assign(n, false);//다 미방문 처리
    matrix.assign(n, vector<int>(n, 0));//2차원 배열
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];//도시 간 비용 저장
    }

    //연산
    //i번째 도시를 시작으로 순회
    for (int i = 0; i < n; i++) {
        visited[i] = true; //방문 처리
        backtracking(n, i, i, 1, 0);//i도시에서 시작해서 현재 있는 도시도 i,방문한 도시도 1개,따라서 비용은 0
        visited[i] = false; //미방문 처리
    }

    //출력
    cout << ans;
}