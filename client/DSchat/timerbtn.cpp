#include "timerbtn.h"

TimerBtn::TimerBtn(QWidget *parent) : QPushButton(parent), _counter(10)
{
    _timer = new QTimer(this);

    connect(_timer, &QTimer::timeout, [this](){
        _counter--;
        if(_counter <= 0){
            _timer->stop();
            _counter = 10;
            this->setText("获取");
            this->setEnabled(true);
            return;
        }
        this->setText(QString::number(_counter));
    });
}

TimerBtn::~TimerBtn()
{
    _timer->stop();
}

void TimerBtn::startCountdown()
{
    this->setEnabled(false);
    this->setText(QString::number(_counter));
    _timer->start(1000);
}
