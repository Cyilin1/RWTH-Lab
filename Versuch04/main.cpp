//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

// �������뱻��ʼ������ֵ const int a;
// const int a = 10;
//#include "Vektor.h"

// class Point
//{
// public:
//   // ����������Զ���Ĺ��캯����ԭ����Ĭ�Ϲ��캯���ͻ�ʧЧ
//   // �������Լ�����һ��Ĭ�ϵĹ��캯��
//   Point();
//   Point(int pX, int pY);

// private:
//   // ����һ��ʼ���뱻��ֵ
//   const int x;
//   const int y;
// };

//// ��ʼ���б�ĺ��ľ��ǣ������������ഴ����ʱ�򣬵�һ����ȥ�ҳ�ʼ���б�
// class Circle
//{
// public:
//   Circle(int pX, int pY, double pRadius);

// private:
//   Point middle;
//   double radius;
// };

// Point::Point(int pX, int pY)
//   : x(pX)
//   , y(pY)
//{}

// Circle::Circle(int pX, int pY, double pRadius)
//{
//   this->middle = Point(pX, pY);
//   this->radius = pRadius;
// }

// Circle a;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
  int matNr;
  std::string name;
  int erreichtePunktzahl;
  int bestanden;

public:
  /* In it ia li si er t das Objekt ,
   * auf jeden Fall nach der Erzeugung eines Objekts aufrufen !
   */
  // �ó�ʼ���б����Ż�
  void init(int pMatNr, std::string pName);

  void versuchBestanden(int versuchsNr, int punktzahl);
  // ��const���Ż�
  int gesamtPunktzahl();
};

#endif
