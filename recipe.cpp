#include "recipe.h"

Recipe::Recipe() : m_a(), m_b(), m_result(), m_level(0) {}

Recipe::Recipe(const QString &a, const QString &b, const QString &result, int level)
    : m_a(a), m_b(b), m_result(result), m_level(level) {}

bool Recipe::matches(const Element &e1, const Element &e2) const {
    return (e1.name() == m_a && e2.name() == m_b) || (e1.name() == m_b && e2.name() == m_a);
}

Element Recipe::createResult() const {
    ElementType t = ElementType::Unknown;
    if(m_level == 1) t = ElementType::Base;
    else if(m_level <= 3) t = ElementType::Composite;
    else t = ElementType::Advanced;
    return Element(m_result, m_level, t);
}

