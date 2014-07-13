#pragma once

#include <QtWidgets/QMainWindow>
#include <QtCore/QScopedPointer>

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
    
private:
    QScopedPointer<Ui::MainWindow> ui;
};
