#include "mainframe.h"
#include "ui_mainframe.h"
#include "imageform.h"
#include "circleHough.h"
#include "edge.h"
#include <QFileDialog>
#include <QPainter>
#include <sstream>
#include <fstream>

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
    }
    else if(ui->tabWidget->currentIndex() == 1)
    {  
    }
    else if(ui->tabWidget->currentIndex() == 2)
    {        
    }
    else if(ui->tabWidget->currentIndex() == 3)
    {
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




void MainFrame::on_pushSearchCoins_clicked()
{
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

    KEdge oEdge(1.0);
    KImageGray igEdge;
    oEdge.Canny(10, 30, igImg, igEdge);

    KPGM(igEdge).Save("./output/edge4Hough.pgm");

    KCircleHough oCircleHough;
    oCircleHough.Init((void*)&oInfo);
    void* pResult = oCircleHough.Run((void*)&oEdge);
    vector<KCircle*>* opCircle = static_cast<vector<KCircle*>*>(pResult);
    if(opCircle->size() == 0)
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

    // 이제 circles를 사용하여 반복할 수 있습니다.
    for(auto& circle : *opCircle) {
        q_pForm->DrawEllipse(QPoint((int)(circle->_dCx), (int)(circle->_dCy)), (int)(circle->_dRadius), (int)(circle->_dRadius), QColor(255, 0, 0), 2);
        ui->listWidget->insertItem(0, QString(">> detected circle --> radius = %1").arg(circle->_dRadius));
    }


    q_pForm->update();
    q_pForm->show();


    if(ui->listWidget->isVisible() == false){
        on_buttonShowList_clicked();
    }

    delete opCircle;
    UpdateUI();
}


void MainFrame::on_pushFindMask_clicked()
{
    KImageGray igMain = _q_pFormFocused->ImageGray();

    GENERALHOUGH_INFO oInfo;

    //ROI 설정
    oInfo.nLeft = 20;
    oInfo.nTop = 20;
    oInfo.nRight = igMain.Col() - 20; // col 454 434
    oInfo.nBottom = igMain.Row() - 20; // row 391  371
    //원의 최소 반지름, 최대 반지름 설정
    oInfo.nMinR = 10;
    oInfo.nMaxR = 100;
    oInfo.nMinRAD = 0;
    oInfo.nMaxRAD = 2*M_PI;
    //ROI의 GRID의 수 계산(RESOLUTION을 1로 설정했으므로 이를 나눠준다.)
    oInfo.nNumGridCx = (int)((oInfo.nRight - oInfo.nLeft + 1)/(1.0));
    oInfo.nNumGridCy = (int)((oInfo.nBottom - oInfo.nTop + 1)/(1.0));
    oInfo.nNumGridR = (int)((oInfo.nMaxR - oInfo.nMinR + 1)/(1.0));
    oInfo.nNumGridAng = (int)((oInfo.nMaxRAD - oInfo.nMinRAD + 1)/(M_PI/72));
    oInfo.nDirEdge = _OUTWARD_EDGE;
    oInfo.nThreshVote = ui->editThresVote->text().toInt();

    int scaleSteps = 3; // 스케일링 단계 수
    double minScale = 0.8; // 최소 스케일
    double maxScale = 1.2; // 최대 스케일
    double scaleStep = (maxScale - minScale) / (scaleSteps - 1);



    double _dSx = (double)(oInfo.nRight - oInfo.nLeft) / (double)(oInfo.nNumGridCx-1); //Cx = nLeft  + k*_dSx
    double _dSy = (double)(oInfo.nBottom- oInfo.nTop)  / (double)(oInfo.nNumGridCy-1); //Cy = nTop   + k*_dSy
    double _dSRAD = (double)(oInfo.nMaxRAD  - oInfo.nMinRAD) / (double)(oInfo.nNumGridAng -1);


    std::string fileName = "./data/mask.txt"; // 파일 경로
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << fileName << std::endl;
    }

    std::vector<KPoint> _lPoints2D;
    int numOfPoints;
    file >> numOfPoints; // 첫 번째 줄에서 포인트의 수를 읽음

    for (int i = 0; i < numOfPoints; ++i) {
        KPoint point;
        file >> point._dX >> point._dY;
        _lPoints2D.push_back(point);
    }

    file.close();



    //중심점 : 모든 reference point의 mean
    int Xc=0, Yc=0; //중심점
    for(int i=0; i<_lPoints2D.size();i++)
    {
        Xc += _lPoints2D[i]._dX;
        Yc += _lPoints2D[i]._dY;
    }
    Xc /= _lPoints2D.size();
    Yc /= _lPoints2D.size();


    //Initialize
    float dTmp;
    int nDir;
    float tmpdDist, tmpdAng;
    vector<shape_points> _lpTables[4];
    for(int j=1, jj=_lPoints2D.size()-2; jj; j++, jj--){
        dTmp = atan((float)(_lPoints2D[j+1]._dY - _lPoints2D[j-1]._dY)/(float)(_lPoints2D[j+1]._dX - _lPoints2D[j-1]._dX));
        dTmp = dTmp * 180/M_PI;
        dTmp += 90.0;
        nDir = ((((int)(dTmp/22.5)+1)>>1) & 0x00000003);
        tmpdDist = sqrt(_SQR(Xc - _lPoints2D[j]._dX) + _SQR(Yc - _lPoints2D[j]._dY));
        tmpdAng = atan2(_lPoints2D[j]._dY - Yc, _lPoints2D[j]._dX- Xc);
        shape_points tmp;
        tmp.dAng = tmpdAng;
        tmp.dDist = tmpdDist;
        _lpTables[nDir].push_back(tmp);
    }

    KEdge oEdge(1.0);
    KImageGray igEdge;
    oEdge.Canny(10, 30, igMain, igEdge);
    KEdge* opEdge = (KEdge*)((void*)&oEdge);
    double dAng;
    double Tmp;
    KPoint		ptCen;
    int			nGridCx,nGridCy,nGridAng;
    vector<vector<vector<vector<double>>>> votes(
        igMain.Row(),
        vector<vector<vector<double>>>(
            igMain.Col(),
            vector<vector<double>>(
                scaleSteps,
                vector<double>(oInfo.nNumGridAng, 0.0)
                )
            )
        );


    int nn;
    for(auto& edgepxl : *opEdge) {
        // Scale과 Rotation에 대한 반복문
        for(int s = 0; s < scaleSteps; ++s) {
            double scale = minScale + s * scaleStep; // 스케일 계산
            for(int r = 0; r < oInfo.nNumGridAng; ++r) {
                dAng = oInfo.nMinRAD + r * _dSRAD;

                for(int i = 0; i < _lpTables[edgepxl.wDir].size(); ++i) {
                    ptCen._dX = edgepxl.u - scale * _lpTables[edgepxl.wDir][i].dDist * cos(_lpTables[edgepxl.wDir][i].dAng + dAng);
                    ptCen._dY = edgepxl.v - scale * _lpTables[edgepxl.wDir][i].dDist * sin(_lpTables[edgepxl.wDir][i].dAng + dAng);

                    // 투표 배열에 스케일링과 회전을 고려하여 투표
                    if(ptCen._dX >= 0 && ptCen._dX < igMain.Row() && ptCen._dY >= 0 && ptCen._dY < igMain.Col()) {
                        votes[ptCen._dX][ptCen._dY][s][r] += 1.0;
                    }
                }
            }
        }
    }

    double maxVote = 0;
    int maxPosX, maxPosY, maxScaleIndex, maxRotationIndex;
    for(int x = 0; x < igMain.Row(); ++x) {
        for(int y = 0; y < igMain.Col(); ++y) {
            for(int s = 0; s < scaleSteps; ++s) {
                for(int r = 0; r < oInfo.nNumGridAng; ++r) {
                    if(votes[x][y][s][r] > maxVote) {
                        maxVote = votes[x][y][s][r];
                        maxPosX = x;
                        maxPosY = y;
                        maxScaleIndex = s;
                        maxRotationIndex = r;
                    }
                }
            }
        }
    }

    // 이 값들은 이미 계산되었다고 가정합니다.
    double finalScale = minScale + maxScaleIndex * scaleStep; // 스케일 계산
    double finalRotation = maxRotationIndex * _dSRAD; // 회전 각도 계산

    // 중심점 및 변환된 점들 계산
    double centerX = oInfo.nLeft + maxPosX * _dSx;
    double centerY = oInfo.nTop + maxPosY * _dSy;
    std::vector<KPoint> transformedPoints;

    // 각 점을 새로운 위치, 스케일 및 각도에 맞게 변환
    for (const KPoint &pt : _lPoints2D) {
        // 중심점으로부터의 상대 위치 계산
        double relativeX = pt._dX - centerX;
        double relativeY = pt._dY - centerY;

        // 스케일 적용
        relativeX *= finalScale;
        relativeY *= finalScale;

        // 회전 적용
        double rotatedX = cos(finalRotation) * relativeX - sin(finalRotation) * relativeY;
        double rotatedY = sin(finalRotation) * relativeX + cos(finalRotation) * relativeY;

        // 중심점에 회전된 위치 추가
        KPoint transformedPt;
        transformedPt._dX = rotatedX + centerX;
        transformedPt._dY = rotatedY + centerY;
        transformedPoints.push_back(transformedPt);
    }

    ImageForm* q_pForm = 0;

    for(auto item: _lImageForm)
        if(item->ID() == "General Hough Transform" && item->size() == _q_pFormFocused->size())
        {
            q_pForm = item;
            q_pForm->Update(igMain.GrayToRGB());
            break;
        }

    if(q_pForm == 0){
        q_pForm = new ImageForm(igMain.GrayToRGB(), "General Hough Transform", this);
        _lImageForm.push_back(q_pForm);
    }
    QPolygon polygon;
    for (const KPoint &pt : transformedPoints) {
        polygon << QPoint(static_cast<int>(pt._dX), static_cast<int>(pt._dY));
    }

    // q_pForm의 DrawPoints 메서드를 사용하여 점들을 그립니다.
    q_pForm->DrawPoints(polygon, QColor(255, 0, 0), 2);
    // 화면 업데이트
    q_pForm->update();
    q_pForm->show();

    /*if(ui->listWidget->isVisible() == false){
        on_pushFindMask_clicked();
    }*/

    UpdateUI();
}
