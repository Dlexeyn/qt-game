#ifndef DIALOGLEVEL_H
#define DIALOGLEVEL_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class DialogLevel;
}

class DialogLevel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLevel(QWidget *parent = nullptr);
    ~DialogLevel();

    bool getIsExit() const;

    int getLevel() const;

private slots:
    void on_lvl1Button_clicked();

    void on_exitButton_clicked();

private:
    Ui::DialogLevel *ui;

    bool isExit = false;
    int level = 0;
};

#endif // DIALOGLEVEL_H
