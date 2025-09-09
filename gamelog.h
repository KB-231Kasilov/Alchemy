#ifndef GAMELOG_H
#define GAMELOG_H

#include <QStringList>

class GameLog {
public:
    void add(const QString &line);
    QStringList records() const;
    void setProgress(int unlocked);
    int progress() const;

private:
    QStringList m_records;
    int m_progress = 0;
};

#endif // GAMELOG_H


