#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> immigration;//�� �ɻ�뿡�� �ɻ��ϴµ� �ɸ��� �ð�

//�ɻ縦 �޴µ� �ɸ��� �ð��� tot_time�� ��, �ɻ縦 ���� �� �ִ� ����� ��
ll cntPeople(ll tot_time) {
    ll cnt = 0;//���� �� �ִ� ��� ��
    for (int i = 0; i < immigration.size(); i++)
        cnt += (tot_time / immigration[i]);//�ɻ��ϴ� �� �ɸ��� �ð� �ȿ� �� ���� �ɻ��� �� �ִ���
    return cnt;//�ɻ��� �� �ִ� ��� �� ��ȯ
}

ll lowerSearch(ll left, ll right, int target) {
    ll ans = 0;//�ɸ��� �ð��� �ּڰ�
    while (left <= right) {//left�� right�� ������ ������ ���
        //�ɻ縦 �޴µ� �ɸ��� �ð��� mid�� ��, �� ���� ģ������ �ɻ縦 ���� �� �ִ°�?
        ll mid = (left + right) / 2;//�߰� ��
        ll entrance = cntPeople(mid);//�߰����� cntPeople�� �־��� ��� �ɻ� ���� �� �ִ� ��� ��

        if (entrance >= target) {//������ ���� ��� ���� ����̿� ģ������ ������ ũ�ٸ�
            ans = mid;//�ּڰ��� mid�� �ΰ� ���� ���� target�� ���� �ʴٸ� left���� right���� �� Ŭ ���̹Ƿ� ��� ���� 
            right = mid - 1;//right�� �Ű��ֱ�
        }
        else if (entrance < target)//���� ����̿� ģ������ ���� �������� ���ߴٸ�
            left = mid + 1;//left�� �ű��
    }
    return ans;//�ּڰ� ��ȯ
}

/**
 * ����̿� ģ������ �ɻ縦 �޴µ� �ɸ��� �ð��� �ּڰ�
 * -> �ð��� t��ŭ �־��� ��, m�� �̻��� ģ������ �Ա� �ɻ縦 ���� �� �ִ°�?
 *
 * left : ��� �ɻ���� �ɻ� �ð��� k�̰�, �ɻ�밡 ģ������ ����ŭ �־����ٸ� �ɸ��� �ð��� k
 * right : �ɻ簡 ���� ���� �ɸ��� �ɻ�� k���� ��� ģ������ �Ѹ� �Ա��ɻ縦 �޴´ٸ�, �ɸ��� �ð��� k*m
 *
 * !����! right k*m�� �ִ��� �ɻ� �ð��� �ִ� 10^9�� m�� �ִ� 10^9�� ���� 10^18�̴�.
 * �׷��Ƿ� long long ������ ��� ��.
 */
int main() {
    int n, m;//�ɻ�� ���� , ����̿� ģ���� ��
    ll max_time = 0, min_time = 1e9;//�ִ��̶� �ּڰ� �ʱ�ȭ

    //�Է�
    cin >> n >> m;
    immigration.assign(n, 0);//�ɻ�뿡�� �ɸ��� �ð� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        cin >> immigration[i];//�ɻ�뿡�� �ɸ��� �ð� �Է� �ޱ�
        max_time = max(max_time, immigration[i]);//�� �ɻ�뿡�� �ɸ��� �ð��� max�� ���ؼ� max�� ����
        min_time = min(min_time, immigration[i]);//�� �ɻ�뿡�� �ɸ��� �ð��� min�� ���ؼ� min�� ����
    }

    //���� & ���
    cout << lowerSearch(min_time, max_time * m, m);
}