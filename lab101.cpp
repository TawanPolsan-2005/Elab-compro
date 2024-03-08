#include <iostream>
using namespace std;

class Animal
{
private:
    int happiness;
    int energy;
    int fullness;
    const int MAX_HAPPINESS = 100;
    const int MAX_ENERGY = 100;
    const int MAX_FULLNESS = 100;
    void limitStat();
public:
    Animal(int, int, int);
    int getHappiness();
    int getEnergy();
    int getFullness();
    void eat(int);
    void play(int);
    void sleep(int);
};
class Bird : public Animal

{
public:
    Bird(int, int, int);
    void fly(int);
    void sing();
};


{

}


void Animal :: limitStat()
{
if (happiness < 0)
        {
            happiness = 0;
        }else if (happiness > MAX_HAPPINESS)
        {
            happiness = MAX_HAPPINESS;
        }

if (energy < 0)
        {
            energy = 0;
        }else  if (energy > MAX_ENERGY)
        {
            energy = MAX_ENERGY;
        }

if (fullness < 0)
        {
            fullness = 0;
        }else if (fullness > MAX_FULLNESS)
        {
           fullness = MAX_FULLNESS;
        }
    
}
Animal :: Animal(int HAPPINESS, int ENERGY,int FULLNESS)
{
    happiness = HAPPINESS;
    energy = ENERGY;
    fullness = FULLNESS;
    limitStat();
}
Bird :: Bird(int hap,int enr, int full) : Animal(hap,enr,full){}

int Animal :: getHappiness()
{
    limitStat();
    
    return happiness;

}
int Animal :: getEnergy()
{
    limitStat();
    return energy;
}
int Animal :: getFullness()
{
    limitStat();
    return fullness;
}
void Animal :: eat(int amt)
{
    fullness += amt;

    if (fullness > 100)
    {
        happiness -= 10;
    }
    limitStat();
}
void Animal :: play(int hr)
{
    if (fullness > 0 || energy > 0)
    {
    fullness -= 20 * hr;
    energy -= 10 * hr;
    happiness += 5 * hr;
       
    }
    limitStat();

}


void Animal :: sleep(int hr)
{
    fullness -= 10 * hr;
    energy += 10 * hr;
    limitStat();
}

int main()
{
    Animal am(100,100,100);
    
    cout << am.getEnergy() << endl;
    cout << am.getFullness() << endl;
    cout << am.getHappiness() << endl;
    am.eat(50);
    am.play(2);
    cout << am.getEnergy() << endl;
    cout << am.getFullness() << endl;
    cout << am.getHappiness() << endl;

}
