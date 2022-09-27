#ifndef DIALOGSIZE_H
#define DIALOGSIZE_H

#include <QDialog>

namespace Ui {
class DialogSize;
}

class DialogSize : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSize(QWidget *parent = nullptr);
    ~DialogSize();

    int getHeight() const;

    int getWidth() const;

    bool getCancel() const;

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::DialogSize *ui;
    int height, width;
    bool cancel = false;
};

#endif // DIALOGSIZE_H
