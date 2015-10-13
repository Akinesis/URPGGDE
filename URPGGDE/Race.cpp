

Race::Race(std::string ra){
	std::string race = ra;
}


////////////////////////////////////////////////////////////////////////////////
// Getters Setters START

std::string Race::getRaceName(){
	return race;
}

void Race::setRace(std::string ra){
	race = ra;
}

int Race::getRangeStrengthMin(){
	return rangeStrength.min;
}

int Race::getRangeStrengthMax(){
	return rangeStrength.max;
}

int Race::getRangeConstitutionMin(){
	return rangeConstitution.min;
}

int Race::getRangeConstitutionMax(){
	return rangeConstitution.max;
}

int Race::getRangeDexterityMin(){
	return rangeDexterity.min;
}

int Race::getRangeDexterityMax(){
	return rangeDexterity.max;
}

int Race::getRangeIntelligenceMin(){
	return rangeIntelligence.min;
}

int Race::getRangeIntelligenceMax(){
	return rangeIntelligence.max;
}

int Race::getRangeWisdomMin(){
	return rangeWisdom.min;
}

int Race::getRangeWisdomMax(){
	return rangeWisdom.max;
}

int Race::getRangeCharismaMin(){
	return rangeCharisma.min;
}

int Race::getRangeCharismaMax(){
	return rangeCharisma.max;
}
