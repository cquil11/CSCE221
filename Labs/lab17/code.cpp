#include <string>
#include <iostream>

std::string hanoi(unsigned short diskCount, char source, char dest, char aux)
{
    std::string tracker = "";

    if (diskCount == 1)
    {
        tracker += "Move disk " + std::to_string(diskCount) + " from source " + source + " to destination " + dest + "\n";
    }
    else
    {
        tracker += hanoi(diskCount - 1, source, aux, dest);
        tracker += "Move disk " + std::to_string(diskCount) + " from source " + source + " to destination " + dest + "\n";
        tracker += hanoi(diskCount - 1, aux, dest, source);
    }

    return tracker;
}

int main()
{
    std::cout << hanoi(3, 'A', 'B', 'C') << std::endl;

    return 0;
}