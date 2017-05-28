/********************************************************************************
** Form generated from reading UI file 'playlist_page.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_PAGE_H
#define UI_PLAYLIST_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playlist_page
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *playlist_tableview;

    void setupUi(QWidget *playlist_page)
    {
        if (playlist_page->objectName().isEmpty())
            playlist_page->setObjectName(QStringLiteral("playlist_page"));
        playlist_page->resize(400, 300);
        verticalLayout = new QVBoxLayout(playlist_page);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        playlist_tableview = new QTableView(playlist_page);
        playlist_tableview->setObjectName(QStringLiteral("playlist_tableview"));
        playlist_tableview->setProperty("showDropIndicator", QVariant(false));
        playlist_tableview->setSelectionMode(QAbstractItemView::SingleSelection);
        playlist_tableview->setSelectionBehavior(QAbstractItemView::SelectRows);
        playlist_tableview->setGridStyle(Qt::SolidLine);
        playlist_tableview->setCornerButtonEnabled(false);

        verticalLayout->addWidget(playlist_tableview);


        retranslateUi(playlist_page);

        QMetaObject::connectSlotsByName(playlist_page);
    } // setupUi

    void retranslateUi(QWidget *playlist_page)
    {
        playlist_page->setWindowTitle(QApplication::translate("playlist_page", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class playlist_page: public Ui_playlist_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_PAGE_H
