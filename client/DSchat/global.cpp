#include "global.h"

QString gate_url_prefix="";

std::function<void(QWidget*)> repolish = [](QWidget* w){
    w->style()->unpolish(w);
    w->style()->polish(w);
};

std::function<QString(QString)> xorString = [](QString input){
    QString result = input;//获取原始字符串，方便修改
    int length = input.length();//获取字符串长度
    length = length % 255;
    for(int i = 0;i<length ;++i){
        //对每个字符进行异或操作，
        //假设字符都是ascll，因此直接转化为QChar
        result[i] = QChar(static_cast<ushort>(input[i].unicode() ^ static_cast<ushort>(length)));
    }
    return result;

};
