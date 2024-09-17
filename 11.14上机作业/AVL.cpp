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
    // 原为空树,插入新结点,树“长高”,置taller为1
    if (b == NULL) {
        b = (BSTNode*)malloc(sizeof(BSTNode));
        b->key = e;
        b->lchild = b->rchild = NULL;
        b->bf = 0;
        taller = 1;
    } else {
        // 树中已存在和e有相同关键字的结点则不再插入
        if (e == b->key) {
            taller = 0;
            return 0;
        }
        // 应继续在*b的左子树中进行搜索
        if (e < b->key) {
            if ((InsertAVL(b->lchild, e, taller)) == 0)  // 未插入
                return 0;
            if (taller == 1)  // 已插入到*b的左子树中且左子树“长高”
                LeftProcess(b, taller);
        } else  // 应继续在*b的右子树中进行搜索
        {
            if ((InsertAVL(b->rchild, e, taller)) == 0)  // 未插入
                return 0;
            if (taller == 1)  // 已插入到b的右子树且右子树“长高”
                RightProcess(b, taller);
        }
    }
    return 1;
}
// 以括号表示法输出AVL
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
        if (p1->bf == 0)  // 需作RR调整
        {
            p->rchild = p1->lchild;
            p1->lchild = p;
            p1->bf = 1;
            p->bf = -1;
            p = p1;
            taller = 0;
        } else if (p1->bf == -1)  // 需作RR调整
        {
            p->rchild = p1->lchild;
            p1->lchild = p;
            p->bf = p1->bf = 0;
            p = p1;
            taller = 1;
        } else  // 需作RL调整
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
        if (p1->bf == 0)  // 需作LL调整
        {
            p->lchild = p1->rchild;
            p1->rchild = p;
            p1->bf = -1;
            p->bf = 1;
            p = p1;
            taller = 0;
        } else if (p1->bf == 1)  // 需作LL调整
        {
            p->lchild = p1->rchild;
            p1->rchild = p;
            p->bf = p1->bf = 0;
            p = p1;
            taller = 1;
        } else  // 需作LR调整
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
// 由DeleteAVL()调用,用于处理被删结点左右子树均不空的情况
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
        printf("空结点");
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
    } else  // 找到了关键字为x的结点,由p指向它
    {
        q = p;
        // 被删结点右子树为空
        if (p->rchild == NULL) {
            p = p->lchild;
            free(q);
            taller = 1;

        }
        // 被删结点左子树为空
        else if (p->lchild == NULL) {
            p = p->rchild;
            free(q);
            taller = 1;
        }
        // 被删结点左右子树均不空
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
    printf("\n请输入要删除的关键字");
    scanf("%d", &k);
    printf("删除关键字%d:", k);
    DeleteAVL(b, k, j);
    DispBSTree(b);
    printf("\n请输入要插入的关键字");
    scanf("%d", &temp);
    InsertAVL(b, temp, j);
    DispBSTree(b);
    DestroyAVL(b);
    return 0;
}