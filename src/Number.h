//
// Created by Steve George Parakal on 26-04-2020.
//

#ifndef HW_NUMBER_H
#define HW_NUMBER_H

#include <random>
#include <algorithm>
#include <string>
#include <math.h>

class Number
{
private:
    std::string storen;

public:
    Number()
    {}

    Number(std::string& tmp)
    {
        storen = tmp;
    }

    char operator[](size_t i)
    {
        return storen[i];
    }

    char operator[] (size_t i) const
    {
        return storen[i];
    }

    std::pair<Number, Number> split(int sz) const
    {

        std::string part1 = "";
        std::string part2 = "";

        int l = storen.size();

        int mid = l - (sz / 2);

        part1 = storen.substr(0, mid);
        part2 = storen.substr(mid, l - mid);
        Number a(part1);
        Number b(part2);
        std::pair<Number, Number> p;
        p.first = a;
        p.second = b;
        return p;
    }

    size_t size()
    {
        size_t l = storen.length();
        return l;
    }

    Number operator +(const Number& num2) const
    {
        std::string tmp1 = storen;
        std::string tmp2 = num2.storen;
        if (tmp1.length() > tmp2.length())
            std::swap(tmp1, tmp2);

        std::string str = "";

        size_t l1 = tmp1.length();
        size_t l2 = tmp2.length();

        std::reverse(tmp1.begin(), tmp1.end());
        std::reverse(tmp2.begin(), tmp2.end());

        int carry = 0;
        for (size_t i = 0; i < l1; i++)
        {
            int sum = ((tmp1[i] - '0') + (tmp2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        for (size_t i = l1; i < l2; i++)
        {
            int sum = ((tmp2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            str.push_back(carry + '0');

        std::reverse(str.begin(), str.end());
        str.erase(0, std::min(str.find_first_not_of('0'), str.size() - 1));

        return str;
    }

    Number operator -(const Number& num2) const
    {

        std::string tmp1 = storen;
        std::string tmp2 = num2.getnum();

        size_t l1 = storen.size();
        size_t l2 = num2.getnum().size();

        std::reverse(tmp1.begin(), tmp1.end());
        std::reverse(tmp2.begin(), tmp2.end());

        std::string str = "";
        int carry = 0;
        for (size_t i = 0; i < l2; i++)
        {
            int sub = ((tmp1[i] - '0') - (tmp2[i] - '0') - carry);

            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }

            else
                carry = 0;

            str.push_back(sub + '0');
        }

        for (size_t i = l2; i < l1; i++)
        {
            int sub = ((tmp1[i] - '0') - carry);
            if (sub < 0)
            {
                sub += 10;
                carry = 1;
            }
            else
                carry = 0;
            str.push_back(sub + '0');

        }

        std::reverse(str.begin(), str.end());
        str.erase(0, std::min(str.find_first_not_of('0'), str.size() - 1));

        return str;
    }

    Number Zeros(size_t st, size_t l)
    {
        while (storen.size() < l)
            storen.insert(st, "0");
        return storen;
    }

    std::string getnum() const
    {
        return storen;
    }

    ~Number()
    {}
};


#endif //HW_NUMBER_H
