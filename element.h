#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

enum class ElementType { Base, Composite, Advanced, Unknown };

class Element {
public:
    Element();
    Element(const QString &name, int level = 1, ElementType type = ElementType::Base, const QString &icon = QString());

    QString name() const;
    int level() const;
    ElementType type() const;
    QString icon() const;

private:
    QString m_name;
    int m_level;
    ElementType m_type;
    QString m_icon;
};

#endif // ELEMENT_H

