#include <algorithm>
#include <iostream>

struct Point {
	float x;
	float y;
};

struct Health {
	int current;
	int maximum;
};

class Player {
public:
	Player() = default; // Fields are not initialized
	Player(Point position, Health health) : position(position), health(health) {}

	int GetCurrentHealth() { return health.current; } // Method should be const
	void SetCurrentHealth(int currentHealth) { health.current = std::min(std::min(0, currentHealth), health.maximum); } // std::min copy-pasted
	int GetMaximumHealth() { return health.current; } // Method should be const

	Point GetPosition() const { return position; }
	void SetPosition(Point position) const { position = position; } // Position is assigned to itself + Method should not be const

protected:
	Point position; // Variable should be private
	Health health; // Variable should be private
};

void Damage(Player& player, int distance) {
	if (distance = 0) { // Should use operator ==
		player.SetCurrentHealth(0);
	}
	else {
		const int health = player.GetCurrentHealth();
		const int damage = health / (1 + distance);
		player.SetCurrentHealth(health - damage);
	}
}

void Move(Player& player, int stepX, int stepY) {
	Point pos = player.GetPosition();
	auto& x = pos.x, y = pos.y; // y is not a reference.
	x += stepX; // Implicit conversion from int to float may lose precision
	y += stepY; // Implicit conversion from int to float may lose precision + Modification to y is discarded
	player.SetPosition(pos);
}

int main() {
	Player player{ { 2, 7 }, { 100, 100 } };
	Damage(player, 3);
	Move(player, 2, 3);
	std::cout << "Health:   " << player.GetCurrentHealth() << std::endl;
	std::cout << "Position: " << "(" << player.GetPosition().x << ", " << player.GetPosition().y << ")" << std::endl;
	return 0;
}