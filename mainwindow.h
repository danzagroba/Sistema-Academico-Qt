#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include "Principal.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    Principal Sistema;

private:
    Ui::MainWindow *ui;
    QMenuBar* menuBar;
    int estado;

private:
    void onNewActionTriggered();
    void onOptionsActionTriggered();
    void onShowActionTriggered();
    void MostrarCadastroUniv();
    void MostrarCadastroDepto();
    void MostrarCadastroDisc();
    void MostrarCadastroAluno();
    void BotaoApertado();

};
#endif // MAINWINDOW_H
