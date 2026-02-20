#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberClickHandler();
    void on_add_clicked();
    void on_sub_clicked();
    void on_mul_clicked();
    void on_div_clicked();
    void on_clear_clicked();
    void on_enter_clicked();

private:
    Ui::MainWindow *ui;

    QString number1;
    QString number2;
    int state;
    int operand;

#endif





















#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Numeronapit
    QList<QPushButton*> numbers = {
        ui->N0, ui->N1, ui->N2, ui->N3, ui->N4,
        ui->N5, ui->N6, ui->N7, ui->N8, ui->N9
    };

    for(QPushButton* btn : numbers)
    {
        connect(btn, &QPushButton::clicked,
                this, &MainWindow::numberClickHandler);
    }

    // Operaationapit
    connect(ui->add, &QPushButton::clicked,
            this, &MainWindow::operatorClickHandler);
    connect(ui->sub, &QPushButton::clicked,
            this, &MainWindow::operatorClickHandler);
    connect(ui->mul, &QPushButton::clicked,
            this, &MainWindow::operatorClickHandler);
    connect(ui->div, &QPushButton::clicked,
            this, &MainWindow::operatorClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(!button) return;

    QString value = button->text();

    if(state == 1)
    {
        number1 += value;
        ui->num1->setText(number1);
    }
    else
    {
        number2 += value;
        ui->num2->setText(number2);
    }

    qDebug() << "number1:" << number1;
    qDebug() << "number2:" << number2;
}

void MainWindow::operatorClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(!button) return;

    if(button == ui->add) operand = 0;
    if(button == ui->sub) operand = 1;
    if(button == ui->mul) operand = 2;
    if(button == ui->div) operand = 3;

    state = 2;
}

void MainWindow::on_clear_clicked()
{
    state = 1;
    number1 = "";
    number2 = "";

    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}

void MainWindow::on_enter_clicked()
{
    if(number1.isEmpty() || number2.isEmpty())
        return;

    float n1 = number1.toFloat();
    float n2 = number2.toFloat();
    float res = 0;

    if(operand == 0) res = n1 + n2;
    if(operand == 1) res = n1 - n2;
    if(operand == 2) res = n1 * n2;
    if(operand == 3)
    {
        if(n2 == 0)
        {
            ui->result->setText("Error");
            return;
        }
        res = n1 / n2;
    }

    ui->result->setText(QString::number(res));
}
