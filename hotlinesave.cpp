#include "hotlinesave.h"
#include "ui_hotlinesave.h"

hotlineSave::hotlineSave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hotlineSave)
{
    ui->setupUi(this);
    ui->ngPlusPath->hide();
    ui->externalSav->hide();
    ui->tmplabel->hide();
    //ui->label->setText("Searching for save file...");
    if(QDir(QDir::homePath()+ "/Documents/My Games/HotlineMiami").exists("SaveData.sav")){
        qInfo("savedata exists");
        //ui->label->setText("Found  save file at " + QDir::homePath() + "/Documents/My Games/HotlineMiami/SaveData.sav. If your copy of HM1 reads a different savefile, use the button to point me to the save file you want to interact with");
        ui->label->setText(QDir::homePath() + "/Documents/My Games/HotlineMiami/SaveData.sav");
        QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Found save file at " + QDir::homePath() + "/Documents/My Games/HotlineMiami/SaveData.sav. If your copy of HM1 reads a different savefile, use the button to point me to the save file you want to interact with",QMessageBox::Ok,this);
        something.exec();
    }
    else{
        ui->label->hide();
        qInfo("savedata does not exist");
        QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Couldn't find save file at " + QDir::homePath() + "/Documents/My Games/HotlineMiami. Use the next window to find where your HM1 save file is located",QMessageBox::Ok, this);
        something.exec();
    }
}

hotlineSave::~hotlineSave()
{
    delete ui;
}

void hotlineSave::on_pushButton_clicked()
{
    QFileDialog fileQuery(this,"SaveData.sav Location",QDir::homePath()+"/Documents/My Games/");
    fileQuery.setFileMode(QFileDialog::AnyFile);
    fileQuery.setOption(QFileDialog::DontUseNativeDialog);
    fileQuery.exec();
    QStringList filenames = fileQuery.selectedFiles();
    //QString file1=filenames.first();
    if(QFile(fileQuery.selectedFiles().first()).exists()){
        if(QFileInfo(fileQuery.selectedFiles().first()).isDir()){
            if(QDir(fileQuery.selectedFiles().first()).exists("SaveData.sav")){
                QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Found save file at " + filenames.first()+ "/SaveData.sav. If your copy of HM1 reads a different savefile, use the button to point me to the save file you want to interact with",QMessageBox::Ok,this);
                something.exec();
                ui->label->setText(fileQuery.selectedFiles().first() + "SaveData.sav");
                if(!ui->label->isVisible()){
                    ui->label->show();
                }
            }
            else{
            ui->label->hide();
            QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Couldn't find save file at " + fileQuery.selectedFiles().first(),QMessageBox::Ok,this);
                something.exec();
            }
        }
        else if(QFileInfo(fileQuery.selectedFiles().first()).isFile()){
            if(QFileInfo(fileQuery.selectedFiles().first()).fileName()=="SaveData.sav"){
                QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Found save file at " + filenames.first()+ ". If your copy of HM1 reads a different savefile, use the button to point me to the save file you want to interact with",QMessageBox::Ok,this);
                something.exec();
                ui->label->setText(fileQuery.selectedFiles().first());
                if(!ui->label->isVisible()){
                    ui->label->show();
                }
            }
            else{
            ui->label->hide();
            QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Couldn't find save file at " + fileQuery.selectedFiles().first(),QMessageBox::Ok,this);
                something.exec();
            }
        }
        else{
            ui->label->hide();
            QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Filename doesn't exist",QMessageBox::Ok,this);
            something.exec();
        }
    }
    else{
        ui->label->hide();
        QMessageBox something(QMessageBox::Information,"SaveData.sav Location","Filename invalid",QMessageBox::Ok,this);
        something.exec();
    }
}

void hotlineSave::on_ngPlus_clicked(bool checked)
{
    if(checked){
        ui->externalSav->show();
        ui->ngPlusPath->show();
    }
    else if(!checked){
        ui->externalSav->hide();
        ui->ngPlusPath->hide();
    }
}

void hotlineSave::on_externalSav_clicked()
{
    QFileDialog fileQuery(this,"SaveData.sav Location",QDir::homePath()+"/Documents/My Games/");
    fileQuery.setFileMode(QFileDialog::AnyFile);
    fileQuery.setOption(QFileDialog::DontUseNativeDialog);
    fileQuery.exec();
    ui->ngPlusPath->setText(fileQuery.selectedFiles().first());
    if(!ui->ngPlusPath->isVisible()){
        ui->ngPlusPath->show();
    }
}

void hotlineSave::on_goButton_clicked()
{
    if(QFile(ui->label->text()).remove()){
        ui->tmplabel->setText("deleted " + ui->label->text());
        ui->tmplabel->show();
    }
    else{
        ui->tmplabel->setText("something failed");
        ui->tmplabel->show();
        return;
    }
    if(ui->ngPlus->isChecked()){
        QFile ngSave(ui->ngPlusPath->text());
        if(ngSave.copy(ui->label->text())){
           //notification would go here
           ui->tmplabel->setText("copied " + ui->ngPlusPath->text() + " to " + ui->label->text());
           ui->tmplabel->show();
        }
        else{
           ui->tmplabel->setText("something failed2\n" + ui->ngPlusPath->text() +  " to " + ui->label->text());
           ui->tmplabel->show();
           return;
        }
    }
    //notification would go here


}
