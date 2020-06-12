/*
** EPITECH PROJECT, 2019
** SYN_autoCompletion_2018
** File description:
** main
*/

#include "../include/Adresses.hpp"

bool isEmpty(ifstream& inFile)
{
    return inFile.peek() == ifstream::traits_type::eof();
}

int readFile(char* argv)
{
    class Adresses adress;
    ifstream inFile;
    bool multipleCities = false;
    int howdy = 0;

    inFile.open(argv);
    if (!inFile || isEmpty(inFile) == true) {
        cout << ("Invalid argument") << endl;
        return(84);
    }
    for (string line; getline(inFile,line); )
    {   
        if (adress.noComma(line)==true){
            char err[line.size() + 2];
            strcpy(err,line.c_str());
            fprintf(stderr,err); 
            fprintf(stderr,"\n");
            continue;
            // return(84);
        }
        if (adress.numbersBeforeComma(line)==true){
            char err[line.size() + 2];
            strcpy(err,line.c_str());
            fprintf(stderr,err); 
            fprintf(stderr,"\n");
            continue;
            // return(84);            
        }
        if (adress.notThreeSpaces(line)==true){
            char err[line.size() + 2];
            strcpy(err,line.c_str());
            fprintf(stderr,err); 
            fprintf(stderr,"\n");    
            continue;
            // return(84);            
        }
        // if (adress.numbersAfterTwoSpaces(line)==true){
        //     char err[line.size() + 2];
        //     strcpy(err,line.c_str());
        //     fprintf(stderr,err); 
        //     fprintf(stderr,"\n");
        //     adress.hasBeenAError = true;
        //     continue;
        //     // return(84);            
        // }
        /*
        // if (adress.spaceBeforeComma(line) == true){
        //     char err[line.size() + 2];
        //     strcpy(err,line.c_str());
        //     fprintf(stderr,err); 
        //     fprintf(stderr,"\n");
        //     adress.hasBeenAError = true;
        //     continue;
        //     // return(84);            
        // }*/
        if (adress.wrongStreetTypes(line) == true){
            char err[line.size() + 2];
            strcpy(err,line.c_str());
            fprintf(stderr,err); 
            fprintf(stderr,"\n");
            continue;
            // return(84);            
        }
        if (adress.parsingBegins(line) == 0){
            adress.direction.push_back(adress);
            //adress.dictionary.insert(pair<string, string>(adress.streetName, adress.city));
            //cout << adress.city  << ", " << adress.numberStreet << " " << adress.streetType << " " << adress.streetName << endl; 
        }
    }
    inFile.close();
    adress.countMyCitys();
    adress.orderMyCitys();   
    adress.createDumpVector();
    map<char, int>::iterator it;
    for (it = adress.noDup.begin(); it != adress.noDup.end(); it++){
        int i = 0;
        char print = it->first;
        print = tolower(print);
        cout << "{" << print << "}" << " ";
        i++;
        if (i == 5)
            break;
    }
    /*for (int i = 0; i < adress.cites.size(); i++) {
        string temp = adress.cites.at(i);
        boost::algorithm::to_lower(temp);
        cout << "{" << temp[0] << "}" << " ";
    }*/
    cout << endl;
    string firstSugestion;
    cin >> firstSugestion;
    if (firstSugestion.compare("ABORT") == 0)
        exit(0);
    for (int i = 0; i < adress.cites.size(); i++) {
        string temp = adress.cites.at(i);
        boost::algorithm::to_lower(temp);
        boost::algorithm::to_lower(firstSugestion);
        if (temp[0] == firstSugestion[0]){
            howdy++;
            adress.suggestedCities.push_back(temp);
            if (howdy > 1){
                multipleCities = true;
            }    
        }
    }
    try
    {
        if (multipleCities == true)
        {
            for (int i = 0; i < adress.suggestedCities.size(); i++) {
                string temp = adress.suggestedCities.at(i);
                cout << "{" ;
                putchar(toupper(temp[0]));
                cout << temp[1] << "}" << " ";
            }
            cout << endl;
            cin >> firstSugestion;
            if (firstSugestion.compare("ABORT") == 0)
                exit(0);            
            for (int i = 0; i < adress.suggestedCities.size(); i++) {
                string temp = adress.suggestedCities.at(i);
                if (temp[1] == firstSugestion[0]){
                    adress.comparativeCity = temp;
                    if (adress.secondPhase() == 84)
                        return (84);
                }
            }
        }
        if (multipleCities == false)
        {
        adress.comparativeCity = adress.suggestedCities.at(0);
        if (adress.secondPhase() == 84)
            return (84);
        }
    }    
    catch(const std::out_of_range& e)
    {
        cout << "Unknown address" << endl;
        return (84);
    }
    /*for (auto & elem : adress.countMap){
        cout << elem.first << "::" << elem.second << std::endl;
    }*/
    return(0);
}

int printHelp()
{
    cout << ("USAGE\n\t./autoCompletion dictionary\n\nDESCRIPTION\n\tdictionary\tfile containing one address per line, as knowledge base\n");
    return(0);
}

int main(int ac, char* argv[])
{
    if (ac != 2)
    {
        printHelp();
        return(84);
    }
    else if (strcmp(argv[1], "-h") == 0)
    {
        printHelp();
    }
    else if (ac == 2)
    {
        //bla bla bla codigo
        if (readFile(argv[1]) == 84)
            return(84);
        return (0);
    }
}
