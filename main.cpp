#include"ChainMultiplication.h"
#include"TextFileReader.h"
#include<iostream>
using namespace std;
int main()
{
	ChainMultiplication obj;
	TextFileReader obj2;	
	obj2.readText();
	int** chain=obj.findChainOrder(obj2.dimensionList);	
	int ** final=obj.multiplyChain(obj2.matrixList, chain, 1, obj2.dimensionList.size()-1);
	cout << "Matrix is:" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
			cout<<final[i][j]<<"\t";
		cout << endl;
	}
}