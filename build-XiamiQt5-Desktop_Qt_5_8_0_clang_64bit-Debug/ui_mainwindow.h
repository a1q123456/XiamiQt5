/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QWidget *title_bar;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *close_btn;
    QPushButton *maxium_btn;
    QPushButton *minium_btn;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *avatar;
    QWidget *search;
    QLineEdit *lineEdit;
    QPushButton *search_btn;
    QWidget *content;
    QHBoxLayout *horizontalLayout_3;
    QListView *function_list;
    QWidget *main_content;
    QHBoxLayout *horizontalLayout_7;
    QWidget *control_bar;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *prev_btn;
    QCheckBox *play_btn;
    QPushButton *next_btn;
    QSlider *player_duration_slider;
    QLabel *player_position_label;
    QLabel *label_2;
    QLabel *player_duration_label;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 600);
        MainWindow->setStyleSheet(QLatin1String("QMainWIndow#MainWindow {\n"
"border: none;\n"
"\n"
"}"));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget#centralWidget {\n"
"	border: none\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame#frame {\n"
"	border: none;\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        title_bar = new QWidget(frame);
        title_bar->setObjectName(QStringLiteral("title_bar"));
        title_bar->setMaximumSize(QSize(16777215, 60));
        title_bar->setStyleSheet(QLatin1String("QWidget#title_bar {\n"
"background: rgb(243, 243, 243);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(title_bar);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(title_bar);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setMaximumSize(QSize(300, 55555));
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        close_btn = new QPushButton(widget_4);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        close_btn->setMaximumSize(QSize(30, 30));
        close_btn->setFocusPolicy(Qt::ClickFocus);
        close_btn->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/orange.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon);
        close_btn->setFlat(true);

        horizontalLayout->addWidget(close_btn);

        maxium_btn = new QPushButton(widget_4);
        maxium_btn->setObjectName(QStringLiteral("maxium_btn"));
        maxium_btn->setMaximumSize(QSize(30, 30));
        maxium_btn->setFocusPolicy(Qt::ClickFocus);
        maxium_btn->setStyleSheet(QStringLiteral("background: none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        maxium_btn->setIcon(icon1);
        maxium_btn->setFlat(true);

        horizontalLayout->addWidget(maxium_btn);

        minium_btn = new QPushButton(widget_4);
        minium_btn->setObjectName(QStringLiteral("minium_btn"));
        minium_btn->setMaximumSize(QSize(30, 30));
        minium_btn->setFocusPolicy(Qt::ClickFocus);
        minium_btn->setStyleSheet(QStringLiteral("background: none"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/green.png"), QSize(), QIcon::Normal, QIcon::Off);
        minium_btn->setIcon(icon2);
        minium_btn->setFlat(true);

        horizontalLayout->addWidget(minium_btn);


        verticalLayout_5->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(12, 27, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(widget_3);

        label = new QLabel(title_bar);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("\n"
"font-weight:500;\n"
"font-size: 14pt;"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        horizontalLayout_4->addWidget(label);

        widget_2 = new QWidget(title_bar);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(80, 16777215));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 20, 0);
        avatar = new QPushButton(widget_2);
        avatar->setObjectName(QStringLiteral("avatar"));
        avatar->setMaximumSize(QSize(40, 40));
        avatar->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(avatar, 0, Qt::AlignLeft);


        horizontalLayout_4->addWidget(widget_2);

        search = new QWidget(title_bar);
        search->setObjectName(QStringLiteral("search"));
        search->setMaximumSize(QSize(200, 16777215));
        lineEdit = new QLineEdit(search);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 20, 181, 25));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        lineEdit->setFocusPolicy(Qt::ClickFocus);
        lineEdit->setStyleSheet(QLatin1String("background: none;\n"
"border-radius: 10px;"));
        search_btn = new QPushButton(search);
        search_btn->setObjectName(QStringLiteral("search_btn"));
        search_btn->setGeometry(QRect(160, 20, 25, 25));
        search_btn->setFocusPolicy(Qt::NoFocus);
        search_btn->setStyleSheet(QLatin1String("QPushButton#search_btn\n"
"{\n"
"	background: rgba(255, 255, 255, 0);\n"
"	image: url(\"../Resources/nav_srch_btn.png\");\n"
"}"));
        search_btn->setFlat(false);

        horizontalLayout_4->addWidget(search);


        verticalLayout->addWidget(title_bar);

        content = new QWidget(frame);
        content->setObjectName(QStringLiteral("content"));
        horizontalLayout_3 = new QHBoxLayout(content);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        function_list = new QListView(content);
        function_list->setObjectName(QStringLiteral("function_list"));
        sizePolicy.setHeightForWidth(function_list->sizePolicy().hasHeightForWidth());
        function_list->setSizePolicy(sizePolicy);
        function_list->setMaximumSize(QSize(180, 16777215));
        function_list->setFocusPolicy(Qt::NoFocus);
        function_list->setStyleSheet(QLatin1String("#function_list{\n"
"background-color: rgb(240, 240, 240);\n"
"border: none;\n"
"outline: none;\n"
"selection-background-color: blue;\n"
"}\n"
"#function_list::item {\n"
"height: 30px;\n"
"}"));
        function_list->setProperty("showDropIndicator", QVariant(false));

        horizontalLayout_3->addWidget(function_list);

        main_content = new QWidget(content);
        main_content->setObjectName(QStringLiteral("main_content"));
        main_content->setStyleSheet(QStringLiteral(""));
        horizontalLayout_7 = new QHBoxLayout(main_content);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        horizontalLayout_3->addWidget(main_content);


        verticalLayout->addWidget(content);


        verticalLayout_2->addWidget(frame);

        control_bar = new QWidget(centralWidget);
        control_bar->setObjectName(QStringLiteral("control_bar"));
        control_bar->setMaximumSize(QSize(16777215, 80));
        control_bar->setStyleSheet(QLatin1String("QWidget#control_bar\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(41, 45, 52, 255), stop:1 rgba(18, 22, 24, 255));\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(control_bar);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(control_bar);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(-1);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(12, 12, 12, 12);
        prev_btn = new QPushButton(widget);
        prev_btn->setObjectName(QStringLiteral("prev_btn"));
        sizePolicy.setHeightForWidth(prev_btn->sizePolicy().hasHeightForWidth());
        prev_btn->setSizePolicy(sizePolicy);
        prev_btn->setMaximumSize(QSize(28, 28));
        prev_btn->setFocusPolicy(Qt::NoFocus);
        prev_btn->setStyleSheet(QLatin1String("QPushButton#prev_btn\n"
"		{\n"
"			min-width: 28px;\n"
"			max-width: 28px;\n"
"			min-height: 28px;\n"
"			max-width: 28px;\n"
"			border-image: url(:img/previous_normal.tiff);\n"
"			qproperty-text: \"\";\n"
"		}\n"
"		QPushButton#prev_btn:hover\n"
"		{\n"
"			border-image: url(:img/previous_hover.tiff);\n"
"		}\n"
"		QPushButton#prev_btn:pressed\n"
"		{\n"
"			border-image: url(:img/previous_down.tiff);\n"
"		}"));
        prev_btn->setIconSize(QSize(40, 40));
        prev_btn->setFlat(true);

        horizontalLayout_6->addWidget(prev_btn);

        play_btn = new QCheckBox(widget);
        play_btn->setObjectName(QStringLiteral("play_btn"));
        sizePolicy.setHeightForWidth(play_btn->sizePolicy().hasHeightForWidth());
        play_btn->setSizePolicy(sizePolicy);
        play_btn->setMaximumSize(QSize(55, 48));
        play_btn->setFocusPolicy(Qt::NoFocus);
        play_btn->setStyleSheet(QString::fromUtf8("#play_btn {\n"
"	margin-right: 7px;\n"
"}\n"
"QCheckBox#play_btn::indicator \n"
"		{\n"
"			width: 48px;\n"
"			height: 48px;\n"
"		}\n"
"		QCheckBox#play_btn\n"
"		{\n"
"			min-width: 48px;\n"
"			max-width: 48px;\n"
"			min-height: 48px;\n"
"			max-width: 48px;\n"
"			qproperty-text: \"\";\n"
"		}\n"
"		/*\346\222\255\346\224\276*/\n"
"		QCheckBox#play_btn::indicator:unchecked\n"
"		{\n"
"			image:url(:img/play_normal.tiff);\n"
"		}\n"
"		QCheckBox#play_btn::indicator:unchecked:hover,\n"
"		QCheckBox#play_btn::indicator:unchecked:pressed\n"
"		{\n"
"			image:url(:img/play_down.tiff);\n"
"		}\n"
"		/*\346\232\202\345\201\234*/\n"
"		QCheckBox#play_btn::indicator::checked\n"
"		{\n"
"			image:url(:img/pause_normal.tiff);\n"
"		}\n"
"		QCheckBox#play_btn::indicator::checked:hover,QCheckBox#play_btn::indicator::checked:pressed\n"
"		{\n"
"			image:url(:img/pause_down.tiff);\n"
"		}"));
        play_btn->setText(QStringLiteral(""));
        play_btn->setIconSize(QSize(48, 48));
        play_btn->setCheckable(false);
        play_btn->setChecked(false);

        horizontalLayout_6->addWidget(play_btn);

        next_btn = new QPushButton(widget);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        sizePolicy.setHeightForWidth(next_btn->sizePolicy().hasHeightForWidth());
        next_btn->setSizePolicy(sizePolicy);
        next_btn->setMaximumSize(QSize(28, 28));
        next_btn->setFocusPolicy(Qt::NoFocus);
        next_btn->setStyleSheet(QLatin1String("QPushButton#next_btn\n"
"		{\n"
"			min-width: 29px;\n"
"			max-width: 29px;\n"
"			min-height: 28px;\n"
"			max-width: 28px;\n"
"			border-image: url(:img/next_normal.tiff);\n"
"			qproperty-text: \"\";\n"
"		}\n"
"		QPushButton#next_btn:hover\n"
"		{\n"
"			border-image: url(:img/next_hover.tiff);\n"
"		}\n"
"		QPushButton#next_btn:pressed\n"
"		{\n"
"			border-image: url(:img/next_down.tiff);\n"
"		}"));
        next_btn->setIconSize(QSize(40, 40));
        next_btn->setFlat(true);

        horizontalLayout_6->addWidget(next_btn);


        horizontalLayout_5->addWidget(widget);

        player_duration_slider = new QSlider(control_bar);
        player_duration_slider->setObjectName(QStringLiteral("player_duration_slider"));
        player_duration_slider->setFocusPolicy(Qt::NoFocus);
        player_duration_slider->setStyleSheet(QStringLiteral("background: none;"));
        player_duration_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(player_duration_slider);

        player_position_label = new QLabel(control_bar);
        player_position_label->setObjectName(QStringLiteral("player_position_label"));
        player_position_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(player_position_label);

        label_2 = new QLabel(control_bar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255)"));

        horizontalLayout_5->addWidget(label_2);

        player_duration_label = new QLabel(control_bar);
        player_duration_label->setObjectName(QStringLiteral("player_duration_label"));
        player_duration_label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"margin-right: 12;"));

        horizontalLayout_5->addWidget(player_duration_label);


        verticalLayout_2->addWidget(control_bar);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        search_btn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\231\276\347\261\263\351\237\263\344\271\220", Q_NULLPTR));
        close_btn->setText(QString());
        maxium_btn->setText(QString());
        minium_btn->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\350\231\276\347\261\263\351\237\263\344\271\220", Q_NULLPTR));
        avatar->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        search_btn->setText(QString());
        prev_btn->setText(QString());
        next_btn->setText(QString());
        player_position_label->setText(QApplication::translate("MainWindow", "00:00", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        player_duration_label->setText(QApplication::translate("MainWindow", "00:00", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
