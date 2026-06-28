#pragma once
#include"BSAI25005-MyString.h"
struct Font;
class Document
{
public:
	MyString** lines;
	int nol;
	int cri, cci;
	Document();
	void insertCharacter(char ch);
	void printDocument();
	void printALine();
	void insertNewLine();
	void draw(Font font);
};

