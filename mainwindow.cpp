#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "menuxy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    auto * menu = new MenuXY(this,nullptr);
    menu->move(33,33);
    // menu->resize(100,100);
    menu->show();
}

