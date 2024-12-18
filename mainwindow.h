#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

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

private:
    Ui::MainWindow *ui;
    QMenuBar* menuBar;

private:
    void onNewActionTriggered();
    void onOptionsActionTriggered();
    void onShowActionTriggered();
    void MostrarCadastroUniv();
    void MostrarCadastroDepto();
    void MostrarCadastroDisc();
    void MostrarCadastroAluno();

};
#endif // MAINWINDOW_H
