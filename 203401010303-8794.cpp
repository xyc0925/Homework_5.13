//预编译区::  
#include <iostream>  
#include <stdio.h>  

#define OK 1  
#define ERROR 0  
#define GT 1  
#define EQ 0  
#define LT -1  

using namespace std;

//数据结构声明区::(用类实现)  
class LinkList {
public:
    char data;
    LinkList* next;
    LinkList& operator=(LinkList& L);
};

//利用赋值运算符重载实现LinkList类型对象的赋值运算:目的是当原始集合操作的时候赋值给临时变量，经过操作之后还可以复用  
LinkList& LinkList::operator=(LinkList& L) {
    LinkList* p = this, * q = (&L)->next, * temp;      //p指向this，然后q指向L的下一个结点  
    while (q != NULL) {     //当q不为空时  
        temp = (LinkList*)malloc(sizeof(LinkList));     //给temp分配空间，存放q结点的data域值  
        temp->data = q->data; temp->next = NULL;       //每次给temp一个新值，并将next域置为空  
        p->next = temp; p = p->next;      //将temp链接在p之后，p下移一位准备链接下一结点  
        q = q->next;     //q下移一位  
    }       //由于每次temp的next域都是空指针，所以不需要将this指向对象的尾结点的next域再次置为空  
    return *this;       //返回该对象的头指针，实现链式编程，可以多次赋值  
}

typedef int status;

//函数声明区:  
void Info();
void InitLink(LinkList& L);
void InsertLink(LinkList* tail, LinkList* s);
int LengthLink(LinkList& L);
void CreatLink(LinkList& L);
void DispLink(LinkList& L, char c);
status CompareLink(LinkList* p, LinkList* q);
void SortLink(LinkList& L);
void Jiao(LinkList A, LinkList B, LinkList& Temp);
void Bing(LinkList A, LinkList B, LinkList& Temp);
void Cha(LinkList A, LinkList B, LinkList& Temp);
void Bu(LinkList A, LinkList B, LinkList& Temp);
void Yihuo(LinkList A, LinkList B, LinkList& Temp);

//主函数区:  
int main(void)
{
    int tag;
    LinkList A, B, C, D, E, F, G;
    InitLink(A); InitLink(B); InitLink(C);
    InitLink(D); InitLink(E); InitLink(F);InitLink(G);
    while (1) {
        Info();
        printf("请输入要选择的集合操作功能:\n");
        scanf("%d", &tag);
        switch (tag) {
        case 0:
            printf("成功退出系统!\n"); exit(0);
        case 1:
            CreatLink(A);
            printf("请按回车继续！\n");                         //第一个getchar吃掉输入的功能编号
            getchar(); getchar(); system("cls"); break;         //第二个getchar吃掉输入的回车   
        case 2:
            CreatLink(B);
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        case 3:
            SortLink(A); DispLink(A, 'A');
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        case 4:
            SortLink(B); DispLink(B, 'B');
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        case 5:
            printf("集合A和B求交集后"); Jiao(A, B, C); DispLink(C, 'C');
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        case 6:
            printf("集合A和B求并集后"); Bing(A, B, D); DispLink(D, 'D');
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        case 7:
            printf("集合A-集合B后"); Cha(A, B, E); DispLink(E, 'E');
            printf("集合B-集合A后"); Cha(B, A, E); DispLink(E, 'E');
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        case 8:
            printf("集合A关于全集A并B的补"); Bu(A, B, F); DispLink(F, 'F');
            printf("集合B关于全集A并B的补"); Bu(B, A, F); DispLink(F, 'F');
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        case 9:
            printf("集合A与集合B的异或（对称差）"); Yihuo(A, B, G); DispLink(G, 'G');
            printf("请按回车继续！\n");
            getchar(); getchar(); system("cls"); break;
        default:
            printf("输入有误!\n"); exit(0); break;
            //exit(0)正常运行并退出程序  
        }
    }
    system("pause");
    return 0;
}

