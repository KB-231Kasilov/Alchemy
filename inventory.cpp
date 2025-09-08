#include "inventory.h"

bool Inventory::add(const Element &e) {
    if(m_elements.contains(e.name())) return false;
    m_elements.insert(e.name(), e);
    return true;
}

bool Inventory::contains(const QString &name) const {
    return m_elements.contains(name);
}

QVector<Element> Inventory::elements() const {
    return m_elements.values().toVector();
}


