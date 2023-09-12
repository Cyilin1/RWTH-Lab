//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////

#include "ListenElement.h"

/**
 * @brief Konstruktor, der ein neues Listenelemente mit allen Werten erstellt
 *
 * @param pData Ein Objekt der Klasse Student
 * @param pNext Zeiger auf das naechste Listenelement
 */
ListenElement::ListenElement(Student pData,
                             ListenElement* pNext,
                             ListenElement* pPrevious)
  : data(pData)
  , next(pNext)
  , pre(pPrevious)
{}

/**
 * @brief Fuegt ein Objekt der Klasse Student ein
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 */
void ListenElement::setData(Student pData)
{
    data = pData;
}

/**
 * @brief Fuegt einen Zeiger auf das naechste Listenelement ein
 *
 * @param pNext Zeiger auf das naechste Listenelement
 */
void ListenElement::setNext(ListenElement* pNext)
{
  next = pNext;
}

void
ListenElement::setPrevious(ListenElement* pPrevious)
{
  pre = pPrevious;
}

/**
 * @brief Gibt ein Objekt der Klasse Student zurueck
 *
 * @return Ein Zeiger auf ein Objekt der Klasse Student
 */
Student ListenElement::getData() const
{
    return data;
}

/**
 * @brief Gibt einen Zeiger auf das naechste Listenelement zurueck
 *
 * @return Zeiger auf das naechste Listenelement
 */
ListenElement* ListenElement::getNext() const
{
  return next;
}

ListenElement*
ListenElement::getPrevious() const
{
  return pre;
}

void
Liste::removeElement(ListenElement* element)
{
  if (element == nullptr) {
    return;
  }

  if (element == front) {
    popFront(); // 如果要删除的是第一个元素，使用 popFront() 函数删除它
    return;
  }

  if (element == back) {
    back = back->getPrevious(); // 如果要删除的是最后一个元素，更新 back 指针
  }

  ListenElement* previous = element->getPrevious();
  ListenElement* next = element->getNext();

  if (previous != nullptr) {
    previous->setNext(next);
  }

  if (next != nullptr) {
    next->setPrevious(previous);
  }

  delete element;
}
