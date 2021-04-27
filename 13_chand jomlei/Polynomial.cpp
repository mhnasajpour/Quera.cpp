#include "Polynomial.h"

void Polynomial::proccess_str(string str, int size)
{
    // +- num1 x^ num2
    // +- num1 x
    // +- x^ num2
    // +- x
    // +- num1

    string payeh, tavan = "0";
    char sign = str[0];

    for (int i = 1; i < size; i++)
    {
        if (str[1] == 'x')
            payeh = "1";

        if (str[i] == 'x' && str[i + 1] == '^')
        {
            tavan.pop_back();
            for (i += 2; i < size; i++)
                tavan.push_back(str[i]);
        }

        else if (str[i] == 'x')
            tavan = "1";

        else
            payeh.push_back(str[i]);
    }

    int t = stoi(payeh, 0, 10);
    if (sign == '-')
        t *= -1;

    zarib[stoi(tavan, 0, 10)] += t;
}

Polynomial::Polynomial()
{
    for (int i = 0; i < 21; i++)
        zarib[i] = 0;
}

Polynomial::Polynomial(int tmp)
{
    zarib[0] = tmp;
    for (int i = 1; i < 21; i++)
        zarib[i] = 0;
}

Polynomial::Polynomial(const Polynomial &a)
{
    for (int i = 0; i < 21; i++)
        zarib[i] = a.zarib[i];
}

istream &operator>>(istream &in, Polynomial &g)
{
    string line, temp;
    int payeh, tavan;
    in >> line;

    for (int i = 0; i <= line.length(); i++)
    {
        if (i && (line[i] == '+' || line[i] == '-' || i == line.length()))
        {
            g.proccess_str(temp, temp.length());
            temp.clear();
        }

        temp.push_back(line[i]);
    }
    return in;
}

ostream &operator<<(ostream &out, Polynomial g)
{
    for (int i = 20; i > 1; i--)
    {
        if (g.zarib[i] > 1)
            out << '+' << g.zarib[i] << "x^" << i;
        else if (g.zarib[i] < -1)
            out << g.zarib[i] << "x^" << i;
        else if (g.zarib[i] == 1)
            out << '+' << "x^" << i;
        else if (g.zarib[i] == -1)
            out << '-' << "x^" << i;
    }

    if (g.zarib[1])
    {
        if (g.zarib[1] > 1)
            out << '+' << g.zarib[1] << "x";
        else if (g.zarib[1] < -1)
            out << g.zarib[1] << "x";
        else if (g.zarib[1] == 1)
            out << '+' << "x";
        else if (g.zarib[1] == -1)
            out << '-' << "x";
    }

    if (g.zarib[0])
    {
        if (g.zarib[0] > 1)
            out << '+' << g.zarib[0];
        else if (g.zarib[0] <= -1)
            out << g.zarib[0];
        else if (g.zarib[0] == 1)
            out << "+1";
    }

    return out;
}

Polynomial operator-(Polynomial &q)
{
    Polynomial temp;
    for (int i = 0; i < 21; i++)
        temp.zarib[i] = q.zarib[i] * -1;

    return temp;
}

Polynomial Polynomial::operator=(Polynomial a)
{
    for (int i = 0; i < 21; i++)
        zarib[i] = a.zarib[i];

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &a)
{
    Polynomial temp;
    for (int i = 0; i < 21; i++)
        temp.zarib[i] = this->zarib[i] + a.zarib[i];

    return temp;
}

Polynomial operator+(int num, const Polynomial &poly)
{
    Polynomial temp = poly;
    temp.zarib[0] += num;
    return temp;
}

Polynomial Polynomial::operator-(const Polynomial &a)
{
    Polynomial temp;
    for (int i = 0; i < 21; i++)
        temp.zarib[i] = this->zarib[i] - a.zarib[i];

    return temp;
}

Polynomial operator-(int num, const Polynomial &poly)
{
    Polynomial temp;
    temp.zarib[0] = num - poly.zarib[0];
    for (int i = 1; i < 21; i++)
        temp.zarib[i] = -poly.zarib[i];
    return temp;
}

Polynomial Polynomial::operator*(const Polynomial &a)
{
    Polynomial temp;
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            if (i + j <= 20)
                temp.zarib[i + j] += this->zarib[i] * a.zarib[j];

    return temp;
}

Polynomial operator*(int num, const Polynomial &poly)
{
    Polynomial temp = poly;
    for (int i = 0; i < 21; i++)
        temp.zarib[i] *= num;
    return temp;
}

Polynomial &Polynomial::operator++()
{
    for (int i = 0; i < 21; i++)
        zarib[i]++;

    return *this;
}

Polynomial Polynomial::operator++(int)
{
    Polynomial temp = *this;
    for (int i = 0; i < 21; i++)
        this->zarib[i]++;

    return temp;
}

Polynomial Polynomial::operator/(Polynomial divider)
{
    Polynomial current = *this;
    static Polynomial ration;
    Polynomial temp;
    for (int i = 20; i >= 0; i--)
        if (current.zarib[i])
            for (int j = 20; j >= 0; j--)
                if (divider.zarib[j])
                {
                    if (j > i)
                        return ration;

                    temp.zarib[i - j] = current.zarib[i] / divider.zarib[j];
                    ration.zarib[i - j] += current.zarib[i] / divider.zarib[j];
                    current = current - (divider * temp);

                    ration = current / divider;
                    return ration;
                }

    return ration;
}

Polynomial Polynomial::operator%(Polynomial divider)
{
    Polynomial remain = *this;
    Polynomial ration;
    for (int i = 20; i >= 0; i--)
        if (remain.zarib[i])
            for (int j = 20; j >= 0; j--)
                if (divider.zarib[j])
                {
                    if (j > i)
                        return remain;

                    ration.zarib[i - j] = remain.zarib[i] / divider.zarib[j];
                    remain = remain - (divider * ration);

                    remain = remain % divider;
                    return remain;
                }

    return remain;
}