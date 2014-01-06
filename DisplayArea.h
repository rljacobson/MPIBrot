//
//  DisplayArea.h
//  MPIBrot
//
//  Created by Robert Jacobson on 1/4/14.
//
//

#ifndef __MPIBrot__DisplayArea__
#define __MPIBrot__DisplayArea__

#include <QtWidgets/QLabel>
#include "Mandelbrot.h"

class DisplayArea: public QLabel {
    Q_OBJECT
    
public:
    // Variables
    Rect view = Rect(-2.75, 1.5, 4.5, 3);
    int maxIterations = 200;
    ColorMethod colorMethod = Standard;
    bool antialiased = false;
    float zoomAmount = 1.5f;

    // Methods
    void renderImage();
    void mouseReleaseEvent(QMouseEvent *event);
    DisplayArea(QWidget *parent = 0);
    
private:
    // Variables
    QImage *image = 0;
    
    //Methods
    QImage *colorsToQImage(Point window, float *colors, ColorMethod colorMethod);
    ~DisplayArea();
    
signals:
    void viewChanged();
};

#endif /* defined(__MPIBrot__DisplayArea__) */
