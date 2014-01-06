//
//  main.cpp
//  MPIBrot
//
//  Created by Robert Jacobson on 12/17/13.
//  Copyright (c) 2013 Robert Jacobson. All rights reserved.
//

//#include <mpi.h>
#include <QtWidgets/QApplication>

#include <iostream>

#include "MainWindow.h"

int main(int argc, char * argv[])
{
    /*
    int numprocs, rank, namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    
    //MPI_Init(&argc, &argv);
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processor_name, &namelen);
    
    std::cout << "Process" << rank << " on " << processor_name;
    std::cout << " out of " << numprocs << "\n";
    
    MPI_Finalize();
    */
    
    QApplication app(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    
    return app.exec();
}

