QT       += core gui printsupport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    crud_horaire.cpp \
    crud_personnel.cpp \
    horaire.cpp \
    main.cpp \
    mainwindow.cpp \
    menu_gestion_personnel.cpp \
    personnel.cpp \
    recherche_perso.cpp

HEADERS += \
    connection.h \
    crud_horaire.h \
    crud_personnel.h \
    horaire.h \
    mainwindow.h \
    menu_gestion_personnel.h \
    personnel.h \
    recherche_perso.h

FORMS += \
    crud_horaire.ui \
    crud_personnel.ui \
    mainwindow.ui \
    menu_gestion_personnel.ui \
    recherche_perso.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
