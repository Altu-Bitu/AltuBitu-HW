#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix;//�Է¹��� ���

int divide(int row, int col, int size) {//�� ,��,ũ��
    //Conquer : n�� ũ�Ⱑ 1
    if (size == 1)//ũ�Ⱑ 1�϶� �����Ƿ�
        return matrix[row][col];//�ٷ� ��ȯ

    //Divide : ��� 4��� �ϱ�
    int next_size = size / 2;//��� 4����ϱ� ���ؼ�
    vector<int> sub_problem;//����ؼ� ���� ũ�Ⱑ �پ�� ���
    for (int i = 0; i <= next_size; i += next_size) {//��� 4���
        for (int j = 0; j <= next_size; j += next_size)//��� 4���
            sub_problem.push_back(divide(row + i, col + j, next_size));//sub_problem�� divide �Լ� ������ ���� �ι�°�� ū ������ ����ؼ� �����ؼ� ��� ���ϱ�
    }

    //Combine : �ι�°�� ū ���� �����
    sort(sub_problem.begin(), sub_problem.end(), greater<>());//������������ ����
    return sub_problem[1];//�ι�°�� ū ��
}

/**
 * 1. ��� 4��� �ϱ�
 * 2. ����� ũ�Ⱑ 1�̶�� ���� ����
 * 3. ���ϵ� ���� 4�� ��Ƽ� �ι�°�� ū ���� ����
 */
int main() {
    int n;

    //�Է�
    cin >> n;//nxn���
    matrix.assign(n, vector<int>(n));//nxn���
    for (int i = 0; i < n; i++) {//��� �Է� �ޱ�
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    //���� & ���
    cout << divide(0, 0, n);//��� ���
}