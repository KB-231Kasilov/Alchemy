#ifndef RECIPE_H
#define RECIPE_H

#include "element.h"

class Recipe {
private:
    QString first;
    QString second;
    QString result;

public:
    Recipe(const QString& first, const QString& second, const QString& result);
    bool matches(const Element& e1, const Element& e2) const;
    QString getResult() const;
};

#endif // RECIPE_H

