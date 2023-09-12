//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
  ListenElement* neuesElement = new ListenElement(pData, nullptr, back);

  if (back != nullptr) {
    back->setNext(neuesElement);
  }

  back = neuesElement;

  if (front == nullptr) // Liste leer?
  {
    front = neuesElement;
  }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth鋖t nur ein Listenelement
    {
        delete front;                                        // Listenelement l鰏chen
        front = nullptr;
        back = nullptr;
    }
    else
    {
      front = front->getNext();
      front->setPrevious(nullptr);
      delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief 输出列表的第一个数据
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief 正序输出所有元素
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
  // ListenElement 看成链表中的一个结点
  ListenElement* cursor = front;

  while (cursor != nullptr) {
    cursor->getData().ausgabe(); // 用于输出
    cursor = cursor->getNext();  // 用于找到下一个元素
  }
}

void
Liste::outputInverse() const
{
  ListenElement* cursor = back;
  while (cursor != nullptr) {
    cursor->getData().ausgabe();
    cursor = cursor->getPrevious();
  }
}

ListenElement*
Liste::getBack()
{
  return back;
}
