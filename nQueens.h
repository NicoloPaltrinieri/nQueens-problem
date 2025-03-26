#pragma once

#include<stdlib.h>
#include<stdio.h>

struct matrix {
	int rows;
	int cols;
	int* data;
}typedef mat;

extern void nQueens(int l);
