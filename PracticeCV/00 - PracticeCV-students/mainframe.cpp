#include "mainframe.h"
#include "ui_mainframe.h"
#include "imageform.h"
#include "edge.h"
#include "circleHough.h"
#include "corner.h"
#include "pyramidGaussian.h"
#include <QFileDialog>
#include <QPainter>
#include <sstream>
#include <fstream>
#include <random>

using namespace std;

MainFrame::MainFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainFrame)
{
    ui->setupUi(this);

    _q_pFormFocused     = 0;

    //객체 맴버의 초기화


    //리스트 출력창을 안보이게    
    ui->listWidget->setVisible(false);
    this->adjustSize();

    //UI 활성화 갱신
    UpdateUI();
}

MainFrame::~MainFrame()
{ 
    delete ui;         

    for(auto& item : _lImageForm)
        delete item;

}

void MainFrame::CloseImageForm(ImageForm *pForm)
{
    //ImageForm 포인터 삭제
    unsigned int idx = std::find(_lImageForm.begin(), _lImageForm.end(), pForm) - _lImageForm.begin();
    if(idx != _lImageForm.size())
    {
        delete _lImageForm[idx];
        _lImageForm.erase(_lImageForm.begin() + idx);
    }

    //활성화 ImageForm 초기화
    _q_pFormFocused     = 0;

    //관련 객체 삭제

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::UpdateUI()
{    
    if(ui->tabWidget->currentIndex() == 0)
    {
        ui->pushRGB2Gray->setEnabled(_q_pFormFocused && _q_pFormFocused->ID() == "OPEN");
    }
    else if(ui->tabWidget->currentIndex() == 1)
    {
        ui->pushSepiaTone->setEnabled(_q_pFormFocused && _q_pFormFocused->ID() == "OPEN");

        ui->pushContrast->setEnabled(_q_pFormFocused && _q_pFormFocused->ID() == "OPEN");
    }
    else if(ui->tabWidget->currentIndex() == 2)
    {
        ui->pushOstu->setEnabled(_q_pFormFocused &&
                                 _q_pFormFocused->ID() == "OPEN" &&
                                 _q_pFormFocused->ImageGray().Address());
        ui->pushThresholding->setEnabled(_q_pFormFocused &&
                                         _q_pFormFocused->ID() == "OPEN" &&
                                         _q_pFormFocused->ImageGray().Address());
        ui->pushDilation->setEnabled(_q_pFormFocused &&
                                         _q_pFormFocused->ID() == "Binary Image" &&
                                         _q_pFormFocused->ImageGray().Address());
        ui->pushErosion->setEnabled(_q_pFormFocused &&
                                        _q_pFormFocused->ID() == "Binary Image" &&
                                        _q_pFormFocused->ImageGray().Address());

        ui->pushBoundary->setEnabled(_q_pFormFocused &&
                                    _q_pFormFocused->ID() == "Binary Image" &&
                                    _q_pFormFocused->ImageGray().Address());

        ui->pushBoundaryFG->setEnabled(_q_pFormFocused &&
                                    _q_pFormFocused->ID() == "Binary Image" &&
                                    _q_pFormFocused->ImageGray().Address());

    }
    else if(ui->tabWidget->currentIndex() == 3)
    {
    }

    else if(ui->tabWidget->currentIndex() == 4)
    {
        ui->pushHistogramEQ->setEnabled(_q_pFormFocused &&
                                        _q_pFormFocused->ID() == "OPEN" &&
                                        _q_pFormFocused->ImageGray().Address());
        ui->pushEdgeFDG->setEnabled(_q_pFormFocused &&
                                    _q_pFormFocused->ID() == "OPEN" &&
                                    _q_pFormFocused->ImageGray().Address());
        ui->pushCanny->setEnabled(_q_pFormFocused &&
                                  _q_pFormFocused->ID() == "Edge Magnitude" &&
                                  _q_pFormFocused->ImageGray().Address());
    }

    else if(ui->tabWidget->currentIndex() == 5)
    {
        ui->pushHarrisCorner->setEnabled(_q_pFormFocused &&
                                         _q_pFormFocused->Atrb() == "GRAY" &&
                                         _q_pFormFocused->ImageGray().Address());
    }
}

void MainFrame::OnMousePos(const int &nX, const int &nY, ImageForm* q_pForm)
{
}

void MainFrame::focusInEvent(QFocusEvent * event)
{
    Q_UNUSED(event) ;

    UpdateUI();
}

void MainFrame::closeEvent(QCloseEvent* event)
{
    //생성된 ImageForm을 닫는다.
    for(int i=0; i< _lImageForm.size(); i++)
        delete _lImageForm[i];

    //리스트에서 삭제한다.
    _lImageForm.clear();
}


void MainFrame::on_buttonOpen_clicked()
{
    //이미지 파일 선택
    QFileDialog::Options    q_Options   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

    if(q_stFile.length() == 0)
        return;

    //이미지 출력을 위한 ImageForm 생성    
    ImageForm*              q_pForm   = new ImageForm(q_stFile, "OPEN", this);

    _lImageForm.push_back(q_pForm);
    q_pForm->show();

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonDeleteContents_clicked()
{
    //생성된 ImageForm을 닫는다.
    for(int i=_lImageForm.size()-1; i>=0; i--)
        delete _lImageForm[i];

    //리스트에서 삭제한다.
    _lImageForm.clear();

    //객체 삭제


    ui->listWidget->clear();
}

void MainFrame::on_tabWidget_currentChanged(int index)
{
    static int nOld = -1;

    if(nOld == 0)
    {

    }
    else if(nOld == 1)
    {

    }
    nOld = index;

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonShowList_clicked()
{
    static int nWidthOld = ui->tabWidget->width();

    if(ui->listWidget->isVisible())
    {
        nWidthOld = ui->listWidget->width();
        ui->listWidget->hide();
        this->adjustSize();
    }
    else
    {        
        ui->listWidget->show();
        QRect q_rcWin = this->geometry();

        this->setGeometry(q_rcWin.left(), q_rcWin.top(), q_rcWin.width()+nWidthOld, q_rcWin.height());
    }
}




void MainFrame::on_pushRGB2Gray_clicked()
{
    KImageColor icMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() && _q_pFormFocused->ID() == "OPEN")
        icMain = _q_pFormFocused->ImageColor();
    else
        return;
    KImageGray igImg = icMain.ColorToGray();

    ImageForm* q_pForm = new ImageForm(igImg, "Gray Image", this);

    _lImageForm.push_back(q_pForm);
    q_pForm->show();
}


void MainFrame::on_pushSepiaTone_clicked()
{
    //포커스 된 ImageForm으로 부터 영상을 가져옴
    KImageColor icMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() && _q_pFormFocused->ID() == "OPEN")
        icMain = _q_pFormFocused->ImageColor();
    else
        return;
    //RGB -> HSV 변환
    KArray<KHSV> arHSV;
    icMain.RGBtoHSV(arHSV);

    //설정된 Hue, Saturation으로 변경
    double dHue = ui->spinHue->value();
    double dSat = ui->spinSat->value();

    for(unsigned int i =0; i<arHSV.Row(); i++)
        for(unsigned int j=0; j<arHSV.Col(); j++)
        {
            arHSV[i][j].h = dHue;
            arHSV[i][j].s = dSat;
        }

    //HSV -> RGB 변환
    icMain.FromHSV(arHSV);

    //출력창 결정
    ImageForm* q_pForm = 0;
    for(auto form: _lImageForm)
        if(form->ID() == "Sepia Tone" && form->size() == _q_pFormFocused->size())
        {
            q_pForm = form;
            break;
        }
    //기존 창에 표시
    if(q_pForm)
        q_pForm->Update(icMain);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(icMain, "Sepia Tone", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }
    //UI 활성화 갱신
    UpdateUI();

}


void MainFrame::on_pushContrast_clicked()
{
    if(_q_pFormFocused == 0 || _q_pFormFocused->ImageGray().Address() == 0 || _q_pFormFocused->ID() != "OPEN")
        return;

    KImageGray igImg = _q_pFormFocused->ImageGray().ContrastTransform(ui->spinContrastA->value(),
                                                                      ui->spinContrastB->value(), 0, 255);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Contrast Transform" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igImg);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igImg, "Contrast Transform", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }
    //UI 활성화 갱신
    UpdateUI();

}


void MainFrame::on_pushHistogram_clicked()
{
    KImageGray igMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() && _q_pFormFocused->ID() == "OPEN")
        igMain = _q_pFormFocused->ImageGray();
    else
        return;

    vector<int> lHisto(256);
    int nRow = igMain.Row();
    int nCol = igMain.Col();


    for(int i=0; i<nRow; i++)
        for(int j=0; j<nCol; j++)
            lHisto[ igMain[i][j] ] ++;

    ofstream fout("./output/histo.csv");
    for(auto item: lHisto){
        fout << item << ',';

    }
    fout.close();

    if(ui->listWidget->isVisible()==false)
        on_buttonShowList_clicked();
    ui->listWidget->addItem(QString(">> finish histogramming --> histo.csv"));
}


