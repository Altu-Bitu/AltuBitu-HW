#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//������ ���� ������ ��ȿ���� Ȯ��
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    //����, ����, ������ �밢��, ����� �밢��
    int dr[4] = { 0, 1, 1, -1 };
    int dc[4] = { 1, 0, 1, 1 };

    //(r, c) ������ ��ġ�� �̾����� ���� �ֳ�?
    bool is_six = promising(r - dr[d], c - dc[d], stone, board);

    int cnt = 0;//�� ����
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)�� ���� �������� �ϴ� �̾����� �ٵϾ��� ����
        cnt++;//6�� �̸��̰� ���� �°� ������ ���� �����ֱ�
        r += dr[d];//��ġ �Ű��ֱ�
        c += dc[d];//��ġ �Ű��ֱ�
    }
    return cnt == 5 && !is_six;//������ �ϼ� �ǰ� ���� ����� ��ġ�� �־����� true ��ȯ
}

bool isEnd(int r, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 4; i++) { //����, ����, ������ �밢��, ����� �밢��
        if (validDir(r, c, i, board[r][c], board))//
            return true;//�̱� ����� ����
    }
    return false;//�̱� ��� ����
}

/**
 * 1. Ư�� ��ǥ(r, c)�� ���� �������� �ϴ� ������ ��� ���� ��ġ�� ���� ���� ���� Ȯ��
 *    ������ ��� ��ġ :  ������, �Ʒ�, ������, �����
 * 2. �����̻��� �Ǵ� ��� : (r, c) ���ʿ� ���� ���� �ִ� ���
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

    //�Է�
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];
    }

    //���� & ���
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //���� ����
                continue;
            if (isEnd(i, j, board)) { //������ �̰峪?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;//�� �� ��ȣ , ���� ���ʿ� �ִ� �ٵϾ� ��ġ
                return 0;//����
            }
        }
    }
    cout << 0;//�ºΰ� �������� �ʾ����� 0
}