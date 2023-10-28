#ifndef NEWSTRING_H
#define NEWSTRING_H
#include <iostream>
#include "AbstractVector.h"
#include <string.h>
using namespace std;

class NewString: public AbstractVector<char>
{
public:
    NewString(const size_t SIZE = 0, const char* temp = NULL): AbstractVector<char>(SIZE, temp){} //转换构造函数
    NewString(const char* temp);
    NewString(const NewString& temp);     //拷贝构造函数

    NewString substr(const unsigned int& start, const unsigned int& len) const; //返回子串
    int Find(const char* str, bool newsearch) const;  //查找子串，newsearch==true代表从头开始新搜索
    NewString operator+(const NewString& str) const;  //连接
	NewString& operator+=(const NewString& str);  //连接自加
    NewString operator*(const unsigned int times) const;  //重复
	bool operator<(const NewString& str) const;	 //按字典序比较			
	bool operator<=(const NewString& str) const;
	bool operator>(const NewString& str) const;
	bool operator>=(const NewString& str) const;
	bool operator==(const NewString& str)const;
	bool operator!=(const NewString& str)const;

    void putout(ostream& out) const;  //完成输入输出虚函数重载
    void putin(istream& in);
};

NewString::NewString(const char* temp)
{
    if(temp==NULL)  //判断是否为空
    {
        size = 0;
        head=NULL;
        return;
    }

    size = strlen(temp);
    head = new char[size+1];
    strcpy(head, temp);
}

NewString::NewString(const NewString& temp)  //拷贝构造函数
{
    *this = temp;
}

void NewString::putout(ostream& out) const  //输出，借用基类重载<<
{
    out << head;
}

void NewString::putin(istream& in)  //输入，借用基类重载>>
{
    size = 0;
    if(head!=NULL)   //先删除，后复制
    {
        delete[] head;
    }

    char temp[1024];
    in >> temp;

    size = strlen(temp);
    head = new char[size+1];
    strcpy(head, temp);
}

NewString NewString::operator+(const NewString& str) const
{
    if(str.empty())
    {
        return *this;
    }

    char* temp = new char[size + str.size + 1];
    strcpy(temp, head);
    strcat(temp, str.head);
    NewString ans(temp);
    return ans;
}

NewString& NewString::operator+=(const NewString& str) //连接
{
    *this = *this + str;
    return *this;
}

bool NewString::operator<(const NewString& str) const	 //按字典序比较
{
    if(strcmp(head, str.head) < 0)
    {
        return true;
    }
    return false;
}

bool NewString::operator>(const NewString& str) const
{
    if(strcmp(head, str.head) > 0)
    {
        return true;
    }
    return false;
}

bool NewString::operator>=(const NewString& str) const
{
    if(strcmp(head, str.head) >= 0)
    {
        return true;
    }
    return false;
}

bool NewString::operator<=(const NewString& str) const
{
    if(strcmp(head, str.head) <= 0)
    {
        return true;
    }
    return false;
}

bool NewString::operator==(const NewString& str) const
{
    if(strcmp(head, str.head) == 0)
    {
        return true;
    }
    return false;
}

bool NewString::operator!=(const NewString& str) const
{
    if(strcmp(head, str.head) != 0)
    {
        return true;
    }
    return false;
}

NewString NewString::operator*(const unsigned int times) const   //重复
{
    if(times == 0)
    {
        return NewString("");
    }

    NewString temp(*this);
    for(int i = 1; i < times; i++)
    {
        temp += *this;
    }
    return temp;
}

NewString NewString::substr(const unsigned int& start, const unsigned int& len) const  //取子串
{
    try
    {
        if(start+len >= size) throw -1;

        char* temp = new char[len+1];
        for(int i = start; i < start+len; i++)
        {
            temp[i-start] = head[i];
        }
        temp[len] = '\0';
        return NewString(temp);
    }
    catch(const int& e)
    {
        cerr << "下标越界" << endl;
    }
    return NewString("");
}

int NewString::Find(const char* str, bool newsearch) const
{
    if(str == NULL || strlen(str)==0)
    {
        return -1;
    }

    static int sooner = 0;
    int lower = 0;
    int len = strlen(str);
	if(newsearch)
	{
		sooner = 0;
	}

    int sum = len;
    for(;sooner < size; sooner++)
    {
        if(head[sooner] == str[lower])
        {
            lower++;
            sum--;
            if(sum == 0)
            {
                break;
            }
        }
        else
        {
            lower = 0;
            sum = len;
        }
    }
    
    if(sooner < size)
    {
        sooner++;
        return sooner-len;
    }
    else
    {
        return -1;
    }
}

#endif