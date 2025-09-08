#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "inventory.h"

class Player {
public:
    Player(const QString &name = QString());

    QString name() const;
    Inventory &inventory();

private:
    QString m_name;
    Inventory m_inventory;
};

#endif // PLAYER_H

