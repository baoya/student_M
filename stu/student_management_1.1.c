#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
#include"string.h"


#define LEN sizeof(struct student)			//�궨�� LEN = sizeof(struct student)

struct student *creat();												//������������ĺ���
void print(struct student *head);										//�����������ĺ���
struct student *loadinfo();												//�����ļ����ݵ�����
void savequit(struct student *head);									//����������д���ļ�
struct student *delname(struct student *head);							//ͨ������ɾ��ѧ����Ϣ
struct student *delid(struct student *head);							//ͨ��ѧ��ɾ��ѧ����Ϣ
struct student *bubblesort(struct student *head);						//ð������
void creat_pwd();														//������������
void remove_pwd();														//�޸���������
struct student *insert(struct student *head,struct student *p);			//������Ϣ
struct student *amend_stu_1(struct student *head);						//ѧ����Ϣ�޸�1
struct student *amend_stu_2(struct student *head,struct student *p);	//ѧ����Ϣ�޸�2
struct student *stu_id(struct student *head);							//ѧ������
struct student *stu_name(struct student *head);							//��������
void menu();															//����ϵͳ���溯��
int delmenu();															//����ɾ������Ͳ���ɾ������
int see();																//�鿴ѧ����Ϣ��������
int n=1;																//�ӵ�һ��ѧ����ʼ,ѧ������ͳ��,����ѭ�����

struct student								//����ѧ����Ϣ��һ�ṹ��
{
	char id[20];							//ѧ��ѧ��
	char name[20];							//ѧ������
	char sex[10];							//ѧ���Ա�
	int age;								//ѧ������
	struct student *next;					//ָ����һ��ѧ����Ϣ��ַ
	
};

