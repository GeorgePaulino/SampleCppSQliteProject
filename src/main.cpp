#include <iostream>
#include "DataManager.hpp"
#include "MainManager.hpp"

using namespace std;

main()
{
    DataManager mng = DataManager();
    MainManager mmng = MainManager();
    mmng.DataMg = &mng;
    mmng.MainPage();
    return 0;
}
