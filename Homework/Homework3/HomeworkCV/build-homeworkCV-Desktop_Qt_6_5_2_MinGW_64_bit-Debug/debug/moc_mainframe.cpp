/****************************************************************************
** Meta object code from reading C++ file 'mainframe.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../00 - HomeworkCV_students/mainframe.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainFrameENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainFrameENDCLASS = QtMocHelpers::stringData(
    "MainFrame",
    "on_buttonOpen_clicked",
    "",
    "on_buttonDeleteContents_clicked",
    "on_tabWidget_currentChanged",
    "index",
    "on_buttonShowList_clicked",
    "on_pushOstu_clicked",
    "on_pushThresholding_clicked",
    "on_pushDilation_clicked",
    "on_pushErosion_clicked",
    "on_pushLabeling_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainFrameENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[28];
    char stringdata5[6];
    char stringdata6[26];
    char stringdata7[20];
    char stringdata8[28];
    char stringdata9[24];
    char stringdata10[23];
    char stringdata11[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainFrameENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainFrameENDCLASS_t qt_meta_stringdata_CLASSMainFrameENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "MainFrame"
        QT_MOC_LITERAL(10, 21),  // "on_buttonOpen_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 31),  // "on_buttonDeleteContents_clicked"
        QT_MOC_LITERAL(65, 27),  // "on_tabWidget_currentChanged"
        QT_MOC_LITERAL(93, 5),  // "index"
        QT_MOC_LITERAL(99, 25),  // "on_buttonShowList_clicked"
        QT_MOC_LITERAL(125, 19),  // "on_pushOstu_clicked"
        QT_MOC_LITERAL(145, 27),  // "on_pushThresholding_clicked"
        QT_MOC_LITERAL(173, 23),  // "on_pushDilation_clicked"
        QT_MOC_LITERAL(197, 22),  // "on_pushErosion_clicked"
        QT_MOC_LITERAL(220, 23)   // "on_pushLabeling_clicked"
    },
    "MainFrame",
    "on_buttonOpen_clicked",
    "",
    "on_buttonDeleteContents_clicked",
    "on_tabWidget_currentChanged",
    "index",
    "on_buttonShowList_clicked",
    "on_pushOstu_clicked",
    "on_pushThresholding_clicked",
    "on_pushDilation_clicked",
    "on_pushErosion_clicked",
    "on_pushLabeling_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainFrameENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    1,   70,    2, 0x08,    3 /* Private */,
       6,    0,   73,    2, 0x08,    5 /* Private */,
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    0,   75,    2, 0x08,    7 /* Private */,
       9,    0,   76,    2, 0x08,    8 /* Private */,
      10,    0,   77,    2, 0x08,    9 /* Private */,
      11,    0,   78,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainFrameENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainFrameENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainFrameENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainFrame, std::true_type>,
        // method 'on_buttonOpen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonDeleteContents_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tabWidget_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_buttonShowList_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushOstu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushThresholding_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushDilation_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushErosion_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushLabeling_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_buttonOpen_clicked(); break;
        case 1: _t->on_buttonDeleteContents_clicked(); break;
        case 2: _t->on_tabWidget_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_buttonShowList_clicked(); break;
        case 4: _t->on_pushOstu_clicked(); break;
        case 5: _t->on_pushThresholding_clicked(); break;
        case 6: _t->on_pushDilation_clicked(); break;
        case 7: _t->on_pushErosion_clicked(); break;
        case 8: _t->on_pushLabeling_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainFrameENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
