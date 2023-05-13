//Ԥ������::  
#include <iostream>  
#include <stdio.h>  

#define OK 1  
#define ERROR 0  
#define GT 1  
#define EQ 0  
#define LT -1  

using namespace std;

//���ݽṹ������::(����ʵ��)  
class LinkList {
public:
    char data;
    LinkList* next;
    LinkList& operator=(LinkList& L);
};

//���ø�ֵ���������ʵ��LinkList���Ͷ���ĸ�ֵ����:Ŀ���ǵ�ԭʼ���ϲ�����ʱ��ֵ����ʱ��������������֮�󻹿��Ը���  
LinkList& LinkList::operator=(LinkList& L) {
    LinkList* p = this, * q = (&L)->next, * temp;      //pָ��this��Ȼ��qָ��L����һ�����  
    while (q != NULL) {     //��q��Ϊ��ʱ  
        temp = (LinkList*)malloc(sizeof(LinkList));     //��temp����ռ䣬���q����data��ֵ  
        temp->data = q->data; temp->next = NULL;       //ÿ�θ�tempһ����ֵ������next����Ϊ��  
        p->next = temp; p = p->next;      //��temp������p֮��p����һλ׼��������һ���  
        q = q->next;     //q����һλ  
    }       //����ÿ��temp��next���ǿ�ָ�룬���Բ���Ҫ��thisָ������β����next���ٴ���Ϊ��  
    return *this;       //���ظö����ͷָ�룬ʵ����ʽ��̣����Զ�θ�ֵ  
}

typedef int status;

//����������:  
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

//��������:  
int main(void)
{
    int tag;
    LinkList A, B, C, D, E, F, G;
    InitLink(A); InitLink(B); InitLink(C);
    InitLink(D); InitLink(E); InitLink(F);InitLink(G);
    while (1) {
        Info();
        printf("������Ҫѡ��ļ��ϲ�������:\n");
        scanf("%d", &tag);
        switch (tag) {
        case 0:
            printf("�ɹ��˳�ϵͳ!\n"); exit(0);
        case 1:
            CreatLink(A);
            printf("�밴�س�������\n");                         //��һ��getchar�Ե�����Ĺ��ܱ��
            getchar(); getchar(); system("cls"); break;         //�ڶ���getchar�Ե�����Ļس�   
        case 2:
            CreatLink(B);
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        case 3:
            SortLink(A); DispLink(A, 'A');
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        case 4:
            SortLink(B); DispLink(B, 'B');
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        case 5:
            printf("����A��B�󽻼���"); Jiao(A, B, C); DispLink(C, 'C');
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        case 6:
            printf("����A��B�󲢼���"); Bing(A, B, D); DispLink(D, 'D');
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        case 7:
            printf("����A-����B��"); Cha(A, B, E); DispLink(E, 'E');
            printf("����B-����A��"); Cha(B, A, E); DispLink(E, 'E');
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        case 8:
            printf("����A����ȫ��A��B�Ĳ�"); Bu(A, B, F); DispLink(F, 'F');
            printf("����B����ȫ��A��B�Ĳ�"); Bu(B, A, F); DispLink(F, 'F');
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        case 9:
            printf("����A�뼯��B����򣨶ԳƲ"); Yihuo(A, B, G); DispLink(G, 'G');
            printf("�밴�س�������\n");
            getchar(); getchar(); system("cls"); break;
        default:
            printf("��������!\n"); exit(0); break;
            //exit(0)�������в��˳�����  
        }
    }
    system("pause");
    return 0;
}

//�㷨ʵ����::  
//����ͷ��Ϣ  
void Info() {
    printf("-----------------------\n");
    printf("���ڼ��ϵĲ���:\n");
    printf("0.�˳���ǰ����\n");
    printf("1.����A��������\n");
    printf("2.����B��������\n");
    printf("3.����A������ʾ\n");
    printf("4.����B������ʾ\n");
    printf("5.���ϵĽ�:\n");
    printf("6.���ϵĲ�:\n");
    printf("7.���ϵĲ�:\n");
    printf("8.���ϵĲ�:\n");
    printf("9.���ϵ����:\n");
    printf("-----------------------\n");
    return;
}

