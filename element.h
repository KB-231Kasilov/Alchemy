#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

class Element {
private:
    QString name;
    QString type;

public:
    Element(const QString& name, const QString& type);
    QString getName() const;
    QString getType() const;
};

#endif // ELEMENT_H
