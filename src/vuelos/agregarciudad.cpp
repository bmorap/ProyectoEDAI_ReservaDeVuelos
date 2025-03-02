#include "agregarciudad.h"
#include "ui_agregarciudad.h"

AgregarCiudad::AgregarCiudad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarCiudad)
{
    ui->setupUi(this);
}

AgregarCiudad::~AgregarCiudad()
{
    delete ui;
}

void AgregarCiudad::on_button_Aceptar_clicked()
{
    QString nombre = ui->lineEditCiudad->text();
    int x = ui->lineEditCiudadX->text().toInt(); // Suponiendo que usas un QSpinBox para X
    int y = ui->lineEditCiudadY->text().toInt(); // Suponiendo que usas un QSpinBox para Y

    emit ciudadAgregada(nombre, x, y); // Emitir la señal con los valores
    close(); // Cerrar la ventana después de aceptar
}

