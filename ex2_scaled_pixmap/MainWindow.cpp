#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->keepAspectRatioCheckBox, &QCheckBox::stateChanged, [&](int state)
    {
        ui->label->setKeepAspectRatioEnabled(state == Qt::Checked);
    });

    connect(ui->overscaleCheckBox, &QCheckBox::stateChanged, [&](int state)
    {
        ui->label->setOverscaleEnabled(state == Qt::Checked);
    });

    connect(ui->loadButton, &QPushButton::clicked, [&]()
    {
        ui->label->loadPixmapData(QFileDialog::getOpenFileName(this));
    });
}

MainWindow::~MainWindow()
{}
