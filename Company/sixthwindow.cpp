#include "sixthwindow.h"
#include "ui_sixthwindow.h"
#include <QDebug>
sixthwindow::sixthwindow(void* window_parent,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sixthwindow)
{
    ui->setupUi(this);
    m_parent = (QWidget*)window_parent;

}

sixthwindow::~sixthwindow()
{
    delete ui;
}
