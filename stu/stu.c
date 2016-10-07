#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
#include"string.h"


#define LEN sizeof(struct student)			//�궨�� LEN = sizeof(struct student)

struct student *creat();								//������������ĺ���
void print(struct student *head);						//�����������ĺ���
struct student *loadinfo();								//�����ļ����ݵ�����
void savequit(struct student *head);					//����������д���ļ�
struct student *delname(struct student *head);			//ͨ������ɾ��ѧ����Ϣ
struct student *delid(struct student *head);			//ͨ��ѧ��ɾ��ѧ����Ϣ
struct student *bubblesort(struct student *head);		//ð������
void creat_pwd();										//������������
void remove_pwd();										//�޸���������
void menu();											//����ϵͳ���溯��
int delmenu();											//����ɾ������Ͳ���ɾ������
int n=1;												//�ӵ�һ��ѧ����ʼ,ѧ������ͳ��,����ѭ�����

struct student											//����ѧ����Ϣ��һ�ṹ��
{
	char id[20];							//ѧ��ѧ��
	char name[20];							//ѧ������
	char sex[10];							//ѧ���Ա�
	int age;								//ѧ������
	struct student *next;					//ָ����һ��ѧ����Ϣ��ַ
	
};

void main()
{
	int number,delnum,a;				//�����Ӧ�Ĺ���ѡ����
	FILE *fp;
	struct student *stu,*head;	//����*stu,����ָ�򴴽�������
	stu = NULL;
	head =NULL;
	
	creat_pwd();
	while(1)
	{
		
		if((fp = fopen("data.txt","r"))==NULL)
		{
			printf("���ששששששששששששששששששש�\n");
			printf("�� ���ݿ�û���κ�ѧ����Ϣ,���ʼ�����ݿ��\n");
			printf("���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ�\n");
			stu = creat();
			stu = bubblesort(stu);
			savequit(stu);
			free(stu);
			printf("���ששששששששששששששששששש�\n");
			printf("��       ѧ �� �� Ϣ ¼ �� �� �� !      ��\n");
			printf("��          1.��������ϵͳ              ��\n");
			printf("��          2.������Ļ����ϵͳ          ��\n");
			printf("���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ�\n");
			printf("������1-2������Ĳ���: ");
			scanf("%d",&a);
			switch(a)
			{
			case 1:
				system("cls");//����
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
			case 1:				//����ѧ����Ϣ
				printf("���ڿ���!\n");
				break;
			case 2:				//ɾ��ѧ����Ϣ
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
					printf("���ڿ���!\n");
					break;
				case 4:				//�������ѧ����Ϣ
					print(head);
					break;
				case 5:				//����
					remove_pwd();
					break;
				case 6:				//�˳�
					exit(0);
					break;
				default:
					printf("���ڿ���!\n");
					break;
					
					
			}
		}
	}	
}

void menu()
{
	printf("\n\n������������--ѧ������ϵͳ--��������������\n\n");
	printf("  �x�y�z�{�| 1.����ѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 2.ɾ��ѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 3.�޸�ѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 4.�鿴ѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 5.�޸��������� �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 6.�˳�         �|�{�z�y�x\n\n");
	printf("������������������������������������������\n\n");
	
	printf("������1-6������Ĳ���: ");
}

int delmenu()
{
	int delnum;
	printf("\n");
	printf("���ששששששששששששששששששש�\n");
	printf("��       1.ͨ��ѧ��ɾ��ѧ����Ϣ         ��\n");
	printf("��       2.ͨ������ɾ��ѧ����Ϣ         ��\n");
	printf("��       3.��                ��         ��\n");
	printf("���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ�\n\n");
	printf("������1-3������Ĳ���: ");
	scanf("%d",&delnum);
	return delnum;
}

