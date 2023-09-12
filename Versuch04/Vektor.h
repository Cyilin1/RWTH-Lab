//
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @brief The Vektor class
 */
class Vektor
{
public:
  Vektor(double x, double y, double z);
  ~Vektor();

  void ausgabe();                               // output
  Vektor sub(const Vektor& input) const;        // ������vector���м���
  double laenge() const;                        // length
  double skalarProd(const Vektor& input) const; // ����
  double winkel(const Vektor& input) const;     // �Ƕ�
  void rotiereUmZ(const double rad);            // ��תʱ��

private:
  double x;
  double y;
  double z;
};
#endif
