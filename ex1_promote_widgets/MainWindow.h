#pragma once

#include <QtWidgets/QMainWindow>
#include <QScopedPointer>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget* parent = Q_NULLPTR);
    virtual ~MainWindow();

public slots:
    void hideView();
    void showView();
    
private:
    QScopedPointer<Ui::MainWindow> ui;
};
