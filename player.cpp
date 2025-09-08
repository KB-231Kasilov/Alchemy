#include "player.h"

Player::Player(const QString &name) : m_name(name) {}
QString Player::name() const { return m_name; }
Inventory &Player::inventory() { return m_inventory; }
