#pragma once
#ifndef NEWVECTOR_H
#define NEWVECTOR_H
#include<iostream>
#include"AbstractVector.h"
using namespace std;

template <typename T>
class NewVector :public AbstractVector<T>
{
public:
	NewVector(const unsigned int size = 0, const T* x = NULL);//转换构造
	NewVector(const NewVector<T>& v);   //派生类深拷贝

	NewVector<T> operator+(const NewVector<T>& v);
	NewVector<T> operator+=(const NewVector<T>& v);
	void push_back(const T val);//在尾部插入元素
	void pop_back();//弹出尾部元素
	T back();//返回尾部元素

	void putout(ostream& out)const;//以（X1，X2，...,Xn）的形式输出
	void putin(istream& in);//以（X1，X2，...,Xn）的形式输入
};
template <typename T>
NewVector<T>::NewVector(const unsigned int size,const T* x) : AbstractVector<T>(size, x) {};

template <typename T>
NewVector<T>::NewVector(const NewVector<T>& v):AbstractVector<T>(v){}

template <typename T>
NewVector<T> NewVector<T>::operator+(const NewVector<T>& v)
{
	NewVector<T> temp(*this);
	try 
	{
		if (this->size != v.size)
		{
			throw 1;
		}
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				temp.head[i] += v.head[i];
			}
		}
	}
	catch (int e)
	{
		cout << "不同维数不能相加" << endl;
	}
	return temp;
}

template <typename T>
NewVector<T> NewVector<T>::operator+=(const NewVector<T>& v)
{
	try
	{
		if (this->size != v.size)
		{
			throw 1;
		}
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				this->head[i] += v.head[i];
			}
			return *this;
		}
	}
	catch (int e)
	{
		cout << "不同维数不能相加" << endl;
		return NewVector<T>();
	}
}

template <typename T>
void NewVector<T>::push_back(const T v)
{
	this->resize(this->size + 1);
	this->head[this->size - 1] = v;
}

template <typename T>
void NewVector<T>::pop_back()
{
	NewVector<T> temp(*this);
	try {
		if (temp.size == 0) throw - 1;

	}
	catch (int e) {
		cout << "下标越界" << endl;
		return;
	}
	delete[]this->head;
	this->head = new T[temp.size - 1];
	this->size = temp.size - 1;
	for (int i = 0; i < temp.size - 1; i++)
	{
		this->head[i] = temp[i];
	}
}

template <typename T>
T NewVector<T>::back() {
	try {
		if (this->size == 0) throw - 1;
		else return this->head[this->size - 1];
	}
	catch (int e) {
		cerr << "\nerror:无元素，无法返回最后一个元素\n";
	}
}

template<class T>
void NewVector<T>::putout(ostream& out) const {
	out << "(";
	if (this->size == 0) {
		out << ")";
		return;
	}
	for (int i = 0; i < this->size - 1; i++) {
		out << this->head[i] << ",";
	}
	out << this->head[this->size - 1] << ")";
	return;
}

template<class T>
void NewVector<T>::putin(istream& in) {
	const int M = 1024, N = 1;//1024;	// N取最小值1是为了调试，实际使用时取1024
	NewVector<T> temp;
	char str[M], ch;				// ch初始化为一个非')'字符即可
	T buffer[N];
	int i, j, k;

	in.getline(str, M, '(');		// 过滤掉'('及之前的所有字符
	while (true)						// 过滤掉左圆括号之后的空白字符
	{
		ch = in.peek();				// 偷看下一个字符，看是否为空白字符
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
			in.get(ch);				// 若是空白字符，则过滤掉（即读取后不用）
		else
			break;					// 直到遇到非空白字符，结束本while循环
	}

	if (in.peek() == ')')				// 偷看下一个字符，若是')'
	{
		this->resize(0);			// 将本对象的维数设置成 0 维
		in.get(ch);					// 读取')'防止向量嵌套时出错
		return;						// 退出本函数，输入为 0 维向量
	}

	for (k = 0; ch != ')'; k++)
	{
		for (i = 0; i < N && ch != ')'; i++)
			in >> buffer[i] >> ch;
		temp.resize(k * N + i);			// 利用了resize函数的"尽量保留了原有数据"的功能
		for (j = 0; j < i; j++)
			temp[k * N + j] = buffer[j];// 利用了方括号运算符
	}
	*this = temp;					// 利用了赋值运算符（深赋值运算）
}





#endif