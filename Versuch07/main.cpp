#include <algorithm>
#include <fstream> // 添加文件流头文件，用于文件读写
#include <functional>
#include <iostream>
#include <string>
#include <vector> // 添加 vector 头文件

#include "Student.h"
// globale Funktion für operator < <()
std ::ostream &operator<<(std ::ostream &out, Student &stu1)
{
    stu1.ausgabe(out); // Aufruf der K l a s s e n f u n k t i o n ausgabe ()
        // out ist eine Referenz fuer std :: cout
    return out;
}

bool cmp(const Student &stu1, const Student &stu2)
{
    return stu1.getMatNr() < stu2.getMatNr();
}

int main()
{
    std::vector<Student> studentenListe; // 使用 vector 存储学生数据
    Student student;
    char abfrage;

    do {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Output inversely" << std::endl
                  << "(5): Datenelement loeschen" << std::endl
                  << "(6): Datenelement vorne hinzufuegen" << std::endl
                  << "(7): Daten aus Datei lesen" << std::endl
                  << "(8): Daten in Datei speichern" << std::endl
                  << "(9): Sort this student list" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage) {
            // ...
        case '1': {
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";
            // input Student's name
            std::cout << "Bitte geben sie die Daten für den Studenten "
                         "ein.\nName: ";
            getline(std::cin,
                    name); // ganze Zeile einlesen inklusive aller Leerzeichen

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            student = Student(matNr, name, geburtstag, adresse);

            studentenListe.push_back(student);
        } break;
            // Datenelement vorne entfernen
        case '2': {
            if (!studentenListe.empty()) {
                auto student_element = studentenListe.rbegin();
                // a student has been deleted;
                std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                student_element->ausgabe();
                studentenListe.pop_back();
            } else {
                std::cout << "Die Liste ist leer!\n";
            }
        } break;

            // output
        case '3':
            if (!studentenListe.empty()) {
                std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                for (auto stu : studentenListe) {
                    stu.ausgabe();
                }
            } else {
                std::cout << "Die Liste ist leer!\n\n";
            }
            break;

            // output inversely
        case '4':
            if (!studentenListe.empty()) {
                // output
                std::cout << "the output Seq of reverse is:" << std::endl;

                for (auto revIt = studentenListe.rbegin(); revIt != studentenListe.rend(); revIt++) {
                    revIt->ausgabe();
                }
            } else {
                std::cout << "Die Liste ist leer!\n\n";
            }
            break;
            // (5): delete element by StudentID
        case '5': {
            unsigned int matNr;
            std::cout << "please input a matNr(0-4294967295)" << std::endl;
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            bool found = false;
            auto it = std::find(studentenListe.begin(),
                                studentenListe.end(),
                                Student(matNr, "", "", ""));
            if (it != studentenListe.end()) {
                found = true;
                it->ausgabe();
                studentenListe.erase(it);
            }
            //            for (auto it = studentenListe.begin(); it != studentenListe.end(); it++) {
            //                if (it->getMatNr() == matNr) {
            //                    found = true;
            //                    it->ausgabe();
            //                    studentenListe.erase(it);
            //                }
            //            }

            if (!found) {
                std::cout << "NO STUDENT ID IN THIS DATABASE!" << std::endl;
            }
            break;
        }

        case '6': {
            unsigned int matNr;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            std::cout << "please input the student's information you want" << std::endl;
            std::cout << "Name: ";
            getline(std::cin, name);

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            //??????element
            student = Student(matNr, name, geburtstag, adresse);

            studentenListe.insert(studentenListe.begin(), student);
            break;
        }
        //从文件中读取数据
        case '7': {
            std::string fileName;
            std::cout << "Bitte geben Sie den Dateinamen ein, um Daten zu lesen: ";
            std::cin >> fileName;
            std::cin.ignore(10, '\n');

            // 清空现有的数据
            studentenListe.clear();

            // 从文件中读取数据并添加到 vector 中
            std::ifstream inputFile("student.txt", std::ios::in);
            if (!inputFile) {
                std ::cout << " File open failed! Please check the path.";
                exit(1);
            }

            int matNr = 0;
            std ::string name = "";
            std ::string geburtsdatum = "";
            std ::string address = "";
            while (inputFile >> matNr) {
                inputFile.ignore(1, '\n');
                std ::getline(inputFile, name);
                std ::getline(inputFile, geburtsdatum);
                std ::getline(inputFile, address);
                student = Student(matNr, name, geburtsdatum, address);
                studentenListe.push_back(student);
            }
            std::cout << "file read successfully!" << std::endl;

            break;
        }

            //数据保存到文件
        case '8': {
            std::string fileName;
            std::cout << "please input filename:";
            std::cin >> fileName;
            std::cin.ignore(10, '\n');

            // 将数据保存到文件
            std::ofstream outputFile(fileName);
            if (outputFile.is_open()) {
                for (const auto &stu : studentenListe) {
                    outputFile << stu.getMatNr() << std::endl;
                    outputFile << stu.getName() << std::endl;
                    outputFile << stu.getGeburtstag() << std::endl;
                    outputFile << stu.getAdresse() << std::endl;
                }
                outputFile.close();
                std::cout << "save to file successfully." << std::endl;
            } else {
                std::cout << "failed to save file." << std::endl;
            }
            break;
        }
        // 通过sort函数来对我们的studentlist进行排序
        case '9': {
            std::sort(studentenListe.begin(), studentenListe.end(), cmp);
            break;
        }
        }
    } while (abfrage != '0');
    return 0;
}
