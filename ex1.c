// Yarin Rahamim 205833668
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();

/* Declarations of other functions */

int sumDigit(int n);
void resOfFun(int n);
void minMaxSum(int n);
int sumRightLeft(int n);
void completeFun(int n);
double sumS(double x, int n);

/* ------------------------------- */
// no need to change the main function for matala 1.
// 
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 6; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 6));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

void Ex1()
{
	int n;
	printf("Enter a natural number: ");
	scanf("%d", &n);
	printf("The sum of digit Even - Odd is: %d\n", sumDigit(n));
}
int sumDigit(int n)
{
	int sumEven = 0;
	int sumOdd = 0;
	int res = 0;
	if (n <= 0)
		return 0;
	else
	{
		while (n > 0)
		{
			if ((n % 10) % 2 == 0)
			{
				sumEven += n % 10;
			}
			else
			{
				sumOdd += n % 10;
			}
			n /= 10;
		}
	}
	res = sumEven - sumOdd;
	return res;
 }

void Ex2() 
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	resOfFun(n);
}
void resOfFun(int n)
{
	int x, y, tmp;
	tmp = n;
	if (n % 14 == 0)
	{
		x = 0; 
		y = n / 7; 
		
		while (y >= 0)
		{
			printf("(%d , %d)\n", x, y); 
			x += 7; 
			y -= 2;	
		}
	}
	else
	{
		printf("Err Enter antoher number!\n");
	}
}

void Ex3() 
{
	int n;
	printf("Please enter natural number bigger or equal to 5: \n");
	scanf("%d", &n);
	minMaxSum(n);
}
void minMaxSum(int n)
{

	int n1, i, max, min, sum;
	sum = 0;
	printf("Enter a natural number: \n");
	scanf("%d", &n1);
	if (n1 < 0)
	{
		printf("***Enter legal number***\n");
		printf("Enter a number: \n");
		scanf("%d", &n1);
	}
		sum = min = max = n1;
		for (i = 1; i < n; i++)
		{
			printf("Enter a number: \n");
			scanf("%d", &n1);
			if (n1 < 0)
			{
				printf("***Enter legal number***\n");
				printf("Enter a number: \n");
				scanf("%d", &n1);
			}
				if (n1 >= max)
				{
					max = n1;
				}
				if (n1 <= min)
				{
					min = n1;
				}
				sum += n1;
		}
		
	printf("The sum is: %d, The max is: %d, The min is: %d\n", sum, max, min);
}

void Ex4() 
{
	int n;
	printf("Please enter a number: \n");
	scanf("%d", &n);
	int res = sumRightLeft(n);
	printf("The result is: %d\n", res);
}
int sumRightLeft(int n)
{
	int sumRight, sumLeft, sumTotal,tmp;
	tmp = n;
	if (n < 1000 || n > 9999)
	{
		return 0;
	}
	else
	{
			sumRight = tmp % 100;
			sumLeft = tmp / 100;
			sumTotal = sumRight + sumLeft;
			if (sumTotal*sumTotal == n)
			{
				return sumTotal;
			}
			else
			{
				return 0;
			}
	}
}

void Ex5()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	completeFun(n);
}
void completeFun(int n)
{
	int digit;
	int fixNum = 0;
	int mult = 1;
	
	while(n > 0)
	{
		digit = n % 10;
		if (digit == 9)
		{
			digit = 9;
		}
		else
		{
			digit = 8 - digit;
		}
		fixNum = fixNum + mult * digit; 
		mult *= 10;
		n /= 10;
	}
	printf("The fix num is: %d\n", fixNum);
}

void Ex6()
{
	double x;
	printf("Enter a number 'x': \n");
	scanf("%lf", &x);

	int n;
	printf("Enter a number 'n': \n");
	scanf("%d", &n);

	double res;
	res = sumS(x, n);
	printf("%lf\n", res);
}
double sumS(double x, int n)
{
	if (n < 0)
	{
		printf("Err! Enter vaild number\n");
		return 0;
	}
	else
	{
		double last = (x - 1), sum = (x - 1);
		int i;
		for (i = 1; i <= n; i++)
		{
			last *= ((x - 1)*(x - 1)) / (((2 * i)*(2 * i + 1))*(i + 1)); // (x-1) * (x-1)^2 : (2*i)(2*i+1)(i+1) --> n=1 --> (x-1)^3 : 3!*2
			sum += last;
		}
		return sum;
	}
}