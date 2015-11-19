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
		void Initialize();
		void UpdateMonsterCfg();
		void UpdatePNJCfg();
		void UpdateBossCfg();

		int getNumberMonsterSaves();
		int getNumberBossSaves();
		int getNumberPNJSaves();



};