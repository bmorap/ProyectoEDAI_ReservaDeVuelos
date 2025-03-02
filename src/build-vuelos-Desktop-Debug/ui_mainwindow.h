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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QPushButton *button_calcularRutaOptima;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QPushButton *button_AgregarCiudad;
    QPushButton *button_AgregarConexion;
    QPushButton *button_EliminarCiudad;
    QPushButton *button_EliminarVuelo;
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
        image->setGeometry(QRect(10, 120, 761, 401));
        image->setScaledContents(true);
        button_calcularRutaOptima = new QPushButton(centralwidget);
        button_calcularRutaOptima->setObjectName(QString::fromUtf8("button_calcularRutaOptima"));
        button_calcularRutaOptima->setGeometry(QRect(610, 10, 161, 41));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 291, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 10, 131, 21));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(310, 40, 291, 21));
        button_AgregarCiudad = new QPushButton(centralwidget);
        button_AgregarCiudad->setObjectName(QString::fromUtf8("button_AgregarCiudad"));
        button_AgregarCiudad->setGeometry(QRect(20, 70, 161, 41));
        button_AgregarConexion = new QPushButton(centralwidget);
        button_AgregarConexion->setObjectName(QString::fromUtf8("button_AgregarConexion"));
        button_AgregarConexion->setGeometry(QRect(400, 70, 161, 41));
        button_EliminarCiudad = new QPushButton(centralwidget);
        button_EliminarCiudad->setObjectName(QString::fromUtf8("button_EliminarCiudad"));
        button_EliminarCiudad->setGeometry(QRect(210, 70, 161, 41));
        button_EliminarVuelo = new QPushButton(centralwidget);
        button_EliminarVuelo->setObjectName(QString::fromUtf8("button_EliminarVuelo"));
        button_EliminarVuelo->setGeometry(QRect(590, 70, 161, 41));
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
        button_calcularRutaOptima->setText(QCoreApplication::translate("MainWindow", "Calcular ruta \303\263ptima", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ciudad de origen:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ciudad destino:", nullptr));
        button_AgregarCiudad->setText(QCoreApplication::translate("MainWindow", "Agregar ciudad", nullptr));
        button_AgregarConexion->setText(QCoreApplication::translate("MainWindow", "Agregar vuelo", nullptr));
        button_EliminarCiudad->setText(QCoreApplication::translate("MainWindow", "Eliminar ciudad", nullptr));
        button_EliminarVuelo->setText(QCoreApplication::translate("MainWindow", "Eliminar vuelo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
