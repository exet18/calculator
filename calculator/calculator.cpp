#include "calculator.h"
#include "ui_calculator.h"

double num_first;

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);

    connect(ui->zero,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->one,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->idk,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->multiplication,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->addition,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->division,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->addition->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->division->setCheckable(true);
    ui->multiplication->setCheckable(true);

}

calculator::~calculator()
{
    delete ui;
}

void calculator::digits_numbers()
{

    QPushButton *button = (QPushButton *) sender();

    double all_numbers;
    QString new_Output;

    if(ui->output->text().contains(".") && button->text() == "0")
    {
        new_Output = ui->output->text() + button->text();
    }
    else
    {
        all_numbers =(ui->output->text() + button->text()).toDouble();

        new_Output = QString::number(all_numbers);

        ui->output->setText(QString::number((new_Output).toDouble()));
    }
}


void calculator::on_dot_clicked()
{
    if(!(ui->output->text().contains(".")))
    ui->output->setText(ui->output->text() + ".");
}

void calculator::operations()
{

    QPushButton *button = (QPushButton *) sender();

    double all_numbers;
    QString new_Output;

    if(button->text() == "+/-")
    {
    all_numbers =(ui->output->text()).toDouble();
    all_numbers = all_numbers * -1;

    new_Output = QString::number(all_numbers);

    ui->output->setText(QString::number((new_Output).toDouble()));
    }
    else if(button->text() == "%")
    {
        all_numbers =(ui->output->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_Output = QString::number(all_numbers);
        ui->output->setText(QString::number((new_Output).toDouble()));
    }
}

void calculator::on_AC_clicked()
{
    ui->multiplication->setChecked(false);
    ui->division->setChecked(false);
    ui->addition->setChecked(false);
    ui->minus->setChecked(false);
    ui->output->setText("0");
}

void calculator::on_result_clicked()
{
    double label_number, number_second;
    QString new_Output;

    number_second = ui->output->text().toDouble();

    if(ui->addition->isChecked())
    {
        label_number = num_first + number_second;
        new_Output = QString::number(label_number);
        ui->output->setText(QString::number((new_Output).toDouble()));
        ui->addition->setChecked(false);
    }
    else if(ui->division->isChecked())
    {
        if(number_second == 0)
        {
            ui->output->setText("0");
        }
        label_number = num_first / number_second;
        new_Output = QString::number(label_number);
        ui->output->setText(QString::number((new_Output).toDouble()));
        ui->division->setChecked(false);
    }
    else if(ui->minus->isChecked())
    {
        label_number = num_first - number_second;
        new_Output = QString::number(label_number);
        ui->output->setText(QString::number((new_Output).toDouble()));
        ui->minus->setChecked(false);
    }
    else if(ui->multiplication->isChecked())
    {
        label_number = num_first * number_second;
        new_Output = QString::number(label_number);
        ui->output->setText(QString::number((new_Output).toDouble()));
        ui->multiplication->setChecked(false);
    }
}

void calculator::math_operations()
{
    QPushButton *button = (QPushButton *) sender();
    num_first = ui->output->text().toDouble();
    ui->output->setText("");
    button->setChecked(true);
}
