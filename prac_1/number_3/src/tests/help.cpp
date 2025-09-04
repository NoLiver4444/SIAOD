#include "help.h"

void create_random_values_file(int min_value, int max_value, ofstream &create_file, ofstream &answ_file) {
    vector<int> vect;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = min_value; i <= max_value; ++i) {
        vect.push_back(i);
        answ_file << i << endl;
    }


    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(vect.begin(), vect.end(), default_random_engine(seed));

    for (size_t i = 0; i < vect.size(); ++i) {
        create_file << vect[i] << endl;
    }
}

bool check_files(ifstream &file_1, ifstream &file_2) {
    int value_1, value_2;

    while (file_1 >> value_1 && file_2 >> value_2) {
        if (value_1 != value_2) {
            return false;
        }
    }
    return true;
}