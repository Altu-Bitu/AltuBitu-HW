#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(int n, vector<vector<bool>>& graph) {
    for (int k = 1; k <= n; k++) {//경유할 수 있는지
        for (int i = 1; i <= n; i++) {//시작
            for (int j = 1; j <= n; j++) {//끝
                if (graph[i][k] && graph[k][j]) //i->k, k->j 전후관계 있는 경우
                    graph[i][j] = true;//갈 수 있다고 표시
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s, a, b;//사건 수, 사건 관계, 전후 관계를 알고 싶은 사건의 수,방향

    //입력
    cin >> n >> k;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));//해당 방향으로 관계가 있는지
    while (k--) {//k개
        cin >> a >> b;
        graph[a][b] = true; //전후관계 -> 단방향 그래프
    }

    //연산
    floydWarshall(n, graph);

    //입력 & 출력
    cin >> s;
    while (s--) {
        cin >> a >> b;
        if (graph[a][b])//만약 a,b가 a->b이면 -1
            cout << "-1";
        else if (graph[b][a])//b->a이면 1
            cout << "1";
        else
            cout << "0";//관계가 없으면 0
        cout << '\n';
    }
    return 0;//종료
}