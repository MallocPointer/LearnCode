#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
private:
	T *Address;   //指针指向堆区开辟的真实数组
	int Capacity;   //数组容量
	int Size;   //数组大小

public:
	MyArray() {

	}

	MyArray(int capacity) {
		cout << "MyArray的有参构造调用" << endl;
		this->Capacity = capacity;
		this->Address = new T[this->Capacity];
		this->Size = 0;
	}

	~MyArray() {
		cout << "MyArray的析构调用" << endl;
		if (this->Address != NULL) {
			delete[]this->Address;
			this->Address = NULL;
		}
	}

	//拷贝构造
	MyArray(const MyArray &arr) {
		cout << "MyArray的拷贝构造函数调用" << endl;
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		
		//深拷贝
		this->Address = new T[arr.Capacity];

		//将arr中的数据全部拷贝
		for (int i = 0; i < this->Size; i++) {
			this->Address[i] = arr.Address[i];
		}
	}

	//重写 = 避免深拷贝的一系列问题
	// 重写 = 避免浅拷贝
	MyArray& operator=(const MyArray &arr) {
		cout << "MyArray的operator=函数调用" << endl;

		// 1) 防止自赋值：a = a
		if (this == &arr) {
			return *this;
		}

		// 2) 先释放原来的堆区
		if (this->Address != nullptr) {   // this->Address
			delete[] this->Address;
			this->Address = nullptr;
		}

		// 3) 深拷贝
		this->Capacity = arr.Capacity;
		this->Size = arr.Size;
		this->Address = new T[this->Capacity];

		for (int i = 0; i < this->Size; i++) {
			this->Address[i] = arr.Address[i];
		}

		return *this;
	}

};