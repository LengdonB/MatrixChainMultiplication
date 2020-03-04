#pragma once
#include"IReader.h"
#include<iostream>
#include <string>
#include<vector>
#include<fstream>
using namespace std;
/*
class TextFileReader contains all the methods required to read matrices from a text file and stores it as an array.
*/
class TextFileReader: public IReader
{
public:
		//Reads the text file where data of all the matrices are present.
	bool readText();
		//An array containing pointer to all the matrices to be multiplied.
	int ***matrixList = new int**[20];
		//sets the path of the text file where matrix is stored.
	void setMatrixFilePath(string path);
	void setDimensionFilePath(string path);
		//contains the dimensions of the matrices
	vector<int>dimensionList;//stores the dimensions

private:	
	int dimensionSize = 0;//stores the number of dimensions present
	string matrixPath= "d:/mymatrix.txt";//path of the file with the matrix
	string dimensionPath="d:/dimensions.txt";//path of the file with dimensions	
};

