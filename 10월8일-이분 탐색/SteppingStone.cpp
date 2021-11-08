#include <iostream>
#include <vector>

using namespace std;

//cnt���� �ǳ� ��, �ǳ� �پ�� �ϴ� ����� ĭ ���� �ִ�
int jumpDist(vector<int>& stones, int cnt) {//�� ��
    int dist = 1, prev = -1; //�ǳʶ� ĭ, ������ ���� �����
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] >= cnt) { //���� �� ����,cnt���� ��Ƶ� 0���� ũ�ų� �����ϱ�
            dist = max(dist, i - prev);//������ ���� �� ���ְ� �� �� �ѹ��� �ִ�� �� �� �ִ� ĭ ����
            prev = i;//����� ���� ����? (�³���?)
        }
    }
    dist = max(dist, (int)stones.size() - prev); //������ ������ �ǳ������ �̵�
    return dist;//�ִ� ��ȯ
}

int upperSearch(vector<int>& stones, int left, int right, int target) {
    int ans = 0;//�ǳ� �� �ִ� ���� �ִ�
    while (left <= right) {
        //mid��ŭ�� ģ������ �ǳ� ��, �ǳ� �پ�� �ϴ� ����� ĭ ���� �ִ��� ��ĭ�ΰ�?
        int mid = (left + right) / 2;//mid 
        int jump = jumpDist(stones, mid);//mid���϶� �ǳʶپ�� �ϴ� ����� ĭ ���� �ִ�

        if (jump <= target) {//target���� �������� 
            ans = mid;//�ִ񰪿� mid �־��ְ�
            left = mid + 1;//left�� �ٲ��ֱ�
        }
        else if (jump > target)//target���� Ŭ ������
            right = mid - 1;//���� �ٿ��� �ϹǷ� right�� �ٲ��ֱ�
    }
    return ans;//�ִ� ��ȯ
}

/**
 * ¡�˴ٸ��� �ǳ� �� �ִ� �ϴ��� ģ������ �ִ�
 * -> �ϴ��� ģ���� n���� ¡�˴ٸ��� �ǳ� ��, �ǳ� �پ�� �ϴ� ����� ĭ ���� �ִ��� k���� ������?
 *
 * left : �迭�� ���Ұ� 1�̻��̱� ������ �ּ��� 1���� �ǳ� �� ����
 * right : �ƹ��� ���� �ǳʵ� �迭 ������ �ִ񰪺��� ���� �ο��� �ǳ� ���� ����
 */
int solution(vector<int> stones, int k) {
    int right = 0; //�迭 ������ �ִ�
    for (int i = 0; i < stones.size(); i++)
        right = max(right, stones[i]);//�� ���� ������ �ִ� �� �߿� �ִ� ã�Ƴ���

    return upperSearch(stones, 1, right, k);//�Լ� ȣ��
}

int main() {
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };//�� ���� ��
    int k = 3;//�ִ� 3ĭ�� �� �� ����
    cout << solution(stones, k);//�ִ�
}