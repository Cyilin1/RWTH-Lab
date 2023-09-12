//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einf黨rung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

// 常量必须被初始化并赋值 const int a;
// const int a = 10;
//#include "Vektor.h"

// class Point
//{
// public:
//   // 如果定义了自定义的构造函数，原来的默认构造函数就会失效
//   // 除非你自己定义一个默认的构造函数
//   Point();
//   Point(int pX, int pY);

// private:
//   // 常量一开始必须被赋值
//   const int x;
//   const int y;
// };

//// 初始化列表的核心就是，编译器会在类创建的时候，第一步先去找初始化列表
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
  // 用初始化列表来优化
  void init(int pMatNr, std::string pName);

  void versuchBestanden(int versuchsNr, int punktzahl);
  // 用const来优化
  int gesamtPunktzahl();
};

#endif