//��ʼ��������:  
void InitLink(LinkList& L) {
    L.data = '0';
    L.next = NULL;
    return;
}

//����Ԫ��:ֱ��β�巨���뼯��,tail����һ�μ�¼��Ϊָ��λ��  
void InsertLink(LinkList* tail, LinkList* s) {
    s->next = tail->next;
    tail->next = s;
    tail = s;
    return;
}

//�жϼ���Ԫ�ظ���  
int LengthLink(LinkList& L) {
    int len = 0;
    LinkList* p = (&L)->next;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

//����һ������Ԫ��  
void CreatLink(LinkList& L) {
    int i, n;
    LinkList* temp, * tail = (&L);
    printf("�����뼯��Ԫ�ظ���:");
    scanf_s("%d", &n);
    printf("�����뼯���е�Ԫ��:\n");
    for (i = 1; i <= n; i++) {
        temp = (LinkList*)malloc(sizeof(LinkList));
        cin >> (temp->data);
        InsertLink(tail, temp);
    }
    return;
}

//�������Ԫ��  
void DispLink(LinkList& L, char c) {
    LinkList* p = (&L)->next;
    if (p == NULL)
        printf("����%cΪ�ռ���!", c);
    else {
        printf("����%cΪ:", c);
        while (p != NULL) {
            printf("%c   ", p->data);
            p = p->next;
        }
    }
    printf("\n");
    return;
}

//�Ƚϼ�����Ԫ�صĴ�С  
status CompareLink(LinkList* p, LinkList* q) {
    if (p->data == q->data) return EQ;
    else if (p->data < q->data) return LT;
    else return GT;
}

//����������  
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

//�������󲢼�  
void Bing(LinkList A, LinkList B, LinkList& Temp) {
    int lenA, lenB;
    LinkList* pa, * pb, TempA/*�϶̵ļ���*/, TempB/*�ϳ��ļ���*/, * temp;
    lenA = LengthLink(A); lenB = LengthLink(B);
    if (lenA == 0 && lenB == 0) { Temp = A; return; }
    else if (lenA != 0 && lenB == 0) {
        Temp = A; return;
    }
    else if (lenA == 0 && lenB != 0) {
        Temp = B; return;
    }
    if (lenA > lenB) {     //paָ���С�ļ��ϣ�pbָ��ϴ�ļ���  
        TempA = B; TempB = A; pa = (&TempA); pb = (&TempB)->next;        //�����Ͻ�С�ĸ�������TempA,�ϳ��ļ��Ϸ���TempB  
    }
    else {
        TempA = A; TempB = B; pa = (&TempA); pb = (&TempB)->next;
    }
    while (pa != NULL && pb != NULL) {
        if (pa->next != NULL && pa->next->data == pb->data) {     //ȥ����ͬ��Ԫ��  
            pa = pa->next;
            pb = pb->next;
            continue;
        }
        while (pa->next != NULL && pa->next->data < pb->data)
            pa = pa->next;       //�ƶ�֮���ֳ����˿�����ͬ�������Ҫ�����ٱȽ�һ��  
        if (pa->next != NULL && pa->next->data == pb->data) {     //ȥ����ͬ��Ԫ��  
            pa = pa->next;
            pb = pb->next;
            continue;
        }
        temp = pb;      //�Ƚ�ԭʼpb��λ�ü�¼��������������֮���Ҳ���ԭʼpb����һλ��  
        pb = pb->next;       //���ƶ�pb����temp����ԭʼpb���в���  
        temp->next = pa->next;
        pa->next = temp;
        pa = pa->next;
    }
    if (pa != (&TempA) && pb != NULL)
        pa->next = pa ? pa : pb;
    Temp = TempA;
    return;
}

//�������󽻼�  
void Jiao(LinkList A, LinkList B, LinkList& Temp) {
    int lenA, lenB, flag = 0;
    LinkList* pa, * pb, TempA/*�϶̵ļ���*/, TempB/*�ϳ��ļ���*/;
    lenA = LengthLink(A); lenB = LengthLink(B);
    if (lenA == 0 || lenB == 0) {
        Temp = ((&A)->next == NULL) ? A : B;
        return;
    }
    if (lenA > lenB) {       //paָ���С�ļ��ϣ�pbָ��ϴ�ļ���  
        TempA = B;TempB = A; pa = (&TempA); pb = (&TempB)->next;       //�����Ͻ�С�ĸ�������TempA,�ϳ��ļ��Ϸ���TempB  
    }
    else {
        TempA = A; TempB = B; pa = (&TempA); pb = (&TempB)->next;
    }
    while (pa->next != NULL) {
        flag = 0;       //����flag��¼��û����ͬ��Ԫ�أ�����flag=1,����flag=0  
        while (pb != NULL) {
            if (pa->next->data == pb->data) {//�������ͬ��Ԫ�أ���ôpa������һ��λ��  
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
        case 0:     //��û����ͬԪ�ص�ʱ��Ž��в���������û�в���  
            if (pa == NULL) break;
            else if (pa->next == NULL) break;
            else if (pa->next->next != NULL)
                pa->next = pa->next->next;     //��û����ȵ�Ԫ��ʱ��������¸�λ��Ϊ�գ�ֱ����ȥ���һ��Ԫ��  
            else pa->next = NULL;
            pb = (&TempB)->next; break;
        case 1:;
        }
    }
    Temp = TempA;
    return;
}

//��������  
void Cha(LinkList A, LinkList B, LinkList& Temp) {
    int lenA, lenB, flag = 0;
    LinkList* pa, * pb, TempA/*�϶̵ļ���*/, TempB/*�ϳ��ļ���*/, jiao;
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
    Jiao(A, B, jiao);       //���A��B�н������򽫽������浽����jiao��  
    if (LengthLink(jiao) == 0) {
        Temp = jiao; return;
    }
    TempA = jiao; TempB = A;        //�����Ͻ�С�ĸ�������TempA,�ϳ��ļ��Ϸ���TempB  
    pa = (&TempA)->next; pb = &TempB;        //paָ���С�ļ��ϣ�pbָ��ϴ�ļ���  
    while (pb->next != NULL) {
        flag = 0;       //��¼�Ƿ��в���ȵ�Ԫ�أ�������flag=1,û����flag=0  
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
                pb = pb->next;       //��û�в���ȵ�Ԫ��ʱ��������¸�λ��Ϊ�գ�ֱ����ȥ���һ��Ԫ��  
            else pb->next = NULL;
            pa = (&TempA)->next; break;
        case 1:;
        }
    }
    Temp = TempB;
    return;
}

//�������󲹼�:A��B�Ĳ�����һ��ȫ������A����ȫ������  
void Bu(LinkList A, LinkList B, LinkList& Temp) {
    LinkList C;     //�����м��������  
    InitLink(C); InitLink(Temp);
    Bing(A, B, C); Cha(C, A, Temp);     //����A��B�Ĳ���Ҳ����ȫ����Ȼ������C��A�Ĳ�  
    return;
}

void Yihuo(LinkList A, LinkList B, LinkList& Temp) {
    LinkList C, D;    //�����м��������  
    InitLink(C);InitLink(D);
    InitLink(Temp);
    Bing(A, B, C); Jiao(A, B, D);     //����A��B�Ĳ���Ҳ����ȫ����Ȼ������A��B�Ľ��������ȫ����ȥ����������A��B�����
    Cha(C, D, Temp);
    return;
}