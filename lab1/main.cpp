#include <any>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using mymap = std::map<int, int>;
using myfunction = std::function<double (mymap)>;

void wypisz(mymap mapa, myfunction fun) {
    using namespace std;
    cout << fun(mapa) << endl;
}

double convert_to_degrees(double x) {
    return x * 3.14159/180;
}

int main(int argc, char **argv) {
    using namespace std;
    vector<string> argumenty(argv, argv + argc);
    mymap mapa;
    map<string, myfunction> formatery;

    for (int i = 2; i < argumenty.size(); i++) {
        mapa[i-1] = stoi(argumenty.at(i));
    }

    formatery["add"] = [](mymap map) { return map.at(1) + map.at(2); };
    formatery["mod"] = [](mymap map) { return map.at(1) %  map.at(2); };
    formatery["sin"] = [](mymap map) {
        double x = convert_to_degrees(map.at(1));
        return sin(x);
    };

    try{
        auto selected_f = argumenty.at(1);
        wypisz(mapa, formatery.at(selected_f));
    } catch (std::out_of_range aor) {
        cout << "Error" << endl;

    }
    return 0;
}