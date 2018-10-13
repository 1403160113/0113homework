#include <QCoreApplication>
#include"student.h"
#include<QVector>
#include<QDebug>

void shuchu(QVector<Student> st)
{
    st[0].printtablelist();
    st[0].print();
    st[1].print();
    st[2].print();
    st[3].print();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<Student> st(4);
    st[0].data(1403130209,"鲁智深",80,72);
    st[1].data(1403140101,"林冲",82,76);
    st[2].data(1403140102,"宋江",76,85);
    st[3].data(1403140103,"武松",88,80);

    qDebug()<<"------------------排序之前：----------------";
    shuchu(st);

    std::sort(st.begin(),st.end(),Student::namesort);
    qDebug()<<"-----------------按姓名排序：----------------";
    shuchu(st);

    std::sort(st.begin(),st.end(),Student::score1sort);
    qDebug()<<"----------------按课程1排序：---------------";
    shuchu(st);

    std::sort(st.begin(),st.end(),Student::score2sort);
    qDebug()<<"----------------按课程2排序：---------------";
    shuchu(st);

    return a.exec();
}
