#include "BSAI25005-MyString.h"
#include<iostream>
#include<fstream>
using namespace std;
MyString::MyString()
{
	size = 0;
	Cs = new char[1];
	Cs[0] = '\0';
}
MyString::MyString(char c)
{
	size = 1;
	Cs = new char[size + 1];
	Cs[0] = c;
	Cs[1] = '\0';
}
MyString::MyString(int n, char c)
{
	size = n;
	Cs = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		Cs[i] = c;
	}
	Cs[size] = '\0';
}
MyString::MyString(int num)
{
	MyString temp = itos(num);
	Copy(temp);
}

int MyString::getsize(const char* p)const
{
	int i = 0;
	while (p[i] != '\0')
	{
		i++;
	}
	return i;
}
MyString::MyString(const char* p)
{
	size = getsize(p);
	Cs = new char[size + 1] {};
	for (int i = 0; i < size; i += 1)
	{
		Cs[i] = p[i];
	}
	Cs[size] = '\0';
}
MyString::MyString(ifstream& rdr)
{
	readfromfile(rdr);
}
MyString::MyString(const MyString& other)
{
	size = other.size;
	Cs = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		Cs[i] = other.Cs[i];
	}
}
void MyString::Copy(const MyString& other)
{
	if (Cs != nullptr)
		delete[] Cs;
	size = other.size;
	Cs = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
		Cs[i] = other.Cs[i];
}
void MyString::readfromfile(ifstream& rdr)
{
	char c[100];
	rdr.getline(c, 100);
	int sc = getsize(c);
	size = sc;
	Cs = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		Cs[i] = c[i];
	}

}
MyString::~MyString()
{
	delete[]Cs;
	Cs = nullptr;
}
void MyString::print()const
{
	for (int i = 0; i < size; i++)
	{
		cout << Cs[i];
	}
}
int MyString::Length() const
{
	return this->size;
}
char MyString::CharacterAt(int i) const
{
	if (i < 0 or i >= size)
	{
		return '\0';
	}
	return Cs[i];

}
void MyString::ReplaceAt(int i, char c)
{
	if (i < 0 or i >= size)
	{
		cout << "Invalid size";
	}
	Cs[i] = c;
}
void MyString::ReplaceFirst(char c)
{
	Cs[0] = c;
}
void MyString::ShallowCopy(const MyString& a)
{
	Cs = a.Cs;
	size = a.size;
}
int MyString::stoi() const
{
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		num = num * 10 + (Cs[i] - '0');
	}
	return num;
}
MyString MyString::itos(int num)
{
	if (num == 0)
		return MyString("0");
	int temp = num, digits = 0;
	while (temp)
	{
		digits++;
		temp /= 10;
	}
	MyString s;
	s.size = digits;
	s.Cs = new char[digits + 1];
	s.Cs[digits] = '\0';
	for (int i = digits - 1; i >= 0; i--)
	{
		s.Cs[i] = (num % 10) + '0';
		num /= 10;
	}
	return s;
}
MyString MyString::Trim() const
{
	if (size == 0)
		return MyString();
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (Cs[i] != ' ' and Cs[i] != '\t' and Cs[i] != '\n')
			count++;
	}
	MyString result;
	result.size = count;
	result.Cs = new char[count + 1];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (Cs[i] != ' ' and Cs[i] != '\t' and Cs[i] != '\n')
		{
			result.Cs[k++] = Cs[i];
		}
	}
	result.Cs[count] = '\0';
	return result;
}


