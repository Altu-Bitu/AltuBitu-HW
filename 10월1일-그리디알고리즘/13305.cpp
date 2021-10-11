#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll greedyOil(vector<pair<ll, ll>>& city, int n) {//���� �� �Ÿ�,�⸧��,���� ����
    ll cur_cost = city[0].second, tot_cost = 0;//�ֱ� �⸧���� ó�� ������ �⸧��, �� ����� 0���� �ʱ�ȭ

    for (int i = 0; i < n; i++) {
        if (city[i].second < cur_cost) //�� ������ �⸧���� �� �����ϸ� ��ü
            cur_cost = city[i].second;//��ü
        tot_cost += (cur_cost * city[i].first); //�̵� ���
    }
    return tot_cost;//���� �⸧�� ��ȯ
}

/**
 * 1. ���̰� �������� ȣ���� �ִٰ� ����
 * 2. ���ݱ��� ������ ���� �� ������ ���� ������ �����ҿ� ȣ���� �����Ѵ�
 * 3. �̹��� ������ ������ �⸧���� ���� ȣ���� ����� �������� �⸧������ �����ϴٸ� ȣ�� ��ü
 *
 * �� Ǯ�� : https://myunji.tistory.com/224
 */
int main() {
    int n;

    //�Է�
    cin >> n;
    vector<pair<ll, ll>> city(n, { 0, 0 });//���� �� �Ÿ��� �⸧�� �Է�
    for (int i = 0; i < n - 1; i++)
        cin >> city[i].first;//���� �� �Ÿ�
    for (int i = 0; i < n; i++)
        cin >> city[i].second;//�� ���ð� �⸧��

    //���� & ���
    cout << greedyOil(city, n);//�ּҰ�
}