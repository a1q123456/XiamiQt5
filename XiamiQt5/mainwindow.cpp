#include "pch.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    is_maxiumized = false;
    is_moving = false;
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    QGraphicsDropShadowEffect *wndShadow = new QGraphicsDropShadowEffect;
    wndShadow->setBlurRadius(9.0);
    wndShadow->setColor(QColor(0, 0, 0, 160));
    wndShadow->setOffset(0);
    ui->setupUi(this);
    ui->centralWidget->setGraphicsEffect(wndShadow);
    FunctionListModel * model = new FunctionListModel(nullptr);

    ui->function_list->setModel(model);

}
void MainWindow::on_function_list_clicked(const QModelIndex &index)
{
    FunctionList::instance()->change_page(index.row(), ui->main_content);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_close_btn_clicked()
{
    this->close();
}

void MainWindow::on_maxium_btn_clicked()
{
    if (is_maxiumized)
    {
        this->showNormal();
        is_maxiumized = false;
    }
    else
    {
        this->showMaximized();
        is_maxiumized = true;
    }
}

void MainWindow::on_minium_btn_clicked()
{
    this->showMinimized();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouse_press_x_coord = event->x();
    mouse_press_y_coord = event->y();
    is_moving = true;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!is_moving)
    {
        return;
    }
    move(event->globalX() - mouse_press_x_coord, event->globalY() - mouse_press_y_coord);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    is_moving = false;
}
