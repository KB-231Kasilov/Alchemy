#include "element.h"

Element::Element(const QString& name, const QString& type)
    : name(name), type(type) {}

QString Element::getName() const {
    return name;
}

QString Element::getType() const {
    return type;
}
