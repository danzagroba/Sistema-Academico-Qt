#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QEvent>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , estado(0)
    , tipo(0)
    , caixaAberta(false)
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

    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::SegundaLista);

    qApp->installEventFilter(this);


}


bool MainWindow::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            if(!caixaAberta) {
                BotaoApertado();
                caixaAberta = true;
            }
            if (caixaAberta) {
                foreach (QWidget *widget, QApplication::topLevelWidgets()) {
                    if (QMessageBox *mbox = qobject_cast<QMessageBox*>(widget)) {
                        mbox->close();
                    }
                }
                caixaAberta = false;
            }
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

MainWindow::~MainWindow()
{
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
        caixaAberta = true;
        Sistema.CadUniversidade(ui->textEdit->toPlainText().toStdString().c_str());
        ui->textEdit->setHtml("");
    } else if(tipo == 2)
    {
        caixaAberta = true;
        Sistema.CadDepartamento(ui->textEdit->toPlainText().toStdString().c_str(), ui->textEdit_2->toPlainText().toStdString().c_str());
        ui->textEdit_2->setHtml("");
    }else if(tipo == 3)
    {
        caixaAberta = true;
        Sistema.CadDisciplina(ui->textEdit->toPlainText().toStdString().c_str(), ui->textEdit_2->toPlainText().toStdString().c_str());
        ui->textEdit_2->setHtml("");
    }else if(tipo == 4)
    {
        caixaAberta = true;
        Sistema.CadAluno(
            ui->textEdit->toPlainText().toStdString().c_str(),
            ui->textEdit_2->toPlainText().toStdString().c_str(),
            ui->textEdit_3->toPlainText().toInt());

        ui->textEdit_2->setHtml("");
        ui->textEdit_3->setHtml("");
        caixaAberta = true;

    }else if(tipo == 0)
    {
        caixaAberta = 0;

    }else
    {
        QMessageBox messageBox;
        messageBox.warning(0,"Erro","tipo não encontrado");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::ListarUniversidades()
{
    tipo = 5;
    ui->listWidget->clear();

    std::list<Universidade*>::iterator IteradorLUniversidades = Sistema.LUniversidades.getBegin();
    while (IteradorLUniversidades!= Sistema.LUniversidades.getEnd())
    {
        QString aux = QString::fromStdString((*IteradorLUniversidades)->getNome());

        ui->listWidget->addItem(aux);
        IteradorLUniversidades++;
    }

    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(true);

    ui->label_4->setText("Universidades");
    ui->label_5->setText("Departamentos");

}

void MainWindow::ListarDepartamentos()
{
    tipo = 6;
    ui->listWidget->clear();

    std::list<Departamento*>::iterator IteradorLDepartamentos = Sistema.LDepartamentos.getBegin();
    while (IteradorLDepartamentos!= Sistema.LDepartamentos.getEnd())
    {
        QString aux = QString::fromStdString((*IteradorLDepartamentos)->getNome());

        ui->listWidget->addItem(aux);
        IteradorLDepartamentos++;
    }

    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(true);

    ui->label_4->setText("Departamentos");
    ui->label_5->setText("Disciplinas");

}

void MainWindow::ListarDisciplinas()
{
    tipo = 7;
    ui->listWidget->clear();

    std::list<Disciplina*>::iterator IteradorLDisciplinas = Sistema.LDisciplinas.getBegin();
    while (IteradorLDisciplinas!= Sistema.LDisciplinas.getEnd())
    {
        QString aux = QString::fromStdString((*IteradorLDisciplinas)->getNome());

        ui->listWidget->addItem(aux);
        IteradorLDisciplinas++;
    }

    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(true);

    ui->label_4->setText("Disciplinas");
    ui->label_5->setText("Alunos");

}

void MainWindow::ListarAlunos()
{
    tipo = 8;
    ui->listWidget->clear();

    std::list<Aluno*>::iterator IteradorLAlunos = Sistema.LAlunos.getBegin();
    while (IteradorLAlunos!= Sistema.LAlunos.getEnd())
    {
        QString aux = QString::fromStdString((*IteradorLAlunos)->getNome());

        ui->listWidget->addItem(aux);
        IteradorLAlunos++;
    }

    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(false);

    ui->label_4->setText("Alunos");
    ui->label_5->setText("");
}

void MainWindow::ListarTudo()
{
    tipo = 9;
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(true);

    ui->listWidget_2->setVisible(false);

    ui->label_4->setText("Tudo");
    ui->label_5->setText("");
}

void MainWindow::SegundaLista(QListWidgetItem *item)
{
    ui->listWidget_2->clear();
    string nome = item->text().toStdString();
    const char* nomec = nome.c_str();
    if(tipo == 5)
    {
        std::vector<Departamento*>::iterator IteradorLDepartamentos = Sistema.LUniversidades.localizar(nomec)->getDepartamentosBegin();
        while (IteradorLDepartamentos!= Sistema.LUniversidades.localizar(nomec)->getDepartamentosEnd())
        {
            QString aux = QString::fromStdString((*IteradorLDepartamentos)->getNome());

            ui->listWidget_2->addItem(aux);
            IteradorLDepartamentos++;
        }
    } else if(tipo == 6)
    {
        std::vector<Disciplina*>::iterator IteradorLDisciplinas = Sistema.LDepartamentos.localizar(nomec)->getDisciplinasBegin();
        while (IteradorLDisciplinas!= Sistema.LDepartamentos.localizar(nomec)->getDisciplinasEnd())
        {
            QString aux = QString::fromStdString((*IteradorLDisciplinas)->getNome());

            ui->listWidget_2->addItem(aux);
            IteradorLDisciplinas++;
        }

    } else if(tipo == 7)
    {
        std::vector<Aluno*>::iterator IteradorLAlunos = Sistema.LDisciplinas.localizar(nomec)->getAlunosBegin();
        while (IteradorLAlunos!= Sistema.LDisciplinas.localizar(nomec)->getAlunosEnd())
        {
            QString aux = QString::fromStdString((*IteradorLAlunos)->getNome());

            ui->listWidget_2->addItem(aux);
            IteradorLAlunos++;
        }
    }
}

/*void MainWindow::listaTudo()
{
    listaUniv();
    listaDept();
    listaDisc();
    listaAlun();
}


void MainWindow::onNewActionTriggered() {
    //stackedWidget->setCurrentIndex(0);
}
void MainWindow::onOptionsActionTriggered() {
    //stackedWidget->setCurrentIndex(1);
}
void MainWindow::onShowActionTriggered() {
    //stackedWidget->setCurrentIndex(1);
}*/
