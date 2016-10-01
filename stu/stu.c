#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"

#define LEN sizeof(struct student)			//ʵ�ִ���ļ�д

struct student *creat();					//������������ĺ���
void print(struct student *head);			//�����������ĺ���

int menu();									//�������溯��
int n=1;									//�ӵ�һ��ѧ����ʼ,ѧ������ͳ��,����ѭ�����

struct student								//����ѧ����Ϣ��һ�ṹ��
{
	char id[20];							//ѧ��ѧ��
	char name[20];							//ѧ������
	char sex[10];							//ѧ���Ա�
	int age;								//ѧ������
	struct student *next;					//ָ����һ��ѧ����Ϣ
	
};

void main()
{
	int number;				//�����Ӧ�Ĺ���ѡ����
	
	struct student *stu;	//����*stu,����ָ�򴴽�������
	
	while(1)
	{
		
		menu();
		scanf("%d",&number);
		switch(number)
		{
		case 1:				//¼��ѧ����Ϣ
			stu =creat();
			
			break;
		case 2:				//ɾ��ѧ����Ϣ
			
			break;
		case 3:
			
			break;
		case 4:				//��ѯѧ����Ϣ
			print(stu);
			break;
		case 5:				//�˳�
			exit(0);
			break;
		default:
			printf("���ڿ���!\n");
			break;
			
		}
	}	
}

int menu()
{
	printf("������������---ѧ������ϵͳ---������������\n\n");
	printf("  �x�y�z�{�| 1.����ѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 2.ɾ��ѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 3.�޸�ѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 4.��ѯѧ����Ϣ �|�{�z�y�x\n");
	printf("  �x�y�z�{�| 5.�˳�         �|�{�z�y�x\n\n");
	
	printf("������1-5������Ĳ���: ");
	return 0;
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
	p2->next = NULL;
	//	free(p1);
	//	p1 = NULL;
	return head;
}
void print(struct student *head)
{	
	struct student *p;
	printf("\nĿǰ���ݿ��ﹲ��%d��ѧ������Ϣ:\n",n-1);
	p=head;
	if(head!=NULL)
	{
		
		printf("\tѧ��\t����\t�Ա�\t����\n");
		while(p!=NULL)
		{
			
			printf("\t%s\t%s\t%s\t%d\n",p->id,p->name,p->sex,p->age);
			p=p->next;
		}
	}
	printf("\n\n");
}