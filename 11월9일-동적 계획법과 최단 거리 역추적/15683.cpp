#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 65;
vector<vector<int>> board;

//cctv ���� ǥ��
void ray(int row, int col, int dir) {
    int dr[4] = { -1, 0, 1, 0 };//��,��
    int dc[4] = { 0, 1, 0, -1 };//��,��

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //dir �������� ������� cctv ǥ��
        if (board[row][col] == 0) //�ٸ� cctv�� ������ �ʱ� ���� �� ������ ���� ǥ��
            board[row][col] = 7;//�湮 ǥ��
        row += dr[dir];//�� �������� �����鼭 cctv ���� Ȯ��
        col += dc[dir];//cctv���� Ȯ��
    }
}

//cctv ���� ����
void install(int cctv, int row, int col, int dir) {
    if (cctv >= 1) //1, 2, 3, 4, 5�� cctv
        ray(row, col, dir);
    if (cctv >= 2 && cctv != 3) //2, 4, 5�� cctv
        ray(row, col, (dir + 2) % 4);
    if (cctv >= 3) //3, 4, 5�� cctv
        ray(row, col, (dir + 1) % 4);
    if (cctv == 5) //5�� cctv
        ray(row, col, (dir + 3) % 4);
}

//�簢���� ���
int blindSpot() {
    int cnt = 0;//0���� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j])//0�̸� �簢�����̹Ƿ�
                cnt++;//�簢���� ũ�� �����ֱ�
        }
    }
    return cnt;//ũ�� ��ȯ
}

void backtracking(int idx) {
    if (idx == n * m) { //���� ���� : �繫���� ��� ��ġ Ȯ��
        ans = min(ans, blindSpot()); //�簢���� ��� �� �ּڰ� ����
        return;
    }

    int row = idx / m;//row���
    int col = idx % m;//col���
    int cur = board[row][col];//�ش� ��ġ board�� ����
    if (cur == 0 || cur == 6 || cur == 7) //cctv�� ���� ��
        return backtracking(idx + 1);//���ȣ��

    vector<vector<int>> save = board; //unvisited ó���� board ���� ����
    for (int i = 0; i < 4; i++) { //4���� ���⿡ ���� cctv ��ġ
        install(cur, row, col, i);//visited ǥ��
        backtracking(idx + 1);//���ȣ��
        board = save;//unvisitedǥ��

        //2�� cctv�� ���� ������ 2��, 5�� cctv�� ���� ������ 1��
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0))
            break;
    }
}

/**
 * cctv�� ��ġ�� �� �ִ� ��� ��츦 ����ϴ� ����Ž�� ����
 *
 * 1. �� cctv�� ���� ������ ��� ������ ����Ͽ� ��ġ
 *    1, 3, 4�� cctv : 4����
 *    2�� cctv : 2����
 *    5�� cctv : 1����
 * 2. install �Լ����� �� cctv�� ���� ����� ������ ����
 * 3. ray �Լ����� cctv�� ���� ���� ���� ǥ��
 * 4. ��� ��ġ�� Ȯ�������� blindSpot �Լ��� ���� �簢���� ���
 *
 * Ǯ�� : https://myunji.tistory.com/411
 * �ش� �ڵ�� �� ��ũ�� �ڵ带 �����丵�� �ڵ��Դϴ�.
 * ���δ� Ǯ�̸� �����ϱ� ������ ��ũ�� �� Ȯ�����ּ���!
 */
int main() {
    //�Է�
    cin >> n >> m;
    board.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];//���� ���� ����
    }

    //����
    backtracking(0);

    //���
    cout << ans;
}