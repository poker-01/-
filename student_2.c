#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    char name[20];
    char numb[10];
    char gender[10];
    int phone;
    int c;
    int j;
    int s;
    float a;
}Student;

typedef struct node {
    struct Student student;
    struct node* next;
} Node;

Node* head=NULL ; //ͷ���

// 1.��ѯ�����ɼ���
void readall()//1.ȫ���ɼ�
{
    Node* p = (Node*)malloc(sizeof(Node));
    p = head; // �� p ָ������Ϊ�����ͷ�ڵ�
    if (head == NULL) {
        printf("����Ϊ�ա�\n");
        return;
    }
    printf("����\tѧ��\t�Ա�\t�绰����   C����   ���������   ���ݽṹ   ƽ����\n");
    // ��������
    while (p != NULL)
    {
        printf("%s\t%s\t%s\t%d      %d\t     %d\t        %d\t  %.2f\n", p->student.name, p->student.numb, p->student.gender, p->student.phone, p->student.c, p->student.j, p->student.s, p->student.a);
        p = p->next;
    }
}

// 2.����ѧ����Ϣ
void addition() {
    // �����½ڵ��ڴ�
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("�ڴ����ʧ��\n");
        return;
    }

    // ����ѧ����Ϣ
    printf("����������: ");
    scanf("%s", new_node->student.name);
    getchar(); // ���ջ��з�

    printf("������ѧ��: ");
    scanf("%s", new_node->student.numb);
    getchar();

    printf("�������Ա�: ");
    scanf("%s", new_node->student.gender);
    getchar();

    printf("������绰����: ");
    scanf("%d", &new_node->student.phone);
    getchar();

    printf("������C���Գɼ�: ");
    scanf("%d", &new_node->student.c);
    getchar();

    printf("��������������ɼ�: ");
    scanf("%d", &new_node->student.j);
    getchar();

    printf("���������ݽṹ�ɼ�: ");
    scanf("%d", &new_node->student.s);
    getchar();

    new_node->student.a = (new_node->student.c + new_node->student.j + new_node->student.s) / 3.0;

    // ������β�������½ڵ�
    if (head == NULL) {
        // �������Ϊ�գ����½ڵ�����Ϊͷ�ڵ�
        head = new_node;
        new_node->next = NULL;
    }
    else {
        // �����ҵ������β���ڵ㣬����nextָ��ָ���½ڵ�
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = NULL;
    }

    printf("���ӳɹ�\n");
}
//3.�޸�ѧ����Ϣ
void correct() 
{
    char na[20];
    printf("��������Ҫ�޸ĵ�ѧ��������");
    scanf("%s", na);
    getchar();
    Node* p = (Node*)malloc(sizeof(Node));
    p = head;    
    while (p != NULL)  //whileѭ����������
    {
        if (strcmp(na, p->student.name) == 0)
        {
            printf("������ѧ��: ");
            scanf("%s", p->student.numb);
            getchar();
            printf("�������Ա�: ");
            scanf("%s", p->student.gender);
            getchar();
            printf("������绰����: ");
            scanf("%d", &p->student.phone);
            getchar();
            printf("������C���Գɼ�: ");
            scanf("%d", &p->student.c);
            getchar();
            printf("��������������ɼ�: ");
            scanf("%d", &p->student.j);
            getchar();
            printf("���������ݽṹ�ɼ�: ");
            scanf("%d", &p->student.s);
            getchar();
            p->student.a = (p->student.c + p->student.j + p->student.s) / 3.0;
            printf("�޸ĳɹ�\n");            
            return;
        }
        p = p->next;
    }
    if (p == NULL)
        printf("�޸�����Ϣ\n");
}

