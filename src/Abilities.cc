#include "Util.cc"

enum AbilityType {
	STRENGTH, DEXTERITY, CONSTITUTION, INTELLIGENCE, WISDOM, CHARISMA, LUCK, 
	ABILITY_COUNT
};

class Ability
{
	private:
		short val = 0;
	public:
		Ability(short a_val) { val = a_val; }
		Ability() { Ability(GenAbility()); }

		short getMod() { return ((val - 10) / 2); }
};

class Strength : public Ability {	public: Strength(short v) : Ability(v) {} 	Strength() : Ability() {}};
class Dexterity : public Ability {	public: Dexterity(short v) : Ability(v) {} 	Dexterity() : Ability() {}};
class Constitution : public Ability {	public: Constitution(short v) : Ability(v) {} 	Constitution() : Ability() {}};
class Wisdom : public Ability {		public: Wisdom(short v) : Ability(v) {} 	Wisdom() : Ability() {}};
class Intelligence : public Ability {	public: Intelligence(short v) : Ability(v) {} 	Intelligence() : Ability() {}};
class Charisma : public Ability {	public: Charisma(short v) : Ability(v) {} 	Charisma() : Ability() {}};
class Luck : public Ability {		public: Luck(short v) : Ability(v) {} 		Luck() : Ability() {}};
 
