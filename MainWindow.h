#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MyDownloader;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_downloadPushButton_clicked();
private:
    Ui::MainWindow *ui;
    MyDownloader *mDownloader;
};

#endif // MAINWINDOW_H
