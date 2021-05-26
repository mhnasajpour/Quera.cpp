#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <fstream>
#include "signup.h"
#include "enter.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

private:
    Ui::Login *ui;
    QVBoxLayout *mainLayout;
    QFormLayout *layoutF;
    QHBoxLayout *layoutH;
    QLineEdit *lineUsername;
    QLineEdit *linePassword;
    QPushButton *key1;
    QPushButton *key2;
    QLabel *label;

public:
    Login(QWidget *parent = nullptr);
    ~Login();

public slots:
    void isExist();
    void signUpPart();
};
#endif // LOGIN_H
