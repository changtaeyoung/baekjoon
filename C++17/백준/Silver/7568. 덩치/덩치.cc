#include <iostream>
#include <algorithm>

using namespace std;

class Person
{
private:
    int weight, height;
    int rank;

public:
    Person()
    {
        rank = 1;
    }
    Person(int weight, int height)
    {
        rank = 1;
        this->weight = weight;
        this->height = height;
    }
    int getWeight()
    {
        return this->weight;
    }
    int getHeight()
    {
        return this->height;
    }
    void plusRank()
    {
        this->rank++;
    }
    int getRank()
    {
        return rank;
    }
    ~Person()
    {
    }
};

int main(void)
{
    int persons, pWeight, pHeight;
    cin >> persons;
    Person* p = new Person[persons];
    for (int i = 0; i < persons; i++)
    {
        cin >> pWeight >> pHeight;
        p[i] = Person(pWeight, pHeight);
    }

    for (int i = 0; i < persons; i++)
    {
        for (int j = 0; j < persons; j++)
        {
            if (p[i].getWeight() < p[j].getWeight() && p[i].getHeight() < p[j].getHeight())
            {
                p[i].plusRank();
            }
        }
    }

    for (int i = 0; i < persons; i++)
    {
        cout << p[i].getRank() << " ";
    }
    return 0;
}