#include "student.h"
#include<QDebug>
Student::Student()
{

}

void Student::data(int nu, QString na, int sc1, int sc2)
{
    number=nu;
    name=na;
    score1=sc1;
    score2=sc2;
}

void Student::printtablelist()
{
    qDebug()<<"   学号"<<"\t   姓名"<<"\t课程1"<<"\t\t课程2";
}

void Student::print()
{
    qDebug()<<number<<"\t"<<name<<"\t"<<score1<<"\t\t"<<score2;
}

bool Student::namesort(const Student &a, const Student &b)
{
    if(a.name>b.name)
        return 1;
    else
        return 0;
}

bool Student::score1sort(const Student &a, const Student &b)
{
    if(a.score1>b.score1)
        return 1;
    else
        return 0;
}

bool Student::score2sort(const Student &a, const Student &b)
{
    if(a.score2>b.score2)
        return 1;
    else
        return 0;
}
