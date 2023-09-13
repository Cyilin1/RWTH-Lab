//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"
/**
 * @brief The ListenElement class 相当于一个Node结点
 */
class ListenElement
{
private:
    Student data;
    ListenElement *next;
    ListenElement *pre;

public:
    ListenElement(Student pData, ListenElement *pNext, ListenElement *pPrevious);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrevious(ListenElement* pPrevious);

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrevious() const;
//    void removeElement(ListenElement* element);
};

#endif
