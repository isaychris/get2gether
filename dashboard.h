#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QTableView>
#include <connection.h>
#include <dialog.h>
#include <QThread>
#include <QtCore>
#include <mythread.h>
#include "display.h"

#include "display.h"

namespace Ui {
class dashboard;
}

/* Class purpose:   Creates user's main dashboard
*/
class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QString u, QWidget *parent = 0);
    ~dashboard();
    QString myuser;
    QString groupID;
    QString groupName;
    MyThread *m_pRefreshThread;
    display *displayObject;
    connection myconn;
    QString getGroupID();
    bool getMode();
    bool isGroupMode;               // to indicate group/personal mode
    bool resetStatus;
    void setMode(bool isGroup);
    void setGroupID(const QModelIndex &groupID);
    void setGroupName();
    void updateCalendarName(QString name);

private:
    Ui::dashboard *ui;

protected:
    void closeEvent(QCloseEvent * e);

signals:
    void updateTable(QTableView *tbl, QString user, QString date);
    void updateReminder(QTableView *reminderTbl, QString user);
    void updateBulletins(QTableView *bulletinTbl, QString groupID);

private slots:
    void on_loadonline_clicked();
    void on_addevents_clicked();
    void on_editEvents_clicked();
    void on_deleteEvents_clicked();
    void on_createGroup_clicked();
    void on_sendButton_clicked();
    void on_homeButton_clicked();
    void on_groupsview_clicked(const QModelIndex &index);
    void on_eventsview_clicked(const QModelIndex &index);
    void on_calendarWidget_selectionChanged();
    void on_messageBox_textChanged();
    void on_networktabs_currentChanged(int index);
    void clearEditInfo();
    void resetGroupAttributes();

    // new methods created for simplification
    int countEvents(QDate target);
    void slot_refreshThread();
    void checkNoDateEvent();
    void on_DescriptxtEdit_textChanged();
    void on_calendarWidget_clicked(const QDate &date);
};

#endif // DASHBOARD_H
