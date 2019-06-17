#pragma once
#include <QString>

/* ----------------------------------------------------------------------------------------
Data
---------------------------------------------------------------------------------------- */
class CurrencyData
{
public:
    CurrencyData()
    {
        nameFr="";
        nameEn="";
        symbol="";
        abbrev="";
    }

    CurrencyData(const QString pNameFr, const QString pNameEn, const QString pSymbol, const QString pAbbrev)
    {
        nameFr = pNameFr;
        nameEn = pNameEn;
        symbol = pSymbol;
        abbrev = pAbbrev;
    }

    const QString& get_namefr() { return nameFr; }
    const QString& get_nameen() { return nameEn; }
    const QString& get_symbol() { return symbol; }
    const QString& get_abbrev() { return abbrev; }

private:
    QString nameFr;
    QString nameEn;
    QString symbol;
    QString abbrev; //abbreviation
};
