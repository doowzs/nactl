/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-17
 * License: CC0
 * Source: Numeriska algoritmer med matlab, Gerd Eriksson, NADA, KTH
 * Description: 找到在区间$[a,b]$中使得函数$f$取最小值的横坐标。返回值与正确答案的误差不超过eps。要求该函数在区间上有且仅有一个最小值。在various一节中的三分搜索(Ternary Search)中有离散化的版本。
 * Status: tested
 * Usage:
	double func(double x) { return 4+x+.3*x*x; }
	double xmin = gss(-1000,1000,func);
 * Time: O(\log((b-a) / \epsilon))
 */
#pragma once

/// r 必须为精确值，否则无法保证 a < x1 < x2 < b。
double gss(double a, double b, double (*f)(double)) {
	double r = (sqrt(5)-1)/2, eps = 1e-7;
	double x1 = b - r*(b-a), x2 = a + r*(b-a);
	double f1 = f(x1), f2 = f(x2);
	while (b-a > eps)
		if (f1 < f2) { //如果要寻找最大值，改为>
			b = x2; x2 = x1; f2 = f1;
			x1 = b - r*(b-a); f1 = f(x1);
		} else {
			a = x1; x1 = x2; f1 = f2;
			x2 = a + r*(b-a); f2 = f(x2);
		}
	return a;
}
