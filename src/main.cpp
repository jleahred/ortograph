#include <QtGui/QApplication>
#include <QIcon>

#include "ortograph.h"


#include "support/alarm.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setWindowIcon(QIcon(":/icon/letter.svg"));

    ortograph w;
    w.show();
    
    return a.exec();
}


namespace mtk
{

void  AlarmMsg(const mtk::Alarm& alarm)
{
    std::cout << alarm << std::endl;
}

}
