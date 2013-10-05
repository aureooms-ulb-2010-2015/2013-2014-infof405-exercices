#include <iostream>
#include <string>
#include <vector>
#include <map>


template<typename O, typename Key, typename T>
O& operator<<(O& out, const std::multimap<Key,T>& map){
	out << "{";
	if (map.size() > 0){
		typename std::multimap<Key,T>::const_iterator it, pen = --map.end();
		for(it = map.begin(); it != pen; ++it){
			out << it->first;
			out << " : ";
			out << it->second;
			out << ", ";
		}
		out << it->first;
		out << " : ";
		out << it->second;
	}
	out << "}";
	return out;
}


typedef struct start_t{
	size_t x = 0;
	size_t y = 0;

	start_t(){}
	start_t(size_t x, size_t y)
	:x(x), y(y){}

	template<typename O>
	friend O& operator<< (O &out, const start_t& start) {
		out << '('
			<< start.x << ','
			<< start.y
		<< ')';
		return out;
	}
} start_t;

template<typename I>
I gcd(I a, I b){
	while(true){
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

template<typename I>
I lcm(I a, I b){
	I temp = gcd(a, b);
	return temp ? (a / temp * b) : 0;
}

int main(){

	typedef std::pair<size_t, start_t> pair_t;
	typedef std::multimap<size_t, start_t> map_t;

	typedef struct node_t{
		start_t start;
		size_t size = 0;
		map_t::iterator it;

		node_t(){}
		node_t(size_t x, size_t y, size_t size)
		:start(x,y), size(size){}
	} node_t;

	typedef std::vector<node_t> line_t;


	std::string ciphertext;
	char prev = '\0', c = '\0';
	line_t line[2];
	map_t map;
	line[0].resize(1);
	line[1].resize(2);
	size_t x = 1;
	while(std::cin >> c){
		std::cout << prev << ": " << line[0].size() << ',' << line[1].size() << std::endl;
		if(c >= 'a' && c <= 'z'){
			if(prev != '\0'){
				for(size_t y = 0; y < x; ++y){
					if(c == ciphertext[y]){
						if(y > 0 && line[0][y-1].size > 0){
							line[1][y] = line[0][y-1];
							++line[1][y].size;
							map.erase(line[1][y].it);
							line[1][y].it = map.insert(pair_t(line[1][y].size, line[1][y].start));
						}
						else{
							line[1][y] = node_t(x,y,1);
							line[1][y].it = map.insert(pair_t(line[1][y].size, line[1][y].start));
						}
					}
					else{
						line[1][y] = node_t(x,y,0);
					}
				}
				line[0].swap(line[1]);
				line[1].emplace_back();
				line[1].emplace_back();
				++x;
			}
			prev = c;
			ciphertext += c;
		}
	}

	std::cout << map << std::endl;

	size_t interval_gcd = 0;

	for(map_t::reverse_iterator it = map.rbegin(); it != map.rend() && interval_gcd != 1; ++it){
		pair_t entry = *it;
		if(entry.first == 1) break;
		for(size_t i = 0; i < ciphertext.size(); ++i){
			if(i < entry.second.y){
				std::cout << ciphertext[i];
			}
			else if(i < entry.second.y + entry.first){
				std::cout << (char)(ciphertext[i] - 'a' + 'A');
			}
			else if(i < entry.second.x){
				std::cout << ciphertext[i];
			}
			else if(i < entry.second.x + entry.first){
				std::cout << (char)(ciphertext[i] - 'a' + 'A');
			}
			else{
				std::cout << ciphertext[i];
			}
		}
		std::cout << std::endl << std::endl;

		interval_gcd = gcd(interval_gcd, entry.second.x - entry.second.y);
		std::cout << "possible ciffer key length: " << interval_gcd << std::endl;
	}
	return 0;
}