//算法实现区::  
//程序头信息  
void Info() {
    printf("-----------------------\n");
    printf("关于集合的操作:\n");
    printf("0.退出当前操作\n");
    printf("1.集合A数据输入\n");
    printf("2.集合B数据输入\n");
    printf("3.集合A排序并显示\n");
    printf("4.集合B排序并显示\n");
    printf("5.集合的交:\n");
    printf("6.集合的并:\n");
    printf("7.集合的差:\n");
    printf("8.集合的补:\n");
    printf("9.集合的异或:\n");
    printf("-----------------------\n");
    return;
}

//初始化链表集合:  
void InitLink(LinkList& L) {
    L.data = '0';
    L.next = NULL;
    return;
}

//插入元素:直接尾插法插入集合,tail是上一次记录的为指针位置  
void InsertLink(LinkList* tail, LinkList* s) {
    s->next = tail->next;
    tail->next = s;
    tail = s;
    return;
}

//判断集合元素个数  
int LengthLink(LinkList& L) {
    int len = 0;
    LinkList* p = (&L)->next;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

//创建一个集合元素  
void CreatLink(LinkList& L) {
    int i, n;
    LinkList* temp, * tail = (&L);
    printf("请输入集合元素个数:");
    scanf_s("%d", &n);
    printf("请输入集合中的元素:\n");
    for (i = 1; i <= n; i++) {
        temp = (LinkList*)malloc(sizeof(LinkList));
        cin >> (temp->data);
        InsertLink(tail, temp);
    }
    return;
}

//输出集合元素  
void DispLink(LinkList& L, char c) {
    LinkList* p = (&L)->next;
    if (p == NULL)
        printf("集合%c为空集合!", c);
    else {
        printf("集合%c为:", c);
        while (p != NULL) {
            printf("%c   ", p->data);
            p = p->next;
        }
    }
    printf("\n");
    return;
}

//比较集合中元素的大小  
status CompareLink(LinkList* p, LinkList* q) {
    if (p->data == q->data) return EQ;
    else if (p->data < q->data) return LT;
    else return GT;
}

//将集合排序  
void SortLink(LinkList& L) {
    LinkList* pre = &L, * p, * q, * temp;
    if (!(&L)->next) return;
    p = pre->next->next;
    pre->next->next = NULL;
    while (p != NULL) {
        q = p->next;
        pre = &L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
    return;
}

//两集合求并集  
void Bing(LinkList A, LinkList B, LinkList& Temp) {
    int lenA, lenB;
    LinkList* pa, * pb, TempA/*较短的集合*/, TempB/*较长的集合*/, * temp;
    lenA = LengthLink(A); lenB = LengthLink(B);
    if (lenA == 0 && lenB == 0) { Temp = A; return; }
    else if (lenA != 0 && lenB == 0) {
        Temp = A; return;
    }
    else if (lenA == 0 && lenB != 0) {
        Temp = B; return;
    }
    if (lenA > lenB) {     //pa指向较小的集合，pb指向较大的集合  
        TempA = B; TempB = A; pa = (&TempA); pb = (&TempB)->next;        //将集合较小的赋给集合TempA,较长的集合放入TempB  
    }
    else {
        TempA = A; TempB = B; pa = (&TempA); pb = (&TempB)->next;
    }
    while (pa != NULL && pb != NULL) {
        if (pa->next != NULL && pa->next->data == pb->data) {     //去除相同的元素  
            pa = pa->next;
            pb = pb->next;
            continue;
        }
        while (pa->next != NULL && pa->next->data < pb->data)
            pa = pa->next;       //移动之后又出现了可能相同的情况，要重新再比较一次  
        if (pa->next != NULL && pa->next->data == pb->data) {     //去除相同的元素  
            pa = pa->next;
            pb = pb->next;
            continue;
        }
        temp = pb;      //先将原始pb的位置记录下来，否则链接之后将找不到原始pb的下一位置  
        pb = pb->next;       //先移动pb，用temp代替原始pb进行操作  
        temp->next = pa->next;
        pa->next = temp;
        pa = pa->next;
    }
    if (pa != (&TempA) && pb != NULL)
        pa->next = pa ? pa : pb;
    Temp = TempA;
    return;
}

//两集合求交集  
void Jiao(LinkList A, LinkList B, LinkList& Temp) {
    int lenA, lenB, flag = 0;
    LinkList* pa, * pb, TempA/*较短的集合*/, TempB/*较长的集合*/;
    lenA = LengthLink(A); lenB = LengthLink(B);
    if (lenA == 0 || lenB == 0) {
        Temp = ((&A)->next == NULL) ? A : B;
        return;
    }
    if (lenA > lenB) {       //pa指向较小的集合，pb指向较大的集合  
        TempA = B;TempB = A; pa = (&TempA); pb = (&TempB)->next;       //将集合较小的赋给集合TempA,较长的集合放入TempB  
    }
    else {
        TempA = A; TempB = B; pa = (&TempA); pb = (&TempB)->next;
    }
    while (pa->next != NULL) {
        flag = 0;       //利用flag记录有没有相同的元素，若有flag=1,若无flag=0  
        while (pb != NULL) {
            if (pa->next->data == pb->data) {//如果有相同的元素，那么pa就下移一个位置  
                pa = pa->next;
                pb = (&TempB)->next;
                flag = 1;
                break;
            }
            else {
                pb = pb->next;
            }
        }
        switch (flag) {
        case 0:     //当没有相同元素的时候才进行操作，否则没有操作  
            if (pa == NULL) break;
            else if (pa->next == NULL) break;
            else if (pa->next->next != NULL)
                pa->next = pa->next->next;     //当没有相等的元素时，如果下下个位置为空，直接舍去最后一个元素  
            else pa->next = NULL;
            pb = (&TempB)->next; break;
        case 1:;
        }
    }
    Temp = TempA;
    return;
}

//两集合求差集  
void Cha(LinkList A, LinkList B, LinkList& Temp) {
    int lenA, lenB, flag = 0;
    LinkList* pa, * pb, TempA/*较短的集合*/, TempB/*较长的集合*/, jiao;
    InitLink(Temp); InitLink(jiao);
    lenA = LengthLink(A); lenB = LengthLink(B);
    if (lenA == 0 && lenB == 0) {
        Temp = A; return;
    }
    else if (lenA != 0 && lenB == 0) {
        Temp = A; return;
    }
    else if (lenA == 0 && lenB != 0) {
        Temp = A; return;
    }
    Jiao(A, B, jiao);       //如果A与B有交集，则将交集保存到变量jiao中  
    if (LengthLink(jiao) == 0) {
        Temp = jiao; return;
    }
    TempA = jiao; TempB = A;        //将集合较小的赋给集合TempA,较长的集合放入TempB  
    pa = (&TempA)->next; pb = &TempB;        //pa指向较小的集合，pb指向较大的集合  
    while (pb->next != NULL) {
        flag = 0;       //记录是否有不相等的元素，若有则flag=1,没有则flag=0  
        while (pa != NULL) {
            if (pb->next->data == pa->data) {
                if (pb->next->next != NULL)
                    pb->next = pb->next->next;
                else pb->next = NULL;
                pa = (&TempA)->next;
                flag = 1;break;
            }
            else pa = pa->next;
        }
        switch (flag) {
        case 0:
            if (pb == NULL) break;
            if (pb->next != NULL)
                pb = pb->next;       //当没有不相等的元素时，如果下下个位置为空，直接舍去最后一个元素  
            else pb->next = NULL;
            pa = (&TempA)->next; break;
        case 1:;
        }
    }
    Temp = TempB;
    return;
}

//两集合求补集:A和B的并集是一个全集，求A关于全集补集  
void Bu(LinkList A, LinkList B, LinkList& Temp) {
    LinkList C;     //用于中间操作步骤  
    InitLink(C); InitLink(Temp);
    Bing(A, B, C); Cha(C, A, Temp);     //先求A与B的并，也就是全集，然后再求C与A的差  
    return;
}

void Yihuo(LinkList A, LinkList B, LinkList& Temp) {
    LinkList C, D;    //用于中间操作步骤  
    InitLink(C);InitLink(D);
    InitLink(Temp);
    Bing(A, B, C); Jiao(A, B, D);     //先求A与B的并，也就是全集，然后再求A与B的交，最后用全集减去交集，就是A与B的异或
    Cha(C, D, Temp);
    return;
}