#include "NewString.h"
#include "NewVector.h"
#include <iostream>
#include<string>
using namespace std;

void test1() {
	cout << "测试NewString类的运算符函数:--------------------------------------------------------------" << endl;
	cout << "原数据：" << endl;
	NewString a1 = "Object Oriented", a2 = " Programming";
	cout << "a1 = " << a1 << "\na2 = " << a2 <<"\n";
	cout << "测试‘+’运算符:" << endl;
	cout << "a1 + a2 = " << a1 + a2 << endl;
    cout << "测试‘*’运算符:" << endl;
	cout << "a1*3 = " << (a1*3) << endl;
	cout << endl;
	cout << "测试‘+=’运算符：" << endl;
	cout << "a1 = " << a1 << "\na2 = " << a2 << "\n";
	cout << "a1 += a2 \na1 = " << a1 << "\na2 = " << a2 << endl;
	a1 += a2;
	cout << endl;
	NewString b1 = "Object", b2 = " Oriented Analysis";
	cout << "原数据：" << endl;
	cout << "b1=" << b1 << "\nb2=" << b2 << endl;
	cout << "测试‘<’运算符：" << endl;
	cout << "b1<b2=" << boolalpha<<(b1 < b2)<< endl;
	cout << "测试‘<=’运算符：" << endl;
	cout << "b1<=b2="  << (b1 <= b2) << endl;
	cout << "测试‘>’运算符：" << endl;
	cout << "b1>b2="  << (b1 > b2) << endl;
	cout << "测试‘>=’运算符：" << endl;
	cout << "b1>=b2="  << (b1 >= b2) << endl;
	cout << "测试‘==’运算符：" << endl;
	cout << "b1==b2="   << (b1 == b2) << endl;
	cout << "测试‘!=’运算符：" << endl;
	cout << "b1!=b2="  << (b1 != b2) << endl;
	cout << noboolalpha << endl;
	cout << "测试‘[]’运算符：" << endl;
	cout << "b1[0]=" << b1[0] << endl;
	cout << "b1[-1]=" << b1[-1];
	cout << "b1[100]=" << b1[100];
	//cout << (b1 < b2) << endl;
}
void test2() {
	cout << "测试NewString类的'substr()'、'Atoi()'、'Find()'函数:--------------------------------------------------------------" << endl;
	cout << "原数据：" << endl;
	NewString a1 = "-12345612341", a2 = "01234";
	cout << "a1 = " << a1 << "\na2 = " << a2 << "\n";
	cout << "a2.substr(1, 3) = " << a2.substr(1, 3) << endl;
	cout << "a2.substr(1, 10) = " << a2.substr(1, 10) << endl;
	cout << "a2.substr(10, 2) = " << a2.substr(10, 2) << endl;
	cout << "Atoi(a2) = " << Atoi(a2) << endl;
	cout << "Atoi(a1=\"\") = " << Atoi(a1="") << endl;
	cout << "测试putout()函数:" << endl;
	cout << "a2.putout()="; a2.putout(cout);
	cout << endl;
	cout << "测试putin()函数:";
	a2.putin(cin);
	cout << "a2=" << a2 << endl;
    cout << "测试Find()函数:" << endl;
    a1 = "131415926112";
    cout << "原数据a1=" << a1 << endl;
    cout << "第一次查找'1'的位置:" << a1.Find("1", true) << endl;
    cout << "第二次查找'1'的位置:" << a1.Find("1", false) << endl;
    cout << "第三次查找'1'的位置:" << a1.Find("1", false) << endl;
    cout << "新查找'1'的位置:" << a1.Find("1", true) << endl;
}
void test3() {
	cout << "String类调用继承于基类的函数------------------------------------------------------------------------------" << endl;
	cout << "原数据：" << endl;
	NewString a1 = "Object Oriented", a2 = " Design";
	cout << "a1 = " << a1 << "\na2 = " << a2 << "\n";
	cout << "测试’Length()’函数:" << endl;
	cout << "a1.Length()=" << a1.Length() << endl;
	cout << "测试’insert()’函数:" << endl;
	a1.insert('1', 3, 1);
	cout << "a1.insert('1',3,1)=" << a1 << endl;
	cout << "测试’erase()’函数:" << endl;
	a2.erase(0);
	cout << "a2.erase(0)=" << a2 << endl;
	cout << "a2.erase(100)="; a2.erase(100);
	a2.erase(0, 2);
	cout << "a2.erase(0,2)=" << a2 << endl;
	cout << "a2.erase(2,3)="; a2.erase(2, 3);
	cout << "测试empty()函数:" << endl;
	cout << "a2.empty()=" << a2.empty() << endl;
	cout << "测试clear()函数:" << endl;
	a2.clear();
	cout <<"a2.clear(),a2.empty()=" <<a2.empty()<< endl;
	cout << "测试swap()函数:" << endl;
    a1 = "Object Oriented";
    a2 = " Design";
	cout << "a1=" << a1 << "\ta2=" << a2 << endl;
	cout << "a1.swap(a2):" << endl;
	a1.swap(a2);
	cout << "a1=" << a1 << "\ta2=" << a2 << endl;
}
/* void test4()
{
	cout << "测试Vector类的函数:--------------------------------------------------------------" << endl;
	cout << "原数据：" << endl;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[11] = { 0,100,200,300,400,500,600,700,800,900,1000 };
	int arr3[10] = { 9,8,7,6,5,4,3,2,1,0 };
	NewVector<int>v1(10, arr);
	NewVector<int>v2(11, arr2);
	NewVector<int>v3(10, arr3);
	cout << "v1=" << v1 << endl;
	cout << "v2=" << v2 << endl;
	cout << "v3=" << v3 << endl;
	cout << "\n测试push_back()函数:" << endl;
	v1.push_back(10);
	cout << "v1.push_back(10)=" << v1 << endl;
	NewVector<int>v4;
	cout << "\n测试pop_back()函数:" << endl;
	v1.pop_back();
	cout << "v1.pop_back()=" << v1 << endl;
	cout << "v4=" << v4 << endl;
	cout << "v4.pop_back()="; v4.pop_back();
	cout << "\n测试back()函数:" << endl;
	cout << "v1.back()=" << v1.back() << endl;
	cout << "v4.back()="; v4.back();
	cout << "\n测试'+'运算符（不同维数不能相加）:" << endl;
	cout << "原数据：" << endl;
	cout << "v1=" << v1 << endl;
	cout << "v2=" << v2 << endl;
	cout << "v3=" << v3 << endl;
	cout << endl;
	cout << "v1+v3=" << v1 + v3 << endl;
	cout << "v1+v2="; v1 + v2;
	cout << "v4+v4=" << v4 + v4 << endl;
	cout << "v1+=v3:" << endl;
	v1 += v3;
	cout << "v1=" << v1 << endl;
	cout << "v3=" << v3 << endl;
	cout << "v1+=v2:"; v1 += v2;
	cout << "测试putout()函数:" << endl;
	cout << "v1.putout()="; v1.putout(cout);
	cout << endl;
	cout << "测试putin()函数(以（X1，X2，...,Xn）的形式输入):";
	v1.putin(cin);
	cout << "v1=" << v1 << endl;
}
void test5() {
	cout << "Vector类调用继承于基类的函数------------------------------------------------------------------------------" << endl;
	cout << "原数据：" << endl;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[11] = { 0,100,200,300,400,500,600,700,800,900,1000 };
	int arr3[10] = { 9,8,7,6,5,4,3,2,1,0 };
	NewVector<int>v1(10, arr);
	NewVector<int>v2(11, arr2);
	NewVector<int>v3(10, arr3);
	cout << "v1=" << v1 << endl;
	cout << "v2=" << v2 << endl;
	cout << "v3=" << v3 << endl;
	cout << "测试’Length()’函数:" << endl;
	cout << "v1.Length()=" << v1.Length() << endl;
	cout << "测试’insert()’函数:" << endl;
	v1.insert(1, 3, 1);
	cout << "v1.insert('1',3,1)=" << v1 << endl;
	cout << "测试’erase()’函数:" << endl;
	v2.erase(0);
	cout << "v2.erase(0)=" << v2 << endl;
	cout << "v2.erase(100)="; v2.erase(100);
	v2.erase(0, 2);
	cout << "v2.erase(0,2)=" << v2 << endl;
	cout << "v2.erase(2,100)="; v2.erase(2, 100);
	cout << "测试empty()函数:" << endl;
	cout << "v2.empty()=" << v2.empty() << endl;
	cout << "测试clear()函数:" << endl;
	v2.clear();
	cout << "v2.clear(),v2.empty()=" << v2.empty() << endl;
	cout << "测试swap()函数:" << endl;
	cout << "v1=" << v1 << "\tv2=" << v2 << endl;
	cout << "v1.swap(v2):" << endl;
	v1.swap(v2);
	cout << "v1=" << v1 << "\tv2=" << v2 << endl;
} */

int main()
{
	//NewVector<int>v;
	test1();
	test2();
	test3();
/* 	test4();
	test5(); */
	
	return 0;
}