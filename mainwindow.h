#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "elementfactory.h"
#include "player.h"
#include "gamelog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCombineClicked();
    void refreshUi();

private:
    Ui::MainWindow *ui;
    ElementFactory factory;
    Player player;
    GameLog gameLog;
};

#endif // MAINWINDOW_H