void creat_pwd()//�����������
{
	FILE *fp;
	char pwd[20];//��������
	char pwd_1[20];//���õ�һ������
	char pwd_2[20];//���õڶ�������
	char userspwd[20] = "userspwd.txt";//�ļ���
	
	while(1)
	{	
		if((fp = fopen(userspwd,"r")) != NULL)//������ļ����ڣ�ֻд,���ļ�,���ļ��е��ַ�����pwd;
		{
			fscanf(fp,"%s",&pwd);
			printf("��������������: ");
			scanf("%s",&pwd_1);
			if(strcmp(pwd,pwd_1) == 0)
			{
				printf("\n������ȷ!\n");
				break;
			}
			else
			{
				printf("\n�������!����������!\n\n");
			}
			fclose(fp);
		}
		else							//���������,��д,����
		{
			while(1)
			{
				printf("��������������: ");
				scanf("%s",&pwd_1);
				printf("\n���ٴ�������������: ");
				scanf("%s",&pwd_2);
				if(strcmp(pwd_1,pwd_2) == 0)
				{
					fp = fopen(userspwd,"w");
					fprintf(fp,"%s",pwd_1);
					printf("\n�������óɹ�!\n");
					fclose(fp);
					break;
				}
				else
				{
					printf("\n�������벻һ��!����������!\n\n");
				}
			}		
		}
	}
}


void remove_pwd()//�޸��������
{
	FILE *fp;
	char pwd[20];			//������������
	char pwd_pwd[20];		//��֤��������
	char pwd_1[20];			//���õ�һ������
	char pwd_2[20];			//���õڶ�������
	char userspwd[20] = "userspwd.txt";
	while(1)
	{
		if((fp = fopen(userspwd,"r")) != NULL)//������ļ����ڣ�ֻд,���ļ�,���ļ��е��ַ�����pwd;
		{
			fscanf(fp,"%s",&pwd);
			printf("����֤��������: ");
			scanf("%s",&pwd_pwd);
			if(strcmp(pwd,pwd_pwd) == 0)
			{
				printf("\n������ȷ!\n");
				if((fp = fopen(userspwd,"w")) != NULL)
				{
					while(1)
					{
						printf("��������������: ");
						scanf("%s",&pwd_1);
						printf("\n���ٴ�������������: ");
						scanf("%s",&pwd_2);
						if(strcmp(pwd_1,pwd_2) == 0)
						{
							fp = fopen(userspwd,"w");
							fprintf(fp,"%s",pwd_1);
							printf("\n�������óɹ�!\n");
							fclose(fp);
							break;
						}
						else
						{
							printf("\n�������벻һ��!����������!\n\n");
						}
					}
				}
				break;
			}
			else
			{
				printf("\n�������!����������!\n\n");
			}
			fclose(fp);
		}
	}
}



struct student *creat()
{
	int len;								//����¼��ѧ����Ϣ������
	struct student *head;					//ͷ�ڵ�
	struct student *p1,*p2;					//�����½ڵ�,p1ָ���½ڵ�ĵ�ַ,p2ָ��β�ڵ�ĵ�ַ
	p1= p2 = (struct student *)malloc(LEN); //����һ���½ڵ㲢�����½ڵ�ĵ�ַ
	
	printf("������Ҫ¼����Ϣ������: ");
	scanf("%d",&len);
	
	printf("����¼���%d��ѧ��:\n",n);
	
	/*
	���ﲻ��ѭ��,ֱ��¼���һ��ѧ����Ϣ,
	����Ҫ�ѵ�һ��ѧ����Ϣ��head.
	*/
	
	printf("����ѧ��: ");
	scanf("%s",&p1->id);
	printf("��������: ");
	scanf("%s",&p1->name);
	printf("�����Ա�: ");
	scanf("%s",&p1->sex);
	printf("��������: ");
	scanf("%d",&p1->age);
	
	printf("\n");
	head = NULL;							//�ȸ�head�յ�ַ
	
	while(n<=len)							//n��1��ʼ,��Ҫ����n��
	{
		
		n=n++;								//ÿѭ��һ��,����һ��,n�ĳ�ʼֵΪ1
		if(n==2)							//�ϴ�n�ĵ�����,������ٷְ�ִ��
			head = p1;						//������ѵ�һ��ѧ����Ϣ����ͷ���head
		else								//ѭ����һ�κ�,n��ֵ���ڿ���Ϊ2,Ȼ��ÿ�ζ�ִ���������
			p2->next = p1;					//��p1�ĵ�ַָ��β�ڵ�
		p2 = p1;							//��p1�ĵ�ַ��p2����,Ȼ����p1���������½ڵ�
		p1 = (struct student *)malloc(LEN); //p1�����½ڵ�
		if(n<=len)
		{
		/*
		�Ұ�n��������������,��һ��¼�����Ϣ��ַ��Ҫ����ͷ�ڵ�,���Ժ�����ж�
		ִ��һ�ε��������,��Ϊ������Ҫ����while���˳�,���������޷���ͨ��
		ѭ��д������,����������if����n>len���,���񵽾��˳�.
			*/
			printf("����¼���%d��ѧ��:\n",n);
			
			printf("����ѧ��: ");
			scanf("%s",&p1->id);
			printf("��������: ");
			scanf("%s",&p1->name);
			printf("�����Ա�: ");
			scanf("%s",&p1->sex);
			printf("��������: ");
			scanf("%d",&p1->age);
			printf("\n");
		}
		else
		{
			break;
		}
		
	}
	p2->next = NULL;			//������������һ���ڵ�Ҫָ��NULL
	free(p1);
	p1=NULL;
	return head;
}




