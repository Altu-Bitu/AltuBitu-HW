//
// Created by iw040 on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;//3���� ������ �����ϱ� ���ؼ� pair�� �����
const int INF = 1e5 * 2; //�ִ� V-1���� ������ ������ ��

//���ͽ�Ʈ��
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph) {//����, ������
    vector<int> dist(vertex + 1, INF);//1���� �����ϱ� ������
    priority_queue<ci, vector<ci>, greater<>> pq; //first : ���������κ����� �Ÿ�, second : ����

    //���� ��ġ �ʱ�ȭ
    dist[start] = 0;
    pq.push({ 0, start });//0���� �ʱ�ȭ

    while (!pq.empty()) {//ť�� ��������
        int weight = pq.top().first;//���������������� ����ġ
        int node = pq.top().second;//����
        pq.pop();

        if (weight > dist[node]) //�̹� Ȯ���ߴ� ����
            continue;//�������� �ٷ� �Ѿ��,�ߺ��� ���̱� ����
        for (int i = 0; i < graph[node].size(); i++) {//����Ǿ� �ִ� ��� ������ ���� Ȯ��
            int next_node = graph[node][i].first; //����� ����
            int next_weight = weight + graph[node][i].second; //���������κ��� ����� ���������� �Ÿ�
            if (dist[next_node] > next_weight) { //�� ª�� ��η� �� �� �ִٸ�
                dist[next_node] = next_weight;//����ġ �����ϱ�
                pq.push({ next_weight, next_node });//���� ť�� �ֱ�
            }
        }
    }
    return dist;//�ִ� ��ΰ� ��ȯ
}

int main() {
    int vertex, edge, k, u, v, w;//�Է� �ޱ�

    //�Է�
    cin >> vertex >> edge >> k;
    vector<vector<ci>> graph(vertex + 1, vector<ci>(0)); //���� ����Ʈ
    while (edge--) {//edge�� ����ŭ �Է� �ޱ�
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); //���� �׷���
    }

    //����
    vector<int> ans = dijkstra(vertex, k, graph);

    //���
    for (int i = 1; i <= vertex; i++) {//������ ��������
        if (ans[i] == INF)//��ΰ� ������
            cout << "INF";
        else
            cout << ans[i];//�ƴϸ� �ִ� ����� ��ΰ� ���
        cout << '\n';
    }
}