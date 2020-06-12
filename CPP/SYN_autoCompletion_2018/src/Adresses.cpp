/*
** EPITECH PROJECT, 2019
** SYN_autoCompletion_2018
** File description:
** Adresses
*/

#include "../include/Adresses.hpp"

Adresses::Adresses()
{
}

Adresses::~Adresses()
{
}

bool Adresses::noComma(string line)
{
    if (line.find_first_of(",") == string::npos)
        return true;
    return false;
}

bool Adresses::isFirstANumber(string line){
    
    if (isdigit(line[0]))
        return true;
    return false;
}

bool Adresses::numbersBeforeComma(string line)
{   
    unsigned int i = 0;
    int check = 0;
    if (noComma(line) == false && isFirstANumber(line) == false) {
        int comma = line.find_first_of(',');
        while (i < line.size()){
            if (!isdigit(line[i]))
                check++;
            i++;
        }
        if (comma > check)
            return true;
    }
    return false;
}

bool Adresses::notThreeSpaces(string line)
{
    int count = 0;
    for (unsigned int i = 0; i < line.size(); i++)
        if (line[i] == ' ') count++;
    if (count < 3)
        return true;
    return false;
}

bool Adresses::numbersAfterTwoSpaces(string line)
{
    unsigned int i = 0;
    unsigned int y = 0;
    int count = 0;
    int check = 0;
    while (i <line.size()){
        if (line[i] == ' ') 
            count++;
        if (count == 2) {
            y = i;
            while(y < line.size()){
                if (isdigit(line[y]))
                    check++;
                y++;
            }
        }
        i++;
    }
    if (check != 0)
        return true;        
    return false;
}
bool Adresses::compareStreetTypes(string line)
{
    if (line.compare("allée") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("avenue") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("boulevard") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("chemin") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("impasse") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("place") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("quai") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("rue") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    if (line.compare("square") == 0){
        char bufferThree[line.size()];
        size_t length = line.copy(bufferThree,line.size(),0);
        bufferThree[length]='\0';
        streetType = bufferThree;
        return true;
    }
    return false;
}
/*
bool Adresses::spaceBeforeComma(string line)
{
    int comma = line.find_first_of(",");
    int space = line.find_first_of(" ");
    if (comma > space)
        return true;
    return false;
}
*/
bool Adresses::wrongStreetTypes(string line)
{
    int i = 0;
    int y = 0;
    int secondSpace = 0;
    int thirdSpace = 0;
    int check = 0;
    string streetType;
    while (i < line.size()){
        if (line[i] == ' ') 
            secondSpace++;
        if (secondSpace == 2) {
            check = i;
            y = i+1;
            while (y < line.size()){
                if (line[y] == ' '){
                    streetType = line.substr(check+1,y-check-1);
                    if (compareStreetTypes(streetType) == false)
                        return true;
                    else
                        return false;
                }
                y++;
            }
        }
        i++;
    }
    return false;
}    

int Adresses::storeCitys(string line)
{
    int comma = line.find_first_of(",");
    char bufferOne[comma];
    size_t length = line.copy(bufferOne,comma,0);
    bufferOne[length]='\0';
    city = bufferOne;
    cites.push_back(city);
    // cout<<city<<endl;
    return(0); 
}

int Adresses::storeNumbers(string line)
{
    int firstSpace = line.find_first_of(' ');
    int i = firstSpace;
    int secondSpace = 0;
    while (i < line.size()){
        if(line[i] == ' '){
            secondSpace = i;
            break;
        }
        i++;
    }
    string numbersS = line.substr(firstSpace, secondSpace);
    int numbersI = stoi(numbersS);
    numberStreet = numbersI;
    // cout<<numberStreet<<endl;
    return(0);
}

int Adresses::storeStreets(string line)
{
    int i = 0;
    int count = 0;
    int thirdSpace = 0;
    while (i < line.size()){
        if(line[i] == ' ')
            count++;
        if (count == 3){
            thirdSpace = i;
            break;
        }
        i++;
    }
    char bufferFour[(line.size()-thirdSpace)];
    size_t length = line.copy(bufferFour,(line.size()-thirdSpace),thirdSpace+1);
    bufferFour[length]='\0';
    streetName = bufferFour;
    // cout << streetName << endl;
    return(0);
}

int Adresses::parsingBegins(string line)
{
    storeCitys(line);
    storeNumbers(line);
    storeStreets(line);
    return (0);
}

int Adresses::countMyCitys()
{
    for (auto & elem : cites){
        auto result = countMap.insert(pair<string, int>(elem,1));
        if (result.second == false)
            result.first->second++;
    }
}

int Adresses::orderMyCitys()
{
    // Declaring the type of Predicate that accepts 2 pairs and return a bool
	typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;
 
	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
			[](pair<string, int> elem1 ,pair<string, int> elem2)
			{
				return elem1.second >= elem2.second;
			};
 
	// Declaring a set that will store the pairs using above comparision logic
	set<pair<string, int>, Comparator> orderedCities(
			countMap.begin(), countMap.end(), compFunctor);
 
	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
    cites.clear();
    int i = 0;
    set<pair<string, int>, Comparator>::iterator it = orderedCities.begin();
    for(pair<string, int> element : orderedCities)
    {   
        cites.push_back(element.first);
    }
    /*
    for (pair<string, int> element : orderedCities)

		cout << element.first << " :: " << element.second << endl;
    */
	return 0;
}

int Adresses::createDumpVector()
{
    //generate a Map, and fill it with just the first char in minuscules.
    //that way it won't be able to generate duplicates
    for (int i = 0; i < cites.size(); i++){
        char fill = cites[i][0];
        noDup.insert(pair<char, int>(fill, i));
    }
}

int Adresses::lastPhase()
{
    //grab cin and loop it thru the vector boi
    string choosenNumber;
    cin >> choosenNumber;
    if (choosenNumber.compare("ABORT") == 0)
        exit(0);
    bool whatIsHeDoing = true;
    vector<string>::iterator it;
    for (it = directionFinal.begin(); it != directionFinal.end(); it++){
        if (choosenNumber[0] == it[0][1]){
            whatIsHeDoing = false;
            cout << "=> ";
                for (int i = 5; i != it[0].size(); i++)
                    cout << it[0][i];
            cout << endl;
        }
    }
    if (whatIsHeDoing == true){
        cout << "Unknown address" << endl;
        exit(84);
    }
    return (0);
}

int Adresses::thirdPhase()
{
    howdyReturns = 0;
    string thirdPhase;
    cin >> thirdPhase;
    if (thirdPhase.compare("ABORT") == 0)
        exit(0);
    thirdPhase[0] = toupper(thirdPhase[0]);
    list<Adresses>::iterator it;
    for (it = direction.begin(); it != direction.end(); it++){
        if (thirdPhase[0] == it->streetName[0] && comparativeCity == it->city){
            wrongStreet = false;
            howdyReturns++;
            string daCity = it->city;
            boost::algorithm::to_upper(daCity);
            string daStreet = it->streetName;
            boost::algorithm::to_upper(daStreet);
            directionFinal.push_back("{"+to_string(howdyReturns)+" : "+it->city+", "+to_string(it->numberStreet)+" "+it->streetType+" "+it->streetName);
            cout << "{" << howdyReturns << " : " << daCity << ", " << it->numberStreet << ' ' << it->streetType << ' ' << daStreet << "} ";
        }
    }
    cout << "";
    if (wrongStreet == false && wrongCity == false){   
        cout << endl;
        if (lastPhase()==84){
            cout << "Unknown addres" << endl;
            return(84);
        }
    }
    else{
        cout << "Unknown addres" << endl;
        return(84);
    }
    return(0);
}

int Adresses::secondPhase()
{
    comparativeCity[0] = toupper(comparativeCity[0]);
    list<Adresses>::iterator it;
    for (it = direction.begin(); it != direction.end(); it++){
        if (comparativeCity == it->city){
            wrongCity = false;
            char bufferStreet[1];
            string actualStreet = it->streetName.substr(0,1);
            actualStreet[0] = tolower(actualStreet[0]);
            string actualCity = comparativeCity;
            boost::algorithm::to_upper(actualCity);
            cout << "{" << actualCity << ", " << actualStreet << "} ";
        }
    }
    cout << endl;
    if (thirdPhase() == 84)
        return(84);
    return(0);
    //cout << comparativeCity << endl;
    // compare comparativeCity with list...
}