#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>

int main(){
	std::unordered_map<char, double> ref = {
		{'a', 9.42},
		{'n', 7.15},
		{'b', 1.02},
		{'o', 5.14},
		{'c', 2.64},
		{'p', 2.86},
		{'d', 3.39},
		{'q', 1.06},
		{'e', 15.87},
		{'r', 6.46},
		{'f', 0.95},
		{'s', 7.90},
		{'g', 1.04},
		{'t', 7.26},
		{'h', 0.77},
		{'u', 6.24},
		{'i', 8.41},
		{'v', 2.15},
		{'j', 0.89},
		{'w', 0.00},
		{'k', 0.00},
		{'x', 0.30},
		{'l', 5.34},
		{'y', 0.24},
		{'m', 3.24},
		{'z', 0.32}
	};

	double french_index = 0;
	for(auto& pair : ref){
		french_index += pow(pair.second/100, 2);
	}

	std::cout << "french language index: " << french_index << std::endl;
	
	std::unordered_map<char, double> freq;
	double count = 0;
	for(auto& entry : ref){
		freq[entry.first] = 0;
	}
	
	std::string ciphertext;
	while(std::cin >> ciphertext){
		for(char& c : ciphertext){
			if(c >= 'a' && c <= 'z'){
				++freq[c];
				++count;
			}
		}
	}

	if(count > 0){

		double ciphertext_index = 0;
		for(auto& pair : freq){
			ciphertext_index += pow(pair.second/count, 2);
		}

		std::cout << "ciphertext language index: " << ciphertext_index << std::endl;

	}

	return 0;
}
