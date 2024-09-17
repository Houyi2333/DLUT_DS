#include <malloc.h>
#include <stdio.h>
typedef int KeyType;
typedef char InfoType;
typedef struct node {
    KeyType key;
    int bf;
    InfoType data;
    struct node *lchild, *rchild;
} BSTNode;
void LeftProcess(BSTNode*& p, int& taller) {
    BSTNode *p1, *p2;
    if (p->bf == 0) {
        p->bf = 1;
        taller = 1;
    } else if (p->bf == -1) {
        p->bf = 0;
        taller = 0;
    } else {
        p1 = p->lchild;
        if (p1->bf == 1) {
            p->lchild = p1->rchild;
            p1->rchild = p;
            p->bf = p1->bf = 0;
            p = p1;
        } else if (p1->bf == -1) {
            p2 = p1->rchild;
            p1->rchild = p2->lchild;
            p2->lchild = p1;
            p->lchild = p2->rchild;
            p2->rchild = p;
            if (p2->bf == 0)
                p->bf = p1->bf = 0;
            else if (p2->bf == 1) {
                p1->bf = 0;
                p->bf = -1;
            } else {
                p1->bf = 1;
                p->bf = 0;
            }
            p = p2;
            p->bf = 0;
        }
        taller = 0;
    }
}
void RightProcess(BSTNode*& p, int& taller) {
    BSTNode *p1, *p2;
    if (p->bf == 0) {
        p->bf = -1;
        taller = 1;
    } else if (p->bf == 1) {
        p->bf = 0;
        taller = 0;
    } else {
        p1 = p->rchild;
        if (p1->bf == -1) {
            p->rchild = p1->lchild;
            p1->lchild = p;
            p->bf = p1->bf = 0;
            p = p1;
        } else if (p1->bf == 1) {
            p2 = p1->lchild;
            p1->lchild = p2->rchild;
            p2->rchild = p1;
            p->rchild = p2->lchild;
            p2->lchild = p;
            if (p2->bf == 0)
                p->bf = p1->bf = 0;
            else if (p2->bf == -1) {
                p1->bf = 0;
                p->bf = 1;
            } else {
                p1->bf = -1;
                p->bf = 0;
            }
            p = p2;
            p->bf = 0;
        }
        taller = 0;
    }
}
int InsertAVL(BSTNode*& b, KeyType e, int& taller) {
    // ԭΪ����,�����½��,�������ߡ�,��tallerΪ1
    if (b == NULL) {
        b = (BSTNode*)malloc(sizeof(BSTNode));
        b->key = e;
        b->lchild = b->rchild = NULL;
        b->bf = 0;
        taller = 1;
    } else {
        // �����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ���
        if (e == b->key) {
            taller = 0;
            return 0;
        }
        // Ӧ������*b���������н�������
        if (e < b->key) {
            if ((InsertAVL(b->lchild, e, taller)) == 0)  // δ����
                return 0;
            if (taller == 1)  // �Ѳ��뵽*b�����������������������ߡ�
                LeftProcess(b, taller);
        } else  // Ӧ������*b���������н�������
        {
            if ((InsertAVL(b->rchild, e, taller)) == 0)  // δ����
                return 0;
            if (taller == 1)  // �Ѳ��뵽b���������������������ߡ�
                RightProcess(b, taller);
        }
    }
    return 1;
}
// �����ű�ʾ�����AVL
void DispBSTree(BSTNode* b) {
    if (b != NULL) {
        printf("%d", b->key);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBSTree(b->lchild);
            if (b->rchild != NULL)
                printf(",");
            DispBSTree(b->rchild);
            printf(")");
        }
    }
}
void DestroyAVL(BSTNode*& b) {
    if (b != NULL) {
        DestroyAVL(b->lchild);
        DestroyAVL(b->rchild);
        free(b);
        b = NULL;
    }
}
void LeftProcess1(BSTNode*& p, int& taller) {
    BSTNode *p1, *p2;
    if (p->bf == 1) {
        p->bf = 0;
        taller = 1;
    } else if (p->bf == 0) {
        p->bf = -1;
        taller = 0;
    } else  // p->bf=-1
    {
        p1 = p->rchild;
        if (p1->bf == 0)  // ����RR����
        {
            p->rchild = p1->lchild;
            p1->lchild = p;
            p1->bf = 1;
            p->bf = -1;
            p = p1;
            taller = 0;
        } else if (p1->bf == -1)  // ����RR����
        {
            p->rchild = p1->lchild;
            p1->lchild = p;
            p->bf = p1->bf = 0;
            p = p1;
            taller = 1;
        } else  // ����RL����
        {
            p2 = p1->lchild;
            p1->lchild = p2->rchild;
            p2->rchild = p1;
            p->rchild = p2->lchild;
            p2->lchild = p;
            if (p2->bf == 0) {
                p->bf = 0;
                p1->bf = 0;
            } else if (p2->bf == -1) {
                p->bf = 1;
                p1->bf = 0;
            } else {
                p->bf = 0;
                p1->bf = -1;
            }
            p2->bf = 0;
            p = p2;
            taller = 1;
        }
    }
}
void RightProcess1(BSTNode*& p, int& taller) {
    BSTNode *p1, *p2;
    if (p->bf == -1) {
        p->bf = 0;
        taller = -1;
    } else if (p->bf == 0) {
        p->bf = 1;
        taller = 0;
    } else  // p->bf=1
    {
        p1 = p->lchild;
        if (p1->bf == 0)  // ����LL����
        {
            p->lchild = p1->rchild;
            p1->rchild = p;
            p1->bf = -1;
            p->bf = 1;
            p = p1;
            taller = 0;
        } else if (p1->bf == 1)  // ����LL����
        {
            p->lchild = p1->rchild;
            p1->rchild = p;
            p->bf = p1->bf = 0;
            p = p1;
            taller = 1;
        } else  // ����LR����
        {
            p2 = p1->rchild;
            p1->rchild = p2->lchild;
            p2->lchild = p1;
            p->lchild = p2->rchild;
            p2->rchild = p;
            if (p2->bf == 0) {
                p->bf = 0;
                p1->bf = 0;
            } else if (p2->bf == 1) {
                p->bf = -1;
                p1->bf = 0;
            } else {
                p->bf = 0;
                p1->bf = 1;
            }
            p2->bf = 0;
            p = p2;
            taller = 1;
        }
    }
}
void Delete2(BSTNode* q, BSTNode*& r, int& taller)
// ��DeleteAVL()����,���ڴ���ɾ����������������յ����
{
    if (r->rchild == NULL) {
        q->key = r->key;
        q = r;
        r = r->lchild;
        free(q);
        taller = 1;
    } else {
        Delete2(q, r->rchild, taller);
        if (taller == 1)
            RightProcess1(r, taller);
    }
}
int DeleteAVL(BSTNode*& p, KeyType x, int& taller) {
    int k;
    BSTNode* q;
    if (p == NULL) {
        printf("�ս��");
        return 0;
    } else if (x < p->key) {
        k = DeleteAVL(p->lchild, x, taller);
        if (taller == 1)
            LeftProcess1(p, taller);
        return k;
    } else if (x > p->key) {
        k = DeleteAVL(p->rchild, x, taller);
        if (taller == 1)
            RightProcess1(p, taller);
        return k;
    } else  // �ҵ��˹ؼ���Ϊx�Ľ��,��pָ����
    {
        q = p;
        // ��ɾ���������Ϊ��
        if (p->rchild == NULL) {
            p = p->lchild;
            free(q);
            taller = 1;

        }
        // ��ɾ���������Ϊ��
        else if (p->lchild == NULL) {
            p = p->rchild;
            free(q);
            taller = 1;
        }
        // ��ɾ�����������������
        else {
            Delete2(q, q->lchild, taller);
            if (taller == 1)
                LeftProcess1(q, taller);
            p = q;
        }
        return 1;
    }
}
int main() {
    BSTNode* b = NULL;
    int i, j, k, temp;
    KeyType a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    KeyType n = 9;
    for (i = 0; i < n; i++)
        InsertAVL(b, a[i], j);
    DispBSTree(b);
    printf("\n������Ҫɾ���Ĺؼ���");
    scanf("%d", &k);
    printf("ɾ���ؼ���%d:", k);
    DeleteAVL(b, k, j);
    DispBSTree(b);
    printf("\n������Ҫ����Ĺؼ���");
    scanf("%d", &temp);
    InsertAVL(b, temp, j);
    DispBSTree(b);
    DestroyAVL(b);
    return 0;
}