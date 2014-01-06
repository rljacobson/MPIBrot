/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "DisplayArea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quit;
    QAction *action_Save_Image;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    DisplayArea *displayArea;
    QHBoxLayout *horizontalLayout;
    QPushButton *renderButton;
    QLabel *label;
    QLineEdit *maxIterationsTextbox;
    QSpacerItem *horizontalSpacer;
    QLabel *viewLabel;
    QLabel *sizeLabel;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(702, 547);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Save_Image = new QAction(MainWindow);
        action_Save_Image->setObjectName(QStringLiteral("action_Save_Image"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        displayArea = new DisplayArea(centralwidget);
        displayArea->setObjectName(QStringLiteral("displayArea"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(displayArea->sizePolicy().hasHeightForWidth());
        displayArea->setSizePolicy(sizePolicy);
        displayArea->setFrameShape(QFrame::NoFrame);
        displayArea->setScaledContents(true);

        verticalLayout->addWidget(displayArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        renderButton = new QPushButton(centralwidget);
        renderButton->setObjectName(QStringLiteral("renderButton"));
        renderButton->setAutoDefault(true);
        renderButton->setDefault(false);
        renderButton->setFlat(false);

        horizontalLayout->addWidget(renderButton);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        maxIterationsTextbox = new QLineEdit(centralwidget);
        maxIterationsTextbox->setObjectName(QStringLiteral("maxIterationsTextbox"));
        maxIterationsTextbox->setMaxLength(5);
        maxIterationsTextbox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(maxIterationsTextbox);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        viewLabel = new QLabel(centralwidget);
        viewLabel->setObjectName(QStringLiteral("viewLabel"));

        horizontalLayout->addWidget(viewLabel);

        sizeLabel = new QLabel(centralwidget);
        sizeLabel->setObjectName(QStringLiteral("sizeLabel"));

        horizontalLayout->addWidget(sizeLabel);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 702, 22));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Save_Image);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindow);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MPIBrot", 0));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        action_Save_Image->setText(QApplication::translate("MainWindow", "&Save Image...", 0));
        displayArea->setText(QString());
        renderButton->setText(QApplication::translate("MainWindow", "Render", 0));
        label->setText(QApplication::translate("MainWindow", "Max iterations:", 0));
        viewLabel->setText(QApplication::translate("MainWindow", "View: (-2, 3)-(2, -1.5)", 0));
        sizeLabel->setText(QApplication::translate("MainWindow", "800x600", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
