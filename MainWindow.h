//
//  MainWindow.h
//  MPIBrot
//
//  Created by Robert Jacobson on 12/31/13.
//
//

#ifndef __MPIBrot__MainWindow__
#define __MPIBrot__MainWindow__

#include <QtWidgets/QMainWindow>

#include "Mandelbrot.h"
#include "ui_mainwindow.h"
#include "DisplayArea.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);

private:
    // Whenever the display area is resized, we update the size display label.
    void updateSizeLabel();
    void resizeEvent(QResizeEvent * event);

private slots:
    void on_renderButton_clicked();
    void on_maxIterationsTextbox_editingFinished();
    void updateViewLabel();
//    void on_inputSpinBox1_valueChanged(int value);
//    void on_inputSpinBox2_valueChanged(int value);
};

#endif /* defined(__MPIBrot__MainWindow__) */
