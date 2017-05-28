#include "functionlist.h"
#include "main_page.h"
#include "playlist_page.h"
#include <QBoxLayout>
#include "play_history_page.h"

QStringList FunctionList::function_list()
{
    return QStringList{
        "今日推荐",
        "虾米排行",
        "播放记录",
        "播放列表"
    };
}
void FunctionList::change_page(const int & index, QWidget* widget, QWidget * context)
{
    if (current_page != nullptr)
    {
        delete current_page;
    }
    qDeleteAll(widget->children());

    switch (index)
    {
    case 0:
        current_page = new main_page(widget, context);
        break;
    case 2:
        current_page = new play_history_page(widget, context);
        break;
    case 3:
        current_page = new playlist_page(widget, context);
        break;
    default:
        current_page = new main_page(widget, context);
    }
    //if (widget->layoutDirection() != Qt)
    //{
        auto layout = new QHBoxLayout;
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
    //}
    //auto layout = widget->layout();

    layout->addWidget(current_page);
    widget->setLayout(layout);

}
FunctionList::FunctionList()
{

}

FunctionList *FunctionList::instance()
{
    static FunctionList * inst = new FunctionList();
    return inst;
}

