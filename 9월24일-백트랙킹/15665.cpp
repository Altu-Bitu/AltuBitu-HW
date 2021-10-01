#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7; //�迭 ũ��

int n, m;
int num[SIZE], ans[SIZE];//num�迭�� �� �迭

void backtracking(int cnt) {
    if (cnt == m) { //���� m�̶�� (��������)
        for (int i = 0; i < m; i++)//���
            cout << ans[i] << ' ';//m���� ���
        cout << '\n';//�� �ٿ� �ϳ���
        return;
    }
    int value = -1; //������ ������ ��
    for (int i = 0; i < n; i++) {
        if (value != num[i]) { //������ Ž���� ���� �ƴ϶��(=�ش� �� ��� �����ϴٸ�)
            value = num[i];//�̹� ���ĵ� �����̹Ƿ� ���� �ߺ��� ���� ���´ٸ� �ٷ� �ڿ� ���� ���̹Ƿ� num[i]�� value�� �ֱ�
            ans[cnt] = num[i];//�� �迭�� �ֱ�
            backtracking(cnt + 1);//�ε��� ���� ���Ѽ� ȣ��
        }
    }
}

/**
 * [��Ʈ��ŷ Ǯ��] (184ms)
 * �ؼ� : https://myunji.tistory.com/309
 */
int main() {
    //�Է�
    cin >> n >> m;//n���� ���� �߿��� m���� ���� ��� ���� ,���� ���� ��� �ǳ� �ߺ��Ǵ� ������ �ȵ�
    for (int i = 0; i < n; i++)
        cin >> num[i];//n���� ���ڸ� num������ �Է�

    //����
    sort(num, num + n);//n���� ���� �������� ����

    //���� + ���
    backtracking(0);//0���� �����ϴ� �Լ� ȣ��
}