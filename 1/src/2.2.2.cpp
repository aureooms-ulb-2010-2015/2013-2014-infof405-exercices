#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>

char rol(char c, int d){
	d = (('z'-'a' + 1) + d) % ('z'-'a' + 1);
	return ('a' + (c -'a' + d )%('z'-'a' + 1));
}

char encrypt(char c){
	return rol(c, 3);
}

char decrypt(char c){
	return rol(c, -3);
}


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
	
	std::multimap<double, int> delta_m;
	
	std::string string, tmp;
	while(std::cin >> tmp) string += tmp;
	if(string.size() > 0){
		for(int i = 0; i < 26; ++i){
			double count = 0;
			std::unordered_map<char, double> freq;
			for(auto& entry : ref){
				freq[entry.first] = 0;
			}
			for(char& c : string){
				if(c >= 'a' && c <= 'z'){
					char x = rol(c, i);
					++freq[x];
					++count;
				}
			}
			
			double delta = 0;
			for(auto& entry : freq){
				double tmp = entry.second;
				tmp = tmp / count - ref[entry.first];
				delta += tmp * tmp ;
			}
			std::cout << i << ": " << sqrt(delta) << std::endl;
			delta_m.insert(std::pair<double, uint>(sqrt(delta), i));
		}
		
		for(auto& entry : delta_m){
			std::cout << entry.second << ": ";
			for(char& c : string){
				if(c >= 'a' && c <= 'z') std::cout << rol(c, entry.second);
				else std::cout << ' ';
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
