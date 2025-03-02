/********************************************************************************
** Form generated from reading UI file 'eliminarciudad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINARCIUDAD_H
#define UI_ELIMINARCIUDAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_eliminarciudad
{
public:
    QDialogButtonBox *button_Aceptar;
    QLabel *label;
    QLineEdit *lineEditCiudad2;

    void setupUi(QDialog *eliminarciudad)
    {
        if (eliminarciudad->objectName().isEmpty())
            eliminarciudad->setObjectName(QString::fromUtf8("eliminarciudad"));
        eliminarciudad->resize(400, 244);
        button_Aceptar = new QDialogButtonBox(eliminarciudad);
        button_Aceptar->setObjectName(QString::fromUtf8("button_Aceptar"));
        button_Aceptar->setGeometry(QRect(-60, 160, 341, 32));
        button_Aceptar->setOrientation(Qt::Horizontal);
        button_Aceptar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(eliminarciudad);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 60, 211, 17));
        lineEditCiudad2 = new QLineEdit(eliminarciudad);
        lineEditCiudad2->setObjectName(QString::fromUtf8("lineEditCiudad2"));
        lineEditCiudad2->setGeometry(QRect(140, 100, 113, 25));

        retranslateUi(eliminarciudad);
        QObject::connect(button_Aceptar, SIGNAL(accepted()), eliminarciudad, SLOT(accept()));
        QObject::connect(button_Aceptar, SIGNAL(rejected()), eliminarciudad, SLOT(reject()));

        QMetaObject::connectSlotsByName(eliminarciudad);
    } // setupUi

    void retranslateUi(QDialog *eliminarciudad)
    {
        eliminarciudad->setWindowTitle(QCoreApplication::translate("eliminarciudad", "Eliminar ciudad", nullptr));
        label->setText(QCoreApplication::translate("eliminarciudad", "Elimine la ciudad que desee:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eliminarciudad: public Ui_eliminarciudad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINARCIUDAD_H
