#include <stdlib.h>
#include <time.h>

int testEuclid();

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int result = testEuclid();
    return result;
}