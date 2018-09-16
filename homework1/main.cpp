#include <QDebug>
typedef quint32 word;
typedef quint8 byte;
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define HHI(xxx) ((byte)((word)(xxx)>>24))//取出最高位
#define LHI(xxx) ((byte)(((word)(xxx)>>16)&0xFF))//取出次高位
#define HLO(xxx) ((byte)(((word)(xxx)>>8)&0xFF))//取出次低位
#define LLO(xxx) ((byte)((word)(xxx)&0xFF))//取出最低位
#define num 0x12345678
int main()
{
    QList<quint8> values;
    values<<HHI(num)<<LHI(num)<<HLO(num)<<LLO(num);
    qDebug("原始值：0x%x==%d",num,num);//输出原始值
    qDebug("最高位：0x%x==%d",HHI(num),HHI(num));//输出最高位
    qDebug("次高位：0x%x==%d",LHI(num),LHI(num));//输出次高位
    qDebug("次低位：0x%x==%d",HLO(num),HLO(num));//输出次低位
    qDebug("最低位：0x%x==%d",LLO(num),LLO(num));//输出最低位
    qDebug("最高8位和次高8位最大值：0x%x<%d>",max(HHI(num),LHI(num)),max(HHI(num),LHI(num)));
    //输出最高8位和次高8位最大值
    qDebug("次高8位和最低8位最小值：0x%x<%d>",min(HLO(num),LLO(num)),min(HLO(num),LLO(num)));
    //输出最高8位和次高8位最大值
    quint32 n=LHI(num)|LLO(num)<<8|HHI(num)<<16|HLO(num)<<24;
    qDebug("重新组合后的数值：0x%x<%d>",n,n);
    qDebug()<<"排序前："<<values;
    std::sort(values.begin(),values.end(),[](int x,int y){return x>y;});
    qDebug()<<"排序后："<<values;
    return 0;
}
