#include "qm_pot.h"
#include "ui_qm_pot.h"

QM_Pot::QM_Pot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QM_Pot)
{
    ui->setupUi(this);
}

QM_Pot::~QM_Pot()
{
    delete ui;
}
