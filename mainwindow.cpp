#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refreshUi();

    connect(ui->combineButton, &QPushButton::clicked,
            this, &MainWindow::onCombineClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshUi()
{
    ui->comboA->clear();
    ui->comboB->clear();

    ui->comboA->addItem("Огонь");
    ui->comboA->addItem("Вода");
    ui->comboA->addItem("Земля");
    ui->comboA->addItem("Воздух");

    ui->comboB->addItem("Огонь");
    ui->comboB->addItem("Вода");
    ui->comboB->addItem("Земля");
    ui->comboB->addItem("Воздух");
}

void MainWindow::onCombineClicked()
{
    const QString aName = ui->comboA->currentText();
    const QString bName = ui->comboB->currentText();

    if (aName.isEmpty() || bName.isEmpty()) return;

    Element a = factory.createElement(aName);
    Element b = factory.createElement(bName);
    Element r = factory.combine(a, b);

    if (r.name() == "Неизвестно") {
        ui->textEdit->append(a.name() + " + " + b.name() + " → не найдено");
    } else {
        ui->textEdit->append(a.name() + " + " + b.name() + " → " + r.name()
                                                                           + " (уровень " + QString::number(r.level()) + ")");
    }
}



