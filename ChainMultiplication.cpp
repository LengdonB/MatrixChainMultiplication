#include "ChainMultiplication.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int ** ChainMultiplication::findChainOrder(vector<int> dimensions)
{
	{
		this->dimensionList = dimensions;
		int n = dimensions.size();
		if (n <= 1)//if n=1 so only one element so there will be no multiplication,if n=0 then wrong entry is done.
		{
			return nullptr;
		}

		//matrix to store the cost of multiplication
		int **cost = new int*[n];
		for (int i = 0; i < n; i++)
			cost[i] = new int[n];

		//matrix to store matrix multiplication chain order		 
		int **chainSequence = new int*[n];
		for (int i = 0; i < n; i++)
			chainSequence[i] = new int[n];

		//setting diagonal elements of matrix as 0 cost.
		for (int i = 0; i < n; i++)
		{
			cost[i][i] = 0;
			chainSequence[i][i] = 0;
		}

		int j,minimum,q;//j is column no.,minimum is used to find the minimum cost of multiplication, q used for storing temporarily the cost of a multiplication sequence.
		for (int d = 1; d < n-1; d++)
		{			
			for (int i = 1; i < n-d; i++)//i is row of matrix
			{
				j = i + d;
				/*
				Calculation of minimum cost of multiplying different sequences of multiplication. One of the case is considered minimum by
				default then it is compared with other cases inside a for loop to see if a better multiplication sequence can be found.
				*/
				q = cost[i][i] + cost[i + 1][j] + dimensions[i - 1] * dimensions[i] * dimensions[j];
					minimum = q;
					chainSequence[i][j] = i;
				
				for (int k = i+1; k <=j-1; k++)// considers the different combinations of multiplication
				{
					q = cost[i][k] + cost[k+ 1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];
					if (q < minimum)
					{
						minimum = q;						
						chainSequence[i][j] = k;
					}
				}
				cost[i][j] = minimum;
			}
		}

		//deallocating memory
		for (int i = 0; i < n; i++)
			delete[] cost[i];
		delete[] cost;

		return chainSequence;
	}
}

int ** ChainMultiplication::multiplyIterative(int ** matrix1, int ** matrix2, int dim1, int dim2, int dim3)
{
	//creating resulting matrix
	int**result = new int*[dim3];
	for (int i = 0; i < dim3; ++i)
		result[i] = new int[dim1];

	//initializing result matrix to 0
	for (int i = 0; i < dim1; i++)
		for (int j = 0; j < dim3; j++)
		{
			result[i][j] = 0;
		}
	//multiplication
	for (int i = 0; i < dim1; ++i)
		for (int j = 0; j < dim3; ++j)
			for (int k = 0; k < dim2; ++k)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
	return result;
}

int ** ChainMultiplication::multiplyChain(int *** matrix, int ** chainTable, int i, int j)
{
	if (i < j)
	{
		int** X = multiplyChain(matrix, chainTable, i, chainTable[i][j]);
		int** Y = multiplyChain(matrix, chainTable, chainTable[i][j] + 1, j);
		return multiplyIterative(X, Y, dimensionList[i - 1], dimensionList[chainTable[i][j]], dimensionList[j]);
	}
	else
	{
		return matrix[i - 1];
	}
}
