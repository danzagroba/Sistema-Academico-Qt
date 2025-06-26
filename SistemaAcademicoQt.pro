QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Aluno.cpp \
    Departamento.cpp \
    Disciplina.cpp \
    ListaAlunos.cpp \
    ListaDepartamentos.cpp \
    ListaDisciplinas.cpp \
    ListaUniversidades.cpp \
    Principal.cpp \
    Universidade.cpp \
    main.cpp \
    mainwindow.cpp \
    stdafx.cpp

HEADERS += \
    Aluno.h \
    Departamento.h \
    Disciplina.h \
    ListaAlunos.h \
    ListaDepartamentos.h \
    ListaDisciplinas.h \
    ListaUniversidades.h \
    Principal.h \
    Universidade.h \
    mainwindow.h \
    stdafx.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
