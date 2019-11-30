#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_buttonBox_accepted()
{
    QString order;
    order.append("Size: " + getSelected(ui->grpSize) + "\r\n");
    order.append("Meal: " + getSelected(ui->grpMeal) + "\r\n");
    order.append("Drink: " + getSelected(ui->grpDrink) + "\r\n");
    QMessageBox::information(this,"Order",order);
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

QString Dialog::getSelected(QGroupBox *groupbox)
{
    QString value = "Not Selected";
    foreach (QObject* obj, groupbox->children())
    {
        QRadioButton *btn = qobject_cast<QRadioButton*>(obj);
        if(!btn) continue;
        if(btn->isChecked())
        {
            value = btn->text();
            break;
        }
    }

    return value;
}
