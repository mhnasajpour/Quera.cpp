#ifndef ENTER_H
#define ENTER_H

#include <QWidget>
#include <QTextEdit>
#include <QString>

class Enter : public QWidget
{
    Q_OBJECT
public:
    explicit Enter(QWidget *parent = nullptr);

private:
    QTextEdit *text;
};

#endif // ENTER_H
