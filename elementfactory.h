#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include "element.h"
#include "recipe.h"
#include <QVector>
#include <QHash>

class ElementFactory {
public:
    ElementFactory();

    Element createElement(const QString &name) const;
    Element combine(const Element &e1, const Element &e2) const;
    QVector<Element> baseElements() const;

private:
    QVector<Element> m_base;
    QVector<Recipe> m_recipes;
    QHash<QString, Element> m_catalog;
};

#endif // ELEMENTFACTORY_H




