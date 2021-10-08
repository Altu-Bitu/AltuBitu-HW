#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int makeTriangle(int n, vector<int>& straw) {//���� ��, ���� ���̵�
    int ans = -1;//�� �� ������ �� �ּڰ� �ʱ�ȭ

    for (int i = 0; i < n - 2; i++) {//2���� �ﰢ���� �ٸ� ���̾���ؼ�
        if (straw[i] < straw[i + 1] + straw[i + 2]) { //�ﰢ���̶��
            ans = straw[i] + straw[i + 1] + straw[i + 2];//���� �����ֱ�
            break;//������
        }
    }

    return ans;//�ִ� ��ȯ
}

/**
 * �� ���� ������ ���� �ִ밡 �ǵ��� �ﰢ���� ����� ����
 * �־����� ������ ���̸� �������� ������ ��, ���̰� �� ������� �׸��������� Ž��
 * ���� ���� ���̸� ���� �� ���� ���̶� �����ϰ� �ﰢ���� ����������� Ȯ���ϸ� �ȴ�
 */

int main() {
    int n;

    //�Է�
    cin >> n;
    vector<int> straw(n, 0);//n�� ����
    for (int i = 0; i < n; i++)
        cin >> straw[i];//���Ϳ� ���� ���� ����ֱ�

    //����
    sort(straw.begin(), straw.end(), greater<>());//��������

    //���
    cout << makeTriangle(n, straw);//�ִ� ���ϱ�

    return 0;//����
}