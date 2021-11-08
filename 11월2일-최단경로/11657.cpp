//
// Created by iw040 on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <tuple>//3�� ������ �� ����

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
const int INF = 1e6 * 5;

//����-����
vector<ll> bellmanFord(int n, int m, int start, vector<ti>& edges) {
    //�����÷ο� X, ����÷ο� O
    //500 * 6,000 * (-10,000) => int ���� �Ѿ!
    vector<ll> dist(n + 1, INF);//INF�� �ʱ�ȭ

    dist[start] = 0; //���� ��ġ �ʱ�ȭ

    for (int i = 1; i <= n; i++) {
        bool flag = true; //�� �̻� �ݺ����� ������ �ʿ䰡 ������ Ȯ��
        for (int j = 0; j < m; j++) {
            //s->d�� ���� ������ ����ġ�� w
            int s = get<0>(edges[j]);//�ε��� 0�� ������
            int d = get<1>(edges[j]);//1�� ������
            int w = get<2>(edges[j]);//�ð�

            if (dist[s] == INF) //���� ���������� s�� ���� ��ΰ� �߰ߵ��� �ʾ����Ƿ� ������ �� ����
                continue;//�������� �Ѿ��
            ll next_weight = w + dist[s];//���۵��ñ����� �ɸ��� �ð�
            if (dist[d] > next_weight) { //�� ª�� ��η� �� �� �ִٸ�
                if (i == n) //n��° �����̾��ٸ� ���� ����Ŭ�� �߻��� ��
                    return { INF + 1 };//��ΰ� ���ٰ� ������ �� �����Ƿ� 1 ���ؼ� ����
                dist[d] = next_weight;//�� ª�� �ð����� ����
                flag = false;//flag�ٲ��ֱ�
            }
        }
        if (flag) //�� �̻� ���ŵ��� �ʾҴٸ� �� Ž���� �ʿ� ����
            break;
    }
    return dist;//�ּ� �ð� �迭 ��ȯ
}

int main() {
    int n, m, a, b, c;//����, ������ ��, ������ ����

    //�Է�
    cin >> n >> m;
    vector<ti> edges(m); //���� ������ ������ ���� (�׷��� ���躸�ٴ� ���� ��ü�� ������ �� �߿���)
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;//���� ���� �Է�
        edges[i] = { a, b, c }; //���� �׷���
    }

    //����
    vector<ll> ans = bellmanFord(n, m, 1, edges);

    //���
    if (ans[0] == INF + 1) { //���� ����Ŭ
        cout << -1;//-1���
        return 0;//�����ϱ�
    }
    for (int i = 2; i <= n; i++)//���� ����Ŭ �ƴϸ�
        cout << ((ans[i] == INF) ? -1 : ans[i]) << '\n';//INF�� -1���, �ƴϸ� �ּ� �ð� ���
}