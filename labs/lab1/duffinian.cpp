#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

bool is_duffinian(int num) {
    // TODO: Your implementation here
    int i, j, h, k, sum, index, x;
    int div[100] = {};
    for (x =2;x<100; x++ ){
        div[x] = 0;
    }
    div[0] = 1; div[1] = num;
    j = 2; sum = 0; index = 0;
    for (i = 2; i<=sqrt(num); i++) {
        if (num % i == 0) {
            div[j] = i;
            if (i != num / i) {
                div[j + 1] = num / i;
                j += 2;
            }
            else {
                j++;
            }
        }
    }
    for (k = 0; k < j; k++) {
        sum += div[k];
    }

    for (h = 2; h <= num; h++){
         if (num%h == 0 && sum%h ==0) {
             index = 0;
             break;
         }
         else {
             index = 1;
         }
    }
    if (index == 0){
    return false;
    }
    else{
        return true;
    }
}


void test_duffinian() {
    assert(!is_duffinian(6));  // 6 is not a Duffinian number
    assert(is_duffinian(35));
    // TODO: Add more test cases
    cout << "Duffinian number tests passed!" << endl;
}
