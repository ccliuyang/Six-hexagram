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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDivinationClass
{
public:
    QAction *actNew;
    QAction *action_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QDivinationClass)
    {
        if (QDivinationClass->objectName().isEmpty())
            QDivinationClass->setObjectName(QStringLiteral("QDivinationClass"));
        QDivinationClass->resize(719, 503);
        actNew = new QAction(QDivinationClass);
        actNew->setObjectName(QStringLiteral("actNew"));
        action_2 = new QAction(QDivinationClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(QDivinationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        QDivinationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QDivinationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 719, 23));
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
        label->setText(QApplication::translate("QDivinationClass", "\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \345\205\221\345\256\253\357\274\232\345\234\260\345\261\261\350\260\246 \343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \351\234\207\345\256\253\357\274\232\351\233\267\345\234\260\350\261\253\n"
"\345\205\255\347\245\236 \343\200\200\344\274\217\347\245\236\343\200\200\343\200\200 \343\200\200\343\200\200\343\200\220\344\270\273\343\200\200\345\215\246\343\200\221 \343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \343\200\200   \343\200\200\343\200\220\345\217\230\343\200\200\345\215\246\343\200\221\343\200\200	\n"
"\347\231\275\350\231\216 \343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \345\205\204\345\274\237\347\231\270\351\205\211\351\207\221 \343\200\200\343\200\200 \343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \347\210\266\346\257\215\345"
                        "\272\232\346\210\214\345\234\237 \343\200\200\343\200\200	\n"
"\350\236\243\350\233\207 \343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \345\255\220\345\255\231\347\231\270\344\272\245\346\260\264 \343\200\200\344\270\226 \343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \345\205\204\345\274\237\345\272\232\347\224\263\351\207\221\n"
"\345\213\276\351\231\210 \343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \347\210\266\346\257\215\347\231\270\344\270\221\345\234\237 \343\200\200\343\200\200 \342\205\251 \342\226\205\342\226\205\342\226\205\342\226\205\342\226\205 \345\256\230\351\254\274\345\272\232\345\215\210\347\201\253 \343\200\200\345\272\224 \343\200\200\343\200\200	\n"
"\346\234\261\351\233\200 \343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \342\226\205"
                        "\342\226\205\342\226\205\342\226\205\342\226\205 \345\205\204\345\274\237\344\270\231\347\224\263\351\207\221 \343\200\200\343\200\200 \343\200\207 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \345\246\273\350\264\242\344\271\231\345\215\257\346\234\250 \343\200\200\343\200\200	\n"
"\351\235\222\351\276\231 \343\200\200\345\246\273\350\264\242\344\270\201\345\215\257\346\234\250\343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \345\256\230\351\254\274\344\270\231\345\215\210\347\201\253 \343\200\200\345\272\224 \343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \345\256\230\351\254\274\344\271\231\345\267\263\347\201\253\n"
"\347\216\204\346\255\246 \343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200\343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205 \347\210\266\346\257\215\344\270\231\350\276\260\345\234\237 \343\200\200\343\200\200 \343\200\200 \342\226\205\342\226\205\343\200\200\342\226\205\342\226\205"
                        " \347\210\266\346\257\215\344\271\231\346\234\252\345\234\237 \343\200\200\344\270\226 \343\200\200\343\200\200", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QDivinationClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("QDivinationClass", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDivinationClass: public Ui_QDivinationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIVINATION_H
