#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = { 0, 1, 1, -1 };
    int dc[4] = { 1, 0, 1, 1 };

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    bool is_six = promising(r - dr[d], c - dc[d], stone, board);

    int cnt = 0;//돌 개수
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++;//6개 미만이고 돌이 맞게 있으면 개수 더해주기
        r += dr[d];//위치 옮겨주기
        c += dc[d];//위치 옮겨주기
    }
    return cnt == 5 && !is_six;//오목이 완성 되고 돌이 제대로 위치해 있었으면 true 반환
}

bool isEnd(int r, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board))//
            return true;//이긴 사람이 있음
    }
    return false;//이긴 사람 없음
}

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //돌이 없음
                continue;
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;//돌 색 번호 , 가장 왼쪽에 있는 바둑알 위치
                return 0;//종료
            }
        }
    }
    cout << 0;//승부가 결정되지 않았으면 0
}