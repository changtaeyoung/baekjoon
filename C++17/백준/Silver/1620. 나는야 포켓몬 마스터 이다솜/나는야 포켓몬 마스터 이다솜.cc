#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> pokemon;
vector<string> pokemonName;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string name, quiz;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> name;
		pokemon.insert({ name, (i + 1) });
		pokemonName.push_back(name);
	}

	for (int i = 0; i < m; i++) {
		cin >> quiz;
		if (isdigit(quiz[0])) {
			cout << pokemonName[stoi(quiz) - 1] << "\n";
		}
		else {
			cout << pokemon.find(quiz)->second << "\n";
		}
	}
	return 0;
}