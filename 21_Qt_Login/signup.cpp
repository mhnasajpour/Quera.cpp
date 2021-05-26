#include "signup.h"

SignUp::SignUp(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Sign Up");
    setFixedSize(300,200);
    mainLayout = new QVBoxLayout(this);
    fLayout = new QFormLayout;
    HLayout = new QHBoxLayout;
    mainLayout->addLayout(fLayout);
    mainLayout->addLayout(HLayout);

    lineUserName = new QLineEdit;
    fLayout->addRow("Username", lineUserName);
    linePassword = new QLineEdit;
    linePassword->setEchoMode(QLineEdit::Password);
    fLayout->addRow("Password", linePassword);
    lineName = new QLineEdit;
    fLayout->addRow("Name", lineName);
    lineEmail = new QLineEdit;
    lineEmail->setPlaceholderText("...@gmail.com");
    fLayout->addRow("Email", lineEmail);
    lineAge = new QSpinBox;
    lineAge->setMaximum(200);
    lineAge->setMinimum(0);
    fLayout->addRow("Age", lineAge);
    lineGender = new QComboBox;
    lineGender->addItem("Mail");
    lineGender->addItem("Femail");
    fLayout->addRow("Gender", lineGender);
    key1 = new QPushButton("Next");
    key2 = new QPushButton("Cancel");
    HLayout->addWidget(key1);
    HLayout->addWidget(key2);
    HLayout->setAlignment(Qt::AlignRight);

    Login *login = new Login;

    connect(key1, SIGNAL(clicked()), this, SLOT(finishSignUp()));
    connect(key2, SIGNAL(clicked()), this, SLOT(hide()));
    connect(key2, SIGNAL(clicked()), login, SLOT(show()));
}

void SignUp::finishSignUp()
{
    bool isGood = true;
    if(lineUserName->text() == ""){
        lineUserName->setPlaceholderText("is empty");
        isGood = false;
    }
    if(linePassword->text() == ""){
        linePassword->setPlaceholderText("is empty");
        isGood = false;
    }
    if(lineEmail->text() == ""){
        lineEmail->setPlaceholderText("is empty");
        isGood = false;
    }
    if(lineName->text() == ""){
        lineName->setPlaceholderText("is empty");
        isGood = false;
    }
    if(isGood){
        ofstream file;
        file.open("info.txt", ios::app);
        hash<QString> hashing;
        unsigned long hashedPassword = hashing(linePassword->text());
        file << lineUserName->text().toStdString() << ' ' << hashedPassword << endl;
        file.close();
        Login *login = new Login;
        login->show();
        this->close();
    }
}
