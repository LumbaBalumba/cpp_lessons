#include <format>
#include <print>
#include <string>
#include <utility>
#include <vector>


class Player
{
    std::string name;
    double health;
    double dmg;

public:
    Player()
    {
        name = "Unnamed player";
        health = 100;
        dmg = 0;
        std::println("Default constructor called");
    }

    Player(std::string &&name)
    {
        this->name = std::format("Player {}", name);
        health = 100;
        dmg = 0;
        std::println("String constructor called");
    }


    Player(std::string &&name, double health, double dmg) : name(std::format("Player {}", name)), health(health), dmg(dmg)
    {
        std::println("Full constructor called");
    }

    Player(const Player &other) : name(other.name), health(other.health), dmg(other.dmg)
    {
        std::println("Copy constructor called");
    }
    Player(Player &&other) noexcept
        : name(other.name), health(other.health), dmg(other.dmg)
    {
        other.name = "Empty player";
        other.health = 0;
        other.dmg = 0;
        std::println("Move constructor called");
    }

    std::string
    info() const
    {
        return std::format("Player \"{}\" with health {} and damage {}", name, health, dmg);
    }


    ~Player() noexcept
    {
        std::println("Player \"{}\" dies from cringe", name);
    }

    void
    attack(Player &other) const
    {
        other.health -= this->dmg;
    }
};


int
main()
{
    Player p1{};
    std::println("{}", p1.info());
    Player p2("2");
    std::println("{}", p2.info());
    Player p3("3", 500.0, 200.0);
    std::println("{}", p3.info());
    p3.attack(p2);
    Player *p4 = new Player(p3);
    delete p4;
    Player p5(std::move(p3));
}
