#include <QCoreApplication>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);   

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/names.db");
    if (db.open() == false) {
        qDebug() << db.lastError().text();
        return 1;
    } else {
        qDebug() << "Connected to database " << db.databaseName();
    }

    // SELECT
    // INSERT
    // DELETE
    // ALTER/UPDATE

    QSqlQuery query;
    QString cmd = "SELECT * FROM general;";
    query.exec(cmd);
    QString error = query.lastError().databaseText();
    if (error.isEmpty() == false) {
        qDebug() << "Error happened: " << error;
        return 2;
    }
    while (query.next()) {
        qDebug() << "|" << query.value("Name").toString() << "\t|" <<
                    query.value("Surname").toString() << "\t|" <<
                    query.value("Cash").toInt() << "\t|";
    }
    return 0;
}
