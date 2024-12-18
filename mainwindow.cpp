#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setVisible(false);
    connect(ui->actionUniversidade, &QAction::triggered, this, &MainWindow::MostrarCadastroUniv);
    connect(ui->actionDepartamento, &QAction::triggered, this, &MainWindow::MostrarCadastroDepto);
    connect(ui->actionDisciplina, &QAction::triggered, this, &MainWindow::MostrarCadastroDisc);
    connect(ui->actionAluno, &QAction::triggered, this, &MainWindow::MostrarCadastroAluno);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MostrarCadastroUniv()
{
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(false);
    ui->textEdit_3->setVisible(false);

    ui->label->setText("Universidade");
}

void MainWindow::MostrarCadastroDepto()
{
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->textEdit_3->setVisible(false);

    ui->label->setText("Universidade");
    ui->label_2->setText("Departamento");
}

void MainWindow::MostrarCadastroDisc()
{
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->textEdit_3->setVisible(false);

    ui->label->setText("Departamento");
    ui->label_2->setText("Disciplina");
}

void MainWindow::MostrarCadastroAluno()
{
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->textEdit_3->setVisible(true);

    ui->label->setText("Disciplina");
    ui->label_2->setText("Aluno");
}

void MainWindow::onNewActionTriggered() {
    //stackedWidget->setCurrentIndex(0);
}
void MainWindow::onOptionsActionTriggered() {
    //stackedWidget->setCurrentIndex(1);
}
void MainWindow::onShowActionTriggered() {
    //stackedWidget->setCurrentIndex(1);
}
