#include<stdio.h>
#include<stdlib.h>

int odd(int x);
int even(int x);
int total(int x);

int odd(int x)
{
	int i, t = 0;
	for (i = 1; i <= x; i++)
		if (i % 2 == 1) t = t + i;
	return t;
}
int even(int x)
{
	int i, t = 0;
	for (i = 1; i <= x; i++)
		if (i % 2 == 0) t = t + i;
	return t;
}
int total(int x)
{
	return odd(x) + even(x);
}

int main(void)
{
	int n, s;
	char ch;
	printf("1+2+3+4+...+n=?\n請輸入n=");
	scanf_s("%d", &n);
	printf("\n奇數和(O)，偶數和(E)，整數和(I)\n請選擇：");
	scanf_s(" %c", &ch);

	switch (ch)
	{
	case 'O':
		s = odd(n);
		break;
	case 'E':
		s = even(n);
		break;
	case'I':
		s = total(n);
		break;
	default:
		printf("選擇錯誤\n");
		return -1;
	}
	printf("總合為%d\n", s);
	system("pause");
	return 0;
}