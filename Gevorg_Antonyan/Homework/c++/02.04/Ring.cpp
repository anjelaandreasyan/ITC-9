#include <iostream>


int main() {
    int bhour = 0;
    int bminut = 0;
    int ehour = 0;
    int eminut = 0;
    int ring = 0;
    std::cout << "enter begin time xx xx" << std::endl;
    std::cin >> bhour >> bminut ;
    std::cin >> ehour >> eminut ;
    while (0 > bhour || 0 > bminut || 0 > ehour || 0 > eminut || 12 < bhour || 12 < ehour || 60 < bminut || 60 < eminut || bhour > ehour || (ehour == bhour && bminut > eminut) /*|| ('0' > (char)bhour && '9' < (char)bhour ) || ('0' > (char)ehour && '9' < (char)ehour) || ('0' > (char)bminut && '9' < (char)bminut) || ('0' > (char)eminut && '9' < (char)eminut)*/) {
        std::cout << "enter correct time" << std::endl;
        std::cin >> bhour >> bminut ;
        std::cin >> ehour >> eminut ;
    } 
    if (12 == ehour && 0 < eminut) {
        eminut = -1;
    }
    if (12 == bhour && (0 != bminut || 12 != ehour || 0 != eminut)) {
        eminut = -1;
    }

    ring = 2 * (ehour - bhour) ;
    if (0 == bminut || 7 == bminut) {
        ring = ring +1;    
    }
    if (7 < bminut) {
        ring = ring -1;
    }
    if (7 <= eminut) {
        ring = ring + 1;
    }
    std::cout << "will ring " << ring << " items" << std::endl;
    return 0;
}
