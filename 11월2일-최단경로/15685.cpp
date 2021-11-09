#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 100 + 1; //���� ������

//��, ��, ��, ��
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

//ũ�Ⱑ 1x1�� ���簢���� �� �������� ��� �巡�� Ŀ���� �Ϻ��� ���� ���� ���ϱ�
int cntSquare(vector<vector<bool>>& board) {
    int ans = 0;//����
    for (int i = 0; i < SIZE - 1; i++) {//100*100�̴ϱ�
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
                ans++;//�ð�������� 4���� ������ ���� 1 �����ֱ�
        }
    }
    return ans;//���� ��ȯ
}

ci makeDragonCurve(vector<vector<bool>>& board, vector<int>& direc, ci point) {
    int size = direc.size(); //�� �� ��������� ���� ���� ����
    for (int i = size - 1; i >= 0; i--) {
        int new_direc = (direc[i] + 1) % 4; //���� ���� ���� ����
        point = { point.first + dy[new_direc], point.second + dx[new_direc] }; //���� �� ��
        board[point.first][point.second] = true;//���ھȿ� �� �ִٰ� ǥ��
        direc.push_back(new_direc);//���� ���� ���� ���� ����
    }
    return point;//���� �� �� ��ȯ
}

/**
 * x: ��, y: ��
 *
 * �巡�� Ŀ�� = ���е�� �̷����
 * => �� ���е��� ������ �����ؼ� �巡�� Ŀ���� ��ǩ���� ���س�����
 *
 * �巡�� Ŀ��� �� ���븶�� �� ���� �������� �ð� �������� 90�� ȸ��
 * -> �巡�� Ŀ�� ������ �� ���� ���� = �� ���� ����鿡�� ���ʷ� �� ���� �������� �ð�������� �̵��� �Ͱ� ����
 * -> (��(0) -> ��(1), ��(1) -> ��(2), ��(2) -> ��(3), ��(3) -> ��(0)) �� �̵�
 * ex) 0����: ��
 *     1����: ��
 *     2����: �� �� (1���� + 0������ ��, �쿡�� ���� �ð���� �̵�)
 *     3����: �� �� �� �� (2���� + 1���� + 0���뿡�� ���� �ð���� �̵�)
 *
 * 0����� �̹� ������ �־����Ƿ� ���� ó��
 * �巡�� Ŀ��� ���� ������ ������ ���� -> ���� �˻� �ʿ� x
 */

int main() {
    int n, x, y, d, g;

    //�Է� & ����
    cin >> n;//�巡�� Ŀ���� ����
    vector<vector<bool>> board(SIZE, vector<bool>(SIZE, false)); //100x100 ����
    while (n--) {
        cin >> x >> y >> d >> g;
        vector<int> direc; //������ ���� ���� ���� �� �����ϴ� ����
        ci end_point = { y + dy[d], x + dx[d] }; //0���� ����
        board[y][x] = board[end_point.first][end_point.second] = true; //0���� ������, ���� �ʱ�ȭ
        direc.push_back(d); //0���� ���� ����
        while (g--) { //�� ���븶�� �巡�� Ŀ�� �����
            end_point = makeDragonCurve(board, direc, end_point);//������ ����
        }
    }

    //���
    cout << cntSquare(board) << '\n';//�� �������� �巡�� Ŀ���� �Ϻ��� ���� ����
    return 0;//����
}