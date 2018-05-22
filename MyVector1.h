#pragma once
#include<iostream>

using namespace std;

template <typename T>

class MyVector
{

 friend ostream& operator<< (ostream &out,const MyVector<T> &obj);


public:

    MyVector(int size = 0);//构造函数


    MyVector(const MyVector &obj);//拷贝构造函数


    ~MyVector();//析构函数



public:

     T &operator [](int index);

     MyVector &operator =(const MyVector &obj);

     int getlen();


protected:

    T *m_space;

    int m_len;

private:

};
