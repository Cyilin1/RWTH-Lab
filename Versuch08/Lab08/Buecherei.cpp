/*! 
 * Praktikum Informatik 1 MMXXII
 *
 * @ file Buecherei.cpp
 */

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXI
// Versuch 08: Vererbung und Polymorphie
//
// Datei:  Buecherei.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/* ????????????????????
  * ????? true???????????DVD???????
  * ????? false??????? Medium
  */
#define UNTERKLASSENVORHANDEN true

#include <iostream>
#include <string>
#include <vector>
#include "Medium.h"
#include "Datum.h"

#if UNTERKLASSENVORHANDEN

#include "DVD.h"
#include "buch.h"
#include "magazin.h"

#endif

std::ostream &operator<<(std::ostream &out, Medium &med)
{
    med.ausgabe(out);
    return out;
}

void fuelleDatenbank(std::vector<Medium*>& medien);
void mediumHinzufuegen(std::vector<Medium*>& medien);
void mediumEntfernen(std::vector<Medium*>& medien);
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum);
void mediumZurueckgeben(std::vector<Medium*>& medien);
void alleMedienAusgeben(std::vector<Medium*>& medien);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    // 一组vector 里面存的是一个个的Medium*对象
    // Medium*的好处是节省空间，只需要传入一个地址
    std::vector<Medium*> medien;

    // aktuelles Datum
    Datum aktuellesDatum;
    std::cout << "Current Datum: " << aktuellesDatum << std::endl;

    // Check if subclasses have been implemented (see conditional compilation)
    // The database is filled with different media types accordingly
    fuelleDatenbank(medien);

    char abfrage;
    do  // Anzeige des Men?s
    {
        std::cout << std::endl
                  << "Menu:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Add a medium" << std::endl
                  << "(2): Delete a medium" << std::endl
                  << "(3): Display the database" << std::endl
                  << "(4): Loan a medium" << std::endl
                  << "(5): Return a medium" << std::endl
                  << "(6): Display borrowed media" << std::endl // New menu option
                  << "(7): Quit" << std::endl;

        // Einlesen der Abfrage
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {

            /////////////////////////////////////////////
            // Ein Medium wird zur Datenbank hinzuf?gt //
            /////////////////////////////////////////////
            case '1':
            {
                mediumHinzufuegen(medien);
                break;
            }

            ////////////////////////////////////////////////
            // Ein Medium wird aus der Datenbank entfernt //
            ////////////////////////////////////////////////
            case '2':
            {
                mediumEntfernen(medien);
                break;
            }

            ///////////////////////////////////////////
            // Ausgabe aller Medien in der Datenbank //
            ///////////////////////////////////////////
            case '3':
            {
                alleMedienAusgeben(medien);
                break;
            }

            /////////////////////////////
            // Verleihen eines Mediums //
            /////////////////////////////
            case '4':
            {
                mediumAusleihen(medien, aktuellesDatum);
                break;
            }

            ////////////////////////////////////////
            // Medium an die B?cherei zur?ckgeben //
            ////////////////////////////////////////
            case '5':
            {
                mediumZurueckgeben(medien);
                break;
            }

            case '6': {
                //displayBorrowedMedia(medien);
                break;
            }

            case '7':
            {
                std::cout << "Das Men? wird nun beendet." << std::endl;
                break;
            }

            default :
            {
                std::cout << "Falsche Eingabe, bitte nochmal versuchen.";
                break;
            }
        }
    }
    while (abfrage != '7');

    // Beim Beenden des Programms s?mtliche Medien l?schen
    for (std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        delete (*it);
    }

    return 0;
}

/////////////////////////////////////////////////////////////
// Definition aller Vorw?rtsdeklarierten Funktionen

