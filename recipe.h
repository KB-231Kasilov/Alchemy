#ifndef RECIPE_H
#define RECIPE_H

#include "element.h"
#include <QString>

class Recipe {
public:
    Recipe();
    Recipe(const QString &a, const QString &b, const QString &result, int level);

    bool matches(const Element &e1, const Element &e2) const;
    Element createResult() const;

private:
    QString m_a;
    QString m_b;
    QString m_result;
    int m_level;
};

#endif // RECIPE_H




