//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

// ��Ա���������ʵ�ֵ�

// ��Ա�����̺��߶�˽�б���private�Ĳ���

/**
 * @brief �������������кܶ���
 */
Student::Student()
{
  erreichtePunktzahl = 0;
  matNr = 0;
  bestanden = 0;
  name = "";
}

// ��ʼ���б�
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

// deleteʱ������������
Student::~Student() {}

/**
 * @brief Student::init �ڶ�ÿһ���µ�student������г�ʼ��
 * @param pMatNr
 * @param pName
 */
void
Student::init(int pMatNr, std::string pName)
{
  erreichtePunktzahl = 0;
  // this-> �ǶԳ�Ա�������и�ֵ�Ĳ�����
  this->matNr = pMatNr;
  bestanden = 0;
  this->name = pName;
}

/**
 * @brief Student::versuchBestanden
 * @param versuchsNr �γ̺�
 * @param punktzahl �γ̷�
 */
void
Student::versuchBestanden(int versuchsNr, int punktzahl)
{
  this->erreichtePunktzahl += punktzahl;
  /*HierfolgtdieImplementierungderFunktion*/
}

/**
 * @brief Student::gesamtPunktzahl ����ܳɼ�
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
