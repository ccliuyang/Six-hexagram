/********************************************************************************
** Form generated from reading UI file 'InputHexagramDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTHEXAGRAMDLG_H
#define UI_INPUTHEXAGRAMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputHexagramDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *cbSex;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLabel *label_11;
    QComboBox *cb_6;
    QLabel *label_10;
    QComboBox *cb_5;
    QLabel *label_9;
    QComboBox *cb_4;
    QLabel *label_8;
    QComboBox *cb_3;
    QLabel *label_7;
    QComboBox *cb_2;
    QLabel *label_6;
    QComboBox *cb_1;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *InputHexagramDlg)
    {
        if (InputHexagramDlg->objectName().isEmpty())
            InputHexagramDlg->setObjectName(QStringLiteral("InputHexagramDlg"));
        InputHexagramDlg->resize(753, 437);
        verticalLayout = new QVBoxLayout(InputHexagramDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(InputHexagramDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(420, 350));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setTextFormat(Qt::AutoText);
        label->setPixmap(QPixmap(QString::fromUtf8(":/QDivination/image/guize.jpg")));
        label->setScaledContents(true);

        horizontalLayout_4->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        horizontalLayout_3->addWidget(dateTimeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        cbSex = new QComboBox(groupBox);
        cbSex->setObjectName(QStringLiteral("cbSex"));

        horizontalLayout_2->addWidget(cbSex);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(15);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_11, 0, 0, 1, 1);

        cb_6 = new QComboBox(groupBox);
        cb_6->setObjectName(QStringLiteral("cb_6"));

        gridLayout->addWidget(cb_6, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        cb_5 = new QComboBox(groupBox);
        cb_5->setObjectName(QStringLiteral("cb_5"));

        gridLayout->addWidget(cb_5, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        cb_4 = new QComboBox(groupBox);
        cb_4->setObjectName(QStringLiteral("cb_4"));

        gridLayout->addWidget(cb_4, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        cb_3 = new QComboBox(groupBox);
        cb_3->setObjectName(QStringLiteral("cb_3"));

        gridLayout->addWidget(cb_3, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        cb_2 = new QComboBox(groupBox);
        cb_2->setObjectName(QStringLiteral("cb_2"));

        gridLayout->addWidget(cb_2, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        cb_1 = new QComboBox(groupBox);
        cb_1->setObjectName(QStringLiteral("cb_1"));

        gridLayout->addWidget(cb_1, 5, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        btnOk = new QPushButton(groupBox);
        btnOk->setObjectName(QStringLiteral("btnOk"));

        horizontalLayout_7->addWidget(btnOk);

        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_7->addWidget(btnCancel);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addWidget(groupBox);


        retranslateUi(InputHexagramDlg);

        QMetaObject::connectSlotsByName(InputHexagramDlg);
    } // setupUi

    void retranslateUi(QDialog *InputHexagramDlg)
    {
        InputHexagramDlg->setWindowTitle(QApplication::translate("InputHexagramDlg", "InputHexagramDlg", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("InputHexagramDlg", "\346\216\222\347\233\230", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("InputHexagramDlg", "\351\230\263\345\216\206\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputHexagramDlg", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        cbSex->clear();
        cbSex->insertItems(0, QStringList()
         << QApplication::translate("InputHexagramDlg", "\347\224\267", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\345\245\263", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("InputHexagramDlg", "\345\205\255\347\210\273\357\274\232", Q_NULLPTR));
        cb_6->clear();
        cb_6->insertItems(0, QStringList()
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\263-", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\264- -", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\263O", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\264X", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("InputHexagramDlg", "\344\272\224\347\210\273\357\274\232", Q_NULLPTR));
        cb_5->clear();
        cb_5->insertItems(0, QStringList()
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\263-", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\264- -", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\263O", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\264X", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("InputHexagramDlg", "\345\233\233\347\210\273\357\274\232", Q_NULLPTR));
        cb_4->clear();
        cb_4->insertItems(0, QStringList()
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\263-", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\264- -", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\263O", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\264X", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("InputHexagramDlg", "\344\270\211\347\210\273\357\274\232", Q_NULLPTR));
        cb_3->clear();
        cb_3->insertItems(0, QStringList()
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\263-", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\264- -", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\263O", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\264X", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("InputHexagramDlg", "\344\272\214\347\210\273\357\274\232", Q_NULLPTR));
        cb_2->clear();
        cb_2->insertItems(0, QStringList()
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\263-", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\264- -", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\263O", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\264X", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("InputHexagramDlg", "\345\210\235\347\210\273\357\274\232", Q_NULLPTR));
        cb_1->clear();
        cb_1->insertItems(0, QStringList()
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\263-", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\345\260\221\351\230\264- -", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\263O", Q_NULLPTR)
         << QApplication::translate("InputHexagramDlg", "\350\200\201\351\230\264X", Q_NULLPTR)
        );
        btnOk->setText(QApplication::translate("InputHexagramDlg", "\346\216\222\347\233\230", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("InputHexagramDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputHexagramDlg: public Ui_InputHexagramDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTHEXAGRAMDLG_H
