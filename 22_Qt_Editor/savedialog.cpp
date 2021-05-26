#include "savedialog.h"

SaveDialog::SaveDialog(QWidget *parent) : QWidget(parent)
{
    dialog = new QFileDialog(this);
    dialog->setAcceptMode(QFileDialog::AcceptSave);
    dialog->show();
}
