#include <iostream>
int main() {
	int zam1, rope1, zam2, rope2, pop=0;
	std::cout << "nermuceq skzbnakan zam@::" << '\n';
	std::cin >> zam1 >> rope1;
	std::cout << "nermuceq verjnakan zam@::" << '\n';
	std::cin >> zam2 >> rope2;
	if(zam1 > zam2 || (zam1 == zam2 && rope1 > rope2)) {
		std::cout << 0 << std::endl;
		return 0;
	}
	if(rope1 <= 7) {
		pop++;
		if(rope1 == 0) {
			pop++;
		}
	} 
	if(rope2 < 7) {
		pop--;
	}
	pop = pop + (zam2 - zam1) * 2;
	std::cout << "kznaga::" << pop << "  angam" << '\n';
	return 0;
}
