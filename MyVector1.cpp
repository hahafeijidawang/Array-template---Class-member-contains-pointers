
#include<iostream>
#include<MyVector1.h>
using namespace std;

    //构造函数
template<typename T>
MyVector<T>::MyVector(int size ){

    m_space = new T [size];

    m_len = size;

    }

//拷贝构造函数
template<typename T>
MyVector<T>::MyVector(const MyVector<T> &obj){

//根据mpv1的大小分配内存

    m_len  =obj.m_len;

    m_space  = new T[m_len];

    for(int i = 0;i<m_len;i++){


    m_space[i] = obj.m_space[i];


    }


    }

    //析构函数
    template<typename T>
    MyVector<T>::~MyVector(){


    if(m_space!=NULL){

        delete [] m_space;

        m_space = NULL;

        m_len = 0;
    }

    }


 template <typename T>
 T& MyVector<T>::operator [](int index){


        return m_space[index];

    }

  //a3=a2=a1;
  template<typename T>
  MyVector<T> & MyVector<T>::operator =(const MyVector<T> &obj){

      //先把a2的旧的内存释放掉
      if(m_space!=NULL){

          delete [] m_space;

          m_space = NULL;

          m_len = 0;
      }


      //根据a1分配内存
        m_len  = obj.m_len;

        m_space = new T[m_len];
      //copy

          for(int i =0;i<m_len;i++){

              m_space[i] =  obj.m_space[i];

          }

        return *this;//返回a2的自身。



   }

  template<typename T>
  int MyVector<T>::getlen(){

        return m_len;

    }


  template<typename T>
  ostream& operator << (ostream &out,const MyVector<T> &obj){


      for(int i= 0;i<obj.getlen();i++){

          out<<obj.m_space[i]<<" ";

      }
      out<<endl;
      return out;



  }






