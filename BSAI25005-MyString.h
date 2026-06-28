#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class MyString
{
	char* Cs;
	int size;
public:
	class Iterator {
		char* ptr;
	public:
		Iterator(char* p)
		{
			ptr = p;
		}
		char& get()
		{
			return *ptr;
		}
		void next()
		{
			ptr++;
		}
		void prev()
		{
			ptr--;
		}
		bool equals(const Iterator&
			other)
		{
			return ptr == other.ptr;
		}
		bool notEquals(const Iterator&
			other)
		{
			return ptr != other.ptr;
		}
		void advance(int n)
		{
			ptr += n;
		}
		int distanceTo(const Iterator&
			other)
		{
			return other.ptr - ptr;
		}
	};
	Iterator begin()
	{
		return Iterator(Cs);
	}
	Iterator end()
	{
		return Iterator(Cs + size);
	}
	MyString SubstrIter(Iterator
		start, Iterator end);
	void InsertAt(Iterator pos, const
		MyString& str);
	void EraseRange(Iterator start,
		Iterator end);
	Iterator Find(char c);
	Iterator FindFrom(Iterator start,
		char c);
	MyString();
	MyString(char c);
	MyString(int n, char c);
	MyString(int num);
	MyString(ifstream& rdr);
	MyString(const	MyString& other);
	MyString(const char* p);
	~MyString();
	int getsize(const char* p)const;
	void readfromfile(ifstream& rdr);
	void print()const;
	int Length() const;
	char CharacterAt(int i) const;
	void ReplaceAt(int i, char c);
	void ReplaceFirst(char c);
	void ShallowCopy(const MyString& a);
	int stoi() const;
	MyString itos(int num);
	MyString Trim() const;
	MyString ToUpper() const;
	MyString ToLower() const;
	void Copy(const MyString& other);
	void Clear();
	MyString Reverse() const;
	bool IsEqual(const MyString& M) const;
	bool IsLess(const MyString& M) const;
	bool IsGreater(const MyString& M) const;
	MyString Substring(int start, int len) const;
	int IndexOf(char c) const;
	int LastIndexOf(char c) const;
	bool Contains(const char* substr) const;
	MyString Concat(const MyString& other) const;
	MyString Replace(const char* old, const char* newStr) const;
	const char* c_str() const;
};