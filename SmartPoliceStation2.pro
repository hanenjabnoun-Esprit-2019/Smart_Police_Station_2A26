QT       += core gui serialport printsupport sql

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
    admin.cpp \
    arduino.cpp \
    cellule.cpp \
    citoyen.cpp \
    compteStats.cpp \
    connection.cpp \
    crud_citoyen.cpp \
    crud_demande.cpp \
    crud_horaire.cpp \
    crud_personnel.cpp \
    demande_a.cpp \
    detenu.cpp \
    dial.cpp \
    dial2.cpp \
    dialog.cpp \
    dialog2.cpp \
    dialog22.cpp \
    dialog_2.cpp \
    dossierc.cpp \
    equipement.cpp \
    horaire.cpp \
    intervenant.cpp \
    login_admin.cpp \
    main.cpp \
    mainwindow.cpp \
    menu_gestion_citoyen.cpp \
    menu_gestion_personnel.cpp \
    personnel.cpp \
    qcustomplot.cpp \
    stats.cpp \
    vehicule.cpp

HEADERS += \
    admin.h \
    arduino.h \
    cellule.h \
    citoyen.h \
    connection.h \
    crud_citoyen.h \
    crud_demande.h \
    crud_horaire.h \
    crud_personnel.h \
    demande_a.h \
    detenu.h \
    dial.h \
    dial2.h \
    dialog.h \
    dialog2.h \
    dialog22.h \
    dialog_2.h \
    dossierc.h \
    equipement.h \
    horaire.h \
    intervenant.h \
    login_admin.h \
    mainwindow.h \
    menu_gestion_citoyen.h \
    menu_gestion_personnel.h \
    personnel.h \
    qcustomplot.h \
    stats.h \
    vehicule.h

FORMS += \
    admin.ui \
    crud_citoyen.ui \
    crud_demande.ui \
    crud_horaire.ui \
    crud_personnel.ui \
    dial.ui \
    dial2.ui \
    dialog.ui \
    dialog2.ui \
    dialog22.ui \
    dialog_2.ui \
    login_admin.ui \
    mainwindow.ui \
    menu_gestion_citoyen.ui \
    menu_gestion_personnel.ui \
    stats.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pictures.qrc

DISTFILES += \
    pictures/3407709_m.jpg \
    pictures/LCPD-GTAIV-logo (1).png \
    pictures/LCPD-GTAIV-logo (1).png \
    pictures/R29ff80e1b872c3a34502081bb24ddc77.png \
    pictures/Search_icon-icons.com_54989 (2).png \
    pictures/Search_icon-icons.com_54989 (2).png \
    pictures/add_new_document_14028.png \
    pictures/adobe_pdf_document_14979.png \
    pictures/classer-par-ordre-alphabetique_318-10614.jpg \
    pictures/pen_edit_modify_pencil_icon_181536.png \
    pictures/trash-can_115312.png \
    pictures/xclock_hour_time_9343.png
