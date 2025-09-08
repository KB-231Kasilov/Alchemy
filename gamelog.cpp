#include "gamelog.h"

void GameLog::add(const QString &line) { m_records << line; }
QStringList GameLog::records() const { return m_records; }
