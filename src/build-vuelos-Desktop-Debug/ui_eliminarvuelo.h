/********************************************************************************
** Form generated from reading UI file 'eliminarvuelo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINARVUELO_H
#define UI_ELIMINARVUELO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EliminarVuelo
{
public:
    QDialogButtonBox *button_Eliminar;
    QLabel *label;
    QComboBox *comboBox_Origen;
    QComboBox *comboBox_Destino;
    QLabel *statusLabel;

    void setupUi(QDialog *EliminarVuelo)
    {
        if (EliminarVuelo->objectName().isEmpty())
            EliminarVuelo->setObjectName(QString::fromUtf8("EliminarVuelo"));
        EliminarVuelo->resize(400, 234);
        button_Eliminar = new QDialogButtonBox(EliminarVuelo);
        button_Eliminar->setObjectName(QString::fromUtf8("button_Eliminar"));
        button_Eliminar->setGeometry(QRect(-60, 150, 341, 32));
        button_Eliminar->setOrientation(Qt::Horizontal);
        button_Eliminar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(EliminarVuelo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 40, 281, 20));
        comboBox_Origen = new QComboBox(EliminarVuelo);
        comboBox_Origen->setObjectName(QString::fromUtf8("comboBox_Origen"));
        comboBox_Origen->setGeometry(QRect(30, 80, 141, 25));
        comboBox_Destino = new QComboBox(EliminarVuelo);
        comboBox_Destino->setObjectName(QString::fromUtf8("comboBox_Destino"));
        comboBox_Destino->setGeometry(QRect(200, 80, 141, 25));
        statusLabel = new QLabel(EliminarVuelo);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(80, 120, 231, 17));

        retranslateUi(EliminarVuelo);
        QObject::connect(button_Eliminar, SIGNAL(accepted()), EliminarVuelo, SLOT(accept()));
        QObject::connect(button_Eliminar, SIGNAL(rejected()), EliminarVuelo, SLOT(reject()));

        QMetaObject::connectSlotsByName(EliminarVuelo);
    } // setupUi

    void retranslateUi(QDialog *EliminarVuelo)
    {
        EliminarVuelo->setWindowTitle(QCoreApplication::translate("EliminarVuelo", "Eliminar conexion", nullptr));
        label->setText(QCoreApplication::translate("EliminarVuelo", "Cual vuelo desea eliminar:", nullptr));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EliminarVuelo: public Ui_EliminarVuelo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINARVUELO_H
