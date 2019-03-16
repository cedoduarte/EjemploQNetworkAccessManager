#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MyDownloader.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow { parent }
    , ui { new Ui::MainWindow }
{
    ui->setupUi(this);
    mDownloader = new MyDownloader(this);

    connect(mDownloader, &MyDownloader::downloaded, this, [&](const QByteArray &data)
    {
        qDebug() << "OK";
        QString downloadedData = QString::fromLatin1(data);
        ui->plainTextEdit->setPlainText(downloadedData);
    });

    connect(mDownloader, &MyDownloader::errorOccurred, this, [&](const QString &errorString)
    {
        qDebug() << "ERROR";
        ui->plainTextEdit->setPlainText(errorString);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_downloadPushButton_clicked()
{
    mDownloader->setUrl(QUrl(ui->urlLineEdit->text()));
    mDownloader->download();
}
