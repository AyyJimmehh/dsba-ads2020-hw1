//
// Created by Steve George Parakal on 26-04-2020.
//

#ifndef HW_MULTIPLICATOR_H
#define HW_MULTIPLICATOR_H


#include "Number.h"

class Multiplicator
{

public:
    Multiplicator()
    {}

    static Number randomizer(size_t k)
    {
        std::string s;
        int c;

        for (size_t i = 0; i < k; i++)
        {
            if (i == 0)
            {
                c = rand() % 9 + 1;
                s += std::to_string(c);
            }

            else
            {
                c = rand() % 10;
                s += std::to_string(c);
            }
        }
        Number random(s);
        return random;
    }

    virtual Number Multiply(Number op1, Number op2) = 0;

    virtual ~Multiplicator()
    {}

};

class GSA : public Multiplicator
{
public:

    Number Multiply(Number operand1, Number operand2) override
    {
        std::string s1 = operand1.getnum();
        std::string s2 = operand2.getnum();

        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());

        Number result;
        for (size_t i = 0; i < operand2.size(); i++)
        {
            std::string tmp;
            int carry = 0;
            std::string mid_r = "";
            for (size_t j = 0; j < operand1.size(); j++)
            {
                tmp = std::to_string(((s1[j] - '0') * (s2[i] - '0')) + carry);
                if(tmp.length() == 2)
                {
                    carry = tmp[0] - '0';
                    mid_r.push_back(tmp[1]);
                }

                else
                {
                    mid_r += tmp;
                    carry = 0;
                }

            }

            if (carry)
                mid_r += std::to_string(carry);

            mid_r.insert(0, i, '0');
            std::reverse(mid_r.begin(), mid_r.end());

            Number r(mid_r);

            result = result + r;
        }

        return result;
    }
};

class Ktsba : public Multiplicator
{
public:

    Number Multiply(Number operand1, Number operand2) override
    {
        std::string s1 = operand1.getnum();
        std::string s2 = operand2.getnum();

        std::string zero = "0";
        int l1 = operand1.size();
        int l2 = operand2.size();
        int L = (std::max(l1, l2));
        if (L == 1)
        {
            std::string s = std::to_string((s1[0] - '0') * (s2[0] - '0'));
            return s;
        }

        if (L == 0)
            return Number(zero);

        operand1.Zeros(0, L);
        operand2.Zeros(0, L);
        int n = L / 2;

        std::pair<Number, Number> soperand1 = operand1.split(L);
        std::pair<Number, Number> soperand2 = operand2.split(L);

        Number A = Multiply(soperand1.first, soperand2.first);
        Number C = Multiply(soperand1.second, soperand2.second);
        Number D = Multiply(soperand1.first + soperand1.second, soperand2.first + soperand2.second);
        Number B = D - C - A;

        B.Zeros(B.size(), n + B.size());
        A.Zeros(A.size(), (2 * n) + A.size());
        return A + B + C;
    }
};

class DC : public Multiplicator
{
public:

    Number Multiply(Number operand1, Number operand2) override
    {
        std::string s1 = operand1.getnum();
        std::string s2 = operand2.getnum();

        std::string zero = "0";
        int l1 = operand1.size();
        int l2 = operand2.size();
        int L = (std::max(l1, l2));
        if (L == 1)
        {
            std::string s = std::to_string((s1[0] - '0') * (s2[0] - '0'));
            return s;
        }

        if (L == 0)
            return Number(zero);

        operand1.Zeros(0, L);
        operand2.Zeros(0, L);
        int n = L / 2;

        std::pair<Number, Number> soperand1 = operand1.split(L);
        std::pair<Number, Number> soperand2 = operand2.split(L);


        Number A = Multiply(soperand1.first, soperand2.first);
        Number C = Multiply(soperand1.second, soperand2.second);
        Number D = Multiply(soperand1.first, soperand2.second);
        Number E = Multiply(soperand1.second, soperand2.first);
        Number B = D + E;

        B.Zeros(B.size(), n + B.size());
        A.Zeros(A.size(), (2 * n) + A.size());
        return A + B + C;
    }
};


#endif //HW_MULTIPLICATOR_H
