/********************************************************************************
** Form generated from reading UI file 'QDivination.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIVINATION_H
#define UI_QDIVINATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDivinationClass
{
public:
    QAction *actNew;
    QAction *action_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QDivinationClass)
    {
        if (QDivinationClass->objectName().isEmpty())
            QDivinationClass->setObjectName(QStringLiteral("QDivinationClass"));
        QDivinationClass->resize(776, 492);
        actNew = new QAction(QDivinationClass);
        actNew->setObjectName(QStringLiteral("actNew"));
        action_2 = new QAction(QDivinationClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(QDivinationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        QDivinationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QDivinationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 776, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        QDivinationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QDivinationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QDivinationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QDivinationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QDivinationClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actNew);
        menu->addAction(action_2);

        retranslateUi(QDivinationClass);

        QMetaObject::connectSlotsByName(QDivinationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QDivinationClass)
    {
        QDivinationClass->setWindowTitle(QApplication::translate("QDivinationClass", "QDivination", Q_NULLPTR));
        actNew->setText(QApplication::translate("QDivinationClass", "\346\226\260\345\273\272", Q_NULLPTR));
        action_2->setText(QApplication::translate("QDivinationClass", "\351\200\200\345\207\272", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QDivinationClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("QDivinationClass", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDivinationClass: public Ui_QDivinationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIVINATION_H
