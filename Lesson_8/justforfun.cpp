#include "justforfun.h"
#include "ui_justforfun.h"

JustForFun::JustForFun(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JustForFun)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &JustForFun::buttonPressed);
    connect(ui->dial, &QDial::valueChanged, ui->prikol_1, &QSlider::setValue);
    connect(ui->dial, &QDial::valueChanged, ui->prikol_2, &QSlider::setValue);

}

JustForFun::~JustForFun()
{
    delete ui;
}

void JustForFun::buttonPressed()
{
    QString text = ui->userInput->text();
    ui->result->setText("Привет, " + text);
}

