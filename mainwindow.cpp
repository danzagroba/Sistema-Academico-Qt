#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , estado(0)
    , tipo(0)
{
    ui->setupUi(this);
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);

    connect(ui->actionUniversidade, &QAction::triggered, this, &MainWindow::MostrarCadastroUniv);
    connect(ui->actionDepartamento, &QAction::triggered, this, &MainWindow::MostrarCadastroDepto);
    connect(ui->actionDisciplina, &QAction::triggered, this, &MainWindow::MostrarCadastroDisc);
    connect(ui->actionAluno, &QAction::triggered, this, &MainWindow::MostrarCadastroAluno);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::BotaoApertado);

    connect(ui->actionUniversidades, &QAction::triggered, this, &MainWindow::ListarUniversidades);
    connect(ui->actionDepartamentos, &QAction::triggered, this, &MainWindow::ListarDepartamentos);
    connect(ui->actionDisciplinas, &QAction::triggered, this, &MainWindow::ListarDisciplinas);
    connect(ui->actionAlunos, &QAction::triggered, this, &MainWindow::ListarAlunos);
    connect(ui->actionTudo, &QAction::triggered, this, &MainWindow::ListarTudo);




}

MainWindow::~MainWindow()
{\
    delete ui;
}

void MainWindow::MostrarCadastroUniv()
{
    tipo = 1;
    ui->widget->setVisible(true);
    ui->widget_2->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->textEdit_2->setVisible(false);
    ui->textEdit_3->setVisible(false);

    ui->label->setText("Universidade");

    ui->textEdit->setHtml("");
    ui->textEdit_2->setHtml("");
    ui->textEdit_3->setHtml("");
}

void MainWindow::MostrarCadastroDepto()
{
    tipo = 2;
    ui->widget->setVisible(true);
    ui->widget_2->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(false);
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
    tipo = 3;
    ui->widget->setVisible(true);
    ui->widget_2->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(false);
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
    tipo = 4;
    ui->widget->setVisible(true);
    ui->widget_2->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
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
    if(tipo == 1)
    {
        Sistema.CadUniversidade(ui->textEdit->toPlainText().toStdString().c_str());
        ui->textEdit->setHtml("");
    } else if(tipo == 2)
    {
        Sistema.CadDepartamento(ui->textEdit->toPlainText().toStdString().c_str(), ui->textEdit_2->toPlainText().toStdString().c_str());
        ui->textEdit_2->setHtml("");
    }else if(tipo == 3)
    {
        Sistema.CadDisciplina(ui->textEdit->toPlainText().toStdString().c_str(), ui->textEdit_2->toPlainText().toStdString().c_str());
        ui->textEdit_2->setHtml("");
    }else if(tipo == 4)
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
        messageBox.warning(0,"Erro","tipo não encontrado");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::ListarUniversidades()
{
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(true);

    ui->label_4->setText("Universidades");
    ui->label_5->setText("Disciplinas");

}

void MainWindow::ListarDepartamentos()
{
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(true);

    ui->label_4->setText("Departamentos");
    ui->label_5->setText("Disciplinas");

}

void MainWindow::ListarDisciplinas()
{
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(true);

    ui->label_4->setText("Disciplinas");
    ui->label_5->setText("Alunos");

}

void MainWindow::ListarAlunos()
{
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(false);

    ui->label_4->setText("Alunos");
    ui->label_5->setText("");
}

void MainWindow::ListarTudo()
{
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(false);

    ui->label_4->setText("Tudo");
    ui->label_5->setText("");
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
