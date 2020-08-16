/********************************************************************************
** Form generated from reading UI file 'server_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_WIDGET_H
#define UI_SERVER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server_Widget
{
public:

    void setupUi(QWidget *Server_Widget)
    {
        if (Server_Widget->objectName().isEmpty())
            Server_Widget->setObjectName(QStringLiteral("Server_Widget"));
        Server_Widget->resize(400, 300);

        retranslateUi(Server_Widget);

        QMetaObject::connectSlotsByName(Server_Widget);
    } // setupUi

    void retranslateUi(QWidget *Server_Widget)
    {
        Server_Widget->setWindowTitle(QApplication::translate("Server_Widget", "Server_Widget", 0));
    } // retranslateUi

};

namespace Ui {
    class Server_Widget: public Ui_Server_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_WIDGET_H
