#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
#include"string.h"


#define LEN sizeof(struct student)			//宏定义 LEN = sizeof(struct student)

struct student *creat();								//声明创建链表的函数
void print(struct student *head);						//声明输出链表的函数
struct student *loadinfo();								//加载文件内容到链表
void savequit(struct student *head);					//将链表内容写入文件
struct student *delname(struct student *head);			//通过姓名删除学生信息
struct student *delid(struct student *head);			//通过学号删除学生信息
void menu();											//声明系统界面函数
int delmenu();											//声明删除界面和操作删除函数
int n=1;												//从第一个学生开始,学生人数统计,控制循环输出

struct student											//定义学生信息这一结构体
{
	char id[20];							//学生学号
	char name[20];							//学生姓名
	char sex[10];							//学生性别
	int age;								//学生年龄
	struct student *next;					//指向下一个学生信息地址
	
};

void main()
{
	int number,delnum,a;				//定义对应的功能选择项
	FILE *fp;
	struct student *stu,*head;	//定义*stu,用来指向创建的链表
	stu = NULL;
	head =NULL;
	while(1)
	{
		if((fp = fopen("data.txt","r"))==NULL)
		{
			printf("┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓\n");
			printf("┣ 数据库没有任何学生信息,请初始化数据库┫\n");
			printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛\n");
			stu = creat();
			savequit(stu);
			free(stu);
			printf("┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓\n");
			printf("┣       学 生 信 息 录 入 成 功 !      ┫\n");
			printf("┣          1.清屏进入系统              ┫\n");
			printf("┣          2.保留屏幕进入系统          ┫\n");
			printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛\n");
			printf("请输入1-2进行你的操作: ");
			scanf("%d",&a);
			switch(a)
			{
			case 1:
				system("cls");//清屏
				break;
			case 2:
				break;
			}		
		}
		else
		{
			head=loadinfo();
			menu();
			scanf("%d",&number);
			switch(number)
			{
			case 1:				//增加学生信息
				printf("正在开发!\n");
				break;
			case 2:				//删除学生信息
				delnum = delmenu();
					switch(delnum)
					{
					case 1:
						delid(head);
						savequit(head);
						break;
					case 2:
						delname(head);
						savequit(head);
						break;
					case 3:
						break;
					}
				break;
			case 3:
				printf("正在开发!\n");
				break;
			case 4:				//输出所有学生信息
				print(head);
				break;
			case 5:				//保存
				savequit(head);
				free(head);
				break;
			case 6:				//退出
				exit(0);
				break;
			default:
				printf("正在开发!\n");
				break;
					
					
			}
		}
	}	
}

void menu()
{
	printf("\n\n■□■□■□--学生管理系统--■□■□■□■\n\n");
	printf("  ▁▂▃▄▅ 1.增加学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 2.删除学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 3.修改学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 4.查看学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 5.保存学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 6.退出         ▅▄▃▂▁\n\n");
	printf("■□■□■□■□■□■□■□■□■□■□■\n\n");
	
	printf("请输入1-6进行你的操作: ");
}

int delmenu()
{
	int delnum;
	printf("\n");
	printf("┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓\n");
	printf("┣       1.通过学号删除学生信息         ┫\n");
	printf("┣       2.通过姓名删除学生信息         ┫\n");
	printf("┣       3.返                回         ┫\n");
	printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛\n\n");
	printf("请输入1-3进行你的操作: ");
	scanf("%d",&delnum);
	return delnum;
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
	p2->next = NULL;			//单向链表的最后一个节点要指向NULL
	free(p1);
	p1=NULL;
	return head;
}




void print(struct student *head)//输出链表
{	
	int a;
	struct student *p;
	
	p=head;
	if(head!=NULL)				//只要不是空链表就输出链表中的值
	{
		
		printf("\n学号\t姓名\t性别\t年龄\n");
		while(p!=NULL)
		{
			printf("%s\t%s\t%s\t%d\n",p->id,p->name,p->sex,p->age);
			p=p->next;			//转移到下一个节点继续输出,直到p=NULL为止
			
		}
	}
	printf("\n\n");
	printf("┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓\n");
	printf("┣       学 生 信 息 输 出 成 功 !      ┫\n");
	printf("┣          1.清屏返回                  ┫\n");
	printf("┣          2.不清屏返回                ┫\n");
	printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛\n");
	printf("请输入1-2进行你的操作: ");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
		system("cls");//清屏
		break;
	case 2:
		break;
	}		
	printf("\n");
}




struct student *loadinfo()//文本文件输出到链表中
{	
	char filename[] = "data.txt";
	FILE *fp;
	struct student *head,*p1;
	int ishead = 1;
	
	head = (struct student *)malloc(LEN);
	p1 = head;
	p1->next = NULL;
	
	if(NULL == (fp = fopen(filename,"r")))
	{
		printf("发生错误!\n");
		exit(0);
	}
	while(!feof(fp))
	{
		if(!ishead)
		{
			p1->next = (struct student *)malloc(LEN);
			p1 = p1->next;
			p1->next = NULL;
		}
		fscanf(fp,"%s %s %s %d\n",&p1->id,&p1->name,&p1->sex,&p1->age);	
		if(ishead)
			ishead = 0;
	}
	fclose(fp);
	return head;
}




void savequit(struct student *head)//链表数据保存到文本文件
{
	struct student *p1;
	FILE *fp;
	char filename[] = "data.txt";
	p1 = head;
	
	if(NULL == (fp = fopen(filename,"w")))//判断文件是否存在且可读
	{
		printf("发生错误!");
		exit(0);
	}
	
	while(p1 != NULL)
	{
		
		fprintf(fp,"%s %s %s %d\n",p1->id,p1->name,p1->sex,p1->age);
		p1 = p1->next;
	}
	fclose(fp);
}



struct student *delname(struct student *head)//通过姓名删除学生信息
{
	char name[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("链表为空\n");
		return head;
	}
	p1 = head;
	printf("很高兴为您服务!\n");
	printf("告诉我需要删除的学生的名字: ");
	scanf("%s",&name);
	while((strcmp(p1->name,name) != 0) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(strcmp(p1->name,name) == 0)
	{
		if(p1 == head)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
		free(p1);
		p1 = NULL;
		
		n-=1;
		printf("删除成功!\n");
	}
	else
	{
		printf("\n抱歉,学生信息没有找到!");
	}
	return head;
}
struct student *delid(struct student *head)//通过学号删除学生信息
{
	char id[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("链表为空\n");
		return head;
	}
	p1 = head;
	printf("很高兴为您服务!\n");
	printf("告诉我需要删除的学生的学号: ");
	scanf("%s",&id);
	while((strcmp(p1->id,id) != 0) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(strcmp(p1->id,id) == 0)
	{
		if(p1 == head)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
		free(p1);
		p1 = NULL;
		
		n-=1;
		printf("删除成功!\n");
	}
	else
	{
		printf("\n抱歉,学生信息没有找到!");
	}
	return head;
}
