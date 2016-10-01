#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"

#define LEN sizeof(struct student)			//实现代码的简写

struct student *creat();					//声明创建链表的函数
void print(struct student *head);			//声明输出链表的函数

int menu();									//声明界面函数
int n=1;									//从第一个学生开始,学生人数统计,控制循环输出

struct student								//定义学生信息这一结构体
{
	char id[20];							//学生学号
	char name[20];							//学生姓名
	char sex[10];							//学生性别
	int age;								//学生年龄
	struct student *next;					//指向下一个学生信息
	
};

void main()
{
	int number;				//定义对应的功能选择项
	
	struct student *stu;	//定义*stu,用来指向创建的链表
	
	while(1)
	{
		
		menu();
		scanf("%d",&number);
		switch(number)
		{
		case 1:				//录入学生信息
			stu =creat();
			
			break;
		case 2:				//删除学生信息
			
			break;
		case 3:
			
			break;
		case 4:				//查询学生信息
			print(stu);
			break;
		case 5:				//退出
			exit(0);
			break;
		default:
			printf("正在开发!\n");
			break;
			
		}
	}	
}

int menu()
{
	printf("■□■□■□---学生管理系统---■□■□■□\n\n");
	printf("  ▁▂▃▄▅ 1.增加学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 2.删除学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 3.修改学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 4.查询学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 5.退出         ▅▄▃▂▁\n\n");
	
	printf("请输入1-5进行你的操作: ");
	return 0;
}

struct student *creat()
{
	int len;								//控制录入学生信息的人数
	struct student *head;					//头节点
	struct student *p1,*p2;					//申请新节点,p1指向新节点的地址,p2指向尾节点的地址
	p1= p2 = (struct student *)malloc(LEN); //开辟一个新节点并保存新节点的地址
	
	printf("输入需要录入信息的人数: ");
	scanf("%d",&len);
	
	printf("正在录入第%d个学生:\n",n);
	
											/*
											这里不用循环,直接录入第一个学生信息,
											后面要把第一个学生信息给head.
											*/
	
	printf("输入学号: ");
	scanf("%s",&p1->id);
	printf("输入姓名: ");
	scanf("%s",&p1->name);
	printf("输入性别: ");
	scanf("%s",&p1->sex);
	printf("输入年龄: ");
	scanf("%d",&p1->age);
	
	printf("\n");
	head = NULL;							//先给head空地址
	
	while(n<=len)							//n从1开始,需要输入n次
	{
		
		n=n++;								//每循环一次,递增一次,n的初始值为1
		if(n==2)							//上次n的递增后,这句语句百分百执行
			head = p1;						//在这里把第一个学生信息放入头结点head
		else								//循环第一次后,n的值不在可能为2,然后每次都执行这条语句
			p2->next = p1;					//把p1的地址指向尾节点
		p2 = p1;							//把p1的地址给p2保留,然后用p1继续开辟新节点
		p1 = (struct student *)malloc(LEN); //p1开辟新节点
		if(n<=len)
		{
			/*
				我把n递增放在了上面,第一次录入的信息地址需要放入头节点,所以后面会有多
				执行一次的情况出现,因为程序还是要走完while才退出,但多的这次无法再通过
				循环写入链表,所以我利用if捕获n>len这次,捕获到就退出.
			*/
			printf("正在录入第%d个学生:\n",n);
			
			printf("输入学号: ");
			scanf("%s",&p1->id);
			printf("输入姓名: ");
			scanf("%s",&p1->name);
			printf("输入性别: ");
			scanf("%s",&p1->sex);
			printf("输入年龄: ");
			scanf("%d",&p1->age);
			printf("\n");
		}
		else
		{
			break;
		}
		
	}
	p2->next = NULL;
	//	free(p1);
	//	p1 = NULL;
	return head;
}
void print(struct student *head)
{	
	struct student *p;
	printf("\n目前数据库里共有%d名学生的信息:\n",n-1);
	p=head;
	if(head!=NULL)
	{
		
		printf("\t学号\t姓名\t性别\t年龄\n");
		while(p!=NULL)
		{
			
			printf("\t%s\t%s\t%s\t%d\n",p->id,p->name,p->sex,p->age);
			p=p->next;
		}
	}
	printf("\n\n");
}