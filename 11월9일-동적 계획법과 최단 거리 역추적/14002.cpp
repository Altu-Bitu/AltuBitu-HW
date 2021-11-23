//
// Created by BaeSuA on 2021-11-09.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<int> back(int x, vector<int>& path) {
    vector<int> result(0); //Lis�� ������ ���� �ε������� ��
    while (x != -1) {//��ΰ� ���� ������
        result.push_back(x);//���� ���� �־��ֱ�
        x = path[x]; //���� ���
    }
    return result;//���� 
}

//�ð� ���⵵ O(n^2) Lis
ci lis(int n, vector<int>& arr, vector<int>& path) {
    vector<int> dp(n, 1);//����
    ci ans = { 1, 0 }; //���� ����, ������ ���� �ε���

    for (int i = 1; i < n; i++) {
        int index = -1; //��� ������ ����
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { //�����ϴ� ����, ���� ū dp[j] + 1
                dp[i] = dp[j] + 1;//dp[j] �������� �;��ϴϱ�
                index = j;//�����ϴ� �������� �� �� ���� ����
            }
        }
        path[i] = index;//���߿� ������ �ؾ��ϴϱ� path[i]�� j����
        if (ans.first < dp[i]) //���� ���� + ������ ���� �ε��� ����
            ans = { dp[i], i };//������� , ������ ���� �ε���
    }
    return ans;//���� ���� , ������ ���� �ε���
}

/**
 * ������ȹ�� ������
 * - �⺻ ����: ���� �� �����ϴ� �κ� ����
 */

int main() {
    int n;

    //�Է�
    cin >> n;
    vector<int> arr(n); //����
    vector<int> path(n, -1); //��� ���� �迭
    for (int i = 0; i < n; i++)
        cin >> arr[i];//���� �Է� �ޱ�

    //����
    ci ans = lis(n, arr, path); //first: ���� ����, second: ���� ������ ������ ���� �ε���
    vector<int> result = back(ans.second, path);//���� ������ ������ ���� �ε����� ��� �޾Ƽ� ������

    //���
    cout << ans.first << '\n';//���� ���� ���
    for (int i = result.size() - 1; i >= 0; i--)//��� ���
        cout << arr[result[i]] << ' ';
    return 0;//����
}