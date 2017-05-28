/********************************************************************************
** Form generated from reading UI file 'main_page.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_PAGE_H
#define UI_MAIN_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_page
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *main_page)
    {
        if (main_page->objectName().isEmpty())
            main_page->setObjectName(QStringLiteral("main_page"));
        main_page->resize(400, 300);
        main_page->setStyleSheet(QLatin1String("\n"
"background: white;"));
        verticalLayout = new QVBoxLayout(main_page);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(main_page);

        QMetaObject::connectSlotsByName(main_page);
    } // setupUi

    void retranslateUi(QWidget *main_page)
    {
        main_page->setWindowTitle(QApplication::translate("main_page", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_page: public Ui_main_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_PAGE_H
