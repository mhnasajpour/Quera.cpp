#include "enter.h"

Enter::Enter(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("main window");
    text = new QTextEdit(this);
    setFixedSize(250,140);
    text->setText("Hi :)\nWelcome");
}
