#include <iostream>
#include <string>

using namespace std;

string getArticle(string country)
{
    //input: country without an article
    //output: string corresponding article to the country

    char lastChar = country.at(country.length() - 1);
    string article = "le "; //article defaults to le

    if (lastChar == 'e' || lastChar == 'E')
    {
        if (country != "Belize" && country != "Cambodge" && country != "Mexique" && country != "Mozambique" && country != "Zaïre" && country != "Zimbabwe")
        {
            //if the country ends in e and its not one of the exceptions to the rule,
            //the country is feminine and article should be la
            article = "la ";
        }
    }
    char firstChar = country.at(0);
    //case if first character of country is a vowel
    if (firstChar == 'a' || firstChar == 'A' || firstChar == 'e' || firstChar == 'E' || firstChar == 'I' || firstChar == 'i' || firstChar == 'O' || firstChar == 'o' || firstChar == 'u' || firstChar == 'U')
    {
        article = "l'";
    }

    //two exceptions to above rule (plural countries)
    if (country == "Etats-Unis" || country == "Pays-Bas")
    {
        article = "les ";
    }

    return article;
}

int main()
{
    //prompt user for input
    cout << "Type in the name of a country in French:\n";

    //get input
    string input;
    getline(cin, input);

    //output country with article by calling method
    cout << "With the article, " << input << " is: " << getArticle(input) << input << "\n";

    //end program
    return 0;
}