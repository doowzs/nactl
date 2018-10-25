/**
 * Author: Simon Lindholm
 * Date: 2016-09-06
 * License: CC0
 * Source: me
 * Description: 要求出线性方程的解中所有唯一确定的未知数，对上面的函数做出如下修改。
 * Status: tested on kattis:equationsolverplus
 */
#pragma once

#include "SolveLinear.h"

rep(j,0,n) if (j != i) // 而不是rep(j,i+1,n)
// 在函数的最后：
x.assign(m, undefined);
rep(i,0,rank) {
	rep(j,rank,m) if (fabs(A[i][j]) > eps) goto fail;
	x[col[i]] = b[i] / A[i][i];
fail:; }
