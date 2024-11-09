#include <print>

class Entity
{
protected:
    double dmg;
    double hp;
    Entity() : dmg(0), hp(100) {}
    Entity(double dmg, double hp) : dmg(dmg), hp(hp) {}

public:
    virtual void
    info() const
    {
        std::println("Entity method called");
    }


    void
    attack(Entity &other) const
    {
        other.hp -= dmg;
    }
};

class Mob : public Entity
{
public:
    Mob(double dmg, double hp) : Entity(dmg, hp) {}

    void
    info() const override
    {
        std::println("Mob method called");
    }

    using Entity::attack;
};

class Player : public Entity
{
    std::string name;

public:
    Player()
    {
        name = "Unnamed player";
        std::println("Default constructor called");
    }

    Player(std::string &&name)
    {
        this->name = std::format("Player {}", name);
        std::println("String constructor called");
    }


    Player(std::string &&name, double health, double dmg) : name(std::format("Player {}", name)), Entity(dmg, health)
    {
        std::println("Full constructor called");
    }

    Player(const Player &other) : name(other.name)
    {
        std::println("Copy constructor called");
    }
    Player(Player &&other) noexcept
        : name(other.name)
    {
        other.name = "Empty player";
        std::println("Move constructor called");
    }

    void
    info() const override
    {
        std::println("Player \"{}\" with {} hp", name, hp);
    }


    ~Player() noexcept
    {
        std::println("Player \"{}\" dies from cringe", name);
    }

    using Entity::attack;
};

int
main()
{

    Mob mob(20, 100);
    Player player{"player1", 100, 0};
    mob.attack(player);
    player.info();
}
