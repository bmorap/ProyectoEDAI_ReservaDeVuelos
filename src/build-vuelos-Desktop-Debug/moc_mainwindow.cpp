/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../vuelos/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "updateMapDisplay"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "QVector<QString>"
QT_MOC_LITERAL(4, 46, 4), // "ruta"
QT_MOC_LITERAL(5, 51, 25), // "button_calcularRutaOptima"
QT_MOC_LITERAL(6, 77, 31), // "on_button_AgregarCiudad_clicked"
QT_MOC_LITERAL(7, 109, 25), // "agregarCiudadDesdeVentana"
QT_MOC_LITERAL(8, 135, 6), // "nombre"
QT_MOC_LITERAL(9, 142, 1), // "x"
QT_MOC_LITERAL(10, 144, 1), // "y"
QT_MOC_LITERAL(11, 146, 33), // "on_button_AgregarConexion_cli..."
QT_MOC_LITERAL(12, 180, 28), // "agregarConexionDesdeVentana3"
QT_MOC_LITERAL(13, 209, 6), // "origen"
QT_MOC_LITERAL(14, 216, 7), // "destino"
QT_MOC_LITERAL(15, 224, 4), // "peso"
QT_MOC_LITERAL(16, 229, 32), // "on_button_EliminarCiudad_clicked"
QT_MOC_LITERAL(17, 262, 27), // "eliminarCiudadDesdeVentana4"
QT_MOC_LITERAL(18, 290, 31), // "on_button_EliminarVuelo_clicked"
QT_MOC_LITERAL(19, 322, 29) // "eliminarConexionDesdeVentana5"

    },
    "MainWindow\0updateMapDisplay\0\0"
    "QVector<QString>\0ruta\0button_calcularRutaOptima\0"
    "on_button_AgregarCiudad_clicked\0"
    "agregarCiudadDesdeVentana\0nombre\0x\0y\0"
    "on_button_AgregarConexion_clicked\0"
    "agregarConexionDesdeVentana3\0origen\0"
    "destino\0peso\0on_button_EliminarCiudad_clicked\0"
    "eliminarCiudadDesdeVentana4\0"
    "on_button_EliminarVuelo_clicked\0"
    "eliminarConexionDesdeVentana5"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    3,   69,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    3,   77,    2, 0x08 /* Private */,
      16,    0,   84,    2, 0x08 /* Private */,
      17,    1,   85,    2, 0x08 /* Private */,
      18,    0,   88,    2, 0x08 /* Private */,
      19,    2,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateMapDisplay((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 1: _t->button_calcularRutaOptima(); break;
        case 2: _t->on_button_AgregarCiudad_clicked(); break;
        case 3: _t->agregarCiudadDesdeVentana((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->on_button_AgregarConexion_clicked(); break;
        case 5: _t->agregarConexionDesdeVentana3((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->on_button_EliminarCiudad_clicked(); break;
        case 7: _t->eliminarCiudadDesdeVentana4((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_button_EliminarVuelo_clicked(); break;
        case 9: _t->eliminarConexionDesdeVentana5((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
