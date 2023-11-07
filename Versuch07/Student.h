//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////
// 循环引用
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const;
    void ausgabe(std::ostream &out) const;
    bool operator<(const Student &other);
    // student1<student2
    // std::cout << student1;
    // a<b
    bool operator>(const Student &other);
    bool operator==(const Student &other);

private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif
// &&  And operation 与
//   0  1
//0  0  0
//1  0  1

// ｜｜ Or operation 或
//   0  1
//0  0  1
//1  1  1
