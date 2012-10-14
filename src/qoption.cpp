#include "qoption.h"

QOption::QOption(QWidget *parent) :
    QLabel(parent), correct_option(false)
{
}


void QOption::mousePressEvent(QMouseEvent * /*ev*/)
{
    signal_clicked(this);
}
