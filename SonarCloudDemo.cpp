#include <algorithm>
#include <iostream>

struct Point {
	float x, y;
};

struct Health {
	int current;
	int maximum;
};

class Player {
public:
	Player() = default;
	Player(Point position, Health health) : position(position), health(health) {}

	// Health
	int GetCurrentHealth() { return health.current; }
	int SetCurrentHealth(int currentHealth) { return health.current = std::min(std::max(0, currentHealth), health.maximum); }

	int GetMaximumHealth() { return health.current; }

	// Position
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
		const int damage = health / distance;
		player.SetCurrentHealth(health - damage);
	}
}

void Move(Player& player, int stepX, int stepY) {
	Point pos = player.GetPosition();
	pos.x += stepX;
	pos.x += stepY;
	player.SetPosition(pos);
}

int main() {
	Player player{ { 2, 7 }, { 100, 100 } };
	Damage(player, 3);

	return 0;
}