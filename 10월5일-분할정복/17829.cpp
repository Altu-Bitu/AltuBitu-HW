#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix;//입력받을 행렬

int divide(int row, int col, int size) {//행 ,열,크기
    //Conquer : n의 크기가 1
    if (size == 1)//크기가 1일때 끝나므로
        return matrix[row][col];//바로 반환

    //Divide : 행렬 4등분 하기
    int next_size = size / 2;//행렬 4등분하기 위해서
    vector<int> sub_problem;//계속해서 만들 크기가 줄어든 행렬
    for (int i = 0; i <= next_size; i += next_size) {//행렬 4등분
        for (int j = 0; j <= next_size; j += next_size)//행렬 4등분
            sub_problem.push_back(divide(row + i, col + j, next_size));//sub_problem에 divide 함수 값으로 받을 두번째로 큰 값들을 계속해서 저장해서 행렬 구하기
    }

    //Combine : 두번째로 큰 수만 남기기
    sort(sub_problem.begin(), sub_problem.end(), greater<>());//내림차순으로 정렬
    return sub_problem[1];//두번째로 큰 수
}

/**
 * 1. 행렬 4등분 하기
 * 2. 행렬의 크기가 1이라면 원소 리턴
 * 3. 리턴된 원소 4개 모아서 두번째로 큰 수만 리턴
 */
int main() {
    int n;

    //입력
    cin >> n;//nxn행렬
    matrix.assign(n, vector<int>(n));//nxn행렬
    for (int i = 0; i < n; i++) {//행렬 입력 받기
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    //연산 & 출력
    cout << divide(0, 0, n);//결과 출력
}