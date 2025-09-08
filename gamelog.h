#ifndef GAMELOG_H
#define GAMELOG_H

#include <QStringList>

class GameLog {
public:
    void add(const QString &line);
    QStringList records() const;

private:
    QStringList m_records;
};

#endif // GAMELOG_H

