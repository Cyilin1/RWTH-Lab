//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Student::ausgabe
 * 这个是不带参数的输出
 */
void Student::ausgabe() const
{
    std::cout << name << ", MatNr. " << matNr << ", geb. am " << geburtstag << ", wohnhaft in "
              << adresse << std::endl;
}

/**
 * @brief 这个是实现<<的重载输出函数，想让cout认识student这个类
 */
void Student::ausgabe(std::ostream &out) const
{
    out << name << ", MatNr. " << matNr << ", geb. am " << geburtstag << ", wohnhaft in " << adresse
        << std::endl;
}

/**
 * @brief 按学号的大小来比较这两个学生对象的大小
 * @param other
 * @return 
 */
bool Student::operator<(const Student &other)
{
    if (matNr < other.getMatNr()) {
        return true;
    }
    return false;
}

bool Student::operator>(const Student &other)
{
    if (matNr > other.getMatNr()) {
        return true;
    }
    return false;
}

bool Student::operator==(const Student &other)
{
    // 学号和姓名同时相等
    // if (matNr == other.getMatNr() && name == other.getName()) {
    //        return true;
    //    }
    // 学号和姓名其中一个相等即可
    //    if (matNr == other.getMatNr() || name == other.getName()) {
    //        return true;
    //    }
    if (matNr == other.getMatNr()) {
        return true;
    }

    return false;
}
