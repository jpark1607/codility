/* Exercise 5.1
 * 1. 문제:
 *   주차장 비용이 다음과 같다.
 *     1) 최초 입장 시 비용 : 2
 *     2) 최초 한시간 사용비 : 3
 *     3) 최초 한시간 이후 한시간마다 사용비 : 4
 *   들어온 시간을 E, 나간 시간을 L이라고 할 때, 주차장 비용을 구하여라.
 *
 * 2. 아이디어:
 *   string을 int로 바꾸고 계산한다.(중간에 있는 ':'는 제외)
 *
 * 3. 코드:
 *   딱히 남길 comment가 없다.
 * */
int
solution(string &E, string &L)
{
    int eTime, lTime;
    int fee = 2;

    if (!E.compare(L))
        return fee;

    fee += 3;

    eTime = (E[0] - 48) * 1000 + (E[1] - 48) * 100 + (E[3] - 48) * 10 + (E[4] - 48) + 100;
    lTime = (L[0] - 48) * 1000 + (L[1] - 48) * 100 + (L[3] - 48) * 10 + (L[4] - 48);

    while (eTime < lTime) {
        eTime += 100;
        fee += 4;
    }

    return fee;
}