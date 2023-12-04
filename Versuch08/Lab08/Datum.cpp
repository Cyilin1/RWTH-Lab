/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file Datum.cpp
 */

#include "Datum.h"

#include <time.h>
#include <sstream>


//Instanzierung des tage-Arrays
const int Datum::tageMonat[12] = { 31,30,31,28,31,30,31,31,30,31,30,31 };


//Standardkonstruktor
Datum::Datum()
{
    // Current time
    time_t aktuelleZeit; 
    time(&aktuelleZeit);

    // current date
    struct tm* aktuellesDatum = localtime(&aktuelleZeit);

    // Werte zuweisen
    tag   = aktuellesDatum->tm_mday;
    monat = aktuellesDatum->tm_mon + 1;
    jahr  = aktuellesDatum->tm_year + 1900;
}

// Konstruktor
Datum::Datum(int initTag, int initMonat, int initJahr)
: tag(initTag)
, monat(initMonat)
, jahr(initJahr)
{
}

// Destruktor
Datum::~Datum(void)
{
}


// Ausgabe des Datums in einen Ausgabestream
void Datum::ausgabe(std::ostream& out) const
{
    out << tag << ".";

    // Formatierung um z.B. 01 statt 1 ausgeben
    if (monat < 10)
    {
        out << '0';
    }

    out << monat << "." << jahr;
}

// Funktion liest aus einem Eingabestream ein Datum ein
void Datum::eingabe(std::istream& in)
{
    std::string DatumString;
    // "2000.10.10"

    while (true) // Endlosschleife
    {
        in >> DatumString; //String einlesen
        try
        {
            // Abfangen der falschen Länge der Eingabe
            if (DatumString.length() != 10)
            {
                throw (std::string("Falsches Format!"));
            }

            // Stringstream zum Umwandeln in Integer-Zahlen
            std::istringstream stringstream;
            stringstream.str(DatumString);

            // Tag einlesen
            stringstream >> tag;

            // Nach dem Tag muss ein Punkt stehen
            if ((char)stringstream.get() != '.')
            {
                throw (std::string("Falsches Format!"));
            }

            // Monat einlesen
            stringstream >> monat;

            // Überprüfen der Gültigkeit des Monats
            if ((monat < 1) || (monat > 12))
            {
                throw (std::string("Ungültiger Monat!"));
            }

            // Überprüfen, ob der eigegebene Tag zum Monat passt
            if ((tag > tageMonat[monat - 1]) || (tag < 1))
            {
                throw (std::string("Ungültiger tag!"));
            }

            // Nach dem Monat muss ein Punkt stehen
            if ((char)stringstream.get() != '.')
            {
                throw (std::string("Falsches Format!"));
            }

            // Einlesen des Jahrs
            stringstream >> jahr;

            if (jahr < 1000 || jahr > 2030) {
                throw(std::string("Ungültiges Jahr!"));
            }

            //Datum wurde korrekt eingelesen, also Endlosschleife verlassen
            return;
        }
        catch (std::string& fehler)
        {
            std::cout << fehler << std::endl;
            std::cout << "Bitte nochmal eingeben: ";
        }
    }
}

// Überladener Subtraktions-Operator
// 2023 01 01
// 2013 02 04
int Datum::operator-(const Datum datum) const
{
    int tagDiff = tag - datum.tag;
    // -3
    int monatDiff = monat - datum.monat;
    // -1
    int jahrDiff = jahr - datum.jahr;
    // 10

    //Differenz der Monate abrunden
    if (tagDiff < 0)
    {
        monatDiff--;
        // -2
    }

    // Berechung der Monatsdifferenz zwischen beiden Daten
    return monatDiff + 12 * jahrDiff;
    // 120 + -2 = 118
}



Datum Datum::operator+(const int anzahl_Tage) const
{
    int tagNeu = tag + anzahl_Tage;
    int monatNeu = monat;
    int jahrNeu = jahr;

    //Mehrere Monate weiterspringen
    // const int Datum::tageMonat[12] = { 31,30,31,28,31,30,31,31,30,31,30,31 };
    while (tagNeu > tageMonat[monatNeu-1])
    {
        //Monat erhöhen und die jeweiligen Tage abziehen
        tagNeu -= tageMonat[monatNeu-1];
        monatNeu++;

        // Monat darf nicht größer als 12 werden
        if (monatNeu > 12)
        {
            monatNeu -= 12;
            jahrNeu++;
        }
    }
    return Datum(tagNeu, monatNeu, jahrNeu);
}

Datum &Datum::operator=(Datum &Datum)
{
    jahr = Datum.jahr;
    monat = Datum.monat;
    tag = Datum.tag;

    return *this;
}

// std::cout << "3";
// std::cout << datum
//Streamoperator für ostream
// overload input/output stream function
std::ostream& operator<<(std::ostream& out, const Datum& datum)
{
    datum.ausgabe(out);
    return out;
}

//Streamoperator für istream
std::istream& operator >> (std::istream& in, Datum& datum)
{
    datum.eingabe(in);
    return in;
}