void MainFrame::on_pushOstu_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();
    KImageGray igBin;
    KBINARIZATION_OUTPUT* opBinOutput = KHisto().Ostu(&igMain, &igBin);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Binary Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igBin);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igBin, "Binary Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    ui->spinOstu->setValue(opBinOutput->nThresh);
    ui->listWidget->addItem(QString(">> Ostuu Threshold : %1").arg(opBinOutput->nThresh));
    ui->listWidget->show();


    UpdateUI();
}


void MainFrame::on_pushThresholding_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();
    igMain.Thresholded(ui->spinOstu->value());

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Binary Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igMain);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igMain, "Binary Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    ui->listWidget->addItem(QString(">> Manual Threshold : %1").arg(ui->spinOstu->value()));
    ui->listWidget->show();

    UpdateUI();

}


void MainFrame::on_pushDilation_clicked()
{
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryDilate(_WHITE);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Binary Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igBin);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igBin, "Binary Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushErosion_clicked()
{
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryErode(_WHITE);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Binary Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igBin);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igBin, "Binary Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushBoundary_clicked()
{
    KImageGray igBin = _q_pFormFocused->ImageGray();
    KImageGray igDilate = igBin.BinaryDilate(_WHITE);

    for(unsigned int i=0; i<igDilate.Row(); i++)
        for(unsigned int j=0; j<igDilate.Col(); j++)
            if(igDilate[i][j] == _BLACK)
                continue;
            else if(igBin[i][j])
                igDilate[i][j] = _BLACK;

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Binary Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igDilate);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igDilate, "Binary Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushBoundaryFG_clicked()
{
    KImageGray igBin = _q_pFormFocused->ImageGray();
    KImageGray igErode = igBin.BinaryErode(_WHITE);

    for(unsigned int i=0; i<igErode.Row(); i++)
        for(unsigned int j=0; j<igErode.Col(); j++)
            if(igBin[i][j] == _BLACK)
                continue;
            else if(igErode[i][j])
                igBin[i][j] = _BLACK;

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Binary Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igBin);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igBin, "Binary Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushGaussianNoise_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    double dSigma = ui->editSigmaNoise->text().toDouble();
    double dIntensity;
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> dist(0.0, dSigma);

    for(unsigned int i=0; i<igMain.Row(); i++)
        for(unsigned int j=0; j<igMain.Col(); j++)
        {
            dIntensity = igMain[i][j] + dist(gen);
            igMain[i][j] = (unsigned char)(dIntensity < 0.0 ? 0 : (dIntensity > 255.0 ? 255 : dIntensity));
        }

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Noised Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igMain);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igMain, "Noised Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushSaltPepper_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    double dTau = ui->editTau->text().toDouble();
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);
    double dRandom;

    for(unsigned int i=0; i<igMain.Row(); i++)
        for(unsigned int j=0; j<igMain.Col(); j++)
        {
            dRandom = dist(gen);
            if(dRandom < dTau)
                igMain[i][j] = 0;
            else if(dRandom > 1.0-dTau)
                igMain[i][j] = 255;
        }

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Noised Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igMain);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igMain, "Noised Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushGaussianSmoothing_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    double dSigma = ui->editSigmaFiltering->text().toDouble();
    igMain.GaussianSmoothed(dSigma);


    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Gaussian Smoothed" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igMain);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igMain, "Gaussian Smoothed", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushMedianFiltering_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    int nWindow = ui->editWindowSize->text().toInt();
    igMain.MedianFiltered(nWindow);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Median Filtered" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igMain);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igMain, "Median Filtered", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushHistogramEQ_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    KHisto oHisto;
    oHisto.Histogram(igMain);

    ofstream fout("./output/hist_before.csv");
    for(int i=0; i<oHisto.Dim(); i++)
        fout << oHisto[i] << ',';
    fout.close();

    oHisto.HEQ(igMain, true);

    fout.open("./output/hist_after.csv");
    for(int i=0; i<oHisto.Dim(); i++)
        fout << oHisto[i] << ',';
    fout.close();

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Histogram Equalized" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igMain);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igMain, "Histogram Equalized", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}





