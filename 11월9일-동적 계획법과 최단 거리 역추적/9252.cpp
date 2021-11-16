#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
//��, ��, �»���
int dr[3] = { -1, 0, -1 };
int dc[3] = { 0, -1, -1 };

//������
string back(string str1, vector<vector<int>>& path) {
    string result = "";//�ʱ�ȭ
    int r = n, c = m;//�� ,��
    while (path[r][c] != -1) {//��ΰ� ���� ������
        int d = path[r][c];//��� ����
        if (d == 2) //�»��⿡�� ������ ��� -> str1[r - 1] == str2[c - 1]
            result += str1[r - 1];
        r += dr[d]; //������
        c += dc[d]; //������
    }
    reverse(result.begin(), result.end());//���� ������ �ٲ��ֱ�
    return result;//���� 
}

//LCS ���� ���ϴ� �Լ�
int lcs(string str1, string str2, vector<vector<int>>& path) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));//���� ����
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] != str2[j - 1]) { //�� ���ڰ� ���� �ٸ���
                dp[i][j] = dp[i - 1][j]; //�켱 ���� �� ������ ������ ����
                path[i][j] = 0; //���(����) ����
                if (dp[i][j] < dp[i][j - 1]) { //������ �� ũ�ٸ�
                    dp[i][j] = dp[i][j - 1];//�Ʒ��� ������ ����
                    path[i][j] = 1; //���(����) ����
                }
            }
            else if (str1[i - 1] == str2[j - 1]) { //�� ���ڰ� ���� ���ٸ�
                dp[i][j] = dp[i - 1][j - 1] + 1;//�� �� ���������� ���̿��� 1 �����ֱ�
                path[i][j] = 2; //���(����) ����
            }
        }
    }
    return dp[n][m]; //LCS ���� ����
}

/**
 * �⺻ ����: LCS (�ش� Ǯ�̴� "08. ������ȹ��.pdf" ����)
 *
 * [������]
 * - ����, ����, �»��� �� ��� ���⿡�� �Դ��� ��θ� ������ ��, �������ϴ� ����
 * - ��� ������ dp�迭�� ���ŵ� �� ��
 *
 * �ش� Ǯ�̴� �ε����� ���ϰ� �����ϱ� ���� dp�� path �迭�� (1, 1)���� ����
 */

int main() {
    string str1, str2;

    //�Է�
    cin >> str1 >> str2;
    n = str1.length();// ù ��° ������ ����
    m = str2.length();//�� ��° ������ ����
    vector<vector<int>> path(n + 1, vector<int>(m + 1, -1)); //�� �� ���� ����

    //����
    int ans = lcs(str1, str2, path); //lcs
    string result = back(str1, path); //������

    //���
    cout << ans << '\n' << result << '\n';
    return 0;
}
