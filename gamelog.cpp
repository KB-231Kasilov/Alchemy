#include "gamelog.h"

void GameLog::add(const QString &line) { m_records << line; }
QStringList GameLog::records() const { return m_records; }
void GameLog::setProgress(int unlocked) { m_progress = unlocked; }
int GameLog::progress() const { return m_progress; }

