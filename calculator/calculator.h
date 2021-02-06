#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();

private:
    Ui::calculator *ui;
private slots:
    void digits_numbers();
    void on_dot_clicked();
    void operations();
    void on_AC_clicked();
    void on_result_clicked();
    void math_operations();
};
#endif // CALCULATOR_H
