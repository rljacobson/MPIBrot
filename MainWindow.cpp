//
//  MainWindow.cpp
//  MPIBrot
//
//  Created by Robert Jacobson on 12/31/13.
//
//

#include <QtWidgets/QMessagebox>
#include <QtWidgets/QLabel>
#include <QtGui/QPixmap>
#include <QtCore/QString>

#include "MainWindow.h"
#include "DisplayArea.h"

void displayMessage(const char *);
void displayMessage(const char *message){
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}


void MainWindow::on_renderButton_clicked(){
    displayArea->renderImage();
}

void MainWindow::updateSizeLabel(){
    QString sizeLabelText;
    
    // Construct the size label text which looks like "800x600".
    sizeLabelText.append(QString::number(displayArea->width())).append("x").append(QString::number(displayArea->height()));
    
    sizeLabel->setText(sizeLabelText);
}

void MainWindow::updateViewLabel(){
    Rect view = displayArea->view;
    
    QString viewLabelText = QString("View: (");
    
    // Construct the view label text which looks like "View: (-2, 1)-(2, -1)".
    viewLabelText.append(QString::number(view.x)).append(", ");
    viewLabelText.append(QString::number(view.y)).append(")-(");
    viewLabelText.append(QString::number(view.x+view.width)).append(", ");
    viewLabelText.append(QString::number(view.y-view.height)).append(")");
    
    viewLabel->setText(viewLabelText);
}

void MainWindow::resizeEvent(QResizeEvent * event){
    updateSizeLabel();
}

void MainWindow::on_maxIterationsTextbox_editingFinished(){
    displayArea->maxIterations = maxIterationsTextbox->text().toInt();
}

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    setupUi(this);
    
    // The DisplayArea's view needs to be connected to the viewLabel.
    connect(displayArea, SIGNAL(viewChanged()), this, SLOT(updateViewLabel()));
    // Give us a nice default view.
    displayArea->view = Rect(-2.75, 1.5, 4.5, 3);
    displayArea->maxIterations = 200;
    displayArea->colorMethod = Phase;
    
    // The maxIterationsTextbox should only accept integers in a certain range.
    QIntValidator *maxIterationsValidator = new QIntValidator(1, INT_MAX, maxIterationsTextbox);
    maxIterationsTextbox->setValidator(maxIterationsValidator);
    maxIterationsTextbox->setText("200");
    
    updateViewLabel();
    updateSizeLabel();
}