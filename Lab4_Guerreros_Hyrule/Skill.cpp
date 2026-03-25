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
	int power, int energyCost) {
	: name
}