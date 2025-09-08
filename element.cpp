#include "element.h"

Element::Element() : m_name(), m_level(0), m_type(ElementType::Unknown), m_icon() {}

Element::Element(const QString &name, int level, ElementType type, const QString &icon)
    : m_name(name), m_level(level), m_type(type), m_icon(icon) {}

QString Element::name() const { return m_name; }
int Element::level() const { return m_level; }
ElementType Element::type() const { return m_type; }
QString Element::icon() const { return m_icon; }

