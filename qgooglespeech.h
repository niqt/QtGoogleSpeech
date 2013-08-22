#ifndef QGOOGLESPEECH_H
#define QGOOGLESPEECH_H

#include "qgooglespeech_global.h"
#include <QString>
#include <QObject>
#include <QtMultimedia>

class QGOOGLESPEECHSHARED_EXPORT QGoogleSpeech: QObject
{
    Q_OBJECT
private:
    QString m_language;
    QMediaPlaylist *m_playlist;
    QMediaPlayer *m_player;
    QString m_url;
public:
    QGoogleSpeech(QString language);
    void setLanguage(QString language);
    Q_INVOKABLE void speech(QString text);

private slots:
    void errorSlot();
    void state(QMediaPlayer::State state);
signals:
    void stopped();
    void error();
};

#endif // QGOOGLESPEECH_H
