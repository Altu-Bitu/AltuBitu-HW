#include <iostream>
#include <vector>

using namespace std;

void postorder(int left, int right, vector<int>& nodes) {
    if (left > right) //�������� : ���� ��谡 ������ ��� �ʸӿ� ����
        return;//����

    //ó������ root ��庸�� ���� Ŀ���� ��ġ
    int idx = right + 1;
    for (int i = left; i <= right; i++) {//������ȸ���  ó������ ������
        if (nodes[i] > nodes[left]) {//root��庸�� i��° ��尡 ���� �� ũ�ٸ� �� ���� ,���� , ������ ����Ʈ���� �����
            idx = i;//idx�� �ٲ��ֱ�
            break;//���� ������
        }
    }

    postorder(left + 1, idx - 1, nodes); //���� ����Ʈ��
    postorder(idx, right, nodes); //������ ����Ʈ��
    cout << nodes[left] << '\n'; //���
}

/**
 * ���� ���� - 4256�� ����
 *
 * ���� ���� Ǯ��
 * 1. ���� ��ȸ�� root ����� ��ġ�� �� �� ������ ����, ������ ����Ʈ���� ���� �� �� ����
 * 2. BST�� ���� : ���� ����Ʈ���� ��� ��� �� < ��Ʈ ��� �� < ������ ����Ʈ���� ��� ��� ��
 *    -> ó������ root ���� ���� Ŀ���ٸ�, �� ��ġ�� ����, ������ ����Ʈ���� ���
 * 3. ����Լ� ȣ��� ���� �ݺ��ϸ� ���
 */
int main() {
    int input;
    vector<int> nodes;//���ּ�ȸ ���

    //�Է�
    while (cin >> input)//�Է��� ��� ����������
        nodes.push_back(input);//�ش� �� �ֱ�

    //����
    postorder(0, nodes.size() - 1, nodes);