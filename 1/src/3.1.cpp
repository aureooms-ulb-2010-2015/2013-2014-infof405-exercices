#include <iostream>
#include <string>

char rol(char c, int d){
	d = (('z'-'a' + 1) + d) % ('z'-'a' + 1);
	return ('a' + (c -'a' + d )%('z'-'a' + 1));
}

int main(){
	std::string key, ciphertext;
	std::cin >> key;
	size_t cursor = 0, size = key.size();
	while(std::cin >> ciphertext){
		for(char& c : ciphertext){
			if(c >= 'a' && c <= 'z'){
				std::cout << rol(c, 'a' - key[cursor]);
				cursor = (cursor + 1) % size;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
