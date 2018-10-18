#include <QDebug>
#include <QTextStream>
#include <QFile>
#include<QList>
namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct{

     QStringList stu;

} studData;//定义学生数据的结构体


QDebug operator << (QDebug d, const studData &data) {
    for(int i=0;i<data.stu.size();i++)
        d.noquote().nospace()<<QString(data.stu.at(i))<<"\t" ;
    return d;

}//运算符重载函数，使其可以直接输出studData结构


class myCmp {

public:
    myCmp(int selectedColumn){
        currentColumn = selectedColumn;
    }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;

};//比较类，用于std::sort第三个参数


bool myCmp::operator()(const studData &d1, const studData &d2)
{
    if( d1.stu.at(currentColumn)>d2.stu.at(currentColumn))
            return 1;
    else
        return 0;
}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
private:
    QString stufile;
    QList<studData>   student;
    QStringList  tablelist;
};
void ScoreSorter::readFile()
{
    QFile file(stufile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug()<<QString("文件 %1 打开失败").arg(stufile);
            return ;
       }
    studData stud;
    QString table(file.readLine());
    tablelist= table.split(" ", QString::SkipEmptyParts);
    while(!file.atEnd()) {
        QString str(file.readLine());
        stud.stu = str.split(" ", QString::SkipEmptyParts);
        if((stud.stu).last() == "\n") stud.stu.removeLast();
        if(stud.stu.size()==0) continue;
        student.append(stud);

    }
    file.close();

}

ScoreSorter::ScoreSorter(QString dataFile)
{
    stufile=dataFile;
}

void ScoreSorter::doSort()

{
        for(int i=1;i<tablelist.size();i++)
    {
        myCmp mycmp(i-1);
        std::sort(student.begin() , student.end() , mycmp );  //排序
        qDebug()<<"排序后输出，当前排序第 "<<i <<" 列：";
        qDebug() <<tablelist;    //输出表头
        for(int i=0;i<student.size();i++)
            qDebug() << student.at(i);
        qDebug()<<"\n";
    }
}



//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
//{

//}

int main()
{
    QString datafile = "data.txt";
    QFile f("sorted_"+datafile); // 如果排序后文件已存在，则删除之
    if (f.exists()){
        f.remove();
    }
    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
