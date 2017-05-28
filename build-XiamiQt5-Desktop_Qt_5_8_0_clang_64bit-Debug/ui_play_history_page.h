/********************************************************************************
** Form generated from reading UI file 'play_history_page.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_HISTORY_PAGE_H
#define UI_PLAY_HISTORY_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_play_history_page
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *play_history_tableview;

    void setupUi(QWidget *play_history_page)
    {
        if (play_history_page->objectName().isEmpty())
            play_history_page->setObjectName(QStringLiteral("play_history_page"));
        play_history_page->resize(400, 300);
        verticalLayout = new QVBoxLayout(play_history_page);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        play_history_tableview = new QTableView(play_history_page);
        play_history_tableview->setObjectName(QStringLiteral("play_history_tableview"));
        play_history_tableview->setProperty("showDropIndicator", QVariant(false));
        play_history_tableview->setDragDropOverwriteMode(false);
        play_history_tableview->setSelectionMode(QAbstractItemView::SingleSelection);
        play_history_tableview->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(play_history_tableview);


        retranslateUi(play_history_page);

        QMetaObject::connectSlotsByName(play_history_page);
    } // setupUi

    void retranslateUi(QWidget *play_history_page)
    {
        play_history_page->setWindowTitle(QApplication::translate("play_history_page", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class play_history_page: public Ui_play_history_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_HISTORY_PAGE_H
