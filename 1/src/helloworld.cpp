#include <iostream>
#include <string>

char rol(char c, int d){
	return ('A' + (c -'A' + d )%('Z'-'A' + 1));
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
			if(c >= 'A' && c <= 'Z'){
				std::cout << encrypt(c);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
