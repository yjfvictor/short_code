/**
 * @file   gcd.c
 * @brief  最大公约数
 * @author 叶剑飞
 * @date   2014-11-30
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 求两个数的最大公约数
 * @param[in] m  第一个数
 * @param[in] n  第二个数
 * @return 最大公约数
 */
int gcd(int m, int n)
{
	int r;
	do
	{
		r = m % n;
		m = n;
		n = r;
	} while (r != 0);
	return m;
}

/**
 * @brief  主函数
 * @return 成功返回EXIT_SUCCESS
 */
int main(void)
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
		printf("%d\n", gcd(m, n));
	return EXIT_SUCCESS;
}
