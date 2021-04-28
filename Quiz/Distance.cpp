#include "Distance.h"

void check(Distance &obj){
    while(obj.inches < 0){
        if(obj.feet <= 0){
            if(obj.yard <= 0){
                break;
            }
            else{
                obj.yard--;
                obj.inches += 36;
            }
        }
        else{
            obj.feet--;
            obj.inches += 12;
        }
    }

    while(obj.feet < 0){
        if(obj.yard <= 0){
            break;
        }
        else{
            obj.yard--;
            obj.feet += 3;
        }
    }

    if(obj.inches >= 12){
        obj.feet += obj.inches / 12;
        obj.inches -= 12 * ((int)obj.inches / 12);
    }
    if(obj.feet >= 3){
        obj.yard += obj.feet / 3;
        obj.feet %= 3;
    }
}

Distance::Distance(){
    yard = feet = inches = 0;
}

Distance::Distance(int _yard, int _feet, float _inches){
    yard = _yard;
    feet = _feet;
    inches = _inches;

    check(*this);
}

Distance::Distance(const Distance &obj){
    yard = obj.yard;
    feet = obj.feet;
    inches = obj.inches;

    check(*this);
}

void Distance::setYard(int _yard){
    yard = _yard;
}

void Distance::setFeet(int _feet){
    feet = _feet;
}

void Distance::setInches(float _inches){
    inches = _inches;
}

int Distance::getYard(){
    return yard;
}

int Distance::getFeet(){
    return feet;
}

float Distance::getInches(){
    return inches;
}

istream &operator>>(istream &in, Distance &obj){
    in >> obj.yard >> obj.feet >> obj.inches;

    check(obj);
    return in;
}

ostream &operator<<(ostream &out, Distance &obj){  
    check(obj);
    out << obj.yard << " yard, " << obj.feet << " feet, " << obj.inches << " inches";    
    
    return out;
}

Distance Distance::operator+(const Distance &obj){
    Distance temp = *this;
    temp.yard += obj.yard;
    temp.feet += obj.feet;
    temp.inches += obj.inches;
    
    check(temp);
    return temp;
}

Distance Distance::operator+(float _inches){
    Distance temp = *this;
    temp.inches += _inches;
    
    check(temp);
    return temp;
}

Distance Distance::operator-(const Distance &obj){
    Distance temp = *this;
    temp.yard -= obj.yard;
    temp.feet -= obj.feet;
    temp.inches -= obj.inches;
    
    check(temp);
    return temp;
}

Distance& Distance::operator=(const Distance &obj){
    yard = obj.yard;
    feet = obj.feet;
    inches = obj.inches;
    
    check(*this);
    return *this;
}

bool Distance::operator==(const Distance &obj){
    Distance temp = obj;
    check(temp);
    if(yard == temp.yard && feet == temp.feet && inches == temp.inches)
        return true;
    
    return false;
}

bool Distance::operator<(const Distance &obj){
    Distance temp = obj;
    check(temp);
    if(yard < temp.yard)
        return true;
    else if(yard == temp.yard && feet < temp.feet)
        return true;
    else if(yard == temp.yard && feet == temp.feet && inches < temp.inches)
        return true;
    
    return false;
}

bool Distance::operator>(const Distance &obj){
    Distance temp = obj;
    check(temp);
    if(yard > temp.yard)
        return true;
    else if(yard == temp.yard && feet > temp.feet)
        return true;
    else if(yard == temp.yard && feet == temp.feet && inches > temp.inches)
        return true;
    
    return false;
}

Distance& Distance::operator+=(const Distance &obj){
    this->yard += obj.yard;
    this->feet += obj.feet;
    this->inches += obj.inches;
    
    check(*this);
    return *this;
}

Distance& Distance::operator+=(float _inches){
    this->inches += _inches;
    
    check(*this);
    return *this;
}