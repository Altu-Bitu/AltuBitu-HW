//
// Created by BaeSuA on 2021-11-09.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5;//�����̰� ���� �� �ִ� �� ����

//������
vector<int> back(int x, vector<int>& path) { //x: k(��������)����
    vector<int> result(0); //���� ���
    while (x != -1) {//��ΰ� ���� ���� ������ ����ؼ�
        result.push_back(x);//���� ���� �־��ֱ�
        x = path[x]; //���� ����
    }
    return result;//�ִ� ��η� ���� �迭
}

int bfs(int n, int k, vector<int>& path) {//�ִܰ��
    vector<int> check(SIZE + 1, 0);//��ü ���� ���ؼ� Ȯ��
    queue<int> q; //ť�� ��ǩ�� ����
    int ans = 0; //�ִ� �ð�

    check[n] = 1; //���� ��� �湮 üũ
    q.push(n); //���� ��� �ʱ�ȭ
    while (!q.empty()) {//ť�� �� ������
        int x = q.front(); //���� Ž���Ϸ��� ��ġ
        q.pop();//ť���� �������ֱ�

        if (x == k) { //���� ã���� Ž�� ����.
            ans = check[x] - 1; //���� ��� �ʱ�ȭ�� 1�� �߱� ������ 1�� ����
            break;//�ݺ��� ������
        }

        vector<int> child = { x - 1, x + 1, x * 2 }; //�ڽĳ��
        for (int i = 0; i < 3; i++) {//�ڽ� ��尡 3������
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { //���� ���� �ְ�, ù �湮�̶��
                check[child[i]] = check[x] + 1;//������� Ž���ϴ� �� �ɸ� �ð��� check[x]�� ����Ǿ� �����Ƿ� �����ֱ�
                path[child[i]] = x; //��� ����
                q.push(child[i]);//���Ŀ� Ž���ؾ��ϴϱ� ť�� �־��ֱ�
            }
        }
    }
    return ans;//�ִ� ��η� �ɸ��� �ð�
}

/**
 * �ִܰŸ�(BFS) ������
 * - �⺻ ����: ���ٲ���
 */

int main() {
    vector<int> path(SIZE + 1, -1); //��� ���� ����
    int n, k;

    //�Է�
    cin >> n >> k;//�������� ��ġ , ������ ��ġ

    //����
    int ans = bfs(n, k, path);//�ִ� ��� ����
    vector<int> result = back(k, path);//������

    //���
    cout << ans << '\n';//�ִ� ��η� �ɸ��� �ð�
    for (int i = result.size() - 1; i >= 0; i--)//������ ������ �ݴ�� ���
        cout << result[i] << ' ';
    return 0;//����
}