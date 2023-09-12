//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einf黨rung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

// 成员函数是如何实现的

// 成员函数蕴含者对私有变量private的操作

/**
 * @brief 构建函数可以有很多种
 */
Student::Student()
{
  erreichtePunktzahl = 0;
  matNr = 0;
  bestanden = 0;
  name = "";
}

// 初始化列表
Student::Student(int pMatNr, std ::string pName)
  : matNr(pMatNr)
  , name(pName)
  , bestanden(0)
  , erreichtePunktzahl(0)
{}
// Student::Student(int pMatNr, std::string pName)
//{
//   erreichtePunktzahl = 0;
//   this->matNr = pMatNr;
//   bestanden = 0;
//   this->name = pName;
// }

// delete时调用析构函数
Student::~Student() {}

/**
 * @brief Student::init 在对每一个新的student对象进行初始化
 * @param pMatNr
 * @param pName
 */
void
Student::init(int pMatNr, std::string pName)
{
  erreichtePunktzahl = 0;
  // this-> 是对成员变量进行赋值的操作；
  this->matNr = pMatNr;
  bestanden = 0;
  this->name = pName;
}

/**
 * @brief Student::versuchBestanden
 * @param versuchsNr 课程号
 * @param punktzahl 课程分
 */
void
Student::versuchBestanden(int versuchsNr, int punktzahl)
{
  this->erreichtePunktzahl += punktzahl;
  /*HierfolgtdieImplementierungderFunktion*/
}

/**
 * @brief Student::gesamtPunktzahl 获得总成绩
 * @return
 */
int
Student::gesamtPunktzahl()
{
  return erreichtePunktzahl;
}

/**
 * @brief Vektor::laenge
 * @return
 */
double
Vektor::laenge() const
{
  double temp = x + y;
  return 0.0;
}

/**
 * @brief Vektor::skalarProd
 * @param input
 * @return
 */
double
Vektor::skalarProd(const Vektor& input) const
{
  return 0.0;
}

double
Vektor::winkel(const Vektor& input) const
{
  return 0.0;
}

void
Vektor::rotiereUmZ(const double rad)
{}

Vektor::Vektor(double inX, double inY, double inZ)
  : x(inX)
  , y(inY)
  , z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
