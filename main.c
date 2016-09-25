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
				printf("您的结果为：%lf\n",zhi);
				break;
			case '-':
				zhi=a-b;
				printf("您的结果为：%lf\n",zhi);
				break;
			case '*':
				zhi=a*b;
				printf("您的结果为：%lf\n",zhi);
				break;
			case '/':
				zhi=a/b;
				printf("您的结果为：%lf\n",zhi);
				break;
			}
			
	}

}


void menu()
{
	printf("*******************Calculator To Welcome You*******************\n\n");
	printf("-->此计算器目前只支持两个简单数据的加减乘除\n");
	
	printf("-->格式： 1+1  然后按回车\n");
}