#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
#include"string.h"


#define LEN sizeof(struct student)			//宏定义 LEN = sizeof(struct student)

struct student *creat();												//声明创建链表的函数
void print(struct student *head);										//声明输出链表的函数
struct student *loadinfo();												//加载文件内容到链表
void savequit(struct student *head);									//将链表内容写入文件
struct student *delname(struct student *head);							//通过姓名删除学生信息
struct student *delid(struct student *head);							//通过学号删除学生信息
struct student *bubblesort(struct student *head);						//冒泡排序
void creat_pwd();														//创建启动密码
void remove_pwd();														//修改启动密码
struct student *insert(struct student *head,struct student *p);			//插入信息
struct student *amend_stu_1(struct student *head);						//学生信息修改1
struct student *amend_stu_2(struct student *head,struct student *p);	//学生信息修改2
struct student *stu_id(struct student *head);							//学号搜索
struct student *stu_name(struct student *head);							//姓名搜索
void menu();															//声明系统界面函数
int delmenu();															//声明删除界面和操作删除函数
int see();																//查看学生信息函数界面
int n=1;																//从第一个学生开始,学生人数统计,控制循环输出

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
	int number,delnum,see_id,a;				//定义对应的功能选择项
	FILE *fp;
	struct student *stu,*head,*p1,*p2;	//定义*stu,用来指向创建的链表
	stu = NULL;
	head =NULL;
	
	creat_pwd();
	while(1)
	{
		
		if((fp = fopen("data.txt","r"))==NULL)
		{
			printf("★★★★★★★★★★★★★★★★★★★★★★★\n");
			printf("★★★★★★student management1.1★★★★★★\n");
			printf("★★★★★★★★★★★★★★★★★★★★★★★\n\n");
			printf("┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓\n");
			printf("┣ 数据库没有任何学生信息,请初始化数据库┫\n");
			printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛\n");
			stu = creat();
			stu = bubblesort(stu);
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
				
				p1 = (struct student *)malloc(LEN);

				printf("请输入插入学生的信息: ");
				printf("\n\n");
				printf("输入学号: ");
				scanf("%s",&p1->id);
				printf("输入姓名: ");
				scanf("%s",&p1->name);
				printf("输入性别: ");
				scanf("%s",&p1->sex);
				printf("输入年龄: ");
				scanf("%d",&p1->age);
				printf("\n");

				head = insert(head,p1);
				savequit(head);
				free(p1);
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
				case 3:					//修改学生信息
				head = amend_stu_1(head);
				savequit(head);
				p1 = (struct student *)malloc(LEN);
				printf("请输入插入学生的信息: ");
				printf("\n\n");
				printf("输入学号: ");
				scanf("%s",&p1->id);
				printf("输入姓名: ");
				scanf("%s",&p1->name);
				printf("输入性别: ");
				scanf("%s",&p1->sex);
				printf("输入年龄: ");
				scanf("%d",&p1->age);
				printf("\n");

					head = amend_stu_2(head,p1);
					
					savequit(head);
					break;
				case 4:				//输出学生信息
					see_id = see();
					switch(see_id)
				{
				case 1:
					stu_id(head);//学号查询
					break;
				case 2:
					stu_name(head);
					break;
				case 3:
					print(head);//查询全部
					break;
				default:
					break;
				}	
					break;
				case 5:				//修改启动密码
					remove_pwd();
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
	printf("★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("★★★★★★student management1.1★★★★★★\n");
	printf("★★★★★★★★★★★★★★★★★★★★★★★\n\n");
	printf("\n\n■□■□■□--学生管理系统--■□■□■□■\n\n");
	printf("  ▁▂▃▄▅ 1.增加学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 2.删除学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 3.修改学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 4.查看学生信息 ▅▄▃▂▁\n");
	printf("  ▁▂▃▄▅ 5.修改启动密码 ▅▄▃▂▁\n");
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

int see()
{
	int see;
	printf("\n");
	printf("┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓\n");
	printf("┣       1.通过学号查看学生信息         ┫\n");
	printf("┣       2.通过姓名查看学生信息         ┫\n");
	printf("┣       3.查看所有学生信息             ┫\n");
	printf("┣       4.返                回         ┫\n");
	printf("┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛\n\n");
	printf("请输入1-4进行你的操作: ");
	scanf("%d",&see);
	return see;

}

void creat_pwd()//创建密码操作
{
	FILE *fp;
	char pwd[20];//启动密码
	char pwd_1[20];//设置第一次密码
	char pwd_2[20];//设置第二次密码
	char userspwd[20] = "userspwd.txt";//文件名
	
	while(1)
	{	
		if((fp = fopen(userspwd,"r")) != NULL)//如果此文件存在，只写,打开文件,将文件中的字符存入pwd;
		{
			fscanf(fp,"%s",&pwd);
			printf("请输入启动密码进入: ");
			scanf("%s",&pwd_1);
			system("cls");
			if(strcmp(pwd,pwd_1) == 0)
			{
				printf("密码正确!");
				system("cls");
				break;
			}
			else
			{
				printf("密码错误!请重新输入!");
				system("cls");
			}
			fclose(fp);
		}
		else							//如果不存在,读写,创建
		{
			while(1)
			{
				printf("请设置启动密码: ");
				scanf("%s",&pwd_1);
				system("cls");
				printf("请再次确认启动密码: ");
				scanf("%s",&pwd_2);
				system("cls");
				if(strcmp(pwd_1,pwd_2) == 0)
				{
					fp = fopen(userspwd,"w");
					fprintf(fp,"%s",pwd_1);
					printf("密码设置成功!");
					system("cls");
					fclose(fp);
					break;
				}
				else
				{
					printf("两次密码不一样!请重新输入!");
					system("cls");
				}
			}		
		}
	}
}


void remove_pwd()//修改密码操作
{
	FILE *fp;
	char pwd[20];			//读入启动密码
	char pwd_pwd[20];		//验证启动密码
	char pwd_1[20];			//设置第一次密码
	char pwd_2[20];			//设置第二次密码
	char userspwd[20] = "userspwd.txt";
	while(1)
	{
		if((fp = fopen(userspwd,"r")) != NULL)//如果此文件存在，只写,打开文件,将文件中的字符存入pwd;
		{
			fscanf(fp,"%s",&pwd);
			printf("请输入启动密码进入: ");
			scanf("%s",&pwd_pwd);
			system("cls");
			if(strcmp(pwd,pwd_pwd) == 0)
			{
				printf("密码正确!");
				system("cls");
				if((fp = fopen(userspwd,"w")) != NULL)
				{
					while(1)
					{
						printf("请设置启动密码: ");
						scanf("%s",&pwd_1);
						system("cls");
						printf("请再次确认启动密码: ");
						scanf("%s",&pwd_2);
						system("cls");
						if(strcmp(pwd_1,pwd_2) == 0)
						{
							fp = fopen(userspwd,"w");
							fprintf(fp,"%s",pwd_1);
							printf("密码设置成功!");
							system("cls");
							fclose(fp);
							break;
						}
						else
						{
							printf("两次密码不一样!请重新输入!");
							system("cls");
						}
					}
				}
				break;
			}
			else
			{
				printf("\n密码错误!请重新输入!\n\n");
				system("cls");
			}
			fclose(fp);
		}
	}
}



struct student *creat() //创建链表
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

struct student *bubblesort(struct student *head) //学号冒泡排序
{
	struct student *endpt;		//控制循环比较
	struct student *p;			//临时指针变量
	struct student *p1,*p2;
	
	p1 = (struct student *)malloc(LEN);
	p1->next = head;
	//增加一个节点,放在第一个节点的前面,主要是为了便于比较,因为第一个节点没有前驱节点,我们不能交换地址
	head = p1;
	//让head指向p1节点,排序完成后我们再把p1节点释放掉
	for(endpt = NULL;endpt != head;endpt = p)
	{
		for(p=p1=head;p1->next->next!=endpt;p1=p1->next)
		{
			if(strcmp(p1->next->id,p1->next->next->id) == 1)
				//如果前面的键值的ASCll比后面的键值的ASCLL大
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;
	free(p1);
	p1 = NULL;
	return head;
}

struct student *insert(struct student *head,struct student *p)     //插入数据
{

  struct student *p1,*p2;
  p1=head;
  p2=p1->next;
  while((strcmp(p->id,p2->id) > 0)&&(p2!=NULL))
  {
   p1=p2;
   p2=p2->next;
  }
  if(strcmp(p->id,p2->id) == 0)
  {
	printf("输入错误!(学号不能重复!)\n");
	printf("请重新操作!\n");
  }
  else if(p2!=NULL)
  {
	  p1->next=p;
      p->next=p2;
	  printf("添加完毕!\n");
  }
  else if(p2==NULL)
  {
	  p1->next=p;
	  p->next=NULL;
	  printf("添加完毕!\n");
  }
	return head;
}


struct student *stu_id(struct student *head)//通过学号搜索学生信息
{
	char id[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("链表为空\n");
		return head;
	}
	p1 = head;
	printf("告诉我你要查看的学生的学号: ");
	scanf("%s",&id);
	while((strcmp(p1->id,id) != 0) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(strcmp(p1->id,id) == 0)
	{
	printf("\n学号\t姓名\t性别\t年龄\n");
	printf("%s\t%s\t%s\t%d\n",p1->id,p1->name,p1->sex,p1->age);
	free(p1);
	p1 = NULL;
	}
	else
	{
		printf("\n抱歉,学生信息没有找到!");
	}
	return head;
}


struct student *stu_name(struct student *head)//通过姓名搜索学生信息
{
	char name[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("链表为空\n");
		return head;
	}
	p1 = head;
	printf("告诉我你要查看的学生的姓名: ");
	scanf("%s",&name);
	while((strcmp(p1->name,name) != 0) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(strcmp(p1->name,name) == 0)
	{
	printf("\n学号\t姓名\t性别\t年龄\n");
	printf("%s\t%s\t%s\t%d\n",p1->id,p1->name,p1->sex,p1->age);
	free(p1);
	p1 = NULL;
	}
	else
	{
		printf("\n抱歉,学生信息没有找到!");
	}
	return head;
}

struct student *amend_stu_1(struct student *head)
{
	char id[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("链表为空\n");
		return head;
	}
	p1 = head;
	printf("告诉我需要修改的学生的学号: ");
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
	}
	else
	{
		printf("\n抱歉,学生信息没有找到!");
	}
	return head;
}


struct student *amend_stu_2(struct student *head,struct student *p)     //插入数据
{

  struct student *p1,*p2;
  p1=head;
  p2=p1->next;
  while((strcmp(p->id,p2->id) > 0)&&(p2!=NULL))
  {
   p1=p2;
   p2=p2->next;
  }
  if(strcmp(p->id,p2->id) == 0)
  {
	printf("输入错误!(学号不能重复!)");
	printf("请重新操作!");
  }
  else if(p2!=NULL)
  {
	  p1->next=p;
      p->next=p2;
	  printf("修改完毕!");
  }
  else if(p2==NULL)
  {
	  p1->next=p;
	  p->next=NULL;
	  printf("修改完毕!");
  }
	return head;
}

