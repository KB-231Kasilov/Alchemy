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

private:
    QHash<QString, Element> m_elements;
};

#endif // INVENTORY_H

