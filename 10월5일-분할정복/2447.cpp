#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;//�� ��� ���� �迭

void star(int row, int col, int size) {//��,��, ũ�� �ޱ�
    //Conquer : size�� ũ�Ⱑ 1
    if (size == 1) {//����� 1�̸� 1x1�̱⶧����
        board[row][col] = '*';//1���� ���
        return;
    }

    //Divide : 9��� �ϴµ�, ��� �κп� ���ؼ� �Լ� ȣ������ ����
    int next_size = size / 3;//��ü size�� 3���� ������ �ϱ� ���� 
    for (int i = 0; i <= next_size * 2; i += next_size) {//��ü�� 3���� ������ �� �κ� ����ϰ� �Ѻκ� ��� ���� �ʰ� �ϱ�����
        for (int j = 0; j <= next_size * 2; j += next_size) {
            if (i == next_size && j == next_size) //��� �κ��̸�
                continue;//�� ���
            star(row + i, col + j, next_size);//�ƴϸ� �� ���
        }
    }
}

/**
 * ***   (0, 0) (0, 1) (0, 2)
 * * *   (1, 0) (1, 1) (1, 2)
 * ***   (2, 0) (2, 1) (2, 2)
 *
 * 1. ��� �κп� ���ؼ��� �Լ��� ȣ������ ������ ��
 * 2. ���� ���� ��ǥ�� (r, c)�� �ϰ�, �迭�� ũ�⸦ size��� �� ��, ��� �κ��� (r+(size/3), c+(size/3))
 * 3. size�� 1�̵� ������ ������
 */
int main() {
    int n;

    //�Է�
    cin >> n;//��ü ����� ���� ����
    board.assign(n, vector<char>(n, ' '));//nxn������ 

    //����
    star(0, 0, n);//(0,0)��ǥ���� �����ϱ�

    //���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];//�� ���� �� �� ���
        cout << '\n';//�� �� ������ ���� ������
    }
}