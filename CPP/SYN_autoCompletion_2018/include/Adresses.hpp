/*
** EPITECH PROJECT, 2019
** SYN_autoCompletion_2018
** File description:
** Adresses
*/

#ifndef ADRESSES_HPP_
#define ADRESSES_HPP_

#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <set>
#include <boost/algorithm/string.hpp>

using namespace std;

class Adresses {
	public:
		Adresses();
		~Adresses();
		string city;
		int numberStreet;
		string streetType;
		string streetName;
		string comparativeCity;
		bool noComma(string line);
		bool isFirstANumber(string line);
		bool numbersBeforeComma(string line);
		bool notThreeSpaces(string line);
		bool numbersAfterTwoSpaces(string line);
		bool compareStreetTypes(string line);
		bool wrongStreetTypes(string line);
		bool spaceBeforeComma(string line);
		int storeCitys(string line);
		int storeNumbers(string line);
		int storeStreets(string line);
		int parsingBegins(string line);
		list<Adresses> direction;
		vector<string> cites;
		map<string, int> countMap;
		vector<string> suggestedCities;
		//map<string, string> dictionary;
		int countMyCitys();
		int orderMyCitys();
		map<char, int> noDup;
		vector<string> dumpVector;
		int createDumpVector();
		bool wrongCity = true;
		bool wrongStreet = true;
		int secondPhase();
		int thirdPhase();
		int howdyReturns;
		vector<string> directionFinal;
		int lastPhase();

	protected:

		//The functions from before are not written here because then they wouldn't work on main.cpp

	private:
};

class filteredCities {
	public:
		string name;
		int timesAppeared;
		list<filteredCities> cleanCities;
	protected:
	private:
};

#endif /* !ADRESSES_HPP */