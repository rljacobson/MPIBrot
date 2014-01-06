//
//  Mandelbrot.h
//  Mandelbrot
//
//  Created by Robert Jacobson on 12/26/13.
//  Copyright (c) 2013 Robert Jacobson. All rights reserved.
//

#ifndef __Mandelbrot__Mandelbrot__
#define __Mandelbrot__Mandelbrot__

#include <iostream>

#define MANDEL_MAX_ITER  200.0f
#define PI 3.14159265f

enum ColorMethod {
    Standard = 0,
    Phase = 1
};

class Point {
public:
    float x;
    float y;
    Point(float xval, float yval){
        x = xval;
        y = yval;
    }
    Point(){
        x=y=0;
    }
};

class Rect {
public:
    float x;
    float y;
    float width;
    float height;
    Rect(float xval, float yval, float widthval, float heightval){
        x = xval;
        y = yval;
        width = widthval;
        height = heightval;
    }
    Rect(){
        x=y=width=height=0;
    }
};

namespace Mandelbrot{
    // Given a point in the complex plane, returns zero of the point is in the Mandelbrot
    // set, and a nonzero number computed from the divergence behavior if the point is not
    // in the Mandelbrot set.
    float color(Point point, int maxIterations, ColorMethod colorMethod);
    
    // Returns a pointer to an array of floats of size window.x*window.y representing 'color'
    // data for the region in the complex plane given by view. This function allocates the
    // array on the heap.
    float *Render(Point window, Rect view, int maxIterations, ColorMethod colorMethod);
    
    // Returns the phase (argument) in [0, 2pi) of a complex number represented by a point.
    float phase(Point point);
};

#endif /* defined(__Mandelbrot__Mandelbrot__) */
