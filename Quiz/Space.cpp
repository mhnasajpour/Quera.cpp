#include "Space.h"

void check(Space &obj){
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

Space::Space(){
    yard = feet = inches = 0;
}

Space::Space(int _yard, int _feet, float _inches){
    yard = _yard;
    feet = _feet;
    inches = _inches;

    check(*this);
}

Space::Space(const Space &obj){
    yard = obj.yard;
    feet = obj.feet;
    inches = obj.inches;

    check(*this);
}

void Space::setYard(int _yard){
    yard = _yard;
}

void Space::setFeet(int _feet){
    feet = _feet;
}

void Space::setInches(float _inches){
    inches = _inches;
}

int Space::getYard(){
    return yard;
}

int Space::getFeet(){
    return feet;
}

float Space::getInches(){
    return inches;
}

istream &operator>>(istream &in, Space &obj){
    in >> obj.yard >> obj.feet >> obj.inches;

    check(obj);
    return in;
}

ostream &operator<<(ostream &out, Space &obj){  
    check(obj);
    out << obj.yard << " yard, " << obj.feet << " feet, " << obj.inches << " inches";    
    
    return out;
}

Space Space::operator+(const Space &obj){
    Space temp = *this;
    temp.yard += obj.yard;
    temp.feet += obj.feet;
    temp.inches += obj.inches;
    
    check(temp);
    return temp;
}

Space Space::operator+(float _inches){
    Space temp = *this;
    temp.inches += _inches;
    
    check(temp);
    return temp;
}

Space Space::operator-(const Space &obj){
    Space temp = *this;
    temp.yard -= obj.yard;
    temp.feet -= obj.feet;
    temp.inches -= obj.inches;
    
    check(temp);
    return temp;
}

Space& Space::operator=(const Space &obj){
    yard = obj.yard;
    feet = obj.feet;
    inches = obj.inches;
    
    check(*this);
    return *this;
}

bool Space::operator==(const Space &obj){
    Space temp = obj;
    check(temp);
    if(yard == temp.yard && feet == temp.feet && inches == temp.inches)
        return true;
    
    return false;
}

bool Space::operator<(const Space &obj){
    Space temp = obj;
    check(temp);
    if(yard < temp.yard)
        return true;
    else if(yard == temp.yard && feet < temp.feet)
        return true;
    else if(yard == temp.yard && feet == temp.feet && inches < temp.inches)
        return true;
    
    return false;
}

bool Space::operator>(const Space &obj){
    Space temp = obj;
    check(temp);
    if(yard > temp.yard)
        return true;
    else if(yard == temp.yard && feet > temp.feet)
        return true;
    else if(yard == temp.yard && feet == temp.feet && inches > temp.inches)
        return true;
    
    return false;
}

Space& Space::operator+=(const Space &obj){
    this->yard += obj.yard;
    this->feet += obj.feet;
    this->inches += obj.inches;
    
    check(*this);
    return *this;
}

Space& Space::operator+=(float _inches){
    this->inches += _inches;
    
    check(*this);
    return *this;
}