#include <iostream>
#include <cassert>

using namespace std;

bool is_alternating(int num, int base) {
    // TODO: Your implementation here
    int baseb[50];
    int n1, i, j, index, k;
    n1 = num; i = 0; index = 0;
    for (k = 0; k<50; k++){
        baseb[k] = 0;
    }
    while (n1 > 0){
        baseb[i] = n1%base;
        n1/=base;
        i++;
    }
    if (i == 1){
        return true;
    }
    else{
        for (j = 1; j < i; j++){
            if (abs((baseb[j] - baseb[j - 1]))%2 == 1){
                index = 1;
            }
            else{
                index = 0;
                break;
            }
        }
        if (index == 0){
            return false;
        }
        else{
            return true;
        }

    }
}

void test_alternating() {
    assert(!is_alternating(24, 10));
    assert(is_alternating(21, 2));


    // 24 is not an alternating number in base 10
    // TODO: Add more test cases
    cout << "Alternating number tests passed!" << endl;
}
