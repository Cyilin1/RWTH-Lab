#ifndef MAGAZIN_H
#define MAGAZIN_H
#include "Medium.h"
class Magazin : public Medium
{
public:
    Magazin(std::string initTitel, Datum initAusgabeDatum, std::string initKategorie)
        : Medium(initTitel)
        , ausgabeDatum(initAusgabeDatum)
        , kategorie(initKategorie)
    {}

    virtual void ausgabe() const
    {
        Medium::ausgabe();
        std::cout << "Ausgabe Datum: " << ausgabeDatum << std::endl;
        std::cout << "Kategorie: " << kategorie << std::endl;
    }

    virtual bool ausleihen(Person person, Datum ausleihdatum)
    {
        // step1 判断是否是最新的一期
        int monthsdiff = ausleihdatum - ausgabeDatum;
        if (monthsdiff <= 0) {
            std::cout << "Sorry, the magazine is the latest issue and cannot be borrowed."
                      << std::endl;
            return false;
        }
        // step2 再去父类判断基本的借出状态status等等
        return Medium::ausleihen(person, ausleihdatum);
    }

private:
    Datum ausgabeDatum;    // publish date
    std::string kategorie; // publisher
};
#endif // MAGAZIN_H
