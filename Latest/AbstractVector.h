#ifndef ABSTRACTVECTOR_H
#define ABSTRACTVECTOR_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

// AbstractVector----------------------------------------------------------
template<class T>
class AbstractVector
{
public:
	AbstractVector(const unsigned int Size=0, const T* Head=NULL);			//构造函数
	AbstractVector(const AbstractVector& v);								//拷贝构造函数
	virtual ~AbstractVector();										//析构函数，不需要释放内存，在子类中释放
	AbstractVector& operator=(const AbstractVector& v);						//赋值运算函数
	void resize(unsigned int Size);  //重构容量
	unsigned int Length() const;							//返回向量大小
	bool empty() const;//判断向量是否为空
	T& operator[](const unsigned int& pos)const; //返回下标为pos的元素
	void clear();
	void insert(const T val, const unsigned int& pos, const unsigned int &n); //在pos位置后插入n个元素val
	void erase(const unsigned int& pos); //删除pos位置的一个元素,下标越界抛出异常
	void erase(const unsigned int& left, const unsigned int& right); //函数重载，删除从[left,right]闭区间内的所有元素。
	void swap(AbstractVector<T>& v);

	virtual void putout(ostream& out) const = 0;			//纯虚函数
	virtual void putin(istream& in) = 0;
protected:
	unsigned int size;
	T* head;
};

// AbstractVector四大函数----------------------------------------------------
template <typename T>											// 构造函数
AbstractVector<T>::AbstractVector(const unsigned int Size, const T* Head) {
	size = Size;
	head = NULL;
	if (size > 0) {
		head = new T[size+1];
		for (int i = 0; i < size; i++)
			head[i] = (Head == NULL) ? 0 : Head[i];
	}
}
template<class T>											// 析构函数
AbstractVector<T>::~AbstractVector() {
	delete []head;
	this->head = NULL;
	this->size = 0;
};

template <class T>											// 赋值运算函数
AbstractVector<T>& AbstractVector<T>::operator=(const AbstractVector<T>& v) {
	if (head == v.head) return *this;
	if (size != v.size) {
		if (head != NULL) delete[] head;
		head = new T[size = v.size];
	}
	for (int i = 0; i < size; i++) {
		head[i] = v.head[i];
	}
	return *this;
}

template <class T>											// 拷贝构造函数
AbstractVector<T>::AbstractVector(const AbstractVector<T>& v) {
	*this = v;
}
// AbstractVector高级成员函数----------------------------------------------------------
template <typename T>
void AbstractVector<T>::resize(unsigned int Size)			// 指定向量的维数（尽量保留原有的数据）
{
	if (Size < 0 || Size == size)
		return;
	else if (Size == 0)
	{
		if (head != NULL) delete[] head;
		head = NULL;
		size = 0;
	}
	else
	{
		T* temp = head;
		head = new T[Size];
		for (int i = 0; i < Size; i++)
			head[i] = (i < size) ? temp[i] : 0;	// 尽量保留原有数据
		size = Size;
		delete[] temp;
	}
}
template<typename T>
bool AbstractVector<T>::empty() const{
	return (size == 0);
}

template <typename T>
T& AbstractVector<T>::operator[](const unsigned int& index) const // 方括号运算符函数（引用返回，可作左值）
{
	try{
		if (head == NULL)
			throw 0;							// 新添加的异常
		if (index < 0 || index >= size)
			throw - 1;
		return head[index];
	}
	catch (int e)
	{
		cerr << "error:下标越界！" << endl;
		T temp;
		return temp;
	}
}

template<typename T>
void AbstractVector<T>::insert(const T val, const unsigned int &pos, const unsigned int &n) {
	int temp = size + n;
	T* usual = new T[size+n+1];
	for (int i = 0; i <= pos; i++) usual[i] = head[i];
	for (int i = 0; i < n; i++) usual[i+pos+1] = val;
	for (int i = pos+1; i < temp; i++) usual[i+n] = head[i];
	
	delete[] head;
	size = temp;
	head = new T[size+1];
	for(int i = 0; i < size; i++)
	{
		head[i] = usual[i];
	}
	delete[] usual;
}
template<typename T>
void AbstractVector<T>::erase(const unsigned int& pos) {
	try {
		if (pos < 0 || pos >= size) throw - 1;
		erase(pos, pos);
	}
	catch (int e) {
		cerr << "error:下标越界" << endl;
	}
}
template<typename T>
void AbstractVector<T>::erase(const unsigned int& left, const unsigned int &right) {
	try {
		if (right >= size || left >= size || right < 0 || left < 0 || left > right){
		    throw - 1;
		}
		else {
			int lenth = right - left + 1;
			int temp_size = size-lenth;
			T* temp = new T[temp_size+1];
			for (int i = 0; i < left; i++) temp[i] = head[i];
			for (int i = right+1; i < size; i++) temp[i-lenth] = head[i];
			size = temp_size;
			delete[] head;
			head = temp;

		}
	}
	catch (int e) {
		cerr << "error:下标越界" << endl;
	}
}
template <class T>				
void AbstractVector<T>::swap(AbstractVector<T>& v) {
	T* temp = head;
	head = new T[v.size+1];

	for(int i = 0; i < v.size; i++)
	{
		head[i] = v[i];
	}
	delete[] v.head;
	v.head = new T[size+1];

	for(int i = 0; i < size; i++)
	{
		v.head[i] = temp[i];
	}
	delete[] temp;
	unsigned int t_size = size;
	size = v.size;
	v.size = t_size;
}

template <class T>
unsigned int AbstractVector<T>::Length() const {
	return size;
}

template <class T>				
void AbstractVector<T>::clear() {
	size = 0;
	delete[]head;
	head = NULL;
}
// AbstractVector输入输出--------------------------------------------------
template <class T>											//输出重载
ostream& operator<<(ostream& out, const AbstractVector<T>& v) {
	v.putout(out);
	return out;
}

template <class T>											//输入重载
istream& operator>>(istream& in, AbstractVector<T>& v) {
	v.putin(in);
	return in;
}


#endif