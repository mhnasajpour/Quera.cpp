#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login)
{
    setWindowTitle("Login");
    mainLayout = new QVBoxLayout(this);
    layoutF = new QFormLayout();
    layoutH = new QHBoxLayout();
    mainLayout->addLayout(layoutF);
    mainLayout->addLayout(layoutH);

    lineUsername = new QLineEdit();
    linePassword = new QLineEdit();
    linePassword->setEchoMode(QLineEdit::Password);
    key1 = new QPushButton("OK");
    key1->setDefault(true);
    key2 = new QPushButton("Sign up");
    label = new QLabel("");

    layoutF->addRow("Username", lineUsername);
    layoutF->addRow("Password", linePassword);

    layoutH->addWidget(label);
    layoutH->addWidget(key2);
    layoutH->addWidget(key1);
    layoutH->setAlignment(Qt::AlignRight);
    setFixedSize(270,110);

    connect(key1, SIGNAL(clicked()), this, SLOT(isExist()));
    connect(key2, SIGNAL(clicked()), this, SLOT(signUpPart()));
}

Login::~Login()
{
    delete ui;
}

void Login::isExist()
{
    bool isGood = true;
    if(lineUsername->text() == ""){
        lineUsername->setPlaceholderText("is empty");
        isGood = false;
    }
    if(linePassword->text() == ""){
        linePassword->setPlaceholderText("is empty");
        isGood = false;
    }
    if(isGood){
        ifstream file("info.txt");
        if(!file){
            label->setText("unsuccess\t");
            return;
        }
        while(!file.eof())
        {
            string str;
            getline(file, str);
            hash<QString> hashing;
            unsigned long hashedPassword = hashing(linePassword->text());
            string found = lineUsername->text().toStdString() + ' ' + to_string(hashedPassword);
            if(str.find(found) != string::npos){
                Enter *enter = new Enter;
                enter->show();
                close();
                return;
            }
        }
        file.close();
        label->setText("unsuccess\t");
    }
}

void Login::signUpPart(){
    SignUp *x = new SignUp;
    x->show();
    this->close();
}