void MainFrame::on_pushHistogramMatching_clicked()
{
    QFileDialog::Options    q_Options   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

    if(q_stFile.length() == 0)
        return;

    ImageForm* q_pFormT = new ImageForm(q_stFile, "Target Image", this);
    KImageColor icTarget = q_pFormT->ImageColor();
    _lImageForm.push_back(q_pFormT);
    q_pFormT->show();

    q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

    if(q_stFile.length() == 0)
        return;

    ImageForm* q_pFormS = new ImageForm(q_stFile, "Source Image", this);
    KImageColor icSrc = q_pFormS->ImageColor();
    _lImageForm.push_back(q_pFormS);
    q_pFormS->show();

    KHisto hMatch;
    KImageColor icMatched = hMatch.HistogramMatching(icTarget, icSrc);

    ImageForm* q_pForm = new ImageForm(icMatched, "Histogram Matched", this);

    _lImageForm.push_back(q_pForm);
    q_pForm->show();
}


void MainFrame::on_pushEdgeFDG_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    KImageGray igMag;
    double dSigma = ui->editSigmaFDG->text().toDouble();
    KEdge oEdge(dSigma);

    oEdge.Gradient(igMain, igMag);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Edge Magnitude" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igMag);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igMag, "Edge Magnitude", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushCanny_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    KImageGray igEdge;
    double dSigma = ui->editSigmaCanny->text().toDouble();
    double dLow = ui->editLow->text().toDouble();
    double dHigh = ui->editHigh->text().toDouble();
    KEdge oEdge(dSigma);

    oEdge.Canny(dLow, dHigh, igMain, igEdge);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Edge Image" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(igEdge);
    //새로운 창에 표시
    else
    {
        q_pForm = new ImageForm(igEdge, "Edge Image", this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    UpdateUI();
}


void MainFrame::on_pushCircleLocalization_clicked()
{
    //포커싱 된 이미지 불러오기
    KImageGray igImg = _q_pFormFocused->ImageGray();
    KCIRCLEHOUGH_INFO oInfo;

    //ROI 설정
    oInfo.nLeft = ui->editMinR->text().toInt();
    oInfo.nTop = ui->editMinR->text().toInt();
    oInfo.nRight = igImg.Col() - ui->editMinR->text().toInt();
    oInfo.nBottom = igImg.Row() - ui->editMinR->text().toInt();
    //원의 최소 반지름, 최대 반지름 설정
    oInfo.nMinR = ui->editMinR->text().toInt();
    oInfo.nMaxR = ui->editMaxR->text().toInt();
    //ROI의 GRID의 수 계산(RESOLUTION을 1로 설정했으므로 이를 나눠준다.)
    oInfo.nNumGridCx = (int)((oInfo.nRight - oInfo.nLeft + 1)/ui->editResolution->text().toDouble());
    oInfo.nNumGridCy = (int)((oInfo.nBottom - oInfo.nTop + 1)/ui->editResolution->text().toDouble());
    oInfo.nNumGridR = (int)((oInfo.nMaxR - oInfo.nMinR + 1)/ui->editResolution->text().toDouble());
    oInfo.nDirEdge = _OUTWARD_EDGE;
    oInfo.nThreshVote = ui->editThresVote->text().toInt();

    KEdge oEdge(ui->editSigmaCanny->text().toDouble());
    KImageGray igEdge;
    oEdge.Canny(ui->editLow->text().toInt(), ui->editHigh->text().toInt(), igImg, igEdge);

    KPGM(igEdge).Save("./output/edge4Hough.pgm");

    KCircleHough oCircleHough;
    KCircle* opCircle;
    oCircleHough.Init((void*)&oInfo);
    opCircle = (KCircle*)oCircleHough.Run((void*)&oEdge);
    if(opCircle == 0)
    {
        if(ui->listWidget->isVisible() == false){
            on_buttonShowList_clicked();
        }
        ui->listWidget->insertItem(0, QString("There is no circle detected !"));
        return;
    }


    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Circle Localization" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            q_pForm->Update(igImg.GrayToRGB());
            break;
        }

    if(q_pForm == 0){
        q_pForm = new ImageForm(igImg.GrayToRGB(), "Circle Localization", this);
        _lImageForm.push_back(q_pForm);
    }
    //새로운 창에 표시
    q_pForm->DrawEllipse(QPoint((int)(opCircle->_dCx), (int)(opCircle->_dCy)), (int)(opCircle->_dRadius), (int)(opCircle->_dRadius), QColor(255, 0, 0), 2);

    q_pForm->update();
    q_pForm->show();


    if(ui->listWidget->isVisible() == false){
        on_buttonShowList_clicked();
    }

    ui->listWidget->insertItem(0, QString(">> detected circle --> radius = %1").arg(opCircle->_dRadius));
    UpdateUI();
}


