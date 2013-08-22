#include "qgooglespeech.h"


QGoogleSpeech::QGoogleSpeech(QString language)
{
    m_language = language;

    m_playlist = new QMediaPlaylist;

    m_player = new QMediaPlayer;

    QObject::connect(m_player, SIGNAL(error(QMediaPlayer::Error)),
                     this, SLOT(errorSlot()) );


    QObject::connect(m_player, SIGNAL(stateChanged(QMediaPlayer::State)),
                     this, SLOT(errorSlot()) );


}

void QGoogleSpeech::setLanguage(QString language)
{
    m_language = language;
}

void QGoogleSpeech::speech(QString text)
{
    if (QMultimedia::Available == 0)  {
        m_playlist->addMedia(QUrl("http://translate.google.com/translate_tts?ie=UTF-8&tl=it&q=" + text));
        m_player->setPlaylist(m_playlist);
        m_player->play();
    } else {
        emit error();
    }

}

void QGoogleSpeech::errorSlot()
{
    emit error();
}

void QGoogleSpeech::state(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::StoppedState)
        emit stopped();
}
