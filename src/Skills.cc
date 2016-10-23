#include "Abilities.cc"
#include<cstdlib> 		// rand()

class Skill
{
	private:
		unsigned long experience = 0;
		short level = 0;
		Ability defaultAbility;
		unsigned long neededToAdvance[20] =    {   30,    90,   270,   650,  1400,
							 2300,  3400,  4800,  6400,  8500,
							10000, 12000, 14000, 16500, 19500,
							22500, 26500, 30500, 35500, 40000};
	public:
		Skill (Ability a_defaultAbility,
			short a_level = 0,
			unsigned long a_experience = 0)
		{
			defaultAbility = a_defaultAbility;
			level = a_level;
			awardXP(a_experience);
		}

		short roll (Ability ability, short advDv = 1)
		{
			return D20Roll(advDv) + ability.getMod();
		}

		short roll (short advDv = 1) { return this->roll(defaultAbility, advDv); }

		int awardXP (unsigned long xp)
		{
			experience += xp;
			// Check if able to level up the skill
			if (experience > neededToAdvance[level])
			{
				level++;
				return 1;
			}
			if (level > 0 && experience < neededToAdvance[level - 1])
			{
				level--;
				return 2;
			}
			return 0;
		}
};

// Saves
class StrSave : Skill { public: StrSave(short l, unsigned long e) : Skill(*(new Strength()), l, e) {}};
class DexSave : Skill { public: DexSave(short l, unsigned long e) : Skill(*(new Dexterity()), l, e) {}};
class ConSave : Skill { public: ConSave(short l, unsigned long e) : Skill(*(new Constitution()), l, e) {}};
class WisSave : Skill { public: WisSave(short l, unsigned long e) : Skill(*(new Wisdom()), l, e) {}};
class IntSave : Skill { public: IntSave(short l, unsigned long e) : Skill(*(new Intelligence()), l, e) {}};
class ChaSave : Skill { public: ChaSave(short l, unsigned long e) : Skill(*(new Charisma()), l, e) {}};
class LckSave : Skill { public: LckSave(short l, unsigned long e) : Skill(*(new Luck()), l, e) {}};


// Combat Skills 	-- Magic appears later
	// Melee
class Piercing1H : Skill { public:	Piercing1H (short l, unsigned long e) :	Skill(*(new Strength()), l, e) {}};
class Piercing2H : Skill { public:	Piercing2H (short l, unsigned long e) :	Skill(*(new Strength()), l, e) {}};
class Slashing1H : Skill { public:	Slashing1H (short l, unsigned long e) :	Skill(*(new Strength()), l, e) {}};
class Slashing2H : Skill { public:	Slashing2H (short l, unsigned long e) :	Skill(*(new Strength()), l, e) {}};
class Bludgeon1H : Skill { public:	Bludgeon1H (short l, unsigned long e) :	Skill(*(new Strength()), l, e) {}};
class Bludgeon2H : Skill { public:	Bludgeon2H (short l, unsigned long e) :	Skill(*(new Strength()), l, e) {}};
	// Ranged
class Shortbow : Skill { public:	Shortbow (short l, unsigned long e) :		Skill(*(new Dexterity()), l, e) {}};
class Longbow : Skill { public:		Longbow (short l, unsigned long e) :		Skill(*(new Dexterity()), l, e) {}};
class HandCrossbow : Skill { public:	HandCrossbow (short l, unsigned long e) :	Skill(*(new Dexterity()), l, e) {}};
class LightCrossbow : Skill { public:	LightCrossbow (short l, unsigned long e) :	Skill(*(new Dexterity()), l, e) {}};
class HeavyCrossbow : Skill { public:	HeavyCrossbow (short l, unsigned long e) :	Skill(*(new Dexterity()), l, e) {}};

// General Skills
	// Str
class Athletics : Skill { public:	Athletics (short l, unsigned long e) :		Skill(*(new Strength()), l, e) {}};
	// Dex
class Acrobatics : Skill { public:	Acrobatics (short l, unsigned long e) :		Skill(*(new Dexterity()), l, e) {}};
class SleightOfHand : Skill { public:	SleightOfHand (short l, unsigned long e) :	Skill(*(new Dexterity()), l, e) {}};
class Stealth : Skill { public:		Stealth (short l, unsigned long e) :		Skill(*(new Dexterity()), l, e) {}};
	// Wis
class HandleAnimal : Skill { public:	HandleAnimal (short l, unsigned long e) :	Skill(*(new Wisdom()), l, e) {}};
class Insight : Skill { public:		Insight (short l, unsigned long e) :		Skill(*(new Wisdom()), l, e) {}};
class Perception : Skill { public:	Perception (short l, unsigned long e) :		Skill(*(new Wisdom()), l, e) {}};
class Fishing : Skill { public:		Fishing (short l, unsigned long e) :		Skill(*(new Wisdom()), l, e) {}};
class Trapping : Skill { public:	Trapping (short l, unsigned long e) :		Skill(*(new Wisdom()), l, e) {}};
class Foraging : Skill { public:	Foraging (short l, unsigned long e) :		Skill(*(new Wisdom()), l, e) {}};
	// Int
class Arcana : Skill { public:		Arcana (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
class History : Skill { public:		History (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
class Investigation : Skill { public:	Investigation (short l, unsigned long e) :	Skill(*(new Intelligence()), l, e) {}};
class Nature : Skill { public:		Nature (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
class Religion : Skill { public:	Religion (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
class Carpentry : Skill { public:	Carpentry (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
class Cooking : Skill { public:		Cooking (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
class Farming : Skill { public:		Farming (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
class Medicine : Skill { public:	Medicine (short l, unsigned long e) :		Skill(*(new Intelligence()), l, e) {}};
	// Cha
class Deception : Skill { public:	Deception (short l, unsigned long e) :		Skill(*(new Charisma()), l, e) {}};
class Intimidation : Skill { public:	Intimidation (short l, unsigned long e) :	Skill(*(new Charisma()), l, e) {}};
class Perform : Skill { public:		Perform (short l, unsigned long e) :		Skill(*(new Charisma()), l, e) {}};
class Persuasion : Skill { public:	Persuasion (short l, unsigned long e) :		Skill(*(new Charisma()), l, e) {}};
	// Lck
class Loot : Skill { public:		Loot (short l, unsigned long e) :		Skill(*(new Luck()), l, e) {}};

