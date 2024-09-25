#include <iostream>
#include "bird.h"
#include <string>

void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
}

using namespace std;

int main()
{
    Bird *bird = new sparrow();
    birdDoesSomething(bird);
    return 0;
}