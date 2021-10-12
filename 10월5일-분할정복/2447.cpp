#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;//별 찍기 위한 배열

void star(int row, int col, int size) {//행,열, 크기 받기
    //Conquer : size의 크기가 1
    if (size == 1) {//사이즈가 1이면 1x1이기때문에
        board[row][col] = '*';//1개만 출력
        return;
    }

    //Divide : 9등분 하는데, 가운데 부분에 대해선 함수 호출하지 않음
    int next_size = size / 3;//전체 size를 3으로 나눠서 하기 위해 
    for (int i = 0; i <= next_size * 2; i += next_size) {//전체를 3으로 나눠서 두 부분 출력하고 한부분 출력 하지 않게 하기위해
        for (int j = 0; j <= next_size * 2; j += next_size) {
            if (i == next_size && j == next_size) //가운데 부분이면
                continue;//별 출력
            star(row + i, col + j, next_size);//아니면 별 출력
        }
    }
}

/**
 * ***   (0, 0) (0, 1) (0, 2)
 * * *   (1, 0) (1, 1) (1, 2)
 * ***   (2, 0) (2, 1) (2, 2)
 *
 * 1. 가운데 부분에 대해서만 함수를 호출하지 않으면 됨
 * 2. 왼쪽 맨위 좌표를 (r, c)라 하고, 배열의 크기를 size라고 할 때, 가운데 부분은 (r+(size/3), c+(size/3))
 * 3. size가 1이될 때까지 나누기
 */
int main() {
    int n;

    //입력
    cin >> n;//전체 사이즈를 위한 정수
    board.assign(n, vector<char>(n, ' '));//nxn사이즈 

    //연산
    star(0, 0, n);//(0,0)좌표부터 시작하기

    //출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];//별 찍은 거 다 출력
        cout << '\n';//한 행 끝나면 다음 행으로
    }
}