#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QButtonGroup *btnGp = new QButtonGroup(this);
    btnGp->addButton(ui->btnInfo, 0);
    btnGp->addButton(ui->btnProduct, 1);
    btnGp->addButton(ui->btnFinance, 2);
    btnGp->addButton(ui->btnHonor, 3);
    btnGp->addButton(ui->btnSettings, 4);

    connect(btnGp, &QButtonGroup::idClicked, ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    btnGp->button(0)->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}
