#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

enum class ElementType { Base, Composite, Advanced, Unknown };

class Element {
public:
    Element();
    Element(const QString &name, int level = 1, ElementType type = ElementType::Base);

    QString name() const;
    int level() const;
    ElementType type() const;

private:
    QString m_name;
    int m_level;
    ElementType m_type;
};

#endif // ELEMENT_H


