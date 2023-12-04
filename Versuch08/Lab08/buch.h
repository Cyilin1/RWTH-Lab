#ifndef BUCH_H
#define BUCH_H

#include "Medium.h"

class Buch : public Medium
{
private:
    std::string autor; // 用于存储作者信息

public:
    // 构造函数，初始化 Buch 对象，需要传入标题和作者信息
    Buch(std::string initTitel, std::string initAutor)
        : Medium(initTitel)
        , autor(initAutor)
    {
    }

    virtual void ausgabe() const
    {
        Medium::ausgabe(); // 调用基类 Medium 的 ausgabe() 函数以输出标题和ID
        std::cout << "Autor: " << autor << std::endl;
    }
    virtual bool ausleihen(Person person, Datum ausleihdatum)
    {
        // 只要判断父类的基本借出情况就好
        return Medium::ausleihen(person, ausleihdatum);
    }
};

#endif // BUCH_H
