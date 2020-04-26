#ifndef JUSTFORFUN_H
#define JUSTFORFUN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class JustForFun; }
QT_END_NAMESPACE

class JustForFun : public QMainWindow
{
    Q_OBJECT

public:
    JustForFun(QWidget *parent = nullptr);
    ~JustForFun();

private slots:
    void buttonPressed();

private:
    Ui::JustForFun *ui;
};
#endif // JUSTFORFUN_H
