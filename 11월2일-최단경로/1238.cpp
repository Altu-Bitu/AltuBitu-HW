#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5; //�ִ� n-1���� ������ ������ ��

vector<int> dijkstra(int n, int start, vector<vector<ci>>& graph) {
    vector<int> dist(n + 1, INF); //���������� �ִ� �ð� ���� �迭
    priority_queue<ci, vector<ci>, greater<>> pq; //first : ���������κ��� �ҿ�ð�, second : ����

    //���� ��ġ �ʱ�ȭ
    dist[start] = 0;
    pq.push({ 0, start });//�켱���� ť�� �־��ֱ�

    while (!pq.empty()) {//ť�� �� ������
        int t = pq.top().first;//�̵��ϴµ� �ɸ��� �ð�
        int node = pq.top().second;//������
        pq.pop();//�켱���� ť���� ����

        if (t > dist[node]) //�̹� �� ª�� ��ΰ� �����Ѵٸ�
            continue;//�ǳʶٱ�

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //����� ����
            int next_t = t + graph[node][i].second; //���������κ��� ����� ���������� �ҿ�ð�
            if (dist[next_node] > next_t) { //�� ª�� ��η� �� �� �ִٸ�
                dist[next_node] = next_t;//�ٲ��ֱ�
                pq.push({ next_t, next_node });//�ҿ�ð��̶� ����� ���� �켱���� ť�� �־��ֱ�
            }
        }
    }
    return dist;//�ҿ�ð� ���� �迭 
}

/**
 * 1. �� �л����� X�� ���� �� �ɸ��� �ִ� �ð� (i -> x)
 * 2. X���� �ٽ� ���ƿ��� �� �ɸ��� �ִ� �ð� (x -> i)
 *
 * �켱 �ܹ��� �׷����̹Ƿ� ���� 2�� ���� �ٸ� �� �־� ���� �����־�� ��
 * 2���� �������� X�� ���ͽ�Ʈ��� ������ ����
 * 1���� ������ �׷������� �������� X�� ���ͽ�Ʈ��� ���� -> �������� �ٽ� �����·� ������ �ᱹ �������� X�� �� (4ms)
 *
 * �ش� ������ N�� ũ�� �ʾ� 1���� �������� i�� ���ͽ�Ʈ�� N�� �Ǵ� 1�� 2���� ��Ʋ�� ���� �� ȿ������ �÷��̵�-���ȷ� ���� ���� (220ms)
 */

int main() {
    int n, m, x, a, b, c, ans = 0;//���� ��, ���� ��, ���̴� ���� ����,������ ,������,�ҿ�ð�,����ҿ�ð�

    //�Է�
    cin >> n >> m >> x;
    vector<vector<ci>> graph(n + 1, vector<ci>());//������,������,�ҿ� �ð� ����
    vector<vector<ci>> rev_graph(n + 1, vector<ci>()); //������ �׷���
    while (m--) {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c }); //�ܹ���
        rev_graph[b].push_back({ a, c }); //������
    }

    //����
    vector<int> dist_go = dijkstra(n, x, rev_graph); //������ �׷������� �������� x�� ��� ������ �ִ� �ð�
    vector<int> dist_back = dijkstra(n, x, graph); //�������� x�� ��� ������ �ִ� �ð�
    for (int i = 1; i <= n; i++)
        ans = max(dist_go[i] + dist_back[i], ans);//���ٰ� ���ƿ��� �ð��̶� ��

    //���
    cout << ans << '\n';//���� �ҿ�ð�
    return 0;//����
}