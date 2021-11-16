#include <iostream>
#include <vector>

using namespace std;

//������
vector<int> back(int x, vector<int>& path) { //x = n���� ������ ����
    vector<int> result(0);//0���� �ʱ�ȭ
    while (x != 0) {//��ΰ� ���� ������
        result.push_back(x);//���� ���� ��� �迭�� x�־��ֱ�
        x = path[x];//�� �� ���갪���� ��ü
    }
    return result;//�迭 ��ȯ
}

//1�� ����� �ּ� ���� Ƚ�� ����
int makeOne(int n, vector<int>& path) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int min_value = dp[i - 1]; //�켱 i - 1 ���� Ƚ�� ����
        path[i] = i - 1;//�ϴ� i��ο� i-1����  ����
        if (!(i % 3) && min_value > dp[i / 3]) {//i�� 3���� ������ ���� �ʰ� 3���� ������ ��� ���� �����Ͽ��� ��� ���� Ƚ���� �� �� ������ ���� ���
            min_value = dp[i / 3];//�� ���� ������ min_value��ü
            path[i] = i / 3;//i��ο� 3���� ���� ������ ����
        }
        if (!(i % 2) && min_value > dp[i / 2]) {//i�� 2���� ������ ���� �ʰ� 2���� ������ ��� ���� �����Ͽ��� ��� ���� Ƚ���� �� �� ������ ���� ���
            min_value = dp[i / 2];//�� ���� Ƚ���� min_value��ü
            path[i] = i / 2;//��ο� 2�� ���� �� ����
        }
        dp[i] = min_value + 1;//1�� ������ �ϴϱ�
    }
    return dp[n];//Ƚ�� ��ȯ
}

/**
 * �⺻ ����: 1�� �����
 *
 * [��ȭ��]
 * dp[i] = (i�� ������ ������ ������ �� �� �ּ� ���� Ƚ��) + 1
 * dp[i] = min(dp[i / 3], dp[i / 2], dp[i - 1]) + 1
 *
 * [������]
 * path: �ε����� ������ ��Ÿ��, �ش� ������ ������ ������ ���� ���� ����
 * n���� ������ ����
 */

int main() {
    int n;

    //�Է�
    cin >> n;
    vector<int> path(n + 1, 0); //��� ����

    //����
    int ans = makeOne(n, path);//���� Ƚ��
    vector<int> result = back(n, path);//���� ���

    //���
    cout << ans << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';//���� ��� ���
    return 0;//����
}