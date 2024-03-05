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

Node* head=NULL ; //头结点

// 1.查询完整成绩单
void readall()//1.全部成绩
{
    Node* p = (Node*)malloc(sizeof(Node));
    p = head; // 将 p 指针设置为链表的头节点
    if (head == NULL) {
        printf("链表为空。\n");
        return;
    }
    printf("姓名\t学号\t性别\t电话号码   C语言   计算机网络   数据结构   平均分\n");
    // 遍历链表
    while (p != NULL)
    {
        printf("%s\t%s\t%s\t%d      %d\t     %d\t        %d\t  %.2f\n", p->student.name, p->student.numb, p->student.gender, p->student.phone, p->student.c, p->student.j, p->student.s, p->student.a);
        p = p->next;
    }
}

// 2.增加学生信息
void addition() {
    // 分配新节点内存
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("内存分配失败\n");
        return;
    }

    // 输入学生信息
    printf("请输入姓名: ");
    scanf("%s", new_node->student.name);
    getchar(); // 吸收换行符

    printf("请输入学号: ");
    scanf("%s", new_node->student.numb);
    getchar();

    printf("请输入性别: ");
    scanf("%s", new_node->student.gender);
    getchar();

    printf("请输入电话号码: ");
    scanf("%d", &new_node->student.phone);
    getchar();

    printf("请输入C语言成绩: ");
    scanf("%d", &new_node->student.c);
    getchar();

    printf("请输入计算机网络成绩: ");
    scanf("%d", &new_node->student.j);
    getchar();

    printf("请输入数据结构成绩: ");
    scanf("%d", &new_node->student.s);
    getchar();

    new_node->student.a = (new_node->student.c + new_node->student.j + new_node->student.s) / 3.0;

    // 在链表尾部插入新节点
    if (head == NULL) {
        // 如果链表为空，将新节点设置为头节点
        head = new_node;
        new_node->next = NULL;
    }
    else {
        // 否则，找到链表的尾部节点，将其next指针指向新节点
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = NULL;
    }

    printf("增加成功\n");
}
//3.修改学生信息
void correct() 
{
    char na[20];
    printf("请输入你要修改的学生姓名：");
    scanf("%s", na);
    getchar();
    Node* p = (Node*)malloc(sizeof(Node));
    p = head;    
    while (p != NULL)  //while循环遍历链表
    {
        if (strcmp(na, p->student.name) == 0)
        {
            printf("请输入学号: ");
            scanf("%s", p->student.numb);
            getchar();
            printf("请输入性别: ");
            scanf("%s", p->student.gender);
            getchar();
            printf("请输入电话号码: ");
            scanf("%d", &p->student.phone);
            getchar();
            printf("请输入C语言成绩: ");
            scanf("%d", &p->student.c);
            getchar();
            printf("请输入计算机网络成绩: ");
            scanf("%d", &p->student.j);
            getchar();
            printf("请输入数据结构成绩: ");
            scanf("%d", &p->student.s);
            getchar();
            p->student.a = (p->student.c + p->student.j + p->student.s) / 3.0;
            printf("修改成功\n");            
            return;
        }
        p = p->next;
    }
    if (p == NULL)
        printf("无该生信息\n");
}

void delete() //4.删除
{
    char na_me[20];
    printf("请输入学生姓名：");
    scanf("%s", na_me);
    getchar();
    //删除一个节点需要找到该节点的前一个节点，使其前一个结点指向下下个节点
    Node* pre = (Node*)malloc(sizeof(Node));
    pre = head;
    while (pre->next != NULL) 
    {
        if (strcmp(na_me, pre->next->student.name) == 0 )
        {
            //temp作为该删除节点的副本被删除
            Node* temp = pre->next;
            //让被删除的节点的下一个节点作为被删除节点
            pre->next = pre->next->next;
            free(temp);
            printf("删除成功\n");
            return;
        }
        pre = pre->next;
    }
    if(pre->next==NULL)
        printf("未找到该生信息\n");
}

//排序
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
            // 交换节点数据
            Student temp = max->student;
            max->student = turn->student;
            turn->student = temp;
        }
        turn = turn->next;
    }
    printf("姓名\t学号\t性别\t电话号码   C语言   计算机网络   数据结构   平均分\n");
    Node* p = head->next; // 从第一个学生节点开始打印
    while (p != NULL) {
        printf("%s\t%s\t%s\t%d      %d\t     %d\t        %d\t  %.2f\n", p->student.name, p->student.numb, p->student.gender, p->student.phone, p->student.c, p->student.j, p->student.s, p->student.a);
        p = p->next;
    }
}

//保存学生信息
void save()
{
    FILE* pfile = fopen("stu.txt", "w");
    if (pfile == NULL)
    {
        printf("无法打开文件\n");
        return;
    }
    //遍历链表
    Node* p = head;
    while (p != NULL)
    {
        fwrite(&p->student, 1, sizeof(Student), pfile);
        p = p->next;
    }
    //关闭文件
    fclose(pfile);
    printf("文件保存成功\n");
}

//读取学生信息
void read()
{
    FILE* pfile = fopen("stu.txt", "r");
    if (pfile == NULL)
    {
        printf("无法打开文件\n");
        return;
    }
    while (!feof(pfile))
    {
        //创建新节点用于存放学生信息
        Node* new = (Node*)malloc(sizeof(Student));
        fread(&new->student, 1, sizeof(Student), pfile);
        new->next = NULL;
        if (head == NULL)
        {
            // 如果链表为空，将新节点设置为头节点
            head = new;
        }
        else
        {
            // 否则，找到链表的尾部节点，将其next指针指向新节点
            //从头结点开始找
            Node* tail = head;
            while (tail->next != NULL)  //tail的下一个节点为空则说明找到了
            {
                tail = tail->next;
            }
            tail->next = new;
        }
    }
    printf("读取成功\n");
    fclose(pfile);
}


int main() {
    while (1)
    {
        printf("----------------------------------\n");
        printf("学生成绩管理系统\n");
        printf("1.查询完整成绩单\n2.增加学生信息\n3.修改学生信息\n4.删除学生信息\n5.按成绩排序\n6.保存学生信息\n7.读取学生信息\nq.退出系统\n");
        printf("----------------------------------\n");
        printf("输入数字编号进行相应操作:");
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
            printf("再见！\n");
            return;
        default:
            printf("输入错误，请重新输入！\n");
            break;
        }
    }
    return 0;
}