void MainFrame::on_pushHarrisCorner_clicked()
{
    double dThresh = ui->editThreshCorner->text().toDouble();
    double dSigma = ui->editSigmaCorner->text().toDouble();
    double nSize = ui->editSizeBlock->text().toInt();

    KImageGray& igMain = _q_pFormFocused->ImageGray();

    KCorner oCorner(dSigma, nSize);
    oCorner.HarrisCorner(dThresh, igMain);

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "Corner Detection" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            q_pForm->Update(igMain.GrayToRGB());
            break;
        }

    if(q_pForm == 0){
        q_pForm = new ImageForm(igMain.GrayToRGB(), "Corner Detection", this);
        _lImageForm.push_back(q_pForm);
    }
    //새로운 창에 표시

    for(auto& oPixel : oCorner)
    {
        q_pForm->DrawEllipse(QPoint(oPixel.u, oPixel.v), 1, 1, QColor(255, 0 ,0), 2);
    }

    q_pForm->update();
    q_pForm->show();

    UpdateUI();
}


void MainFrame::on_pushPyramid_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    int nOctave = ui->editOctave->text().toInt();
    double dSigma = ui->editSigmaPyramid->text().toDouble();
    KPyramidGaussian oPyramid(igMain, dSigma, nOctave);


    ImageForm* q_pForm = 0;
    QString stOctave;

    for(int i=0; i< oPyramid.Octave(); i++){
        stOctave = QString("%1").arg(i);
        q_pForm = 0;

        for(auto item: _lImageForm)
            if(item->ID() == "Image Pyramid" && item->Atrb() == stOctave && item->size() == _q_pFormFocused->size())
            {
                q_pForm = item;
                q_pForm->Update(oPyramid[i].ToGray());
                break;
            }

        if(q_pForm == 0){
            q_pForm = new ImageForm(oPyramid[i].ToGray(), "Image Pyramid", stOctave);
            _lImageForm.push_back(q_pForm);
        }
        q_pForm->show();
    }



}

