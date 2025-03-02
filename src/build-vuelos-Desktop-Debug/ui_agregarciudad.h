/********************************************************************************
** Form generated from reading UI file 'agregarciudad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARCIUDAD_H
#define UI_AGREGARCIUDAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AgregarCiudad
{
public:
    QDialogButtonBox *button_Aceptar;
    QLineEdit *lineEditCiudad;
    QLabel *label;
    QLineEdit *lineEditCiudadX;
    QLineEdit *lineEditCiudadY;

    void setupUi(QDialog *AgregarCiudad)
    {
        if (AgregarCiudad->objectName().isEmpty())
            AgregarCiudad->setObjectName(QString::fromUtf8("AgregarCiudad"));
        AgregarCiudad->resize(396, 214);
        button_Aceptar = new QDialogButtonBox(AgregarCiudad);
        button_Aceptar->setObjectName(QString::fromUtf8("button_Aceptar"));
        button_Aceptar->setGeometry(QRect(110, 140, 171, 32));
        button_Aceptar->setOrientation(Qt::Horizontal);
        button_Aceptar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEditCiudad = new QLineEdit(AgregarCiudad);
        lineEditCiudad->setObjectName(QString::fromUtf8("lineEditCiudad"));
        lineEditCiudad->setGeometry(QRect(30, 80, 161, 31));
        label = new QLabel(AgregarCiudad);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 331, 17));
        lineEditCiudadX = new QLineEdit(AgregarCiudad);
        lineEditCiudadX->setObjectName(QString::fromUtf8("lineEditCiudadX"));
        lineEditCiudadX->setGeometry(QRect(200, 80, 51, 31));
        lineEditCiudadY = new QLineEdit(AgregarCiudad);
        lineEditCiudadY->setObjectName(QString::fromUtf8("lineEditCiudadY"));
        lineEditCiudadY->setGeometry(QRect(260, 80, 51, 31));

        retranslateUi(AgregarCiudad);
        QObject::connect(button_Aceptar, SIGNAL(accepted()), AgregarCiudad, SLOT(accept()));
        QObject::connect(button_Aceptar, SIGNAL(rejected()), AgregarCiudad, SLOT(reject()));

        QMetaObject::connectSlotsByName(AgregarCiudad);
    } // setupUi

    void retranslateUi(QDialog *AgregarCiudad)
    {
        AgregarCiudad->setWindowTitle(QCoreApplication::translate("AgregarCiudad", "Agregar ciudad", nullptr));
        label->setText(QCoreApplication::translate("AgregarCiudad", "Agregue la ciudad que desee y sus coordenadas:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgregarCiudad: public Ui_AgregarCiudad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARCIUDAD_H
