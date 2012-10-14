#ifndef QOPTION_H
#define QOPTION_H

#include <QLabel>

class QOption : public QLabel
{
    Q_OBJECT
public:
    explicit QOption(QWidget *parent = 0);

    bool     correct_option;

protected:
    void mousePressEvent(QMouseEvent *ev);
    
signals:
    void signal_clicked(QOption*);
    
public slots:
    
};

#endif // QOPTION_H
