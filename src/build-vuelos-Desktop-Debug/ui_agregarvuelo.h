/********************************************************************************
** Form generated from reading UI file 'agregarvuelo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARVUELO_H
#define UI_AGREGARVUELO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_agregarvuelo
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBoxPeso;
    QLabel *label;
    QLabel *labelOrigen;
    QLabel *labelDestino;

    void setupUi(QDialog *agregarvuelo)
    {
        if (agregarvuelo->objectName().isEmpty())
            agregarvuelo->setObjectName(QString::fromUtf8("agregarvuelo"));
        agregarvuelo->resize(400, 207);
        buttonBox = new QDialogButtonBox(agregarvuelo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-50, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBoxPeso = new QSpinBox(agregarvuelo);
        spinBoxPeso->setObjectName(QString::fromUtf8("spinBoxPeso"));
        spinBoxPeso->setGeometry(QRect(180, 90, 44, 26));
        label = new QLabel(agregarvuelo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 60, 201, 20));
        labelOrigen = new QLabel(agregarvuelo);
        labelOrigen->setObjectName(QString::fromUtf8("labelOrigen"));
        labelOrigen->setGeometry(QRect(10, 30, 171, 20));
        labelDestino = new QLabel(agregarvuelo);
        labelDestino->setObjectName(QString::fromUtf8("labelDestino"));
        labelDestino->setGeometry(QRect(200, 30, 161, 20));

        retranslateUi(agregarvuelo);
        QObject::connect(buttonBox, SIGNAL(accepted()), agregarvuelo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), agregarvuelo, SLOT(reject()));

        QMetaObject::connectSlotsByName(agregarvuelo);
    } // setupUi

    void retranslateUi(QDialog *agregarvuelo)
    {
        agregarvuelo->setWindowTitle(QCoreApplication::translate("agregarvuelo", "Agregue vuelo", nullptr));
        label->setText(QCoreApplication::translate("agregarvuelo", "Ingrese el peso del vuelo:", nullptr));
        labelOrigen->setText(QString());
        labelDestino->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class agregarvuelo: public Ui_agregarvuelo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARVUELO_H
