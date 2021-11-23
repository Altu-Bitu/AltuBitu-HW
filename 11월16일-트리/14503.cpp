#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {
    //상, 우, 하, 좌
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    int step = 0, ans = 0;//회전한 횟수 , 청소한 칸의 개수
    while (true) {
        if (board[r][c] == 0) {//현재 있는 칸이 청소가 되어 있지 않은 상태이면
            board[r][c] = 2;//청소한 상태로 변경
            ans++;//청소한 칸의 개수 1 더해주기
        }

        if (step == 4) {//4방향으로 다 회전하고
            if (board[r - dr[d]][c - dc[d]] == 1)//후진한 칸이 1이면
                return ans;//청소한 칸의 개수 반환
            r -= dr[d];//행 이동
            c -= dc[d];//열 이동
            step = 0;//회전한 횟수 초기화
        }
        else {
            d = (d + 3) % 4;//방향
            if (board[r + dr[d]][c + dc[d]]) {//청소기 이동
                step++;//회전 횟수 더해주기
                continue;//건너 뛰기
            }
            r += dr[d];//행 이동
            c += dc[d];//열 이동
            step = 0;//회전 횟수 초기화
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0));//n*m
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];//각 장소의 상태
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;//종료
}