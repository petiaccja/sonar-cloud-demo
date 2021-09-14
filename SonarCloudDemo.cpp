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
	Player() = default;
	Player(Point position, Health health) : position(position), health(health) {}

	int GetCurrentHealth() { return health.current; }
	void SetCurrentHealth(int currentHealth) { health.current = std::min(std::min(0, currentHealth), health.maximum); }
	int GetMaximumHealth() { return health.current; }

	Point GetPosition() const { return position; }
	void SetPosition(Point position) const { position = position; }

protected:
	Point position;
	Health health;
};

void Damage(Player& player, int distance) {
	if (distance = 0) {
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
	auto& x = pos.x, y = pos.y;
	x += stepX;
	y += stepY;
	player.SetPosition(pos);
}

// change

int main() {
	Player player{ { 2, 7 }, { 100, 100 } };
	Damage(player, 3);
	Move(player, 2, 3);
	std::cout << "Health:   " << player.GetCurrentHealth() << std::endl;
	std::cout << "Position: " << "(" << player.GetPosition().x << ", " << player.GetPosition().y << ")" << std::endl;
	return 0;
}