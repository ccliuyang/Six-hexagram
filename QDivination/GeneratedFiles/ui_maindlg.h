/********************************************************************************
** Form generated from reading UI file 'maindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDLG_H
#define UI_MAINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ctitlebar.h>

QT_BEGIN_NAMESPACE

class Ui_MainDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    CTitleBar *titleBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMenu;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnMenuMin;
    QPushButton *btnMenuClose;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QComboBox *comboBox_7;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QComboBox *comboBox_4;
    QComboBox *comboBox_3;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_5;
    QComboBox *comboBox_6;
    QComboBox *comboBox;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QComboBox *comboBox_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *MainDlg)
    {
        if (MainDlg->objectName().isEmpty())
            MainDlg->setObjectName(QStringLiteral("MainDlg"));
        MainDlg->resize(850, 549);
        verticalLayout_2 = new QVBoxLayout(MainDlg);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleBar = new CTitleBar(MainDlg);
        titleBar->setObjectName(QStringLiteral("titleBar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleBar->sizePolicy().hasHeightForWidth());
        titleBar->setSizePolicy(sizePolicy);
        titleBar->setMinimumSize(QSize(50, 34));
        titleBar->setMaximumSize(QSize(16777215, 50));
        titleBar->setMouseTracking(false);
        titleBar->setAcceptDrops(false);
        titleBar->setAutoFillBackground(false);
        titleBar->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(titleBar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 0, 6, 0);
        btnMenu = new QPushButton(titleBar);
        btnMenu->setObjectName(QStringLiteral("btnMenu"));
        btnMenu->setMinimumSize(QSize(32, 32));

        horizontalLayout->addWidget(btnMenu);

        horizontalSpacer = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(titleBar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMargin(5);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(287, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnMenuMin = new QPushButton(titleBar);
        btnMenuMin->setObjectName(QStringLiteral("btnMenuMin"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnMenuMin->sizePolicy().hasHeightForWidth());
        btnMenuMin->setSizePolicy(sizePolicy1);
        btnMenuMin->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btnMenuMin);

        btnMenuClose = new QPushButton(titleBar);
        btnMenuClose->setObjectName(QStringLiteral("btnMenuClose"));
        sizePolicy1.setHeightForWidth(btnMenuClose->sizePolicy().hasHeightForWidth());
        btnMenuClose->setSizePolicy(sizePolicy1);
        btnMenuClose->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btnMenuClose);


        verticalLayout->addWidget(titleBar);

        groupBox = new QGroupBox(MainDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        comboBox_7 = new QComboBox(groupBox);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        gridLayout->addWidget(comboBox_7, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(400, 300));
        widget->setStyleSheet(QLatin1String("QWidget{border:1px solid #000000;\n"
"border-radius:2px;\n"
"background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,  stop:0 #FFFFF1,  stop: 1 #FFFFFF);\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(14);
        label_7->setFont(font1);
        label_7->setFrameShape(QFrame::NoFrame);
        label_7->setFrameShadow(QFrame::Plain);
        label_7->setMidLineWidth(0);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setMargin(10);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        comboBox_4 = new QComboBox(widget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_4->sizePolicy().hasHeightForWidth());
        comboBox_4->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setWeight(50);
        font2.setKerning(true);
        comboBox_4->setFont(font2);

        gridLayout_2->addWidget(comboBox_4, 3, 1, 1, 1);

        comboBox_3 = new QComboBox(widget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        sizePolicy3.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy3);
        comboBox_3->setFont(font2);

        gridLayout_2->addWidget(comboBox_3, 2, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(10);

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setMargin(10);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(10);

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setMargin(10);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        comboBox_6 = new QComboBox(widget);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        sizePolicy3.setHeightForWidth(comboBox_6->sizePolicy().hasHeightForWidth());
        comboBox_6->setSizePolicy(sizePolicy3);
        comboBox_6->setFont(font2);

        gridLayout_2->addWidget(comboBox_6, 5, 1, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        comboBox->setFont(font2);

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(10);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        sizePolicy3.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy3);
        comboBox_2->setFont(font2);

        gridLayout_2->addWidget(comboBox_2, 1, 1, 1, 1);

        comboBox_5 = new QComboBox(widget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        sizePolicy3.setHeightForWidth(comboBox_5->sizePolicy().hasHeightForWidth());
        comboBox_5->setSizePolicy(sizePolicy3);
        comboBox_5->setFont(font2);

        gridLayout_2->addWidget(comboBox_5, 4, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);


        verticalLayout_4->addWidget(widget);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton->setFont(font3);

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MainDlg);

        QMetaObject::connectSlotsByName(MainDlg);
    } // setupUi

    void retranslateUi(QDialog *MainDlg)
    {
        MainDlg->setWindowTitle(QApplication::translate("MainDlg", "MainDlg", Q_NULLPTR));
        btnMenu->setText(QString());
        label_2->setText(QApplication::translate("MainDlg", "China divination", Q_NULLPTR));
        btnMenuMin->setText(QString());
        btnMenuClose->setText(QString());
        groupBox->setTitle(QString());
        label_8->setText(QApplication::translate("MainDlg", "\350\265\267\345\215\246\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainDlg", "\345\215\240\344\272\213\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainDlg", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\344\275\277\347\224\250\351\223\234\351\222\261\350\277\233\350\241\214\347\210\273\345\215\246\357\274\214\345\260\206\346\257\217\346\254\241\347\210\273\345\215\246\347\273\223\346\236\234\345\241\253\345\206\231\345\234\250\344\270\213\351\235\242</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainDlg", "\345\205\255\347\210\273\357\274\232", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainDlg", "\345\260\221\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\345\260\221\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205O", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205X", Q_NULLPTR)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainDlg", "\345\260\221\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\345\260\221\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205O", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205X", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainDlg", "\345\210\235\347\210\273\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainDlg", "\344\272\224\347\210\273\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainDlg", "\344\272\214\347\210\273\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainDlg", "\345\233\233\347\210\273\357\274\232", Q_NULLPTR));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("MainDlg", "\345\260\221\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\345\260\221\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205O", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205X", Q_NULLPTR)
        );
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainDlg", "\345\260\221\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\345\260\221\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205O", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205X", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainDlg", "\344\270\211\347\210\273\357\274\232", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainDlg", "\345\260\221\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\345\260\221\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205O", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205X", Q_NULLPTR)
        );
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainDlg", "\345\260\221\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\345\260\221\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\263\342\226\205\342\226\205\342\226\205\342\226\205\342\226\205O", Q_NULLPTR)
         << QApplication::translate("MainDlg", "\350\200\201\351\230\264\342\226\205\342\226\205    \342\226\205\342\226\205X", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("MainDlg", "\345\274\200\345\247\213\350\265\267\345\215\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainDlg: public Ui_MainDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDLG_H
