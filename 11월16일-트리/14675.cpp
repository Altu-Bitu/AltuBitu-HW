#include <iostream>
#include <vector>

using namespace std;

//������, ������ �ľ� �Լ�
string isTrue(int t, int k, vector<vector<int>>& tree) {
    if (t == 2)
        return "yes";//��� ������ �������̹Ƿ� yes
    if (tree[k].size() >= 2)
        return "yes";//k�� ������ ����� ������ ����� ������ 2����  yes
    return "no";//�ƴϸ�no
}

/**
 * �θ� ��带 �� �� ���⿡ Ʈ���� ����� �׷����� ����
 * ������: Ʈ���� ��� ������ ����Ǿ� �ְ�, ����Ŭ�� �������� �ʱ� ������ ����� ������ 2�� �̻��̸� ������
 * ������: Ʈ���� ��� ������ ����Ǿ� �ְ�, ����Ŭ�� �������� �ʱ� ������ ��� ������ ������
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, q, t, k;

    //�Է�
    cin >> n;
    vector<vector<int>> tree(n + 1, vector<int>(0));//������ 1���� Ʈ��
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);//Ʈ�� ���� ���� �Է�
        tree[b].push_back(a);//Ʈ�� ���� ���� �Է�
    }
    cin >> q;
    while (q--) {
        cin >> t >> k;//���� , ���� Ȥ�� ����
        cout << isTrue(t, k, tree) << '\n';//���
    }
    return 0;//����
}