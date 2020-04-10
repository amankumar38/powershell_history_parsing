#include "powershell_history_parser.h"
#include "ui_powershell_history_parser.h"

powershell_history_parser::powershell_history_parser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::powershell_history_parser)
{
    ui->setupUi(this);
    get_powershell_history();
}

powershell_history_parser::~powershell_history_parser()
{
    delete ui;
}

void powershell_history_parser::get_powershell_history()
{
    QFile file(destination_database_path);
    file.remove(destination_database_path); //Remove db if alredy exists

    QFile inputFile(powershell_history_file_path);

    QSqlDatabase cmd_history_db = QSqlDatabase::addDatabase("QSQLITE");
    cmd_history_db.setDatabaseName(destination_database_path);
    cmd_history_db.open();

    QSqlQuery query(cmd_history_db);
    query.exec("CREATE TABLE powershell_cmd_history"
               "(bookmark integer,"
               "system_account varchar(100),"
               "command_history varchar(1024),"
               "source_file varchar(1024),"
               "source_count_name  varchar(1024),"
               "os_scheme  varchar(1024),"
               "notes varchar(1024))");

    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            powershell_cmd_history = in.readLine();

            QSqlQuery query(cmd_history_db);
            query.prepare("INSERT INTO powershell_cmd_history(bookmark, system_account, command_history, source_file,  source_count_name, os_scheme, notes) VALUES(0,?,?,?,?,?,?)");
            query.addBindValue(0);
            query.addBindValue(powershell_cmd_history);
            query.addBindValue(powershell_history_file_path);
            query.addBindValue(0);
            query.addBindValue(0);
            query.addBindValue(0);

            if(query.exec())
            {
                qDebug()<<"query executed";
            }
        }
        inputFile.close();
        cmd_history_db.close();
    }

}

