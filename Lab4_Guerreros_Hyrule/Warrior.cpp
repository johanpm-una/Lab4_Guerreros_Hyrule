#include "Warrior.h"
#include <sstream>
#include <iostream>
using namespace EIF201;

int Warrior::clampRange(int value, int mn, int mx) {
	if (value < mn) return mn;
	if (value > mx) return mx;
	return value;
}

bool Warrior::isValidClass(std::string cls) {
	return cls == "Tank" || cls == "Assassin"
		|| cls == "Mage" || cls == "Support";
}

Warrior::Warrior(std::string name, std::string combatClass,
	int attack, int defense, int health, 
	int maxSkills)
	: name(name.empty() ? "Unnamed" : name),
	combatClass(isValidClass(combatClass)
		? combatClass : "Tank"),
	attack(clampRange(attack, 1, 100)),
	defense(clampRange(defense, 1, 100)),
	health(clampRange(health, 1, 1000)),
	skillCount(0),
	maxSkills(maxSkills > 0 ? maxSkills : 3) {
	skills = new Skill*[this->maxSkills];
	for (int i = 0; i < this->maxSkills; i++) {
		skills[i] = nullptr;
	}
}

Warrior::~Warrior() {
	for (int i = 0; i < skillCount; i++) {
		delete skills[i];
	}
	delete[] skills;
}

bool Warrior::learnSkill(std::string name, std::string type,
	int power, int cost) {
	if (skillCount >= maxSkills) return false;
	skills[skillCount++] = new Skill(name, type, power, cost);
	return true;
}

bool Warrior::hasSkill(std::string name) const {
	for (int i = 0; i < skillCount; i++) {
		if (skills[i]->getName() == name) return true;
	}
	return false;
}

int Warrior::totalSkillEffect() const {
	int sum = 0;
	for (int i = 0; i < skillCount; i++) {
		sum += skills[i]->calculateEffect();
	}
	return sum;
}

int Warrior::calculatePower() const {
	return (attack * 2) + defense + (health / 10) + totalSkillEffect();
}

std::string Warrior::getName() const { return name; }
std::string Warrior::getCombatClass() const {
	return combatClass; 
}
int Warrior::getAttack() const { return attack; }
int Warrior::getDefense() const { return defense; }
int Warrior::getHealth() const { return health; }
int Warrior::getSkillCount() const { return skillCount; }

std::string Warrior::toString() const {
	std::ostringstream oss;
	oss << "[" << combatClass << "]" << name
		<< " | ATK: " << attack << " | DEF: " << defense
		<< " HP " << health << " | Skills: "
		<< skillCount << "/" << maxSkills
		<< " | Power: " << calculatePower();
	return oss.str();
}

void Warrior::showSkills() const {
	std::cout << name << " Skills of:" << name
		<< ":" << std::endl;
	for (int i = 0; i < skillCount; i++) {
		std::cout << " - " 
			<< skills[i]->toString()
			<< std::endl;
	}
}

