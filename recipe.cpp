#include "recipe.h"

Recipe::Recipe() : m_a(), m_b(), m_result(), m_resultLevel(0) {}
Recipe::Recipe(const QString &a, const QString &b, const QString &result, int resultLevel)
    : m_a(a), m_b(b), m_result(result), m_resultLevel(resultLevel) {}

bool Recipe::matches(const Element &e1, const Element &e2) const {
    return (e1.name() == m_a && e2.name() == m_b) || (e1.name() == m_b && e2.name() == m_a);
}

QString Recipe::resultName() const { return m_result; }
int Recipe::resultLevel() const { return m_resultLevel; }
