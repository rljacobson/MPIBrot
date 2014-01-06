//
//  Mandelbrot.cpp
//  Mandelbrot
//
//  Created by Robert Jacobson on 12/26/13.
//  Copyright (c) 2013 Robert Jacobson. All rights reserved.
//

#include "Mandelbrot.h"
#include <math.h>

float Mandelbrot::phase(Point point){
    // The atan function returns values in [-pi/2, pi/2]. We must therefore check
    // which quadrant point is in and adjust accordingly.
    float angle = 0;
    
    // We check that we're not dividing by zero.
    if(point.x != 0.0f){
        angle = atan(point.y/point.x);
    }
    else{
        // If the point is on the imaginary axis...
        if(point.y > 0) angle = PI/2.0f;
        else angle = 3.0f*PI/2.0f;
    }
    
    // If point is on the left half plane...
    if(point.x < 0){
        angle += PI;
    }
    
    // Make sure we return a value in [0, 2pi).
    if(angle < 0.0f) angle += 2.0f*PI;
    
    return angle;
}

float Mandelbrot::color(Point point, int maxIterations, ColorMethod colorMethod){
    float colorval = 0;
    int iterations = 0;
    
    // Initialize to the point given.
    Point z = point, c  = point;
    Point w; // Holds the next value of z.
    
    // Now we iterate the map z <-- z^2 + C, where C is the point given.
    for(iterations = 0; iterations < maxIterations; iterations++){
        
        // z^2 = (x + iy)(x + iy) = (x^2 - y^2) + 2xyi
        w.x = z.x*z.x - z.y*z.y + c.x;
        w.y = 2*z.x*z.y + c.y;
        
        /*
         It is known that if z wanders outside of a circle of radius 2,
         then z will never converge.
        */
        if(sqrt(w.x*w.x + w.y*w.y) > 2){
            // z will not converge, so point is not in the Mandelbrot set.
            switch (colorMethod) {
                case Standard:
                    // We set the colorvalue based on how many iterations it took to
                    // determine that z escapes.
                    colorval = sqrt((float)iterations/(float)maxIterations);
                    break;
                case Phase:
                    colorval = phase(w);
                    break;
                default:
                    break;
            }
            
            break; // Break out of the loop.
        }
        
        //Record the previous point and loop.
        z = w;
    }
    
    return colorval;
}

float *Mandelbrot::Render(Point window, Rect view, int maxIterations, ColorMethod colorMethod){
    /*
     For each point in window, determine the corresponding point in view.
     Then compute the color of the point according to its convergence
     behavior.
     
     The window is a rectangle of pixels into which we draw points. The 
     view is a region on the complex plane.
    */
    
    /* 
     Create an array to hold the computed color values. Keep in mind that
     this one dimensional array is holding two dimensional data.
    */
    float *points = new float[(int)window.x*(int)window.y];
    
    // Which point we are computing the color of.
    Point point;
    
    // This is the increment.
    Point inc;
    inc.x = view.width/window.x;
    inc.y = -view.height/window.y;
    
    int x,y;
    float maxColor = 0;
    float currentColor;

    for(point.y = view.y, y = 0; y < window.y; point.y += inc.y, y++ ){
        for(point.x = view.x, x = 0; x < window.x; point.x += inc.x, x++ ){
            currentColor = Mandelbrot::color(point, maxIterations, colorMethod);
            // Record the maximum color value so we can normalize later.
            if(colorMethod == Standard && currentColor > maxColor) maxColor = currentColor;
            points[x + (int)window.x*y] = currentColor;
        }
    }
    
    if(colorMethod == Standard){
        // Normalize the color values.
        for(int j = 0; j < (int)(window.x*window.y); j++){
            points[j] = points[j]/maxColor;
        }
    }
    
    return points;
}