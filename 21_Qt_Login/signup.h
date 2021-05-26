#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QString>
#include <fstream>
#include "login.h"

class SignUp : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLayout;
    QFormLayout *fLayout;
    QHBoxLayout *HLayout;
    QLineEdit *lineName;
    QLineEdit *lineUserName;
    QLineEdit *linePassword;
    QLineEdit *lineEmail;
    QSpinBox *lineAge;
    QComboBox *lineGender;
    QPushButton *key1;
    QPushButton *key2;

public:
    explicit SignUp(QWidget *parent = nullptr);
public slots:
    void finishSignUp();
};

#endif // SIGNUP_H
