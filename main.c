#include"stdio.h"

void menu();

void main()
{
	
	double a,b,zhi;
	char suan,deng;
	menu();
	
	while(1)
	{	
		printf("\n");
		scanf("%lf",&a);
		scanf("%c",&suan);
		scanf("%lf",&b);	
			switch(suan)
			{
			case '+':
				zhi=a+b;
				printf("���Ľ��Ϊ��%lf\n",zhi);
				break;
			case '-':
				zhi=a-b;
				printf("���Ľ��Ϊ��%lf\n",zhi);
				break;
			case '*':
				zhi=a*b;
				printf("���Ľ��Ϊ��%lf\n",zhi);
				break;
			case '/':
				zhi=a/b;
				printf("���Ľ��Ϊ��%lf\n",zhi);
				break;
			}
			
	}

}


void menu()
{
	printf("*******************Calculator To Welcome You*******************\n\n");
	printf("-->�˼�����Ŀǰֻ֧�����������ݵļӼ��˳�\n");
	
	printf("-->��ʽ�� 1+1  Ȼ�󰴻س�\n");
}