/////////////////////////////////////////////////////////////
// Funktion fuellt die Datenbank der Buecherei automatisch //
/////////////////////////////////////////////////////////////
void fuelleDatenbank(std::vector<Medium*>& medien)
{
#if UNTERKLASSENVORHANDEN
    {
        // Datenbank wird mit Medien gef?llt
        Medium* neuesMedium = new Buch("Das Parfum", "Patrick Suskind");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Harry Potter und der Stein der Weisen", "J. K. Rowling");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Tom Sawyer", "Mark Twain");
        medien.push_back(neuesMedium);

        neuesMedium = new Magazin("Chip", Datum(1, 12, 2017), "Computer");
        medien.push_back(neuesMedium);

        neuesMedium = new DVD("Fluch der Karibik", 12, "Actionkom?die");
        medien.push_back(neuesMedium);

        neuesMedium = new Buch("Huckleberry Finn", "Mark Twain");
        medien.push_back(neuesMedium);
    }
#else
    {
        // Datenbank wird mit Medien gef?llt
        Medium* neuesMedium = new Medium("Das Parfum");
        medien.push_back(neuesMedium);

        neuesMedium = new Medium("Harry Potter und der Stein der Weisen");
        medien.push_back(neuesMedium);

        neuesMedium = new Medium("Tom Sawyer");
        medien.push_back(neuesMedium);
    }
#endif
}

/////////////////////////////////////////////////////////
/**
 * @brief 新增一个书籍 可以说buch mag dvd
 * @param medien
 */
void mediumHinzufuegen(std::vector<Medium *> &medien)
{
    #if UNTERKLASSENVORHANDEN
    {
        std::cout << "Geben Sie die Art des Mediums ein: " << std::endl
                  << "(1): Buch" << std::endl
                  << "(2): Magazin" << std::endl
                  << "(3): DVD" << std::endl;

        // Einlesen der aktuellen Abfrage
        // ?ber std::cin.ignore(10,\n) wird die "Enter-Eingabe, die f?r std::cin ben?tigt wird ignoriert
        // Ansonsten w?rde der n?chste getline Befehl nicht auf eine Eingabe warten...
        char abfrage;
        std::cin >> abfrage;
        std::cin.ignore(10,'\n');

        switch (abfrage)
        {
            // Case 1: Buch
            case '1':
            {
                // Einlesen des Buch-Titels
                std::string titel;
                std::cout << "Bitte geben Sie den Titel des Buchs ein: " << std::endl;
                std::getline(std::cin, titel);

                std::string autor;
                std::cout << "Bitte geben sie den Autor des Buchs ein: " << std::endl;
                std::getline(std::cin, autor);

                // erzeugen eines neuen Buchs
                Medium* neuesMedium = new Buch(titel,autor);
                medien.push_back(neuesMedium);
            }
            break;

            //Case 2: Magazin
            case '2':
            {
                // Einlesen des Magazin-Titels
                std::string titel;
                std::cout << "Geben Sie den Titel des Magazins ein:" << std::endl;
                getline(std::cin, titel);

                // Categary
                std::string sparte;
                std::cout << "Geben Sie die Sparte an:" << std::endl;
                getline(std::cin, sparte);

                // Einlesen des Datums (siehe ?berladener Eingabeoperator in der Klasse Datum)
                Datum datumAusgabe;
                std::cout << "Geben Sie das Erscheinungsdatum der Ausgabe an:" << std::endl;
                std::cin >> datumAusgabe;
                std::cin.ignore(10, '\n');

                // erzeugen eines neuen Magazins
                Medium* neuesMedium = new Magazin(titel, datumAusgabe, sparte);
                medien.push_back(neuesMedium);
            }
            break;

            // Case 3: DVD
            case '3':
            {
                // Einlesen des DVD-Titels
                std::string titel;
                std::cout << "Bitte geben Sie den Titel der DVD ein:" << std::endl;
                getline(std::cin, titel);

                // Einlesen des DVD-Generes
                std::string genre;
                std::cout << "Geben Sie das Genre an:" << std::endl;
                getline(std::cin, genre);

                // Einlesen der DVD-Altersfreigabe
                int altersfreigabe;
                std::cout << "Geben Sie die Altersfreigabe ein:" << std::endl;
                std::cin >> altersfreigabe;
                std::cin.ignore(10, '\n');

                Medium* neuesMedium = new DVD(titel, altersfreigabe, genre);
                medien.push_back(neuesMedium);
            }
            break;

            // Ung?ltige Eingabe
            default:
                std::cout << "Ung?ltige Eingabe!" << std::endl;
                break;
        }
    }
#else //UNTERKLASSEVORHANDEN:only medium, subclass undefined.
    {
        // Einlesen des Titels
        std::string titel;
        std::cout << "Bitte geben sie den Titel des Mediums ein:\n";
        getline(std::cin, titel);

        // Erzeugen eines neuen Mediums
        Medium* neuesMedium = new Medium(titel);
        medien.push_back(neuesMedium);
    }
#endif
}

