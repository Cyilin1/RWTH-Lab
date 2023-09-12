//
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einf黨rung Klasse
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
  Vektor sub(const Vektor& input) const;        // 将两个vector进行减法
  double laenge() const;                        // length
  double skalarProd(const Vektor& input) const; // 标量
  double winkel(const Vektor& input) const;     // 角度
  void rotiereUmZ(const double rad);            // 旋转时间

private:
  double x;
  double y;
  double z;
};
#endif
