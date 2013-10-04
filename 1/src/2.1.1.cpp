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
		for(char& c : string){
			if(c >= 'a' && c <= 'z'){
				std::cout << encrypt(c);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
