#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionHideView, &QAction::triggered, this, &MainWindow::hideView);
    connect(ui->actionShowView, &QAction::triggered, this, &MainWindow::showView);

    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [&]()
    {
        ui->textBrowser->setHtml(ui->plainTextEdit->toPlainText());
    });

    ui->textBrowser->setHtml(ui->plainTextEdit->toPlainText());
}

MainWindow::~MainWindow()
{}

void MainWindow::hideView()
{
    ui->splitter->moveHandleAt(ui->splitter->width());
}

void MainWindow::showView()
{
    ui->splitter->moveHandleAt(ui->splitter->width() / 2);
}
