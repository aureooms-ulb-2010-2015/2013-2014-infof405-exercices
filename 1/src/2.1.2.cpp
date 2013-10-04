#include <iostream>
#include <string>

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
	std::string string;
	while(std::cin >> string){
		for(int i = 0; i < 26; ++i){
			std::cout << i << ": ";
			for(char& c : string){
				if(c >= 'a' && c <= 'z'){
					std::cout << rol(c, i);
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	
	
		for(char& c : string){
			if(c >= 'a' && c <= 'z'){
				std::cout << rol(c, -('i'-'a'));
			}
		}
	}
	return 0;
}
