#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"

#define LEN sizeof(struct student)

struct student *creat();

int menu();
int n;

struct student
{
	int id;//学生学号
	char name[20];//学生姓名
	char sex;//学生性别
	int age;//学生年龄
	struct student *next;//指向下一个地址
	
};

void main()
{
	int number;
	
	struct student *stu;
	
	
	while(1)
	{
		
		menu();
		scanf("%d",&number);
		switch(number)
		{
		case 1://录入学生信息
			stu =creat();
			break;
		case 2://删除学生信息
			
			break;
		case 3:
			
			break;
		case 4:
			break;
		case 5:
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
}

struct student *creat()
{
	int i=0,len;
	struct student *head;//头指针
	struct student *p1,*p2;//申请新节点
	p1= p2 = (struct student *)malloc(LEN);
	
	printf("输入学号: ");
	scanf("%d",&p1->id);
	printf("输入姓名: ");
	scanf("%s",&p1->name);
	printf("输入性别: ");
	scanf("%s",&p1->sex);
	printf("输入年龄: ");
	scanf("%d",&p1->age);
	head = NULL;
	
	while(p1->id != 0)
	{
		n=n++;
		if(n==1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		printf("输入学号: ");
		scanf("%d",&p1->id);
		printf("输入姓名: ");
		scanf("%s",&p1->name);
		printf("输入性别: ");
		scanf("%s",&p1->sex);
		printf("输入年龄: ");
		scanf("%d",&p1->age);
	}
	p2->next = NULL;
	return head;
}