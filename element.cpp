#include "element.h"

Element::Element() : m_name(), m_level(0), m_type(ElementType::Unknown) {}

Element::Element(const QString &name, int level, ElementType type)
    : m_name(name), m_level(level), m_type(type) {}

QString Element::name() const { return m_name; }
int Element::level() const { return m_level; }
ElementType Element::type() const { return m_type; }


