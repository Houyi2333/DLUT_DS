#include <stdio.h>
#include <string.h>
#define N 50         // Ҷ�ӽ����
#define M 2 * N - 1  // ���н������

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
// ��ht��Ҷ�ӽ�㹹�������Ĺ�������
void CreateHT(HTNode ht[], int n) {
    int i;
    int k;
    int lnode;
    int rnode;
    int min1;
    int min2;

    // ���н�����������ó�ֵΪ-1
    for (i = 0; i < 2 * n - 1; i++)
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    // ������������ķ�֧���
    for (i = n; i < 2 * n - 1; i++) {
        min1 = min2 = 32767;
        lnode = rnode = -1;
        // ������С�ʹ�С�Ľ��
        for (k = 0; k <= i - 1; k++) {  // ֻ����δ����������Ľ���в���
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
        ht[lnode].parent = i;  // �ϲ�������С�ʹ�С�Ľ��
        ht[rnode].parent = i;
        ht[i].weight =
            ht[lnode].weight + ht[rnode].weight;  // ����˫�׽���Ȩ��
        ht[i].lchild = lnode;  // ����˫�׽�������
        ht[i].rchild = rnode;  // ����˫�׽����Һ���
    }
}

void CreateHCode(HTNode ht[], HCode hcd[], int n) {
    int i;
    int f;
    int c;
    HCode hc;
    // ���ݹ���������������Ҷ�ӽ��Ĺ���������
    for (i = 0; i < n; i++) {
        hc.start = n;
        c = i;
        f = ht[i].parent;
        // ѭ��ֱ���������
        while (f != -1) {
            if (ht[f].lchild == c)  // �������ӽ��
                hc.cd[hc.start--] = '0';
            else  // �����Һ��ӽ��
                hc.cd[hc.start--] = '1';
            c = f;
            f = ht[f].parent;
        }
        hc.start++;  // startָ������������ʼ�ַ�
        hcd[i] = hc;
    }
}
// �������������
void DispHCode(HTNode ht[], HCode hcd[], int n) {
    int i, k;
    int sum = 0, m = 0, j;
    printf("�������������:\n");
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
    // printf("ƽ������=%g\n", 1.0 * sum / m);
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
    CreateHT(ht, n);          // ������������
    CreateHCode(ht, hcd, n);  // �������������
    DispHCode(ht, hcd, n);    // �������������
    return 0;
}
