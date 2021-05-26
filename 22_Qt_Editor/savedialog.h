#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QWidget>
#include <QFileDialog>

class SaveDialog : public QWidget
{
    Q_OBJECT
public:
    explicit SaveDialog(QWidget *parent = nullptr);

private:
    QFileDialog *dialog;

};

#endif // SAVEDIALOG_H
