#include <algorithm>
#include <iostream>

struct Position {
	float x, y;
};

struct Health {
	int current;
	int maximum;
};

class Player {
public:
	Player() = default;
	Player(Position position) : Player(position, { 0, 100 }) {}
	Player(Health health) : Player({ 0,0 }, health) {}
	Player(Position position, Health health) { position = position; health = health; }

	int GetCurrentHealth() { return health.current; }
	int SetCurrentHealth(int currentHealth) { return health.current = std::min(currentHealth, health.maximum); }

	int GetMaximumHealth() { return health.current; }
protected:
	Position position;
	Health health;
};

void Damage(Player& player) {
	const int currentHealth = player.GetCurrentHealth();
	const int maxmimumHealth = player.GetMaximumHealth();
	const double fraction = currentHealth < maxmimumHealth / 2 ? (1 / 2) : (1 / 3); //  Less damage on low health.
	player.SetCurrentHealth(int(currentHealth * fraction));
}

int main() {
	Player player{ { 2, 7 }, { 100, 100 } };
	std::cout << player.GetCurrentHealth() << std::endl;
	Damage(player);
	std::cout << player.GetCurrentHealth() << std::endl;
	return 0;
}