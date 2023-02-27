#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>

struct City
{
    float x, y;
};

float vzdalenost(City& a, City& b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;

    return sqrtf(dx * dx + dy * dy);
}

float hodnoceni(std::vector<City>& mesta, std::vector<int>& indexy)
{
    float suma = 0.0;

    for (int i = 0; i < indexy.size() - 1; i++)
    {
        City& a = mesta[indexy[i + 0]];
        City& b = mesta[indexy[i + 1]];

        suma += vzdalenost(a, b);
    }

    suma += vzdalenost(mesta[indexy[0]], mesta[indexy[indexy.size() - 1]]);

    return suma;
}

int main()
{
    int pocet_mest;

    printf("Vyberte pocet mest pro Travelling Salesman Problem: ");
    scanf_s("%d", &pocet_mest);

    if (pocet_mest <= 1)
    {
        printf("Prilis maly pocet mest, musi byt vetsi nez 1\n");
        exit(1);
    }

    if (pocet_mest > 20)
    {
        printf("Prilis velky pocet mest, musi byt mensi nez 21\n");
        exit(1);
    }

    unsigned int seed;

    printf("Vyberte nahodny seed pro generaci pozic\n");
    scanf_s("%u", &seed);

    srand(seed);

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<City> mesta;

    for (int i = 0; i < pocet_mest; i++)
    {
        float x = 100.0f * (rand() / (float)RAND_MAX);
        float y = 100.0f * (rand() / (float)RAND_MAX);

        mesta.push_back({ x, y });

        printf("Mesto %d vytvoreno v {%06.3f, %06.3f}\n", i, x, y);
    }

    std::vector<int> reseni;
    float reseni_skore;

    std::deque<int> unvisited;

    for (int i = 0; i < mesta.size(); i++)
    {
        unvisited.push_back(i);
    }

    int current = unvisited[0];
    unvisited.pop_front();
    reseni.push_back(current);

    while (!unvisited.empty())
    {
        float best_score = INFINITY;
        int best_index = -1;

        for (int i = 0; i < unvisited.size(); i++)
        {
            float dist = vzdalenost(mesta[current], mesta[unvisited[i]]);

            if (dist < best_score)
            {
                best_score = dist;
                best_index = i;
            }
        }

        //printf("%d -> %d\n", current, unvisited[best_index]);

        current = unvisited[best_index];
        reseni.push_back(current);
        unvisited.erase(unvisited.begin() + best_index);
    }


    reseni_skore = hodnoceni(mesta, reseni);
    
    printf("Reseni s vzdalenosti %f se sklada z:\n", reseni_skore);

    for (int i = 0; i < reseni.size() - 1; i++)
    {
        printf("%d -> %d (%f)\n", reseni[i], reseni[i + 1], vzdalenost(mesta[reseni[i]], mesta[reseni[i + 1]]));
    }

    printf("%d -> %d (%f)\n", reseni[reseni.size() - 1], reseni[0], vzdalenost(mesta[reseni[reseni.size() - 1]], mesta[reseni[0]]));
    
    auto end = std::chrono::high_resolution_clock::now();

    printf("Trvalo %lf sekund spocitat reseni.\n", (end - start).count() / 1000000000.0);

    system("pause");
}