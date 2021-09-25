#include <algorithm>
/*
 * struct tree {
 *     int x;
 *     tree *l;
 *     tree *r;
 * };
 */

/* Lesson X.X Case #
 * 1. 문제:
 *   binary tree의 최대 높이를 구하여라.
 *
 * 2. 아이디어:
 *   모든 leaf가 같은 레벨인 것이 보장이 안 되기 때문에 다 따라가 볼 수 밖에 없다.
 *   recursive로 leaf까지 따라가 본다.
 *
 * 3. 코드:
 *   특별히 남길 comment는 없다.
 * */
int
height(tree *T)
{
    tree *l = T->l;
    tree *r = T->r;

    if (l && r)
        return max(height(l), height(r)) + 1;
    else if (l && !r)
        return height(l) + 1;
    else if (!l && r)
        return height(r) + 1;
    else //if (!l && !r) , leaf
        return 0;
}

int
solution(tree *T)
{
    return height(T);
}