////////////////////////////////////////////////////
/**
 * @brief 删除一个书籍
 * @param medien
 */
void mediumEntfernen(std::vector<Medium*>& medien)
{
    unsigned int id;

    std::cout << "Geben Sie die ID des Mediums ein, welches gel?scht werden soll: " ;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    bool success = false;

    for (std::vector<Medium *>::iterator it = medien.begin(); it != medien.end(); it++) {
        if((*it)->getID() == id)
        {
            delete (*it);  // Objekt l?schen
            medien.erase(it); // Zeiger auf das Objekt l?schen
            success = true; // L?schen war erfolgreich
            break; // Schleife abbrechen
        }
    }
    if(!success)
    {
        std::cout << "Keine g?ltige ID!" << std::endl;
    }
}

/////////////////////////////////////////////////////
/**
 * @brief 借书
 * @param medien
 * @param aktuellesDatum
 */
void mediumAusleihen(std::vector<Medium*>& medien, Datum aktuellesDatum)
{
    // Einlesen der ID (?ber std::cin.ignore(10, '\n'), wird die
    // Enter-Eingabe am Ende std::cin Eingabe ignoriert
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein:" << std::endl;
    std::cin >> id;
    std::cin.ignore(10, '\n');

    // reader's name
    std::string name;
    std::cout << "Geben Sie den Namen der Person ein: ";
    getline(std::cin, name);

    // Einlesen des birthday
    Datum geburtsdatum;
    std::cout << "Geben Sie das Geburtsdatum der Person ein: (Format TT.MM.JJJJ) ";
    std::cin >> geburtsdatum;
    std::cin.ignore(10, '\n');

    Person person(name,geburtsdatum);

    bool id_vorhanden = false;
    // Suchen des richtigen Elementes
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->ausleihen(person,aktuellesDatum);
            id_vorhanden = true; // find book
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine g?ltige ID!" << std::endl;
    }
}

////////////////////////////////////////////////////
// Funktion return book //
////////////////////////////////////////////////////
void mediumZurueckgeben(std::vector<Medium*>& medien)
{
    // Einlesen der ID (?ber std::cin.ignore(10, '\n'), wird die
    // Enter-Eingabe am Ende std::cin Eingabe ignoriert)
    unsigned int id;
    std::cout << "Geben Sie die ID des Mediums ein: ";
    std::cin >> id;
    std::cin.ignore(10,'\n');

    bool id_vorhanden = false;
    // Suchen des richtigen Elementes
    for(std::vector<Medium*>::iterator it = medien.begin(); it != medien.end(); it++)
    {
        if((*it)->getID() == id)
        {
            (*it)->zurueckgeben();
            id_vorhanden = true;
        }
    }
    if (!id_vorhanden)
    {
        std::cout << "Keine g?ltige ID!" << std::endl;
    }
}

////////////////////////////////////////////////////
// ???????????medium //
////////////////////////////////////////////////////
void alleMedienAusgeben(std::vector<Medium*>& medien)
{
    std::cout << "Vorhandene Medien in der B?cherei:" << std::endl;

    for (unsigned int index = 0; index < medien.size(); index++)
    {
        std::cout << "*************************************************************" << std::endl;
        medien[index]->ausgabe();
    }
}
