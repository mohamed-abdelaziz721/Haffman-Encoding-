#ifndef PGMDISPLAY_H
#define PGMDISPLAY_H

#include <QDialog>

namespace Ui {
class pgmdisplay;
}

class pgmdisplay : public QDialog
{
    Q_OBJECT

public:
    explicit pgmdisplay(QWidget *parent = nullptr);
    ~pgmdisplay();

private:
    Ui::pgmdisplay *ui;
};

#endif // PGMDISPLAY_H
