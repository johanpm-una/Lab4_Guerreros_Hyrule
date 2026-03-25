#include "Skill.h"
#include <sstream>

using namespace EIF201;

int Skill::clampRange(int value, int mn, int mx) {
	if (value < mn) return mn;
	if (value > mx) return mx;
	return value;
}

bool Skill::isValidType(std::string type) {
	return type == "Physical" || type == "Magical"
		|| type == "Healing";
}

Skill::Skill(std::string name, std::string damageType,
	int power, int energyCost)
	: name(name.empty() ? "Unnamed" : name), 
	damageType(isValidType(damageType)
		? damageType : "Physical"),
		power(clampRange(power, 1, 200)),
		energyCost(clampRange(energyCost, 0, 100)) {}

	Skill::~Skill() {
	
	}

	std::string Skill::getName() const { return name; }
	std::string Skill::getDamageType() const { return damageType; }
	int Skill::getPower() const { return power; }
	int Skill::getEnergyCost() const { return energyCost; }

	int Skill::calculateEffect() const {
		if (damageType == "Magical") 
			return (int)(power * 1.5);
		if (damageType == "Healing") 
			return (int)(power * 0.8);
		return power;
	}

	std::string Skill::toString() const {
		std::ostringstream oss;
		oss << name << " (" << damageType
			<< "Poder: " << power
			<< "Efecto: " << calculateEffect()
			<< "Costo: " << energyCost << ")";
		return oss.str();
	}