void delete() //4.ɾ��
{
    char na_me[20];
    printf("������ѧ��������");
    scanf("%s", na_me);
    getchar();
    //ɾ��һ���ڵ���Ҫ�ҵ��ýڵ��ǰһ���ڵ㣬ʹ��ǰһ�����ָ�����¸��ڵ�
    Node* pre = (Node*)malloc(sizeof(Node));
    pre = head;
    while (pre->next != NULL) 
    {
        if (strcmp(na_me, pre->next->student.name) == 0 )
        {
            //temp��Ϊ��ɾ���ڵ�ĸ�����ɾ��
            Node* temp = pre->next;
            //�ñ�ɾ���Ľڵ����һ���ڵ���Ϊ��ɾ���ڵ�
            pre->next = pre->next->next;
            free(temp);
            printf("ɾ���ɹ�\n");
            return;
        }
        pre = pre->next;
    }
    if(pre->next==NULL)
        printf("δ�ҵ�������Ϣ\n");
}

//����
void sort() {
    Node* turn = head->next;

    while (turn != NULL) {
        Node* max = turn;
        Node* nextNode = turn->next;

        while (nextNode != NULL) {
            if (nextNode->student.a > max->student.a) {
                max = nextNode;
            }
            nextNode = nextNode->next;
        }
        if (turn != max) {
            // �����ڵ�����
            Student temp = max->student;
            max->student = turn->student;
            turn->student = temp;
        }
        turn = turn->next;
    }
    printf("����\tѧ��\t�Ա�\t�绰����   C����   ���������   ���ݽṹ   ƽ����\n");
    Node* p = head->next; // �ӵ�һ��ѧ���ڵ㿪ʼ��ӡ
    while (p != NULL) {
        printf("%s\t%s\t%s\t%d      %d\t     %d\t        %d\t  %.2f\n", p->student.name, p->student.numb, p->student.gender, p->student.phone, p->student.c, p->student.j, p->student.s, p->student.a);
        p = p->next;
    }
}

//����ѧ����Ϣ
void save()
{
    FILE* pfile = fopen("stu.txt", "w");
    if (pfile == NULL)
    {
        printf("�޷����ļ�\n");
        return;
    }
    //��������
    Node* p = head;
    while (p != NULL)
    {
        fwrite(&p->student, 1, sizeof(Student), pfile);
        p = p->next;
    }
    //�ر��ļ�
    fclose(pfile);
    printf("�ļ�����ɹ�\n");
}

//��ȡѧ����Ϣ
void read()
{
    FILE* pfile = fopen("stu.txt", "r");
    if (pfile == NULL)
    {
        printf("�޷����ļ�\n");
        return;
    }
    while (!feof(pfile))
    {
        //�����½ڵ����ڴ��ѧ����Ϣ
        Node* new = (Node*)malloc(sizeof(Student));
        fread(&new->student, 1, sizeof(Student), pfile);
        new->next = NULL;
        if (head == NULL)
        {
            // �������Ϊ�գ����½ڵ�����Ϊͷ�ڵ�
            head = new;
        }
        else
        {
            // �����ҵ������β���ڵ㣬����nextָ��ָ���½ڵ�
            //��ͷ��㿪ʼ��
            Node* tail = head;
            while (tail->next != NULL)  //tail����һ���ڵ�Ϊ����˵���ҵ���
            {
                tail = tail->next;
            }
            tail->next = new;
        }
    }
    printf("��ȡ�ɹ�\n");
    fclose(pfile);
}


int main() {
    while (1)
    {
        printf("----------------------------------\n");
        printf("ѧ���ɼ�����ϵͳ\n");
        printf("1.��ѯ�����ɼ���\n2.����ѧ����Ϣ\n3.�޸�ѧ����Ϣ\n4.ɾ��ѧ����Ϣ\n5.���ɼ�����\n6.����ѧ����Ϣ\n7.��ȡѧ����Ϣ\nq.�˳�ϵͳ\n");
        printf("----------------------------------\n");
        printf("�������ֱ�Ž�����Ӧ����:");
        char ch;
        scanf(" %c", &ch);
        getchar();
        switch (ch)
        {
        case '1':
            readall();
            break;
        case '2':
            addition();
            break;
        case '3':
            correct();
            break;
        case '4':
            delete();
            break;
        case '5':
            sort();  
            break;
        case '6':
            save();  
            break;
        case '7':
            read();
            break;
        case 'q':
            printf("�ټ���\n");
            return;
        default:
            printf("����������������룡\n");
            break;
        }
    }
    return 0;
}
