#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"

#define LEN sizeof(struct student)

struct student *creat();

int menu();
int n;

struct student
{
	int id;//ѧ��ѧ��
	char name[20];//ѧ������
	char sex;//ѧ���Ա�
	int age;//ѧ������
	struct student *next;//ָ����һ����ַ
	
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
		case 1://¼��ѧ����Ϣ
			stu =creat();
			break;
		case 2://ɾ��ѧ����Ϣ
			
			break;
		case 3:
			
			break;
		case 4:
			break;
		case 5:
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
}

struct student *creat()
{
	int i=0,len;
	struct student *head;//ͷָ��
	struct student *p1,*p2;//�����½ڵ�
	p1= p2 = (struct student *)malloc(LEN);
	
	printf("����ѧ��: ");
	scanf("%d",&p1->id);
	printf("��������: ");
	scanf("%s",&p1->name);
	printf("�����Ա�: ");
	scanf("%s",&p1->sex);
	printf("��������: ");
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
		printf("����ѧ��: ");
		scanf("%d",&p1->id);
		printf("��������: ");
		scanf("%s",&p1->name);
		printf("�����Ա�: ");
		scanf("%s",&p1->sex);
		printf("��������: ");
		scanf("%d",&p1->age);
	}
	p2->next = NULL;
	return head;
}