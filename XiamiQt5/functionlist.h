#ifndef FUNCTIONLIST_H
#define FUNCTIONLIST_H

#include <QStringList>
#include <QWidget>

class FunctionList
{
private:
    QWidget* current_page = nullptr;
    FunctionList();
public:
    FunctionList(const FunctionList&) = delete;
    FunctionList(FunctionList&&) = delete;
    QStringList static function_list();
    void change_page(const int & index, QWidget* widget, QWidget * context);
    FunctionList static * instance();
};

#endif // FUNCTIONLIST_H
