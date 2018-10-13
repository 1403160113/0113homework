#ifndef STUDENT_H
#define STUDENT_H
#include<QString>

class Student
{
public:
    Student();
    void data(int nu,QString na,int sc1,int sc2);//调用私有对象的成员函数；
    void printtablelist();//输出表头；
    void print();//输出所有数据；
    bool static namesort(const Student &a, const Student &b);//按姓名排序；
    bool static score1sort(const Student &a,const Student &b);//按课程1排序；
    bool static score2sort(const Student &a,const Student &b);//按课程2排序；
private:
    int number;
    QString name;
    int score1;
    int score2;//定义私有成员对象；
};

#endif // STUDENT_H
