#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {
    //��, ��, ��, ��
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    int step = 0, ans = 0;//ȸ���� Ƚ�� , û���� ĭ�� ����
    while (true) {
        if (board[r][c] == 0) {//���� �ִ� ĭ�� û�Ұ� �Ǿ� ���� ���� �����̸�
            board[r][c] = 2;//û���� ���·� ����
            ans++;//û���� ĭ�� ���� 1 �����ֱ�
        }

        if (step == 4) {//4�������� �� ȸ���ϰ�
            if (board[r - dr[d]][c - dc[d]] == 1)//������ ĭ�� 1�̸�
                return ans;//û���� ĭ�� ���� ��ȯ
            r -= dr[d];//�� �̵�
            c -= dc[d];//�� �̵�
            step = 0;//ȸ���� Ƚ�� �ʱ�ȭ
        }
        else {
            d = (d + 3) % 4;//����
            if (board[r + dr[d]][c + dc[d]]) {//û�ұ� �̵�
                step++;//ȸ�� Ƚ�� �����ֱ�
                continue;//�ǳ� �ٱ�
            }
            r += dr[d];//�� �̵�
            c += dc[d];//�� �̵�
            step = 0;//ȸ�� Ƚ�� �ʱ�ȭ
        }
    }
}

/**
 * board ���� -> 0: �� ĭ, 1: ��, 2: û���� ����
 * step: ȸ�� ī��Ʈ. 4�� �Ǹ� �� ���� ���� �ٽ� ���ڸ��� ���ƿ����� �ǹ�
 *
 * �׻� ù ��, ������ ��, ù ��, ������ ���� ���̶�� �������� �־������Ƿ� ���� �˻縦 �� �ʿ䰡 ����
 */

int main() {
    int n, m, r, c, d;

    //�Է�
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0));//n*m
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];//�� ����� ����
        }
    }

    //���� & ���
    cout << cntCleanRobot(r, c, d, board);
    return 0;//����
}