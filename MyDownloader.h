#ifndef MYDOWNLOADER_H
#define MYDOWNLOADER_H

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;

class MyDownloader : public QObject
{
    Q_OBJECT
public:
    MyDownloader(QObject *parent = nullptr);
    void setUrl(const QUrl &url);
    QUrl url() const;
    void download();
signals:
    void downloaded(const QByteArray &data);
    void errorOccurred(const QString &errorString);
private:
    QNetworkAccessManager *mManager;
    QUrl mUrl;
};

#endif // MYDOWNLOADER_H
