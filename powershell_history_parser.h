#ifndef POWERSHELL_HISTORY_PARSER_H
#define POWERSHELL_HISTORY_PARSER_H

#include <QMainWindow>
#include <QDebug>
#include <QtCore>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class powershell_history_parser; }
QT_END_NAMESPACE

class powershell_history_parser : public QMainWindow
{
    Q_OBJECT

public:
    powershell_history_parser(QWidget *parent = nullptr);
    ~powershell_history_parser();


private slots:
    void get_powershell_history();


private:
    Ui::powershell_history_parser *ui;

    QString powershell_history_file_path = "C:/Users/amank/AppData/Roaming/Microsoft/Windows/PowerShell/PSReadLine/ConsoleHost_history.txt";

    QString powershell_cmd_history;

    QString destination_database_path = "C:/Users/amank/Desktop/ConsoleHost_history.db";

};
#endif // POWERSHELL_HISTORY_PARSER_H
