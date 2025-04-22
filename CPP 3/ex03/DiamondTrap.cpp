#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
    this->_name = "Default";
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << INFO << "DiamondTrap " << _name << " created" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << INFO << "DiamondTrap " << _name << " created" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << INFO << "DiamondTrap " << _name << " copied" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << INFO << "DiamondTrap " << _name << " destroyed" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        ClapTrap::_name = other.ClapTrap::_name;
    }
    std::cout << INFO << "DiamondTrap assignment called" << RESET << std::endl;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << DEBUG << "DiamondTrap name: " << _name
              << ", ClapTrap name: " << ClapTrap::_name << RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
