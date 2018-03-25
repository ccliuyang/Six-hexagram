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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDivinationClass
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLabel *label_9;
    QLineEdit *lineEdit_2;
    QCalendarWidget *calendarWidget;
    QDateTimeEdit *dateTimeEdit;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_5;
    QComboBox *comboBox_4;
    QLabel *label_4;
    QComboBox *comboBox_5;
    QLabel *label_6;
    QComboBox *comboBox_6;
    QLabel *label_7;
    QComboBox *comboBox_7;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QDivinationClass)
    {
        if (QDivinationClass->objectName().isEmpty())
            QDivinationClass->setObjectName(QStringLiteral("QDivinationClass"));
        QDivinationClass->resize(776, 491);
        action = new QAction(QDivinationClass);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(QDivinationClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(QDivinationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        horizontalLayout->addWidget(calendarWidget);


        verticalLayout->addLayout(horizontalLayout);

        dateTimeEdit = new QDateTimeEdit(centralWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        verticalLayout->addWidget(dateTimeEdit);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBox_3 = new QComboBox(centralWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 2, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        comboBox_4 = new QComboBox(centralWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout->addWidget(comboBox_4, 3, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        comboBox_5 = new QComboBox(centralWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        gridLayout->addWidget(comboBox_5, 4, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        comboBox_6 = new QComboBox(centralWidget);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        gridLayout->addWidget(comboBox_6, 5, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        comboBox_7 = new QComboBox(centralWidget);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        gridLayout->addWidget(comboBox_7, 6, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 200));
        label_10->setFrameShape(QFrame::Box);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_10);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_3->addWidget(textEdit);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

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
        menu->addAction(action);
        menu->addAction(action_2);

        retranslateUi(QDivinationClass);

        QMetaObject::connectSlotsByName(QDivinationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QDivinationClass)
    {
        QDivinationClass->setWindowTitle(QApplication::translate("QDivinationClass", "QDivination", Q_NULLPTR));
        action->setText(QApplication::translate("QDivinationClass", "\346\226\260\345\273\272", Q_NULLPTR));
        action_2->setText(QApplication::translate("QDivinationClass", "\351\200\200\345\207\272", Q_NULLPTR));
        label_8->setText(QApplication::translate("QDivinationClass", "\346\234\210", Q_NULLPTR));
        label_9->setText(QApplication::translate("QDivinationClass", "\346\227\245", Q_NULLPTR));
        label->setText(QApplication::translate("QDivinationClass", "\345\205\255\347\210\273", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\263\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\264\342\200\224 \342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\263O\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\264X\342\200\224 \342\200\224", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("QDivinationClass", "\344\272\224\347\210\273", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\263\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\264\342\200\224 \342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\263O\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\264X\342\200\224 \342\200\224", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("QDivinationClass", "\345\233\233\347\210\273", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\263\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\264\342\200\224 \342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\263O\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\264X\342\200\224 \342\200\224", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("QDivinationClass", "\344\270\211\347\210\273", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\263\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\264\342\200\224 \342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\263O\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\264X\342\200\224 \342\200\224", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("QDivinationClass", "\344\272\214\347\210\273", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\263\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\264\342\200\224 \342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\263O\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\264X\342\200\224 \342\200\224", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("QDivinationClass", "\345\210\235\347\210\273", Q_NULLPTR));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\263\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\260\221\351\230\264\342\200\224 \342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\263O\342\200\224\342\200\224", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\350\200\201\351\230\264X\342\200\224 \342\200\224", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("QDivinationClass", "\347\224\250\347\245\236\357\274\232", Q_NULLPTR));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("QDivinationClass", "\345\210\235\347\210\273", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\344\272\214\347\210\273", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\344\270\211\347\210\273", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\233\233\347\210\273", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\344\272\224\347\210\273", Q_NULLPTR)
         << QApplication::translate("QDivinationClass", "\345\205\255\347\210\273", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("QDivinationClass", "\350\256\241\347\256\227", Q_NULLPTR));
        label_10->setText(QApplication::translate("QDivinationClass", "\346\216\222\347\233\230\344\277\241\346\201\257", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QDivinationClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("QDivinationClass", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QDivinationClass: public Ui_QDivinationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIVINATION_H
