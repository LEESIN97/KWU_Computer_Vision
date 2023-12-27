/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *buttonOpen;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *buttonDeleteContents;
    QSpacerItem *horizontalSpacer;
    QToolButton *buttonShowList;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QPushButton *pushRGB2Gray;
    QWidget *tab_4;
    QPushButton *pushSepiaTone;
    QLabel *label;
    QSpinBox *spinHue;
    QLabel *label_2;
    QDoubleSpinBox *spinSat;
    QPushButton *pushContrast;
    QSpinBox *spinContrastA;
    QLabel *label_3;
    QSpinBox *spinContrastB;
    QPushButton *pushHistogram;
    QWidget *tab_5;
    QPushButton *pushOstu;
    QLabel *label_4;
    QSpinBox *spinOstu;
    QPushButton *pushThresholding;
    QPushButton *pushDilation;
    QPushButton *pushErosion;
    QPushButton *pushBoundary;
    QPushButton *pushBoundaryFG;
    QWidget *tab_2;
    QPushButton *pushGaussianNoise;
    QLabel *label_5;
    QLineEdit *editSigmaNoise;
    QPushButton *pushSaltPepper;
    QLabel *label_6;
    QLineEdit *editTau;
    QPushButton *pushGaussianSmoothing;
    QLabel *label_7;
    QLineEdit *editSigmaFiltering;
    QPushButton *pushMedianFiltering;
    QLineEdit *editWindowSize;
    QLabel *label_8;
    QWidget *tab;
    QPushButton *pushHistogramEQ;
    QPushButton *pushHistogramMatching;
    QPushButton *pushEdgeFDG;
    QLabel *label_9;
    QLineEdit *editSigmaFDG;
    QPushButton *pushCanny;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *editSigmaCanny;
    QLineEdit *editLow;
    QLineEdit *editHigh;
    QWidget *tab_3;
    QPushButton *pushCircleLocalization;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *editMinR;
    QLineEdit *editMaxR;
    QLineEdit *editResolution;
    QLineEdit *editThresVote;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushHarrisCorner;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *editSigmaCorner;
    QLineEdit *editThreshCorner;
    QLineEdit *editSizeBlock;
    QWidget *tab_6;
    QPushButton *pushPyramid;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *editOctave;
    QLineEdit *editSigmaPyramid;
    QListWidget *listWidget;

    void setupUi(QDialog *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName("MainFrame");
        MainFrame->resize(622, 461);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainFrame->sizePolicy().hasHeightForWidth());
        MainFrame->setSizePolicy(sizePolicy);
        MainFrame->setMinimumSize(QSize(0, 461));
        MainFrame->setModal(false);
        verticalLayout = new QVBoxLayout(MainFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(MainFrame);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 41));
        frame->setMaximumSize(QSize(16777215, 41));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QToolButton(frame);
        buttonOpen->setObjectName("buttonOpen");
        buttonOpen->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonOpen->sizePolicy().hasHeightForWidth());
        buttonOpen->setSizePolicy(sizePolicy2);
        buttonOpen->setMinimumSize(QSize(41, 41));
        buttonOpen->setMaximumSize(QSize(41, 41));
        buttonOpen->setLayoutDirection(Qt::LeftToRight);
        buttonOpen->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOpen->setIcon(icon);
        buttonOpen->setIconSize(QSize(41, 41));
        buttonOpen->setCheckable(false);
        buttonOpen->setAutoRepeat(false);
        buttonOpen->setAutoExclusive(false);
        buttonOpen->setPopupMode(QToolButton::DelayedPopup);
        buttonOpen->setToolButtonStyle(Qt::ToolButtonIconOnly);
        buttonOpen->setAutoRaise(false);

        horizontalLayout_3->addWidget(buttonOpen);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName("toolButton_2");
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setMinimumSize(QSize(41, 41));
        toolButton_2->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName("toolButton_3");
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setMinimumSize(QSize(41, 41));
        toolButton_3->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_3);

        buttonDeleteContents = new QToolButton(frame);
        buttonDeleteContents->setObjectName("buttonDeleteContents");
        sizePolicy2.setHeightForWidth(buttonDeleteContents->sizePolicy().hasHeightForWidth());
        buttonDeleteContents->setSizePolicy(sizePolicy2);
        buttonDeleteContents->setMinimumSize(QSize(41, 41));
        buttonDeleteContents->setMaximumSize(QSize(41, 41));
        buttonDeleteContents->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/1-21.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDeleteContents->setIcon(icon1);
        buttonDeleteContents->setIconSize(QSize(41, 41));

        horizontalLayout_3->addWidget(buttonDeleteContents);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonShowList = new QToolButton(frame);
        buttonShowList->setObjectName("buttonShowList");
        sizePolicy2.setHeightForWidth(buttonShowList->sizePolicy().hasHeightForWidth());
        buttonShowList->setSizePolicy(sizePolicy2);
        buttonShowList->setMinimumSize(QSize(41, 41));
        buttonShowList->setMaximumSize(QSize(41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonShowList->setIcon(icon2);
        buttonShowList->setIconSize(QSize(82, 41));

        horizontalLayout_3->addWidget(buttonShowList);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, -1, -1, -1);
        tabWidget = new QTabWidget(MainFrame);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(299, 394));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(255, 85, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush1);
        tabWidget->setPalette(palette);
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(31, 31));
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        pushRGB2Gray = new QPushButton(tab_1);
        pushRGB2Gray->setObjectName("pushRGB2Gray");
        pushRGB2Gray->setGeometry(QRect(90, 70, 80, 24));
        tabWidget->addTab(tab_1, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        pushSepiaTone = new QPushButton(tab_4);
        pushSepiaTone->setObjectName("pushSepiaTone");
        pushSepiaTone->setGeometry(QRect(100, 70, 80, 24));
        label = new QLabel(tab_4);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 130, 50, 16));
        spinHue = new QSpinBox(tab_4);
        spinHue->setObjectName("spinHue");
        spinHue->setGeometry(QRect(70, 130, 42, 25));
        spinHue->setMaximum(360);
        spinHue->setSingleStep(10);
        spinHue->setValue(30);
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 130, 50, 16));
        spinSat = new QDoubleSpinBox(tab_4);
        spinSat->setObjectName("spinSat");
        spinSat->setGeometry(QRect(180, 130, 62, 25));
        spinSat->setMaximum(1.000000000000000);
        spinSat->setSingleStep(0.100000000000000);
        spinSat->setValue(0.300000000000000);
        pushContrast = new QPushButton(tab_4);
        pushContrast->setObjectName("pushContrast");
        pushContrast->setGeometry(QRect(100, 200, 80, 24));
        spinContrastA = new QSpinBox(tab_4);
        spinContrastA->setObjectName("spinContrastA");
        spinContrastA->setGeometry(QRect(70, 250, 42, 25));
        spinContrastA->setMaximum(255);
        spinContrastA->setSingleStep(3);
        spinContrastA->setValue(20);
        label_3 = new QLabel(tab_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 260, 50, 16));
        spinContrastB = new QSpinBox(tab_4);
        spinContrastB->setObjectName("spinContrastB");
        spinContrastB->setGeometry(QRect(160, 250, 42, 25));
        spinContrastB->setMaximum(255);
        spinContrastB->setSingleStep(3);
        spinContrastB->setValue(230);
        pushHistogram = new QPushButton(tab_4);
        pushHistogram->setObjectName("pushHistogram");
        pushHistogram->setGeometry(QRect(100, 300, 80, 24));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        pushOstu = new QPushButton(tab_5);
        pushOstu->setObjectName("pushOstu");
        pushOstu->setGeometry(QRect(90, 60, 80, 24));
        label_4 = new QLabel(tab_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 120, 61, 31));
        spinOstu = new QSpinBox(tab_5);
        spinOstu->setObjectName("spinOstu");
        spinOstu->setGeometry(QRect(120, 120, 42, 25));
        spinOstu->setMinimum(1);
        spinOstu->setMaximum(254);
        spinOstu->setValue(100);
        pushThresholding = new QPushButton(tab_5);
        pushThresholding->setObjectName("pushThresholding");
        pushThresholding->setGeometry(QRect(180, 130, 41, 16));
        pushDilation = new QPushButton(tab_5);
        pushDilation->setObjectName("pushDilation");
        pushDilation->setGeometry(QRect(90, 170, 80, 24));
        pushErosion = new QPushButton(tab_5);
        pushErosion->setObjectName("pushErosion");
        pushErosion->setGeometry(QRect(90, 220, 80, 24));
        pushBoundary = new QPushButton(tab_5);
        pushBoundary->setObjectName("pushBoundary");
        pushBoundary->setGeometry(QRect(90, 270, 80, 24));
        pushBoundaryFG = new QPushButton(tab_5);
        pushBoundaryFG->setObjectName("pushBoundaryFG");
        pushBoundaryFG->setGeometry(QRect(90, 310, 80, 24));
        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        pushGaussianNoise = new QPushButton(tab_2);
        pushGaussianNoise->setObjectName("pushGaussianNoise");
        pushGaussianNoise->setGeometry(QRect(80, 10, 111, 41));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 60, 50, 16));
        editSigmaNoise = new QLineEdit(tab_2);
        editSigmaNoise->setObjectName("editSigmaNoise");
        editSigmaNoise->setGeometry(QRect(110, 60, 41, 21));
        pushSaltPepper = new QPushButton(tab_2);
        pushSaltPepper->setObjectName("pushSaltPepper");
        pushSaltPepper->setGeometry(QRect(80, 90, 111, 41));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 150, 50, 16));
        editTau = new QLineEdit(tab_2);
        editTau->setObjectName("editTau");
        editTau->setGeometry(QRect(100, 150, 51, 20));
        pushGaussianSmoothing = new QPushButton(tab_2);
        pushGaussianSmoothing->setObjectName("pushGaussianSmoothing");
        pushGaussianSmoothing->setGeometry(QRect(80, 200, 111, 31));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 240, 50, 16));
        editSigmaFiltering = new QLineEdit(tab_2);
        editSigmaFiltering->setObjectName("editSigmaFiltering");
        editSigmaFiltering->setGeometry(QRect(120, 240, 31, 16));
        pushMedianFiltering = new QPushButton(tab_2);
        pushMedianFiltering->setObjectName("pushMedianFiltering");
        pushMedianFiltering->setGeometry(QRect(80, 270, 111, 31));
        editWindowSize = new QLineEdit(tab_2);
        editWindowSize->setObjectName("editWindowSize");
        editWindowSize->setGeometry(QRect(130, 310, 16, 24));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(70, 310, 50, 16));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        pushHistogramEQ = new QPushButton(tab);
        pushHistogramEQ->setObjectName("pushHistogramEQ");
        pushHistogramEQ->setGeometry(QRect(80, 30, 131, 51));
        pushHistogramMatching = new QPushButton(tab);
        pushHistogramMatching->setObjectName("pushHistogramMatching");
        pushHistogramMatching->setGeometry(QRect(80, 120, 131, 51));
        pushEdgeFDG = new QPushButton(tab);
        pushEdgeFDG->setObjectName("pushEdgeFDG");
        pushEdgeFDG->setGeometry(QRect(80, 200, 131, 51));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(90, 260, 50, 16));
        editSigmaFDG = new QLineEdit(tab);
        editSigmaFDG->setObjectName("editSigmaFDG");
        editSigmaFDG->setGeometry(QRect(150, 260, 51, 20));
        pushCanny = new QPushButton(tab);
        pushCanny->setObjectName("pushCanny");
        pushCanny->setGeometry(QRect(80, 280, 131, 51));
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 280, 50, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 300, 50, 16));
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 320, 50, 16));
        editSigmaCanny = new QLineEdit(tab);
        editSigmaCanny->setObjectName("editSigmaCanny");
        editSigmaCanny->setGeometry(QRect(40, 280, 31, 20));
        editLow = new QLineEdit(tab);
        editLow->setObjectName("editLow");
        editLow->setGeometry(QRect(40, 300, 31, 20));
        editHigh = new QLineEdit(tab);
        editHigh->setObjectName("editHigh");
        editHigh->setGeometry(QRect(40, 320, 31, 20));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        pushCircleLocalization = new QPushButton(tab_3);
        pushCircleLocalization->setObjectName("pushCircleLocalization");
        pushCircleLocalization->setGeometry(QRect(80, 130, 111, 41));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(70, 190, 50, 16));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(70, 210, 61, 16));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(70, 230, 61, 16));
        editMinR = new QLineEdit(tab_3);
        editMinR->setObjectName("editMinR");
        editMinR->setGeometry(QRect(150, 180, 31, 24));
        editMaxR = new QLineEdit(tab_3);
        editMaxR->setObjectName("editMaxR");
        editMaxR->setGeometry(QRect(200, 180, 31, 24));
        editResolution = new QLineEdit(tab_3);
        editResolution->setObjectName("editResolution");
        editResolution->setGeometry(QRect(150, 210, 31, 24));
        editThresVote = new QLineEdit(tab_3);
        editThresVote->setObjectName("editThresVote");
        editThresVote->setGeometry(QRect(150, 240, 31, 24));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(190, 240, 50, 16));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(190, 210, 50, 16));
        pushHarrisCorner = new QPushButton(tab_3);
        pushHarrisCorner->setObjectName("pushHarrisCorner");
        pushHarrisCorner->setGeometry(QRect(80, 20, 101, 31));
        label_18 = new QLabel(tab_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(70, 70, 50, 16));
        label_19 = new QLabel(tab_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(130, 70, 50, 16));
        label_20 = new QLabel(tab_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(190, 70, 50, 16));
        editSigmaCorner = new QLineEdit(tab_3);
        editSigmaCorner->setObjectName("editSigmaCorner");
        editSigmaCorner->setGeometry(QRect(60, 100, 51, 21));
        editThreshCorner = new QLineEdit(tab_3);
        editThreshCorner->setObjectName("editThreshCorner");
        editThreshCorner->setGeometry(QRect(120, 100, 51, 21));
        editSizeBlock = new QLineEdit(tab_3);
        editSizeBlock->setObjectName("editSizeBlock");
        editSizeBlock->setGeometry(QRect(190, 100, 41, 21));
        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        pushPyramid = new QPushButton(tab_6);
        pushPyramid->setObjectName("pushPyramid");
        pushPyramid->setGeometry(QRect(70, 150, 131, 31));
        label_21 = new QLabel(tab_6);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(80, 200, 50, 16));
        label_22 = new QLabel(tab_6);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(150, 200, 50, 16));
        editOctave = new QLineEdit(tab_6);
        editOctave->setObjectName("editOctave");
        editOctave->setGeometry(QRect(80, 230, 31, 16));
        editSigmaPyramid = new QLineEdit(tab_6);
        editSigmaPyramid->setObjectName("editSigmaPyramid");
        editSigmaPyramid->setGeometry(QRect(150, 230, 31, 20));
        tabWidget->addTab(tab_6, QString());

        horizontalLayout->addWidget(tabWidget);

        listWidget = new QListWidget(MainFrame);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);
        listWidget->setMinimumSize(QSize(0, 394));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 0, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        QBrush brush6(QColor(120, 120, 120, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        QBrush brush7(QColor(240, 240, 240, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        listWidget->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(10);
        listWidget->setFont(font);

        horizontalLayout->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MainFrame);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QDialog *MainFrame)
    {
        MainFrame->setWindowTitle(QCoreApplication::translate("MainFrame", "Practice CV", nullptr));
#if QT_CONFIG(tooltip)
        buttonOpen->setToolTip(QCoreApplication::translate("MainFrame", "open an image file", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonOpen->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonDeleteContents->setToolTip(QCoreApplication::translate("MainFrame", "close all forms", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonDeleteContents->setText(QString());
#if QT_CONFIG(tooltip)
        buttonShowList->setToolTip(QCoreApplication::translate("MainFrame", "show the list view", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonShowList->setText(QString());
        pushRGB2Gray->setText(QCoreApplication::translate("MainFrame", "RGB->Gray", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainFrame", "1 ", nullptr));
        pushSepiaTone->setText(QCoreApplication::translate("MainFrame", "Sepia Tone", nullptr));
        label->setText(QCoreApplication::translate("MainFrame", "Hue", nullptr));
        label_2->setText(QCoreApplication::translate("MainFrame", "Sat", nullptr));
        pushContrast->setText(QCoreApplication::translate("MainFrame", "Contrast Transform", nullptr));
        label_3->setText(QCoreApplication::translate("MainFrame", "~", nullptr));
        pushHistogram->setText(QCoreApplication::translate("MainFrame", "Histogram", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainFrame", "2", nullptr));
        pushOstu->setText(QCoreApplication::translate("MainFrame", "Ostu Thresholding", nullptr));
        label_4->setText(QCoreApplication::translate("MainFrame", "Threshold", nullptr));
        pushThresholding->setText(QCoreApplication::translate("MainFrame", ">>", nullptr));
        pushDilation->setText(QCoreApplication::translate("MainFrame", "Dilation", nullptr));
        pushErosion->setText(QCoreApplication::translate("MainFrame", "Erosion", nullptr));
        pushBoundary->setText(QCoreApplication::translate("MainFrame", "Boundary", nullptr));
        pushBoundaryFG->setText(QCoreApplication::translate("MainFrame", "Boundary - FG", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainFrame", "3", nullptr));
        pushGaussianNoise->setText(QCoreApplication::translate("MainFrame", "Gaussian Noise", nullptr));
        label_5->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        editSigmaNoise->setText(QCoreApplication::translate("MainFrame", "0.7", nullptr));
        pushSaltPepper->setText(QCoreApplication::translate("MainFrame", "Salt & Pepper Noise", nullptr));
        label_6->setText(QCoreApplication::translate("MainFrame", "ratio", nullptr));
        editTau->setText(QCoreApplication::translate("MainFrame", "0.01", nullptr));
        pushGaussianSmoothing->setText(QCoreApplication::translate("MainFrame", "Gaussian Smoothing", nullptr));
        label_7->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        editSigmaFiltering->setText(QCoreApplication::translate("MainFrame", "0.7", nullptr));
        pushMedianFiltering->setText(QCoreApplication::translate("MainFrame", "Median Filtering", nullptr));
        editWindowSize->setText(QCoreApplication::translate("MainFrame", "7", nullptr));
        label_8->setText(QCoreApplication::translate("MainFrame", "window", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainFrame", "4", nullptr));
        pushHistogramEQ->setText(QCoreApplication::translate("MainFrame", "Histogram Equlization", nullptr));
        pushHistogramMatching->setText(QCoreApplication::translate("MainFrame", "Histograming Matching", nullptr));
        pushEdgeFDG->setText(QCoreApplication::translate("MainFrame", "Edge with FDG", nullptr));
        label_9->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        editSigmaFDG->setText(QCoreApplication::translate("MainFrame", "1.0", nullptr));
        pushCanny->setText(QCoreApplication::translate("MainFrame", "Canny Edge Detection", nullptr));
        label_10->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        label_11->setText(QCoreApplication::translate("MainFrame", "low", nullptr));
        label_12->setText(QCoreApplication::translate("MainFrame", "high", nullptr));
        editSigmaCanny->setText(QCoreApplication::translate("MainFrame", "1.0", nullptr));
        editLow->setText(QCoreApplication::translate("MainFrame", "10", nullptr));
        editHigh->setText(QCoreApplication::translate("MainFrame", "30", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainFrame", "5", nullptr));
        pushCircleLocalization->setText(QCoreApplication::translate("MainFrame", "Circle Localization", nullptr));
        label_13->setText(QCoreApplication::translate("MainFrame", "Radius", nullptr));
        label_14->setText(QCoreApplication::translate("MainFrame", "Resolution", nullptr));
        label_15->setText(QCoreApplication::translate("MainFrame", "Threshold", nullptr));
        editMinR->setText(QCoreApplication::translate("MainFrame", "50", nullptr));
        editMaxR->setText(QCoreApplication::translate("MainFrame", "70", nullptr));
        editResolution->setText(QCoreApplication::translate("MainFrame", "1", nullptr));
        editThresVote->setText(QCoreApplication::translate("MainFrame", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainFrame", "votes", nullptr));
        label_17->setText(QCoreApplication::translate("MainFrame", "pixel", nullptr));
        pushHarrisCorner->setText(QCoreApplication::translate("MainFrame", "Harris Corner", nullptr));
        label_18->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        label_19->setText(QCoreApplication::translate("MainFrame", "thresh", nullptr));
        label_20->setText(QCoreApplication::translate("MainFrame", "block", nullptr));
        editSigmaCorner->setText(QCoreApplication::translate("MainFrame", "0.7", nullptr));
        editThreshCorner->setText(QCoreApplication::translate("MainFrame", "100000", nullptr));
        editSizeBlock->setText(QCoreApplication::translate("MainFrame", "7", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainFrame", "6", nullptr));
        pushPyramid->setText(QCoreApplication::translate("MainFrame", "Pyramid", nullptr));
        label_21->setText(QCoreApplication::translate("MainFrame", "octave", nullptr));
        label_22->setText(QCoreApplication::translate("MainFrame", "sigma", nullptr));
        editOctave->setText(QCoreApplication::translate("MainFrame", "5", nullptr));
        editSigmaPyramid->setText(QCoreApplication::translate("MainFrame", "0.7", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainFrame", "7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
