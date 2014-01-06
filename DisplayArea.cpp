//
//  DisplayArea.cpp
//  MPIBrot
//
//  Created by Robert Jacobson on 1/4/14.
//
//

#include <QtGui/QMouseEvent>

#include "DisplayArea.h"

void DisplayArea::renderImage(){
    Point window(width(), height());
    float *colors;
    
    colors = Mandelbrot::Render(window, view, maxIterations, colorMethod);
    
    // The pointer image is initialized to 0.
    if(image) delete image;
    image = colorsToQImage(window, colors, colorMethod);
    setPixmap(QPixmap::fromImage(*image));
    
    delete colors;
}

void DisplayArea::mouseReleaseEvent(QMouseEvent *ev){
    // We are only interested in left or right clicks.
    if( !(ev->button() == Qt::LeftButton || ev->button() == Qt::RightButton)) return;
    
    // Convert the mouse coordinates to view coordinates.
    // (Remember that in view coordinates, the positive y direction is up, not down.)
    // This point will be the center of our new view.
    Point point;
    point.x = (float)ev->x()/(float)width()*view.width + view.x;
    point.y = -(float)ev->y()/(float)height()*view.height + view.y;

    // Left click zooms in.
    if(ev->button() == Qt::LeftButton){
        view.width = view.width/zoomAmount;
        view.height = view.height/zoomAmount;
    }
    // Right click zooms out.
    else if(ev->button() == Qt::RightButton){
        view.width = view.width*zoomAmount;
        view.height = view.height*zoomAmount;
    }
    
    view.x = point.x - view.width/2.0f;
    view.y = point.y + view.height/2.0f;
    
    emit viewChanged();
    
    // Redraw the image.
    renderImage();
}

DisplayArea::DisplayArea(QWidget *parent) : QLabel(parent){
    // Sensible defaults are already provided for member variables in the class definition.
}

QImage *DisplayArea::colorsToQImage(Point window, float *colors, ColorMethod colorMethod){
    // The QImage object we will paint on and return.
    QImage *image = new QImage((int)window.x, (int)window.y, QImage::Format_RGB32);
    QColor color;
    int colorval;
    int x, y;
    
    for(y = 0; y < window.y; y++ ){
        for(x = 0; x < window.x; x++ ){
            switch (colorMethod) {
                case Standard:
                    colorval = (int)(colors[x + (int)window.x*y] * 255.0f);
                    image->setPixel(x, y, qRgb(colorval, colorval, colorval));
                    break;
                    
                case Phase:
                    // HSV takes angles in degrees, not radians. (WTF?!)
                    colorval = (int)(colors[x + (int)window.x*y] * 180.0f / (PI));
                    color = QColor::fromHsv(colorval, 255, 255);
                    image->setPixel(x, y, color.rgb());
                    break;
                    
                default:
                    break;
            } // end switch
        } // x loop
    } // y loop
    
    return image;
}

DisplayArea::~DisplayArea(){
    delete image;
}