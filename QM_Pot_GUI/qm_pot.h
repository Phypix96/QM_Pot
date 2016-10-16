#ifndef QM_POT_H
#define QM_POT_H

#include <QMainWindow>

namespace Ui {
class QM_Pot;
}

class QM_Pot : public QMainWindow
{
    Q_OBJECT

public:
    explicit QM_Pot(QWidget *parent = 0);
    ~QM_Pot();

private:
    Ui::QM_Pot *ui;
};

#endif // QM_POT_H
