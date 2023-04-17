/****************************************************************************
** Meta object code from reading C++ file 'GameScreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GameScreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameScreen_t {
    QByteArrayData data[14];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameScreen_t qt_meta_stringdata_GameScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameScreen"
QT_MOC_LITERAL(1, 11, 7), // "animate"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "ListaSimple"
QT_MOC_LITERAL(4, 32, 8), // "dataList"
QT_MOC_LITERAL(5, 41, 12), // "shootBullets"
QT_MOC_LITERAL(6, 54, 11), // "spawnEnemys"
QT_MOC_LITERAL(7, 66, 10), // "moveEnemys"
QT_MOC_LITERAL(8, 77, 15), // "checkCollisions"
QT_MOC_LITERAL(9, 93, 11), // "checkOleada"
QT_MOC_LITERAL(10, 105, 8), // "exePower"
QT_MOC_LITERAL(11, 114, 14), // "tempSelecStrat"
QT_MOC_LITERAL(12, 129, 14), // "tempSelecPower"
QT_MOC_LITERAL(13, 144, 14) // "pararEjecucion"

    },
    "GameScreen\0animate\0\0ListaSimple\0"
    "dataList\0shootBullets\0spawnEnemys\0"
    "moveEnemys\0checkCollisions\0checkOleada\0"
    "exePower\0tempSelecStrat\0tempSelecPower\0"
    "pararEjecucion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameScreen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,
      10,    2,   62,    2, 0x0a /* Public */,
      13,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,

       0        // eod
};

void GameScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->animate((*reinterpret_cast< const ListaSimple(*)>(_a[1]))); break;
        case 1: _t->shootBullets(); break;
        case 2: _t->spawnEnemys(); break;
        case 3: _t->moveEnemys(); break;
        case 4: _t->checkCollisions(); break;
        case 5: _t->checkOleada(); break;
        case 6: _t->exePower((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->pararEjecucion(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_GameScreen.data,
    qt_meta_data_GameScreen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameScreen.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int GameScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