void main()
{
	int number,delnum,see_id,a;				//�����Ӧ�Ĺ���ѡ����
	FILE *fp;
	struct student *stu,*head,*p1,*p2;	//����*stu,����ָ�򴴽�������
	stu = NULL;
	head =NULL;
	
	creat_pwd();
	while(1)
	{
		
		if((fp = fopen("data.txt","r"))==NULL)
		{
			printf("������������������������\n");
			printf("�������student management1.1�������\n");
			printf("������������������������\n\n");
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
				
				p1 = (struct student *)malloc(LEN);

				printf("���������ѧ������Ϣ: ");
				printf("\n\n");
				printf("����ѧ��: ");
				scanf("%s",&p1->id);
				printf("��������: ");
				scanf("%s",&p1->name);
				printf("�����Ա�: ");
				scanf("%s",&p1->sex);
				printf("��������: ");
				scanf("%d",&p1->age);
				printf("\n");

				head = insert(head,p1);
				savequit(head);
				free(p1);
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
				case 3:					//�޸�ѧ����Ϣ
				head = amend_stu_1(head);
				savequit(head);
				p1 = (struct student *)malloc(LEN);
				printf("���������ѧ������Ϣ: ");
				printf("\n\n");
				printf("����ѧ��: ");
				scanf("%s",&p1->id);
				printf("��������: ");
				scanf("%s",&p1->name);
				printf("�����Ա�: ");
				scanf("%s",&p1->sex);
				printf("��������: ");
				scanf("%d",&p1->age);
				printf("\n");

					head = amend_stu_2(head,p1);
					
					savequit(head);
					break;
				case 4:				//���ѧ����Ϣ
					see_id = see();
					switch(see_id)
				{
				case 1:
					stu_id(head);//ѧ�Ų�ѯ
					break;
				case 2:
					stu_name(head);
					break;
				case 3:
					print(head);//��ѯȫ��
					break;
				default:
					break;
				}	
					break;
				case 5:				//�޸���������
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
	printf("������������������������\n");
	printf("�������student management1.1�������\n");
	printf("������������������������\n\n");
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

int see()
{
	int see;
	printf("\n");
	printf("���ששששששששששששששששששש�\n");
	printf("��       1.ͨ��ѧ�Ų鿴ѧ����Ϣ         ��\n");
	printf("��       2.ͨ�������鿴ѧ����Ϣ         ��\n");
	printf("��       3.�鿴����ѧ����Ϣ             ��\n");
	printf("��       4.��                ��         ��\n");
	printf("���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ�\n\n");
	printf("������1-4������Ĳ���: ");
	scanf("%d",&see);
	return see;

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
			printf("�����������������: ");
			scanf("%s",&pwd_1);
			system("cls");
			if(strcmp(pwd,pwd_1) == 0)
			{
				printf("������ȷ!");
				system("cls");
				break;
			}
			else
			{
				printf("�������!����������!");
				system("cls");
			}
			fclose(fp);
		}
		else							//���������,��д,����
		{
			while(1)
			{
				printf("��������������: ");
				scanf("%s",&pwd_1);
				system("cls");
				printf("���ٴ�ȷ����������: ");
				scanf("%s",&pwd_2);
				system("cls");
				if(strcmp(pwd_1,pwd_2) == 0)
				{
					fp = fopen(userspwd,"w");
					fprintf(fp,"%s",pwd_1);
					printf("�������óɹ�!");
					system("cls");
					fclose(fp);
					break;
				}
				else
				{
					printf("�������벻һ��!����������!");
					system("cls");
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
			printf("�����������������: ");
			scanf("%s",&pwd_pwd);
			system("cls");
			if(strcmp(pwd,pwd_pwd) == 0)
			{
				printf("������ȷ!");
				system("cls");
				if((fp = fopen(userspwd,"w")) != NULL)
				{
					while(1)
					{
						printf("��������������: ");
						scanf("%s",&pwd_1);
						system("cls");
						printf("���ٴ�ȷ����������: ");
						scanf("%s",&pwd_2);
						system("cls");
						if(strcmp(pwd_1,pwd_2) == 0)
						{
							fp = fopen(userspwd,"w");
							fprintf(fp,"%s",pwd_1);
							printf("�������óɹ�!");
							system("cls");
							fclose(fp);
							break;
						}
						else
						{
							printf("�������벻һ��!����������!");
							system("cls");
						}
					}
				}
				break;
			}
			else
			{
				printf("\n�������!����������!\n\n");
				system("cls");
			}
			fclose(fp);
		}
	}
}



struct student *creat() //��������
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

struct student *bubblesort(struct student *head) //ѧ��ð������
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

struct student *insert(struct student *head,struct student *p)     //��������
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
	printf("�������!(ѧ�Ų����ظ�!)\n");
	printf("�����²���!\n");
  }
  else if(p2!=NULL)
  {
	  p1->next=p;
      p->next=p2;
	  printf("������!\n");
  }
  else if(p2==NULL)
  {
	  p1->next=p;
	  p->next=NULL;
	  printf("������!\n");
  }
	return head;
}


struct student *stu_id(struct student *head)//ͨ��ѧ������ѧ����Ϣ
{
	char id[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("����Ϊ��\n");
		return head;
	}
	p1 = head;
	printf("��������Ҫ�鿴��ѧ����ѧ��: ");
	scanf("%s",&id);
	while((strcmp(p1->id,id) != 0) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(strcmp(p1->id,id) == 0)
	{
	printf("\nѧ��\t����\t�Ա�\t����\n");
	printf("%s\t%s\t%s\t%d\n",p1->id,p1->name,p1->sex,p1->age);
	free(p1);
	p1 = NULL;
	}
	else
	{
		printf("\n��Ǹ,ѧ����Ϣû���ҵ�!");
	}
	return head;
}


struct student *stu_name(struct student *head)//ͨ����������ѧ����Ϣ
{
	char name[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("����Ϊ��\n");
		return head;
	}
	p1 = head;
	printf("��������Ҫ�鿴��ѧ��������: ");
	scanf("%s",&name);
	while((strcmp(p1->name,name) != 0) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(strcmp(p1->name,name) == 0)
	{
	printf("\nѧ��\t����\t�Ա�\t����\n");
	printf("%s\t%s\t%s\t%d\n",p1->id,p1->name,p1->sex,p1->age);
	free(p1);
	p1 = NULL;
	}
	else
	{
		printf("\n��Ǹ,ѧ����Ϣû���ҵ�!");
	}
	return head;
}

struct student *amend_stu_1(struct student *head)
{
	char id[20];
	struct student *p1,*p2;
	
	if(head == NULL)
	{
		printf("����Ϊ��\n");
		return head;
	}
	p1 = head;
	printf("��������Ҫ�޸ĵ�ѧ����ѧ��: ");
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
		printf("\n��Ǹ,ѧ����Ϣû���ҵ�!");
	}
	return head;
}


struct student *amend_stu_2(struct student *head,struct student *p)     //��������
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
	printf("�������!(ѧ�Ų����ظ�!)");
	printf("�����²���!");
  }
  else if(p2!=NULL)
  {
	  p1->next=p;
      p->next=p2;
	  printf("�޸����!");
  }
  else if(p2==NULL)
  {
	  p1->next=p;
	  p->next=NULL;
	  printf("�޸����!");
  }
	return head;
}

