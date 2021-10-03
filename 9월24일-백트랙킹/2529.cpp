#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int k;//�ε�ȣ�� ����
bool is_find;//�ε�ȣ ���踦 ������Ű����
vector<char> op(SIZE); //�ε�ȣ
vector<int> arr(SIZE), num(SIZE);//�ִ�, �ּҰ��̸� �ε�ȣ ���踦 �˾Ƴ��� ���� �迭, 
vector<bool> check(SIZE);//���ڸ� ����ߴ��� ǥ���ϱ� ���� �迭

//������ ���ڿ��� �ٲٴ� �Լ�
string arrToString(vector<int>& arr) {
    string result;
    for (int i = 0; i <= k; i++)
        result += (arr[i] + '0');//������ ���ڿ��� ��ȯ , 0�߰� �ؼ� ���ڷ� ǥ��
    return result;//���ڿ� ��ȯ
}

//���������� ���� ���ɼ� �ִ� ������ üũ�ϴ� �Լ�
bool promising(int idx) {
    if (op[idx] == '<' && arr[idx] > arr[idx + 1]) //�ε�ȣ�� '<'�ε� '>'������ ���� �ε�ȣ ���谡 �����ϴ� ���� �ƴϹǷ� false
        return false;
    if (op[idx] == '>' && arr[idx] < arr[idx + 1]) //�ε�ȣ�� '>'�ε� '<'������ ��  �ε�ȣ ���谡 �����ϴ� ���� �ƴϹǷ� false
        return false;
    return true; //���� ���谡 �ƴ϶�� true
}

//�ִ� or �ּڰ� ���ϴ� ��Ʈ��ŷ �Լ� (num�迭�� ���� ����)
void findValue(int cnt) {
    //���� 2�� �̻��� ��ġ�ƴٸ�, �־��� �ε�ȣ �����ϴ��� �˻�, �������� ������ �ٷ� ���� (����ġ��)
    if (cnt >= 2 && !promising(cnt - 2))
        return;
    if (cnt == k + 1) { //�ε�ȣ �����ϴ� ���� ã�� (��������)
        is_find = true;//�ε�ȣ ���� ����
        return;
    }
    for (int i = 0; i <= k; i++) { //num[i]: �ִ��̸� 9 ~ (9-k), �ּڰ��̸� 0 ~ k
        if (!check[num[i]]) {//num[i]�� ������ ������ �ʾҴٸ� 
            check[num[i]] = true;//check�迭�� trueǥ��
            arr[cnt] = num[i];//arr�迭�� �� ����,�ִ�,�ּڰ����� ������ �迭
            findValue(cnt + 1);//�ε��� �ϳ� ���ؼ� ȣ��
            if (is_find)
                return;//���� �ε�ȣ ���� �����ϴ� k+1���� ���ڸ� ã������ �Լ� ����
            check[num[i]] = false;//�ٽ� �ʱ�ȭ
            arr[cnt] = 0;//�ٽ� �ʱ�ȭ
        }
    }
}

/**
 * [��Ʈ��ŷ Ǯ��] (0ms)
 * ���� �ߺ����� ��ġ�� (N�� M(1)�� ����)
 * ���� ��ġ�� ������ �ش� ���� �� �� ���� �ε�ȣ ���踦 �����ϴ��� Ȯ��, �������� ������ back (����ġ��)
 */

int main() {
    string max_num, min_num; //����

    //�Է�
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> op[i];//�ε�ȣ ����
    }

    //�ִ� ����
    for (int i = 0; i <= k; i++) //num�迭�� �� �̸� ����
        num[i] = 9 - i; //�ִ��� 9���� (9-k)���� ���ڷ� �̷����
    findValue(0);//0�� �ε������� �ؼ� �ִ� �迭 ã��
    max_num = arrToString(arr);//arr�迭 ���ڿ��� ��ȯ

    //�ʱ�ȭ !����! �������� ��� �� �ʱ�ȭ ���Ա� ����� �� üũ����
    is_find = false;//�ʱ�ȭ
    check.assign(SIZE, false);//�ʱ�ȭ
    arr.assign(SIZE, 0);//�ʱ�ȭ

    

    //�ּڰ� ����
    for (int i = 0; i <= k; i++)
        num[i] = i; //�ּڰ��� 0���� k���� ���ڷ� �̷����
    findValue(0);//0�� �ε��������ؼ� �ּڰ� ã��
    min_num = arrToString(arr);//���ڿ��� ��ȯ

    //���
    cout << max_num << '\n' << min_num;

    return 0;
}