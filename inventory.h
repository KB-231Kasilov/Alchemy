#ifndef INVENTORY_H
#define INVENTORY_H

#include "element.h"
#include <QHash>
#include <QVector>

class Inventory {
public:
    bool add(const Element &e);
    bool contains(const QString &name) const;
    QVector<Element> elements() const;
    int unlockedCount() const; // новый метод

private:
    QHash<QString, Element> m_elements;
};

#endif // INVENTORY_H


