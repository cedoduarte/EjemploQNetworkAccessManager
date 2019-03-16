#include "MyDownloader.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

MyDownloader::MyDownloader(QObject *parent)
    : QObject { parent }
{
    mManager = new QNetworkAccessManager(this);

    connect(mManager, &QNetworkAccessManager::finished, this, [&](QNetworkReply *reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            emit downloaded(reply->readAll());
        }
        else
        {
            emit errorOccurred(reply->errorString());
        }
    });
}

void MyDownloader::setUrl(const QUrl &url)
{
    mUrl = url;
}

QUrl MyDownloader::url() const
{
    return mUrl;
}

void MyDownloader::download()
{
    QNetworkRequest request;
    request.setUrl(mUrl);
    mManager->get(request);
}
