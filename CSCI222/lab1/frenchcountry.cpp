#include <iostream>
#include <string>

using namespace std;

string getArticle(string country)
{
    char lastChar = country.at(country.length() - 1);
    string article = "le ";
    if (lastChar == 'e' || lastChar == 'E')
    {
        if (country != "Belize" && country != "Cambodge" && country != "Mexique" && country != "Mozambique" && country != "Zaïre" && country != "Zimbabwe")
        {
            article = "la ";
        }
    }
    char firstChar = country.at(0);
    if (firstChar == 'a' || firstChar == 'A' || firstChar == 'e' || firstChar == 'E' || firstChar == 'I' || firstChar == 'i' || firstChar == 'O' || firstChar == 'o' || firstChar == 'u' || firstChar == 'U')
    {
        article = "l'";
    }
    if (country == "Etats-Unis" || country == "Pays-Bas")
    {
        article = "les ";
    }

    return article;
}

int main()
{
    cout << "Type in the name of a country in French:\n";

    string input;
    getline(cin, input);

    cout << "With the article, " << input << " is: " << getArticle(input) << input << "\n";
    return 0;
}