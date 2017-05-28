/****************************************************************************
** Meta object code from reading C++ file 'main_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../XiamiQt5/main_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_main_page_t {
    QByteArrayData data[11];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_page_t qt_meta_stringdata_main_page = {
    {
QT_MOC_LITERAL(0, 0, 9), // "main_page"
QT_MOC_LITERAL(1, 10, 9), // "loadImage"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "QPushButton*&"
QT_MOC_LITERAL(4, 35, 6), // "button"
QT_MOC_LITERAL(5, 42, 15), // "FileDownloader*"
QT_MOC_LITERAL(6, 58, 10), // "downloader"
QT_MOC_LITERAL(7, 69, 14), // "playCollection"
QT_MOC_LITERAL(8, 84, 12), // "collectionId"
QT_MOC_LITERAL(9, 97, 9), // "playAlbum"
QT_MOC_LITERAL(10, 107, 7) // "albumId"

    },
    "main_page\0loadImage\0\0QPushButton*&\0"
    "button\0FileDownloader*\0downloader\0"
    "playCollection\0collectionId\0playAlbum\0"
    "albumId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_page[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x08 /* Private */,
       7,    1,   34,    2, 0x08 /* Private */,
       9,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void main_page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        main_page *_t = static_cast<main_page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadImage((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< FileDownloader*(*)>(_a[2]))); break;
        case 1: _t->playCollection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->playAlbum((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FileDownloader* >(); break;
            }
            break;
        }
    }
}

const QMetaObject main_page::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_main_page.data,
      qt_meta_data_main_page,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *main_page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_page::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_main_page.stringdata0))
        return static_cast<void*>(const_cast< main_page*>(this));
    return QWidget::qt_metacast(_clname);
}

int main_page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
