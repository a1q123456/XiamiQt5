#include "functionlist.h"
#include "main_page.h"


QStringList FunctionList::function_list()
{
    return QStringList{
        "今日推荐",
        "虾米排行",
        "艺人列表",
        "本地音乐",
        "播放记录",
        "播放列表",
        "下载列表"
    };
}
void FunctionList::change_page(const int & index, QWidget* widget, QWidget * context)
{
    if (current_page != nullptr)
    {
        delete current_page;
    }
    qDeleteAll(widget->children());
    current_page = new main_page(widget, context);
}
FunctionList::FunctionList()
{

}

FunctionList *FunctionList::instance()
{
    static FunctionList * inst = new FunctionList();
    return inst;
}

