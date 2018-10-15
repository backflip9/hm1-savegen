#ifndef HOTLINESAVE_H
#define HOTLINESAVE_H

#include <QMainWindow>
#include<QFileDialog>
#include<QStandardPaths>
#include<QDir>
#include <QMessageBox>
#include <QShortcut>
#include <QtDebug>



namespace Ui {
class hotlineSave;
}

class hotlineSave : public QMainWindow
{
    Q_OBJECT

public:
    explicit hotlineSave(QWidget *parent = nullptr);
    ~hotlineSave();

private slots:
    void on_pushButton_clicked();


    void on_ngPlus_clicked(bool checked);

    void on_externalSav_clicked();

    void on_goButton_clicked();

private:
    Ui::hotlineSave *ui;
};

#endif // HOTLINESAVE_H
