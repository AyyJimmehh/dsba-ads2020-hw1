//
// Created by Steve George Parakal on 26-04-2020.
//

#include <iostream>
#include <ctime>
#include <memory>
#include <fstream>
#include "Multiplicator.h"

void JoinCreate()
{
    long double gsavg = 0;
    long double karatsubavg = 0;
    long double dcavg = 0;

    clock_t start1, end1;
    clock_t start2, end2;
    clock_t start3, end3;
    long double timeusedkarat;
    long double timeuseddc;
    long double timeusedgsa;

    using N = std::shared_ptr<Multiplicator>;
    N obj;


    auto g = std::make_shared<GSA>();
    auto k = std::make_shared<Ktsba>();
    auto d = std::make_shared<DC>();

    std::fstream fout;

    fout.open("C:/Users/Steve George Parakal/Desktop/AlgorithmCSV.csv", std::ios::out | std::ios::app);
    fout << "Digit, " << "GSA, " << "Ktsba, " << "DC " << "\n";

    size_t i = 1;
    while(i <= 5000)
    {
        for(size_t j = 1; j <= 3; j++)
        {
            srand(static_cast<unsigned int>(time(0)));
            Number a(Multiplicator::randomizer(i));
            Number b(Multiplicator::randomizer(i));

            start1 = clock();
            g->Multiply(a,b);
            end1 = clock();
            timeusedgsa = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
            gsavg += timeusedgsa;

            start2 = clock();
            k->Multiply(a,b);
            end2 = clock();
            timeusedkarat = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
            karatsubavg += timeusedkarat;

            start3 = clock();
            d->Multiply(a,b);
            end3 = clock();
            timeuseddc = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
            dcavg += timeuseddc;
        }

        gsavg /= 3;
        karatsubavg /= 3;
        dcavg /= 3;

        fout << i << ", " << gsavg << ", " <<  karatsubavg << ", " << dcavg << "\n";
        if (i <= 1000)
            i += 25;
        else
            i += 500;
    }
    fout.close();

}

int main()
{
    JoinCreate();
}
