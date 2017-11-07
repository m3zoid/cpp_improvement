#include "IncludeAll.h"

void testMyObject();
void testMyList();
void testAll();
void testInt();

int main()
{
    std::cout << "<- START_PROGRAM_FLOW" << std::endl;

    testMyObject();
    testMyList();
    testAll();
    // testInt();

    std::cout << "<- END_PROGRAM_FLOW\n";

    return 0;
}

void testMyObject()
{
    std::cout << "<- Start testMyObject()" << std::endl;

    MyObject my_object(10);
    my_object.sayname();

    std::cout << "<- End testMyObject()\n";
}

void testMyList()
{
    std::cout << "<- Start testMyList()" << std::endl;

    MyList<MyObject> my_list_1;
    std::cout << my_list_1.empty() << " <- Is empty\n";
    std::cout << my_list_1.size() << " <- List size\n";

    MyObject my_object(555);
    my_object.sayname();

    std::cout << my_list_1.empty() << " <- Is empty\n";
    std::cout << my_list_1.size() << " <- List size\n";
    my_list_1.reveal();

    std::cout << "<- End testMyList()\n";
}

void testAll()
{
    std::cout << "<- Start testAll()" << std::endl;

    MyList<MyObject> my_list_1;

    for (std::size_t i = 0; i < 5; ++i)
    {
        MyObject my_object(i);
        my_list_1.push_back(my_object);
    }
    my_list_1.reveal();
    my_list_1.reverse();
    my_list_1.reveal();

    while (my_list_1.size() > 0)
    {
        my_list_1.pop_back();
    }
    my_list_1.reveal();

    std::cout << "<- End testAll()\n";
}

void testInt()
{
    std::cout << "<- Start testInt()" << std::endl;

    MyList<int> my_list_1;

    for (std::size_t i = 0; i < 5; ++i)
    {
        my_list_1.push_back(i);
    }

    my_list_1.reverse();

    while (!my_list_1.empty())
    {
        my_list_1.pop_back();
    }

    std::cout << "<- End testInt()\n";
}
