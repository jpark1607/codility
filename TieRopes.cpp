/* Lesson 16.2
 * 1. 문제:
 *   vector A는 로프의 길이에 대한 배열을 표현한다. i번째 로프와 i+1번째 로프를 묶어 K보다 길이가 크거나 같게 만들 수 있는 개수를 구하여라.
 *
 * 2. 아이디어:
 *   (탐욕법) 어떤 로프는 그 다음 로프만 연결할 수 있다. 그러므로 앞에서부터 하나씩 이어 붙이면서 크기를 비교해보면 된다.
 *
 * 3. 코드:
 *   코드상 특별히 남길 내용이 없음
 * */
int
solution(int K, vector<int> &A)
{
    int size = A.size();
    int count = 0;
    int sum = 0;
    int i;


    for (i = 0; i < size; i++) {
        sum += A[i];

        if (sum >= K) {
            sum = 0;
            count++;
        }
    }

    return count;
}