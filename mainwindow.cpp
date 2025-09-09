#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    player("Игрок")
{
    ui->setupUi(this);

    for(const auto &e : factory.baseElements())
        player.inventory().add(e);

    refreshUi();
    connect(ui->combineButton, &QPushButton::clicked,
            this, &MainWindow::onCombineClicked);

    gameLog.setProgress(player.inventory().unlockedCount());
    ui->statusbar->showMessage(
        QString("Элементов разблокировано: %1").arg(gameLog.progress())
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshUi()
{
    ui->comboA->clear();
    ui->comboB->clear();

    for(const auto &e : player.inventory().elements()) {
        ui->comboA->addItem(e.name());
        ui->comboB->addItem(e.name());
    }
}

void MainWindow::onCombineClicked()
{
    const QString aName = ui->comboA->currentText();
    const QString bName = ui->comboB->currentText();
    if(aName.isEmpty() || bName.isEmpty()) return;

    if(!player.inventory().contains(aName) || !player.inventory().contains(bName)) {
        ui->textEdit->append("Эти элементы ещё не доступны!");
        return;
    }

    Element a = factory.createElement(aName);
    Element b = factory.createElement(bName);
    Element r = factory.combine(a, b);

    if (r.name() == "Неизвестно") {
        ui->textEdit->append(a.name() + " + " + b.name() + " → не найдено");
    } else {
        ui->textEdit->append(a.name() + " + " + b.name() + " → " + r.name()
                                                                           + " (уровень " + QString::number(r.level()) + ")");
        if(player.inventory().add(r)) {
            gameLog.setProgress(player.inventory().unlockedCount());
            ui->statusbar->showMessage(
                QString("Элемент %1 разблокирован! Всего элементов: %2")
                    .arg(r.name())
                    .arg(gameLog.progress())
                );
            refreshUi();
        }
    }
}






