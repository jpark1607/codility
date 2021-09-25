/* Lesson 16.1
 * 1. 문제:
 *   vector A와 B가 어떤 특정 index i에 대한 시작점(A[i])과 끝점(B[i])으로 이루어진 세그먼트라고 할 때, 이 세그먼트들이 겹치지 않는
 *   선에서 최대한 수행될 수 있는 수를 구하시오.
 *
 * 2. 아이디어:
 *   (탐욕법) 어떤 시점 i에 대해서 가장 효율적인 것은, i 시점에 수행될 일이 가장 빨리 끝나는 것이다.
 *   그러므로 0에서부터 가장 빨리 끝나는 일을 찾은 뒤, 그 일을 끝낸 직후 또 빨리 끝나는 일을 찾는 것을 반복하면 된다.
 *
 * 3. 코드:
 *   [A] 특정 세그먼트의 시작점이 마지막 세그먼트의 끝나는 점보다 크면 그 세그먼트를 시작한다.
 * */
int
solution(vector<int> &A, vector<int> &B)
{
    int size = A.size();
    int count = 0;
    int pos = -1;
    int i;

    if (size == 0)
        return 0;

   for (i = 0; i < size; i++) {
       /* [A] */
       if (A[i] > pos) {
           pos = B[i];
           count++;
       }
    }

    return count;
}