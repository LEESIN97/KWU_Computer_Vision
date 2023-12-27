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


    void on_pushLuminanceColorTransform_clicked();

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // MAINFRAME_H
