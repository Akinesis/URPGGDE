#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <dirent.h>

class Config{
	private:
		int numberMonsterSaves;
		int numberBossSaves;
		int numberPNJSaves;

	public:
		Config();
		~Config();
		void initialize();
		void updateMonsterCfg();
		void updatePNJCfg();
		void updateBossCfg();

		int getNumberMonsterSaves();
		int getNumberBossSaves();
		int getNumberPNJSaves();



};