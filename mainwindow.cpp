#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , estado(0)
{
    ui->setupUi(this);
    ui->widget->setVisible(false);
    connect(ui->actionUniversidade, &QAction::triggered, this, &MainWindow::MostrarCadastroUniv);
    connect(ui->actionDepartamento, &QAction::triggered, this, &MainWindow::MostrarCadastroDepto);
    connect(ui->actionDisciplina, &QAction::triggered, this, &MainWindow::MostrarCadastroDisc);
    connect(ui->actionAluno, &QAction::triggered, this, &MainWindow::MostrarCadastroAluno);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::BotaoApertado);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MostrarCadastroUniv()
{
    estado = 1;
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(false);
    ui->textEdit_3->setVisible(false);

    ui->label->setText("Universidade");

    ui->textEdit->setHtml("");
    ui->textEdit_2->setHtml("");
    ui->textEdit_3->setHtml("");
}

void MainWindow::MostrarCadastroDepto()
{
    estado = 2;
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->textEdit_3->setVisible(false);

    ui->label->setText("Universidade");
    ui->label_2->setText("Departamento");

    ui->textEdit->setHtml("");
    ui->textEdit_2->setHtml("");
    ui->textEdit_3->setHtml("");
}

void MainWindow::MostrarCadastroDisc()
{
    estado = 3;
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->textEdit_3->setVisible(false);

    ui->label->setText("Departamento");
    ui->label_2->setText("Disciplina");

    ui->textEdit->setHtml("");
    ui->textEdit_2->setHtml("");
    ui->textEdit_3->setHtml("");
}

void MainWindow::MostrarCadastroAluno()
{
    estado = 4;
    ui->widget->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->textEdit_3->setVisible(true);

    ui->label->setText("Disciplina");
    ui->label_2->setText("Aluno");

    ui->textEdit->setHtml("");
    ui->textEdit_2->setHtml("");
    ui->textEdit_3->setHtml("");
}

void MainWindow::BotaoApertado()
{
    if(estado == 1)
    {
        Sistema.CadUniversidade(ui->textEdit->toPlainText().toStdString().c_str());
        ui->textEdit->setHtml("");
    } else if(estado == 2)
    {
        Sistema.CadDepartamento(ui->textEdit->toPlainText().toStdString().c_str(), ui->textEdit_2->toPlainText().toStdString().c_str());
        ui->textEdit_2->setHtml("");
    }else if(estado == 3)
    {
        Sistema.CadDisciplina(ui->textEdit->toPlainText().toStdString().c_str(), ui->textEdit_2->toPlainText().toStdString().c_str());
        ui->textEdit_2->setHtml("");
    }else if(estado == 4)
    {
        Sistema.CadAluno(
            ui->textEdit->toPlainText().toStdString().c_str(),
            ui->textEdit_2->toPlainText().toStdString().c_str(),
            ui->textEdit_3->toPlainText().toInt());

        ui->textEdit_2->setHtml("");
        ui->textEdit_3->setHtml("");

    }else
    {
        QMessageBox messageBox;
        messageBox.warning(0,"Erro","Estado não encontrado");
        messageBox.setFixedSize(500,200);
    }
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
