#include <stdio.h>
#include <string.h>
#define N 50         // 叶子结点数
#define M 2 * N - 1  // 树中结点总数

typedef struct {
    char data[5];
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode;

typedef struct {
    char cd[N];
    int start;
} HCode;
// 由ht的叶子结点构造完整的哈夫曼树
void CreateHT(HTNode ht[], int n) {
    int i;
    int k;
    int lnode;
    int rnode;
    int min1;
    int min2;

    // 所有结点的相关域设置初值为-1
    for (i = 0; i < 2 * n - 1; i++)
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    // 构造哈夫曼树的分支结点
    for (i = n; i < 2 * n - 1; i++) {
        min1 = min2 = 32767;
        lnode = rnode = -1;
        // 查找最小和次小的结点
        for (k = 0; k <= i - 1; k++) {  // 只在尚未构造二叉树的结点中查找
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }
        ht[lnode].parent = i;  // 合并两个最小和次小的结点
        ht[rnode].parent = i;
        ht[i].weight =
            ht[lnode].weight + ht[rnode].weight;  // 计算双亲结点的权重
        ht[i].lchild = lnode;  // 设置双亲结点的左孩子
        ht[i].rchild = rnode;  // 设置双亲结点的右孩子
    }
}

void CreateHCode(HTNode ht[], HCode hcd[], int n) {
    int i;
    int f;
    int c;
    HCode hc;
    // 根据哈夫曼树构造所有叶子结点的哈夫曼编码
    for (i = 0; i < n; i++) {
        hc.start = n;
        c = i;
        f = ht[i].parent;
        // 循环直到树根结点
        while (f != -1) {
            if (ht[f].lchild == c)  // 处理左孩子结点
                hc.cd[hc.start--] = '0';
            else  // 处理右孩子结点
                hc.cd[hc.start--] = '1';
            c = f;
            f = ht[f].parent;
        }
        hc.start++;  // start指向哈夫曼编码最开始字符
        hcd[i] = hc;
    }
}
// 输出哈夫曼编码
void DispHCode(HTNode ht[], HCode hcd[], int n) {
    int i, k;
    int sum = 0, m = 0, j;
    printf("输出哈夫曼编码:\n");
    for (i = 0; i < n; i++) {
        j = 0;
        printf("      %s: ", ht[i].data);
        for (k = hcd[i].start; k <= n; k++) {
            printf("%c", hcd[i].cd[k]);
            j++;
        }
        m += ht[i].weight;
        sum += ht[i].weight * j;
        printf("\n");
    }
    // printf("平均长度=%g\n", 1.0 * sum / m);
}
int main() {
    int n = 15, i;
    char sss1[] = "the";
    char sss2[] = "of";
    char sss3[] = "a";
    char sss4[] = "to";
    char sss5[] = "and";
    char sss6[] = "in";
    char sss7[] = "that";
    char sss8[] = "he";
    char sss9[] = "is";
    char sss10[] = "at";
    char sss11[] = "on";
    char sss12[] = "for";
    char sss13[] = "his";
    char sss14[] = "are";
    char sss15[] = "be";
    char* str[] = {sss1, sss2,  sss3,  sss4,  sss5,  sss6,  sss7, sss8,
                   sss9, sss10, sss11, sss12, sss13, sss14, sss15};
    int fnum[] = {1192, 677, 541, 518, 462, 450, 242, 195,
                  190,  181, 174, 157, 138, 124, 123};
    // scanf("%d", &fnum[14]);
    HTNode ht[M];
    HCode hcd[N];
    for (i = 0; i < n; i++) {
        strcpy(ht[i].data, str[i]);
        ht[i].weight = fnum[i];
    }
    CreateHT(ht, n);          // 创建哈夫曼树
    CreateHCode(ht, hcd, n);  // 构造哈夫曼编码
    DispHCode(ht, hcd, n);    // 输出哈夫曼编码
    return 0;
}
