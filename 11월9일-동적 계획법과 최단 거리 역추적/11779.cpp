//
// Created by BaeSuA on 2021-11-09.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e8;//���*���� ����

//������
vector<int> back(int x, vector<int>& path) { //x: �������� ����
    vector<int> result(0);//0���� �ʱ�ȭ
    while (x != 0) {//0���� ���൵ ��ΰ� ���� �ſ��� 0���� �ص� ������
        result.push_back(x);//�迭�� ���� ���� �־��ֱ�
        x = path[x]; //���� ����
    }
    return result;//�ִ� ��α��� ���� �迭
}

int dijkstra(int n, int s, int e, vector<vector<ci>>& graph, vector<int>& path) {
    vector<int> dist(n + 1, INF);//��� �ʱ�ȭ
    priority_queue<ci, vector<ci>, greater<>> pq;

    //���� ��ġ �ʱ�ȭ
    dist[s] = 0;//���� ���ô� ��� 0
    pq.push({ 0, s });//����ġ , ���� ����

    while (!pq.empty()) {//ť�� �� ������
        int weight = pq.top().first;//����ġ
        int node = pq.top().second; //�߰� ����
        pq.pop();//ť���� ����

        if (weight > dist[node]) //�̹� Ž���� ���� (�� �ڵ� ������ �ð��ʰ�)
            continue;//�ǳ� �ٰ� ��������

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //����� ����
            int next_weight = weight + graph[node][i].second; //���������κ��� ����� ���������� �Ÿ�
            if (dist[next_node] > next_weight) { //�� ª�� ���
                dist[next_node] = next_weight;//�� ª�� �ɷ� �ٲ��ֱ�
                path[next_node] = node; //��� ����
                pq.push({ next_weight, next_node });//����ġ�� ���� ��带 �־��ֱ�
            }
        }
    }
    return dist[e];//������������ �ִܰ��
}

/**
 * ���ͽ�Ʈ�� ������
 * - �⺻ ����: �ּ� ��� ���ϱ�
 */

int main() {
    int n, m, a, b, c, s, e;

    //�Է�
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //���� ����Ʈ
    vector<int> path(n + 1, 0); //��� ����
    while (m--) {
        cin >> a >> b >> c;//��� ���� , ���� ���� , ���
        graph[a].push_back({ b, c }); //�ܹ��� �׷���
    }
    cin >> s >> e;//��� ���� , ���� ����

    //����
    int ans = dijkstra(n, s, e, graph, path);
    vector<int> result = back(e, path);//������ 

    //���
    cout << ans << '\n' << result.size() << '\n';//�ּҺ�� , ���İ��� ���� ����
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';//���
    return 0;//����
}