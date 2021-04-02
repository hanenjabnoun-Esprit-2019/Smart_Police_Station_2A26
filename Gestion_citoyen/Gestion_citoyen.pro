QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    citoyen.cpp \
    connection.cpp \
    crud_citoyen.cpp \
    crud_demande.cpp \
    demande_a.cpp \
    main.cpp \
    mainwindow.cpp \
    menu_gestion_citoyen.cpp

HEADERS += \
    citoyen.h \
    connection.h \
    crud_citoyen.h \
    crud_demande.h \
    demande_a.h \
    mainwindow.h \
    menu_gestion_citoyen.h

FORMS += \
    crud_citoyen.ui \
    crud_demande.ui \
    mainwindow.ui \
    menu_gestion_citoyen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
