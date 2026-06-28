#include "BSAI25005-Document.h"
#include "raylib.h"
#include <string>
void gotoRowCol(int rpos, int cpos);

void hideConsoleCursor();
void color(int k);

Document::Document()
{
	nol = 1;
	lines = new MyString * [nol] { new MyString};
	cri = 0;
	cci = 0;
}
void Document::insertCharacter(char ch)
{
	MyString temp(ch);  

	MyString::Iterator it = lines[cri]->begin();
	it.advance(cci);

	lines[cri]->InsertAt(it, temp);

	cci++;
}
//void Document::printDocument()
//{
//	system("cls");
//
//	for (int i = 0; i < nol; i++)
//	{
//		lines[i]->print();
//		cout << endl;
//	}
//
//	gotoRowCol(cri, cci);
//}
//void Document::printALine()
//{
//	gotoRowCol(cri, 0);
//	lines[cri]->print();
//	gotoRowCol(cri, cci);
//}
void Document::insertNewLine()
{
	MyString left = lines[cri]->Substring(0, cci);
	MyString right = lines[cri]->Substring(cci, lines[cri]->Length());

	MyString** temp = new MyString * [nol + 1];
	for (int i = 0; i < cri; i++)
		temp[i] = lines[i];
	temp[cri] = new MyString(left);
	temp[cri + 1] = new MyString(right);
	for (int i = cri + 1; i < nol; i++)
		temp[i + 1] = lines[i];
	delete lines[cri];
	delete[] lines;

	lines = temp;
	nol++;

	cri++;  
	cci = 0;
}
void Document::draw(Font font)
{
    float startX = 20;
    float startY = 20;
    float lnw = 60;
    float fontSize = 24;
    float spacing = 2;
    float lineHeight = 35;
    float textStartX = startX + lnw;
    for (int i = 0; i < nol; i++)
    {
        float currentY = startY + (i * lineHeight);
        if (i == cri)
        {
            DrawRectangle(0, (int)currentY, GetScreenWidth(), (int)lineHeight, Fade(GRAY,0.5));
        }
        string ln = to_string(i + 1);
        DrawTextEx(font,ln.c_str(),{ startX, currentY },fontSize,spacing,GRAY);
        DrawTextEx(font,lines[i]->c_str(),{ textStartX, currentY },  fontSize, spacing, WHITE);
        if (i == cri)
        {
            MyString prefix = lines[i]->Substring(0, cci);
            Vector2 size = MeasureTextEx(font,prefix.c_str(),fontSize,  spacing);
            float cursorX = textStartX + size.x;
            float cursorY = currentY;
            static float timer = 0;
            timer += GetFrameTime();

            if ((int)(timer * 2) % 2 == 0)
            {
                DrawRectangle((int)cursorX, (int)cursorY, 2,(int)fontSize,SKYBLUE);
            }
        }
    }
}