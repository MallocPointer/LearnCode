#ifndef UNTITLED_MYARRAY_H
#define UNTITLED_MYARRAY_H
#include <cstddef>
#include <iostream>

using namespace std;


template <class T>
class MyArray {
public:
    // 有参构造  参数 容量
    MyArray(int capacity) {
        cout << "MyArray 的有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 拷贝构造
    MyArray(const MyArray& arr) {
        cout << "MyArray 的有拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
    }

    // operator= 防止前拷贝问题
    MyArray& operator=(const MyArray& arr) {
        cout << "MyArray 的有 operator= 调用" << endl;
        // 先判断原来堆区是否有数据 如果有先释放
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    //尾插法
    void Push_Back(const T& val) {
        // 判断容量是否都已经被占用
        if (this->m_Capacity == this->m_Size) return;
        this->pAddress[this->m_Size] = val;   // 在数组的末尾添加数据
        this->m_Size++;   // 更新数组大小
    }

    // 尾删法
    void Pop_Back() {   // 采取策略为直接访问不到最后一个元素即可
        if (this->m_Size == 0) return;
        this->m_Size--;

    }

    // 通过下标的方式访问数组中的元素 采取重载[]策略
    // 设置为T&的原因是希望对象可以作为左值出现，例如 arr[100] = 10
    T& operator[](int index) {
        return this->pAddress[index];
    }

    // 返回数组的容量
    int getCapacity() {
        return this->m_Capacity;
    }

    // 返回数组的大小
    int getSize() {
        return this->m_Size;
    }


    //析构函数
    ~MyArray() {
        if (this->pAddress != NULL) {
            cout << "MyArray 的析构函数调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }


private:
    T* pAddress;   // 指针指向堆区开辟的真实数组
    int m_Capacity;   // 数组容量
    int m_Size;
};

#endif //UNTITLED_MYARRAY_H
