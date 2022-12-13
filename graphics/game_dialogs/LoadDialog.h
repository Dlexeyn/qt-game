#ifndef LOADDIALOG_H
#define LOADDIALOG_H

#include <QDialog>

namespace Ui {
class LoadDialog;
}

class LoadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadDialog(QWidget *parent = nullptr);
    ~LoadDialog();
    void setSaves(std::vector<std::string> &saves);
    int getCur() const;

signals:
    void loadSave(int num);

private slots:
    void on_firstSave_clicked();

    void on_secondSave_clicked();

    void on_thirdSave_clicked();

    void on_fourthSave_clicked();

    void on_fifthSave_clicked();

    void on_cancelButton_clicked();

    void on_firstSaveDel_clicked();

    void on_secondSaveDel_clicked();

    void on_thirdSaveDel_clicked();

    void on_fourthSaveDel_clicked();

    void on_fifthSaveDel_clicked();

private:
    Ui::LoadDialog *ui;
    std::vector<std::pair<QPushButton*, QPushButton*>> buttons;
    const int COUNT_SAVES = 5;
    int cur = 0;
};

#endif // LOADDIALOG_H
