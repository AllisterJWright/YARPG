#include "Util.cc"

enum Race {
	// just getting PHB races for now; will get Monster Manual and non-core later
	DWARF, ELF, HALFLING, HUMAN, DRAGONBORN, GNOME, HALFELF, HALFORC, TIEFLING, 
	RACE_COUNT
};

struct race {
	Race raceName;
	unordered_map<struct ability*, short> unlocks;
};
