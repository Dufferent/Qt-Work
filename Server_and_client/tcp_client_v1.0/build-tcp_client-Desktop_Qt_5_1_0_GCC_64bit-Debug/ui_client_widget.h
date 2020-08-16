/********************************************************************************
** Form generated from reading UI file 'client_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_WIDGET_H
#define UI_CLIENT_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client_Widget
{
public:

    void setupUi(QWidget *Client_Widget)
    {
        if (Client_Widget->objectName().isEmpty())
            Client_Widget->setObjectName(QStringLiteral("Client_Widget"));
        Client_Widget->resize(400, 300);

        retranslateUi(Client_Widget);

        QMetaObject::connectSlotsByName(Client_Widget);
    } // setupUi

    void retranslateUi(QWidget *Client_Widget)
    {
        Client_Widget->setWindowTitle(QApplication::translate("Client_Widget", "Client_Widget", 0));
    } // retranslateUi

};

namespace Ui {
    class Client_Widget: public Ui_Client_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_WIDGET_H
