#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
//#include"string.h"


#define LEN sizeof(struct student)			//宏定义 LEN = sizeof(struct student)

struct student *creat();					//声明创建链表的函数
void print(struct student *head);			//声明输出链表的函数
struct student *loadinfo();					//加载文件内容到链表
void savequit(struct student *head);		//将链表内容写入文件
void menu();								//声明界面函数
int n=1;									//从第一个学生开始,学生人数统计,控制循环输出

struct student								//定义学生信息这一结构体
{
	char id[20];							//学生学号
	char name[20];							//学生姓名
	char sex[10];							//学生性别
	int age;								//学生年龄
	struct student *next;					//指向下一个学生信息地址
	
};

void main()
{
	int number;				//定义对应的功能选择项
	FILE *fp;
	struct student *stu,*head;	//定义*stu,用来指向创建的链表
	stu = NULL;
	head =NULL;
	while(1)
	{
		if((fp = fopen("data.txt","r"))==NULL)
		{
			//	if(stu == NULL)//判断数据库是否存有数据
			//	{
			char cls = 'y';
			printf("┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓\n");
			printf("┣ 数据库没有任何学生信息,请初始化数据库┫\n");
			printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛\n");
			stu = creat();
			savequit(stu);
			free(stu);
			printf("录入完毕,按y清屏,输入任意键进入主界面: ");
			scanf("%s",&cls);
			if(cls=='y' || cls=='Y')
				system("cls");//清屏
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
				printf("正在开发!\n");
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
	printf("  ▁▂▃▄▅ 4.输出学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 5.保存学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 6.退出         ▅▄▃▂▁\n\n");
	printf("■□■□■□■□■□■□■□■□■□■□■\n\n");
	
	printf("请输入1-6进行你的操作: ");
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
	return head;
}

void print(struct student *head)//链表输出函数
{	
	char cls='y';
	struct student *p;
	printf("\n◆◆◆目前数据库里共有%d名学生的信息◆◆◆\n",n-1);
	p=head;
	if(head!=NULL)				//只要不是空链表就输出链表中的值
	{
		
		printf("学号\t姓名\t性别\t年龄\n");
		while(p!=NULL)
		{
			
			printf("%s\t%s\t%s\t%d\n",p->id,p->name,p->sex,p->age);
			p=p->next;			//转移到下一个节点继续输出,直到p=NULL为止
		}
	}
	printf("\n\n");
	if(cls=='y' || cls=='Y')
	{
		printf("输出完毕,按y清屏,输入任意键返回主界面: ");
		scanf("%s",&cls);
		if(cls=='y' || cls=='Y')
			system("cls");
	}
	printf("\n");
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
		
		fprintf(fp,"%s\t%s\t%s\t%d\r",p1->id,p1->name,p1->sex,p1->age);
		p1 = p1->next;
	}
	fclose(fp);
}

struct student *loadinfo()//文本文件输出到链表中
{	
	char filename[] = "data.txt";
	FILE *fp;
	struct student *head,*p1;
	
	head = (struct student *)malloc(LEN);
	p1 = head;
	p1 -> next = NULL;
	
	if(NULL == (fp = fopen(filename,"r")))
	{
		printf("发生错误!");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%d",&p1->id,&p1->name,&p1->sex,&p1->age);
		
		p1->next = (struct student *)malloc(LEN);
		p1 = p1->next;
		p1->next = NULL;
	}
	fclose(fp);
	return head;
}