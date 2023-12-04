#ifndef DVD_H
#define DVD_H

#include "Medium.h"

class DVD : public Medium
{
public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
        : Medium(initTitel)
        , altersfreigabe(initAltersfreigabe)
        , genre(initGenre)
    {}

    virtual void ausgabe() const
    {
        Medium::ausgabe();
        std::cout << "Altersfreigabe: " << altersfreigabe << std::endl;
        std::cout << "Genre: " << genre << std::endl;
    }

    virtual bool ausleihen(Person person, Datum ausleihdatum)
    {
        // "20230101" - "20130109" = 10*12 = 118
        // 7*12 =84
        if ((ausleihdatum - person.getGeburtsdatum()) > altersfreigabe * 12) {
            return Medium::ausleihen(person, ausleihdatum);
        } else {
            std::cout << "your age isnot suitable for this book!" << std::endl;
            return false;
        }
    }

private:
    int altersfreigabe;
    std::string genre;
};

#endif // DVD_H
