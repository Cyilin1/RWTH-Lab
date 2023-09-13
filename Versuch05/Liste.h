//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);                                // 插入元素
    void popFront();               // 删除一个元素
    bool empty();                  // 判断列表是否为空
    Student dataFront();           // 输出列表的第一个数据
    void ausgabeVorwaerts() const; // 正序输出
    void outputInverse() const;    // 逆序输出
    ListenElement* getBack();
    void removeElement(ListenElement *element);
    void pushFront(Student pData);
};

#endif /*LISTE_H_*/
