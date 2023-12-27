/****************************************************************************
** Meta object code from reading C++ file 'mainframe.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainframe.h"
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
    "on_pushRGB2Gray_clicked",
    "on_pushSepiaTone_clicked",
    "on_pushContrast_clicked",
    "on_pushHistogram_clicked",
    "on_pushOstu_clicked",
    "on_pushThresholding_clicked",
    "on_pushDilation_clicked",
    "on_pushErosion_clicked",
    "on_pushBoundary_clicked",
    "on_pushBoundaryFG_clicked",
    "on_pushGaussianNoise_clicked",
    "on_pushSaltPepper_clicked",
    "on_pushGaussianSmoothing_clicked",
    "on_pushMedianFiltering_clicked",
    "on_pushHistogramEQ_clicked",
    "on_pushHistogramMatching_clicked",
    "on_pushEdgeFDG_clicked",
    "on_pushCanny_clicked",
    "on_pushCircleLocalization_clicked",
    "on_pushHarrisCorner_clicked",
    "on_pushPyramid_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainFrameENDCLASS_t {
    uint offsetsAndSizes[56];
    char stringdata0[10];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[28];
    char stringdata5[6];
    char stringdata6[26];
    char stringdata7[24];
    char stringdata8[25];
    char stringdata9[24];
    char stringdata10[25];
    char stringdata11[20];
    char stringdata12[28];
    char stringdata13[24];
    char stringdata14[23];
    char stringdata15[24];
    char stringdata16[26];
    char stringdata17[29];
    char stringdata18[26];
    char stringdata19[33];
    char stringdata20[31];
    char stringdata21[27];
    char stringdata22[33];
    char stringdata23[23];
    char stringdata24[21];
    char stringdata25[34];
    char stringdata26[28];
    char stringdata27[23];
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
        QT_MOC_LITERAL(125, 23),  // "on_pushRGB2Gray_clicked"
        QT_MOC_LITERAL(149, 24),  // "on_pushSepiaTone_clicked"
        QT_MOC_LITERAL(174, 23),  // "on_pushContrast_clicked"
        QT_MOC_LITERAL(198, 24),  // "on_pushHistogram_clicked"
        QT_MOC_LITERAL(223, 19),  // "on_pushOstu_clicked"
        QT_MOC_LITERAL(243, 27),  // "on_pushThresholding_clicked"
        QT_MOC_LITERAL(271, 23),  // "on_pushDilation_clicked"
        QT_MOC_LITERAL(295, 22),  // "on_pushErosion_clicked"
        QT_MOC_LITERAL(318, 23),  // "on_pushBoundary_clicked"
        QT_MOC_LITERAL(342, 25),  // "on_pushBoundaryFG_clicked"
        QT_MOC_LITERAL(368, 28),  // "on_pushGaussianNoise_clicked"
        QT_MOC_LITERAL(397, 25),  // "on_pushSaltPepper_clicked"
        QT_MOC_LITERAL(423, 32),  // "on_pushGaussianSmoothing_clicked"
        QT_MOC_LITERAL(456, 30),  // "on_pushMedianFiltering_clicked"
        QT_MOC_LITERAL(487, 26),  // "on_pushHistogramEQ_clicked"
        QT_MOC_LITERAL(514, 32),  // "on_pushHistogramMatching_clicked"
        QT_MOC_LITERAL(547, 22),  // "on_pushEdgeFDG_clicked"
        QT_MOC_LITERAL(570, 20),  // "on_pushCanny_clicked"
        QT_MOC_LITERAL(591, 33),  // "on_pushCircleLocalization_cli..."
        QT_MOC_LITERAL(625, 27),  // "on_pushHarrisCorner_clicked"
        QT_MOC_LITERAL(653, 22)   // "on_pushPyramid_clicked"
    },
    "MainFrame",
    "on_buttonOpen_clicked",
    "",
    "on_buttonDeleteContents_clicked",
    "on_tabWidget_currentChanged",
    "index",
    "on_buttonShowList_clicked",
    "on_pushRGB2Gray_clicked",
    "on_pushSepiaTone_clicked",
    "on_pushContrast_clicked",
    "on_pushHistogram_clicked",
    "on_pushOstu_clicked",
    "on_pushThresholding_clicked",
    "on_pushDilation_clicked",
    "on_pushErosion_clicked",
    "on_pushBoundary_clicked",
    "on_pushBoundaryFG_clicked",
    "on_pushGaussianNoise_clicked",
    "on_pushSaltPepper_clicked",
    "on_pushGaussianSmoothing_clicked",
    "on_pushMedianFiltering_clicked",
    "on_pushHistogramEQ_clicked",
    "on_pushHistogramMatching_clicked",
    "on_pushEdgeFDG_clicked",
    "on_pushCanny_clicked",
    "on_pushCircleLocalization_clicked",
    "on_pushHarrisCorner_clicked",
    "on_pushPyramid_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainFrameENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  164,    2, 0x08,    1 /* Private */,
       3,    0,  165,    2, 0x08,    2 /* Private */,
       4,    1,  166,    2, 0x08,    3 /* Private */,
       6,    0,  169,    2, 0x08,    5 /* Private */,
       7,    0,  170,    2, 0x08,    6 /* Private */,
       8,    0,  171,    2, 0x08,    7 /* Private */,
       9,    0,  172,    2, 0x08,    8 /* Private */,
      10,    0,  173,    2, 0x08,    9 /* Private */,
      11,    0,  174,    2, 0x08,   10 /* Private */,
      12,    0,  175,    2, 0x08,   11 /* Private */,
      13,    0,  176,    2, 0x08,   12 /* Private */,
      14,    0,  177,    2, 0x08,   13 /* Private */,
      15,    0,  178,    2, 0x08,   14 /* Private */,
      16,    0,  179,    2, 0x08,   15 /* Private */,
      17,    0,  180,    2, 0x08,   16 /* Private */,
      18,    0,  181,    2, 0x08,   17 /* Private */,
      19,    0,  182,    2, 0x08,   18 /* Private */,
      20,    0,  183,    2, 0x08,   19 /* Private */,
      21,    0,  184,    2, 0x08,   20 /* Private */,
      22,    0,  185,    2, 0x08,   21 /* Private */,
      23,    0,  186,    2, 0x08,   22 /* Private */,
      24,    0,  187,    2, 0x08,   23 /* Private */,
      25,    0,  188,    2, 0x08,   24 /* Private */,
      26,    0,  189,    2, 0x08,   25 /* Private */,
      27,    0,  190,    2, 0x08,   26 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        // method 'on_pushRGB2Gray_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushSepiaTone_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushContrast_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushHistogram_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushOstu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushThresholding_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushDilation_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushErosion_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushBoundary_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushBoundaryFG_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushGaussianNoise_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushSaltPepper_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushGaussianSmoothing_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushMedianFiltering_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushHistogramEQ_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushHistogramMatching_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushEdgeFDG_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushCanny_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushCircleLocalization_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushHarrisCorner_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushPyramid_clicked'
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
        case 4: _t->on_pushRGB2Gray_clicked(); break;
        case 5: _t->on_pushSepiaTone_clicked(); break;
        case 6: _t->on_pushContrast_clicked(); break;
        case 7: _t->on_pushHistogram_clicked(); break;
        case 8: _t->on_pushOstu_clicked(); break;
        case 9: _t->on_pushThresholding_clicked(); break;
        case 10: _t->on_pushDilation_clicked(); break;
        case 11: _t->on_pushErosion_clicked(); break;
        case 12: _t->on_pushBoundary_clicked(); break;
        case 13: _t->on_pushBoundaryFG_clicked(); break;
        case 14: _t->on_pushGaussianNoise_clicked(); break;
        case 15: _t->on_pushSaltPepper_clicked(); break;
        case 16: _t->on_pushGaussianSmoothing_clicked(); break;
        case 17: _t->on_pushMedianFiltering_clicked(); break;
        case 18: _t->on_pushHistogramEQ_clicked(); break;
        case 19: _t->on_pushHistogramMatching_clicked(); break;
        case 20: _t->on_pushEdgeFDG_clicked(); break;
        case 21: _t->on_pushCanny_clicked(); break;
        case 22: _t->on_pushCircleLocalization_clicked(); break;
        case 23: _t->on_pushHarrisCorner_clicked(); break;
        case 24: _t->on_pushPyramid_clicked(); break;
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
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}
QT_WARNING_POP
