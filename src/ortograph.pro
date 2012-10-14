#-------------------------------------------------
#
# Project created by QtCreator 2012-09-29T11:33:36
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=gnu++0x


TARGET = ortograph
TEMPLATE = app


SOURCES += main.cpp\
        ortograph.cpp \
    qoption.cpp \
    db/msg_structs.cpp

HEADERS  += ortograph.h \
    qoption.h \
    db/msg_structs.cpp

FORMS    += ortograph.ui

OTHER_FILES += \
    db/msg_structs.msg


INCLUDEPATH += ../../mtk/src


LIBS =  -L../mtk/lib  -lyaml -lmtksupport -lqpidtypes

RESOURCES += \
    qrc.qrc
