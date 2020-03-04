#include "TextFileReader.h"
#include "sstream"

void TextFileReader::setMatrixFilePath(string path)
{
	this->matrixPath = path;
}

void TextFileReader::setDimensionFilePath(string path)
{
	this->dimensionPath = path;
}

bool TextFileReader::readText()
{
	ifstream matrixFile;//for opening matrix file
	ifstream dimensionFile;//for opening dimension file
	dimensionFile.open(dimensionPath);//open file
	if (!dimensionFile.is_open())//checks if file is open or not
		return false;

	string temp;
	int inttemp;
	while (getline(dimensionFile, temp, ' '))
	{
		inttemp = stoi(temp);//converting to int from string
		dimensionList.push_back({ inttemp });//pusing int data into vector
	}
	dimensionSize = dimensionList.size();//assigns the dimension size for future reference
	dimensionFile.close();//close the file

	matrixFile.open(matrixPath);//open matrix file
	if (!matrixFile.is_open())//checks if file is open or not
		return false;
	vector<string>dataList;//datalist is used to store each matrix as a string
	while (matrixFile.good())
	{
		string data;
		getline(matrixFile, data);
		dataList.push_back({ data });
	}
	matrixFile.close();//close file

	int a, b;//a,b are used to stores the dimensions of a matrix

	/*
	Each matrix is read from the vector dataList and create new matrices and
	finally store the link of all the matrices in an array
	*/
	for (int p = 0; p < dataList.size(); p++)//scrolls through the matrices
	{
		a=dimensionList[p];//assining the row dimension of the matrix.
		b=dimensionList[p+1];//assining the column dimension of the matrix.

		//creating a new dynamic matrix of dimension a*b to store the data
		int **tmpMatrix = new int*[b];
		for (int i = 0; i < b; ++i)
			tmpMatrix[i] = new int[a];

		stringstream ss(dataList[p]);//moving the matrix from vector dataList to stream so that space can be delimited
		int i = 0;
		int j = 0;
		while (getline(ss, temp, ' '))
		{
			if (j >= b)//j represents the columns so when it reaches the end, it resets itself and goes to the next row.
			{
				j = 0;
				i++;
			}
			tmpMatrix[i][j] = stoi(temp);//temp is converted from string to int and stored in the matrix
			j++;			
		}
		this->matrixList[p] = tmpMatrix;//stores pointer to newly created matrix (tmpMatrix) in the matrixList
	}
	return true;
}
