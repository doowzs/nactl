/**
 * Author: Simon Lindholm
 * Date: 2015-02-11
 * License: CC0
 * Source: Wikipedia
 * Description: 利用辛普森法则计算指定区间上的函数积分。
 * 误差与$h^4$成正比，在实际使用中最好验证答案与需要的精度相吻合。
 * Status: mostly untested
 */
#pragma once

double quad(double (*f)(double), double a, double b) {
	const int n = 1000;
	double h = (b - a) / 2 / n;
	double v = f(a) + f(b);
	rep(i,1,n*2)
		v += f(a + i*h) * (i&1 ? 4 : 2);
	return v * h / 3;
}