void print(struct student *head)//�������
{	
	int a;
	struct student *p;
	
	p=head;
	if(head!=NULL)				//ֻҪ���ǿ��������������е�ֵ
	{
		
		printf("\nѧ��\t����\t�Ա�\t����\n");
		while(p!=NULL)
		{
			printf("%s\t%s\t%s\t%d\n",p->id,p->name,p->sex,p->age);
			p=p->next;			//ת�Ƶ���һ���ڵ�������,ֱ��p=NULLΪֹ
			
		}
	}
	printf("\n\n");
	printf("���ששששששששששששששששששש�\n");
	printf("��       ѧ �� �� Ϣ �� �� �� �� !      ��\n");
	printf("��          1.��������                  ��\n");
	printf("��          2.����������                ��\n");
	printf("���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ�\n");
	printf("������1-2������Ĳ���: ");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
		system("cls");//����
		break;
	case 2:
		break;
	}		
	printf("\n");
}




struct student *loadinfo()//�ı��ļ������������
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
		printf("��������!\n");
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




void savequit(struct student *head)//�������ݱ��浽�ı��ļ�
{
	struct student *p1;
	FILE *fp;
	char filename[] = "data.txt";
	p1 = head;
	
	if(NULL == (fp = fopen(filename,"w")))//�ж��ļ��Ƿ�����ҿɶ�
	{
		printf("��������!");
		exit(0);
	}
	
	while(p1 != NULL)
	{
		
		fprintf(fp,"%s %s %s %d\n",p1->id,p1->name,p1->sex,p1->age);
		p1 = p1->next;
	}
	fclose(fp);
}



struct student *delname(struct student *head)//ͨ������ɾ��ѧ����Ϣ
{
	char name[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("����Ϊ��\n");
		return head;
	}
	p1 = head;
	printf("�ܸ���Ϊ������!\n");
	printf("��������Ҫɾ����ѧ��������: ");
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
		printf("ɾ���ɹ�!\n");
	}
	else
	{
		printf("\n��Ǹ,ѧ����Ϣû���ҵ�!");
	}
	return head;
}
struct student *delid(struct student *head)//ͨ��ѧ��ɾ��ѧ����Ϣ
{
	char id[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("����Ϊ��\n");
		return head;
	}
	p1 = head;
	printf("�ܸ���Ϊ������!\n");
	printf("��������Ҫɾ����ѧ����ѧ��: ");
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
		printf("ɾ���ɹ�!\n");
	}
	else
	{
		printf("\n��Ǹ,ѧ����Ϣû���ҵ�!");
	}
	return head;
}

struct student *bubblesort(struct student *head)
{
	struct student *endpt;		//����ѭ���Ƚ�
	struct student *p;			//��ʱָ�����
	struct student *p1,*p2;
	
	p1 = (struct student *)malloc(LEN);
	p1->next = head;
	//����һ���ڵ�,���ڵ�һ���ڵ��ǰ��,��Ҫ��Ϊ�˱��ڱȽ�,��Ϊ��һ���ڵ�û��ǰ���ڵ�,���ǲ��ܽ�����ַ
	head = p1;
	//��headָ��p1�ڵ�,������ɺ������ٰ�p1�ڵ��ͷŵ�
	for(endpt = NULL;endpt != head;endpt = p)
	{
		for(p=p1=head;p1->next->next!=endpt;p1=p1->next)
		{
			if(strcmp(p1->next->id,p1->next->next->id) == 1)
				//���ǰ��ļ�ֵ��ASCll�Ⱥ���ļ�ֵ��ASCLL��
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