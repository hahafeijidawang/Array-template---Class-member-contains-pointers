/*

    1）请设计一个数据模板类<MyVector>,完成对int、char、Teacher类型元素的管理。
    2）请仔细思考：
        a) 如果数组模板中的元素是Teacher元素时，需要Teacher类做什么工作
        b) 如果数组模板类中的元素是Teacher元素时，Theacher 类含有指针 应该怎样做？
    作业：1.优化Teacher 类，属性变成 char *pname,配置函数里面 分配内存。
    2.析构函数 释放pname的内存空间。
    3.避免浅拷贝
    4.在Teacher增加<<
    5.在模板数组类中存了 int char  Teacher /要求存Teacher*

*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<MyVector1.h>
#include<MyVector1.cpp>
#include<string.h>
using namespace std;
class Teacher{

public:
    Teacher(){
        age= 22;
        //pname =  new char[1];
        pname = (char*)malloc(strlen(""));

        strcpy(pname,"");

    }
    Teacher(char *pname,int age){

        this->age=age;

       this-> pname = (char*)malloc(strlen(pname)+1) ;

        //pname = new char[strlen(name)+1];

        strcpy(this->pname,pname);

    }
   Teacher(const Teacher &obj ){


       age = obj.age;

       pname = (char*)malloc(strlen(obj.pname)+1);

        // pname = new char[strlen(obj.pname)+1];

         strcpy(pname,obj.pname);


   }
//t1=t2
   Teacher & operator =( const Teacher & obj1){
            //清楚t1的旧内存。
       if (this->pname != NULL)
       {
           free(pname);
           //delete[] pname;
           pname = NULL;
           age= 20;
       }
      //根据obj1分配内存
       age = obj1.age;

       pname = (char*)malloc(strlen(obj1.pname)+1);

       strcpy(pname,obj1.pname);

       return *this;

   }
   friend ostream& operator <<(ostream &out,Teacher &t){

        out<<t.pname<<","<<"age"<<t.age<<endl;

        return out;


   }

   ~Teacher(){


       if(pname != NULL){

           //free(pname);
            delete [] pname;

             pname = NULL;

            age = 0;

       }



   }


  void printT(){

        cout<<"pname:"<<pname<<","<<"age:"<<age<<endl;

    }

 private:

    int age;

    char *pname;


};




//再升级 复杂类型数据。
int main(){
    char a[]="yzm",a1[]="yzm1",a2[]="yzm2",a3[]="yzm3";

    Teacher t1(a,31),t2(a1,32),t3(a2,33),t4(a3,34);

     t1=t2;

    MyVector<Teacher> tArray(4);

    tArray[0] = t1;

    tArray[1] = t2;

    tArray[2] = t3;

    tArray[3] = t4;

    for(int i=0;i<4;i++){

        Teacher tmp = tArray[i];

        tmp.printT();

    }




return 0;


}








//升级版
int main02(){

    MyVector<char> myv1(10);

    myv1[0] = 'a';

    myv1[1] = 'b';

    myv1[2] = 'c';

    myv1[3] = 'd';

   // cout<<myv1;


return 0;
}





//初始版
/*int main01()
{

    MyVector<int> myv1(10);

    for(int i = 0;i < myv1.getlen();i++){

        myv1[i] = i+1;

        cout<<myv1[i]<<" ";

    }

        cout<<endl;


    MyVector<int> myv2=myv1;

    for(int i = 0;i < myv2.getlen();i++){

        cout<<myv2[i]<<" ";

    }

        //cout<<myv2<<endl;



    return 0;
}

*/
