#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QDialog>

namespace Ui {
class MainFrame;

}

class ImageForm;

class MainFrame : public QDialog
{
    Q_OBJECT

private:
    Ui::MainFrame *ui;

    std::vector<ImageForm*>  _lImageForm;
    ImageForm*               _q_pFormFocused;

public:
    explicit MainFrame(QWidget *parent = 0);
    ~MainFrame();

    void    ImageFormFocused(ImageForm* q_pImageForm)
            {   _q_pFormFocused  = q_pImageForm;   //활성화된 창의 포인터를 저장함
                UpdateUI();                        //UI 활성화 갱신
            }
    void    UpdateUI();
    void    CloseImageForm(ImageForm* pForm);

public:
    void    focusInEvent(QFocusEvent *event);
    void    OnMousePos(const int& nX, const int& nY, ImageForm* q_pForm);

private slots:
    void on_buttonOpen_clicked();
    void on_buttonDeleteContents_clicked();        
    void on_tabWidget_currentChanged(int index);               
    void on_buttonShowList_clicked();


    void on_pushRGB2Gray_clicked();

    void on_pushSepiaTone_clicked();

    void on_pushContrast_clicked();

    void on_pushHistogram_clicked();

    void on_pushOstu_clicked();

    void on_pushThresholding_clicked();

    void on_pushDilation_clicked();

    void on_pushErosion_clicked();

    void on_pushBoundary_clicked();

    void on_pushBoundaryFG_clicked();

    void on_pushGaussianNoise_clicked();

    void on_pushSaltPepper_clicked();

    void on_pushGaussianSmoothing_clicked();

    void on_pushMedianFiltering_clicked();

    void on_pushHistogramEQ_clicked();



    void on_pushHistogramMatching_clicked();

    void on_pushEdgeFDG_clicked();

    void on_pushCanny_clicked();

    void on_pushCircleLocalization_clicked();

    void on_pushHarrisCorner_clicked();

    void on_pushPyramid_clicked();

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // MAINFRAME_H
