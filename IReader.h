#pragma once
#include<string>
/*
class IReader is an abstract class which can be inherited by classes that are meant to take matrix input from different sources
*/
class IReader
{
public:
			//Set the path containing all the matrices
	virtual void setMatrixFilePath(std::string path)=0;
			//read all the files in location specified above. It returns false if reading was unsuccessful.
	virtual bool readText()=0;
};

