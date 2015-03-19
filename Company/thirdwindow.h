#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H
#include "company.h"
#include "person.h"
#include <QWidget>


class Company;
class Person;
namespace Ui {
class thirdwindow;
}

class thirdwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit thirdwindow(QWidget *parent = 0);
    ~thirdwindow();
    
private slots:
    void on_newname_textEdited(const QString &arg1);

    void on_comboBox_editTextChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_create_newusr_clicked();

private:
    Ui::thirdwindow *ui;
};

#endif // THIRDWINDOW_H
