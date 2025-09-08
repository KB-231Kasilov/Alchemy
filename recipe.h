#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include "element.h"

class Recipe {
public:
    Recipe();
    Recipe(const QString &a, const QString &b, const QString &result, int resultLevel);

    bool matches(const Element &e1, const Element &e2) const;
    QString resultName() const;
    int resultLevel() const;

private:
    QString m_a;
    QString m_b;
    QString m_result;
    int m_resultLevel;
};

#endif // RECIPE_H


