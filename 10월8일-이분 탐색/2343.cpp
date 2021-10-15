#include <iostream>
#include <vector>

using namespace std;

int bluRayNum(vector<int>& lesson, int size) {
    int len = 0; //�� ��緹�̿� ���� ���� ����
    int cnt = 0; //��緹�� ����
    for (int i = 0; i < lesson.size(); i++) {
        if (len + lesson[i] > size) { //�� ��緹�̿� �� �� �ִ� ���̸� �ʰ�
            len = 0;//�� ��緹�̷� ����Ž
            cnt++;//��緹�� ���� 1 �����ֱ�
        }
        len += lesson[i];//�־��� ���� ���� ��� �����ֱ�
    }

    return cnt + 1; //������ ������ ��緹�� ���ؼ� ����
}

int lowerSearch(vector<int>& lesson, int left, int right, int target) {
    int ans = 0; //m���� ��緹�̸� ������ �� �ּ� ũ��
    while (left <= right) {
        int mid = (left + right) / 2;//mid��
        int cnt = bluRayNum(lesson, mid); //��緹�� ũ�Ⱑ mid�� ��, �� ���� ��緹�̸� ������ ����

        if (cnt <= target) {//��緹�� ������ target���� �۰ų� ������
            right = mid - 1;//�� �۾ƾ��ϴϱ� right �ٿ��ֱ�
            ans = mid; //cnt == target�� ��
        }
        else {
            left = mid + 1;//�� Ŀ���ϴϱ� left ũ�� ���ֱ�
        }
    }

    return ans;//�ּ� ũ�� ��ȯ
}

/**
 * m���� ��緹�̿� ��� ��Ÿ ���� �������� ��ȭ�� �� ��緹�� ũ���� �ּҸ� ���ϴ� ����
 * -> Ư�� ��緹�� ũ��� ��Ÿ ���� �������� ���ʷ� ��ȭ�� ��, �� ��緹�� ������ m���� �Ǵ°�?
 *
 * left: ������ ��緹���� �ּ� ũ�� (��緹�� �ִ� ����) -> ���� �� ���� ���̰�
 * right: ������ ��緹���� �ִ� ũ�� (��緹�� �ּ� ����) -> ��� ���Ǹ� ���� ���̰�
 */

int main() {
    int n, m, left = 0, right = 0;//���� �� , ��緹�� ����, left,right �ʱ�ȭ

    //�Է�
    cin >> n >> m;
    vector<int> lesson(n, 0);//�迭 �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        cin >> lesson[i];//���� �ð� �Է�
        left = max(left, lesson[i]); //���� �� ���� ���̰� ã��
        right += lesson[i]; //��� ���� ���� ���ϱ�
    }

    //���� & ���
    cout << lowerSearch(lesson, left, right, m);

    return 0;//����
}