void MyString::Clear()
{
	for (int i = 0; i < size; i++)
	{
		Cs[i] = ' ';
	}
}
MyString MyString::ToUpper() const
{
	MyString other(*this);

	for (int i = 0; i < size; i++)
	{
		if (other.Cs[i] >= 'a' and other.Cs[i] <= 'z')
			other.Cs[i] -= 32;
	}
	return other;
}
MyString MyString::ToLower() const
{
	MyString other(*this);

	for (int i = 0; i < size; i++)
	{
		if (other.Cs[i] >= 'a' && other.Cs[i] <= 'z')
			other.Cs[i] += 32;
	}
	return other;
}
MyString MyString::Reverse() const
{
	MyString result(*this);
	int s = 0;
	int e = size - 1;
	while (s < e)
	{
		swap(result.Cs[s], result.Cs[e]);
		s++;
		e--;
	}

	return result;
}
bool MyString::IsEqual(const MyString& M) const
{
	if (size != M.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (Cs[i] != M.Cs[i])
			return false;
	}
	return true;

}
bool MyString::IsLess(const MyString& M) const {

	int i = 0;
	while (M.Cs[i] and Cs[i])
	{
		if (Cs[i] > M.Cs[i])
			return false;
		if (Cs[i] < M.Cs[i])
			return true;
		i++;
	}
	return size < M.size;
}
bool MyString::IsGreater(const MyString& M)const
{
	if (!IsEqual(M) and !IsLess(M))
		return true;
	else
		return false;
}
int MyString::IndexOf(char c) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->Cs[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int MyString::LastIndexOf(char c) const
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (this->Cs[i] == c)
		{
			return i;
		}
	}
	return -1;
}
bool MyString::Contains(const char* substr) const
{
	if (!Cs or !substr)
		return false;
	int n = getsize(Cs);
	int m = getsize(substr);
	if (m == 0)
		return true;
	for (int i = 0; i <= n - m; i++)
	{
		int j = 0;
		while (j < m and Cs[i + j] == substr[j])
			j++;
		if (j == m)
			return true;
	}
	return false;
}
MyString MyString::Concat(const MyString& other) const
{
	int n1 = getsize(Cs);
	int n2 = getsize(other.Cs);

	char* temp = new char[n1 + n2 + 1];

	int k = 0;

	for (int i = 0; i < n1; i++)
		temp[k++] = Cs[i];

	for (int i = 0; i < n2; i++)
		temp[k++] = other.Cs[i];
	temp[k] = '\0';
	MyString result(temp);
	delete[] temp;
	return result;
}
MyString MyString::Replace(const char* old, const char* newStr) const
{
	int oldLen = getsize(old);
	int newLen = getsize(newStr);
	int n = getsize(Cs);
	if (oldLen == 0)
		return MyString(Cs);
	int count = 0;
	for (int i = 0; i <= n - oldLen; )
	{
		int j = 0;
		while (j < oldLen and Cs[i + j] == old[j])
			j++;

		if (j == oldLen)
		{
			count++;
			i += oldLen;
		}
		else
			i++;
	}
	int newSize = n + count * (newLen - oldLen);
	char* temp = new char[newSize + 1];
	int i = 0, k = 0;
	while (Cs[i] != '\0')
	{
		int j = 0;
		while (j < oldLen and Cs[i + j] == old[j])
			j++;
		if (j == oldLen)
		{
			for (int x = 0; x < newLen; x++)
				temp[k++] = newStr[x];

			i += oldLen;
		}
		else
		{
			temp[k++] = Cs[i++];
		}
	}
	temp[k] = '\0';
	MyString result(temp);
	delete[] temp;
	return result;
}
MyString MyString::Substring(int start, int len) const
{

	if (start < 0 or start >= size or len <= 0)
		return MyString();
	if (start + len > size)
		len = size - start;
	MyString sub;
	sub.size = len;
	sub.Cs = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		sub.Cs[i] = Cs[start + i];
	}
	sub.Cs[len] = '\0';
	return sub;
}

MyString MyString::SubstrIter(Iterator start, Iterator stop)
{
	int len = start.distanceTo(stop);
	MyString result;
	result.size = len;
	result.Cs = new char[len + 1];
	Iterator temp = start;
	for (int i = 0; i < len; i++)
	{
		result.Cs[i] = temp.get();
		temp.next();
	}
	result.Cs[len] = '\0';
	return result;
}
void MyString::InsertAt(Iterator pos, const MyString& str)
{
	int index = begin().distanceTo(pos);
	int newSize = size + str.size;
	char* temp = new char[newSize + 1];
	int k = 0;
	for (int i = 0; i < index; i++)
		temp[k++] = Cs[i];
	for (int i = 0; i < str.size; i++)
		temp[k++] = str.Cs[i];
	for (int i = index; i < size; i++)
		temp[k++] = Cs[i];

	temp[newSize] = '\0';
	delete[] Cs;
	Cs = temp;
	size = newSize;
}
void MyString::EraseRange(Iterator start, Iterator stop)
{
	int si = begin().distanceTo(start);
	int ei = begin().distanceTo(stop);

	int rem = ei - si;
	int newSize = size - rem;
	char* temp = new char[newSize + 1];
	int k = 0;
	for (int i = 0; i < si; i++)
		temp[k++] = Cs[i];
	for (int i = ei; i < size; i++)
		temp[k++] = Cs[i];
	temp[newSize] = '\0';
	delete[] Cs;
	Cs = temp;
	size = newSize;
}
MyString::Iterator MyString::Find(char c)
{
	Iterator it = begin();
	while (it.notEquals(end()))
	{
		if (it.get() == c)
			return it;
		it.next();
	}
	return end();
}
MyString::Iterator MyString::FindFrom(Iterator start, char c)
{
	Iterator it = start;
	while (it.notEquals(end()))
	{
		if (it.get() == c)
			return it;
		it.next();
	}
	return end();
}
const char* MyString::c_str() const
{
	return Cs;
}