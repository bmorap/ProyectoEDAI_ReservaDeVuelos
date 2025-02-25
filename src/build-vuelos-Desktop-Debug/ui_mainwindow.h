/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *image;
    QLabel *instructions;
    QPushButton *button;
    QPushButton *zoominbutton;
    QPushButton *zoomoutbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(777, 566);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, -10, 431, 591));
        image->setScaledContents(true);
        instructions = new QLabel(centralwidget);
        instructions->setObjectName(QString::fromUtf8("instructions"));
        instructions->setGeometry(QRect(440, 10, 351, 231));
        QFont font;
        font.setFamily(QString::fromUtf8("Tlwg Typewriter"));
        instructions->setFont(font);
        instructions->setLayoutDirection(Qt::LeftToRight);
        button = new QPushButton(centralwidget);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(520, 290, 161, 41));
        zoominbutton = new QPushButton(centralwidget);
        zoominbutton->setObjectName(QString::fromUtf8("zoominbutton"));
        zoominbutton->setGeometry(QRect(0, 10, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Downloads/WhatsApp Image 2025-02-24 at 3.53.30 PM(1).jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        zoominbutton->setIcon(icon);
        zoomoutbutton = new QPushButton(centralwidget);
        zoomoutbutton->setObjectName(QString::fromUtf8("zoomoutbutton"));
        zoomoutbutton->setGeometry(QRect(30, 10, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Downloads/WhatsApp Image 2025-02-24 at 3.53.30 PM.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        zoomoutbutton->setIcon(icon1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 777, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Reserva de vuelos", nullptr));
        image->setText(QString());
        instructions->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:14pt; font-weight:600;\">\360\237\223\214 Instrucciones de uso:</span></p><p align=\"justify\">1\357\270\217\342\203\243 Selecciona tu ciudad de partida.</p><p align=\"justify\">2\357\270\217\342\203\243 Si no est\303\241 en la lista, agr\303\251gala </p><p align=\"justify\">manualmente al hacer doble click.</p><p align=\"justify\">3\357\270\217\342\203\243 Elige tu ciudad de destino.</p><p align=\"justify\">4\357\270\217\342\203\243 Haz clic en &quot;Calcular ruta \303\263ptima&quot; </p><p align=\"justify\">para encontrar el mejor camino.</p></body></html>", nullptr));
        button->setText(QCoreApplication::translate("MainWindow", "Calcular ruta \303\263ptima", nullptr));
        zoominbutton->setText(QString());
        zoomoutbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
