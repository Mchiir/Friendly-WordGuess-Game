#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <unordered_set>

#include "Animals.cpp"
#include "Districts.cpp"
#include "Films.cpp"
#include "Books.cpp"
#include "Teams.cpp"

using namespace std;

enum Category
{
    ANIMALS = 1,
    DISTRICTS,
    FILMS,
    BOOKS,
    TEAMS
};

void playGame(const vector<string> &words)
{
    string selectedWord = words[rand() % words.size()];
    string guessedWord(selectedWord.size(), '_');
    int attempts = 6;
    unordered_set<char> guessedLetters;
    char guess;

    cout << "Guess the word: " << guessedWord << endl;

    while (attempts > 0 && guessedWord != selectedWord)
    {
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Enter a letter (or type 'exit' to quit): ";
        string input;
        cin >> input;

        if (input == "exit")
        {
            Sleep(1000);
            cout << "Thanks for playing!" << endl;
            exit(0);
        }
        else if (input.length() != 1)
        {
            Sleep(700);
            cout << "Please enter a single letter." << endl;
            continue;
        }

        guess = input[0];

        // Checking if the letter has already been guessed
        if (guessedLetters.count(guess) > 0)
        {
            Sleep(500);
            cout << "You have already guessed that letter!" << endl;
            continue;
        }

        guessedLetters.insert(guess);
        bool found = false;

        for (size_t i = 0; i < selectedWord.size(); ++i)
        {
            if (selectedWord[i] == guess)
            {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (!found)
        {
            --attempts;
            Sleep(1000);
            cout << "Incorrect guess!" << endl;
        }

        cout << "Current word: " << guessedWord << endl;
    }

    if (guessedWord == selectedWord)
    {
        cout << "Congratulations! You've guessed the word: " << selectedWord << endl;
        Sleep(2000);
    }
    else
    {
        cout << "Out of attempts! The word was: " << selectedWord << endl;
        Sleep(2000);
    }
}

int main()
{
    cout << "\nWelcome to Word guess game!\n"
         << endl;
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    vector<string> animals = {
        "Dog", "Cow", "Cat", "Horse",
        "Donkey", "Tiger", "Lion", "Panther",
        "Leopard", "Cheetah", "Bear", "Elephant",
        "Polar bear", "Turtle", "Tortoise", "Crocodile",
        "Rabbit", "Porcupine", "Hare", "Hen",
        "Pigeon", "Albatross", "Crow", "Fish",
        "Dolphin", "Frog", "Whale", "Alligator",
        "Eagle", "Flying squirrel", "Ostrich", "Fox",
        "Goat", "Jackal", "Emu", "Armadillo",
        "Eel", "Goose", "Arctic fox", "Wolf",
        "Beagle", "Gorilla", "Chimpanzee", "Monkey",
        "Beaver", "Orangutan", "Antelope", "Bat",
        "Badger", "Giraffe", "Hermit Crab", "Giant Panda",
        "Hamster", "Cobra", "Hammerhead shark", "Camel",
        "Hawk", "Deer", "Chameleon", "Hippopotamus",
        "Jaguar", "Chihuahua", "King Cobra", "Ibex",
        "Lizard", "Koala", "Kangaroo", "Iguana",
        "Llama", "Chinchillas", "Dodo", "Jellyfish",
        "Rhinoceros", "Hedgehog", "Zebra", "Possum",
        "Wombat", "Bison", "Bull", "Buffalo",
        "Sheep", "Meerkat", "Mouse", "Otter",
        "Sloth", "Owl", "Vulture", "Flamingo",
        "Racoon", "Mole", "Duck", "Swan",
        "Lynx", "Monitor lizard", "Elk", "Boar",
        "Lemur", "Mule", "Baboon", "Mammoth",
        "Blue whale", "Rat", "Snake", "Peacock"};

    vector<string> districts = {
        "Bugesera", "Gatsibo", "Kayonza", "Kirehe",
        "Ngoma", "Nyagatare", "Rwamagana", "Gasabo",
        "Kicukiro", "Nyarugenge", "Burera", "Gakenke",
        "Gicumbi", "Musanze", "Rulindo", "Gisagara",
        "Huye", "Kamonyi", "Muhanga", "Nyamagabe",
        "Nyanza", "Nyaruguru", "Ruhango", "Karongi",
        "Ngororero", "Nyabihu", "Nyamasheke", "Rubavu",
        "Rusizi", "Rutsiro"};

    vector<string> films = {
        "The Godfather", "The Shawshank Redemption", "Schindler's List",
        "Raging Bull", "Casablanca", "Citizen Kane", "Gone with the Wind",
        "The Wizard of Oz", "One Flew Over the Cuckoo's Nest",
        "Lawrence of Arabia", "Vertigo", "Psycho", "The Godfather Part II",
        "On the Waterfront", "Sunset Boulevard", "Forrest Gump",
        "The Sound of Music", "12 Angry Men", "West Side Story",
        "Star Wars: Episode IV - A New Hope", "2001: A Space Odyssey",
        "E.T. the Extra-Terrestrial", "The Silence of the Lambs", "Chinatown",
        "The Bridge on the River Kwai", "Singin' in the Rain",
        "It's a Wonderful Life", "Dr. Strangelove or: How I Learned to Stop Worrying and Love the Bomb",
        "Some Like It Hot", "Ben-Hur", "Apocalypse Now", "Amadeus",
        "The Lord of the Rings: The Return of the King", "Gladiator",
        "Titanic", "From Here to Eternity", "Saving Private Ryan",
        "Unforgiven", "Raiders of the Lost Ark", "Rocky",
        "A Streetcar Named Desire", "The Philadelphia Story",
        "To Kill a Mockingbird", "An American in Paris",
        "The Best Years of Our Lives", "My Fair Lady",
        "A Clockwork Orange", "Doctor Zhivago", "The Searchers",
        "Jaws", "Patton", "Butch Cassidy and the Sundance Kid",
        "The Treasure of the Sierra Madre", "The Good, the Bad and the Ugly",
        "The Apartment", "Platoon", "High Noon", "Braveheart",
        "Dances with Wolves", "Jurassic Park", "The Exorcist",
        "The Pianist", "Goodfellas", "The Deer Hunter",
        "All Quiet on the Western Front", "Bonnie and Clyde",
        "The French Connection", "City Lights", "It Happened One Night",
        "A Place in the Sun", "Midnight Cowboy", "Mr. Smith Goes to Washington",
        "Rain Man", "Annie Hall", "Fargo", "Giant", "Shane",
        "The Grapes of Wrath", "The Green Mile", "Close Encounters of the Third Kind",
        "Nashville", "Network", "The Graduate", "American Graffiti",
        "Pulp Fiction", "Terms of Endearment", "Good Will Hunting",
        "The African Queen", "Stagecoach", "Mutiny on the Bounty",
        "The Great Dictator", "Double Indemnity", "The Maltese Falcon",
        "Wuthering Heights", "Taxi Driver", "Rear Window",
        "The Third Man", "Rebel Without a Cause", "North by Northwest",
        "Yankee Doodle Dandy"};

    vector<string> books = {
        "Funny Story", "The Women", "Just for the Summer", "First Lie Wins",
        "The Teacher", "House of Flame and Shadow", "Bride",
        "The Housemaid Is Watching", "The Paradise Problem",
        "When the Moon Hatched", "The God of the Woods", "Reckless",
        "This Summer Will Be Different", "Listen for the Lie", "Heartless Hunter",
        "The Fury", "A Fate Inked in Blood", "Home Is Where the Bodies Are",
        "All the Colors of the Dark", "Wild Love", "The Wedding People",
        "King of Sloth", "The Midnight Feast", "The Reappearance of Rachel Price",
        "Blue Sisters", "Intermezzo", "The Boyfriend", "If Only I Had Told Her",
        "The Familiar", "Not in Love", "Honeymoon", "Fifty Lies",
        "The Girl Who Cried Wolf", "The Forgotten Ones", "The Secrets We Keep",
        "Falling Stars", "Not Enough", "The Ones That Got Away",
        "Lost and Found", "Someone Like You", "Nightingale",
        "The Key", "The Boyfriend", "Never Too Late", "Someone Like Me",
        "The Bride", "Love and Lost", "In the Shadows", "Twilight Story",
        "Where I Found You", "A Time to Love", "Chasing Clouds",
        "The Girl with the Red Shoes", "Love Is All You Need",
        "The Girl Who Knew Too Much", "The Little Things",
        "The Road to Yesterday", "Without You", "The Unexpected Family",
        "Wanderlust", "Just Friends", "The Dance",
        "The Key to Your Heart", "The One Who Got Away",
        "Someone to Trust", "The Hardest Goodbye"};

    vector<string> teams = {
        "Manchester United", "Real Madrid", "Barcelona", "Arsenal",
        "Chelsea", "Bayern Munich", "Juventus", "Manchester City",
        "Liverpool", "AC Milan", "Inter Milan", "Paris Saint-Germain",
        "Borussia Dortmund", "Atletico Madrid", "Napoli", "FC Porto",
        "Benfica", "Ajax", "Tottenham Hotspur", "Lazio",
        "Sevilla", "Olympique Lyonnais", "RB Leipzig", "Valencia",
        "AS Roma", "West Ham United", "Everton", "Leicester City",
        "Southampton", "Villarreal", "Real Betis", "Celtic",
        "Rangers", "Newcastle United", "Fulham", "Burnley",
        "Wolverhampton Wanderers", "Crystal Palace", "Sheffield United",
        "Brighton & Hove Albion", "Bournemouth", "Nottingham Forest",
        "Lille OSC", "Marseille", "Monaco", "Saint-Étienne",
        "Athletic Bilbao", "Real Sociedad", "Villarreal", "Real Betis",
        "Celta Vigo", "Getafe", "Levante", "Granada", "Osasuna",
        "Alaves", "Cadiz", "Elche", "Espanyol"};

    int categoryChoice;

    do
    {
        cout << "Please choose a category from which to guess names." << endl;
        cout << "1. Animals" << endl;
        cout << "2. Districts" << endl;
        cout << "3. Films" << endl;
        cout << "4. Books" << endl;
        cout << "5. Teams" << endl;
        cout << "6. Exit" << endl;
        Sleep(500);
        cout << "Enter your choice number: ";
        cin >> categoryChoice;

        switch (categoryChoice)
        {
        case ANIMALS:
            playGame(animals);
            break;
        case DISTRICTS:
            playGame(districts);
            break;
        case FILMS:
            playGame(films);
            break;
        case BOOKS:
            playGame(books);
            break;
        case TEAMS:
            playGame(teams);
            break;
        case 6:
            cout << "Thanks for playing!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            return 1;
        }

        char choice;
        cout << "Continue? [y/n]: ";
        cin >> choice;
        if (choice != 'y'){
            cout << "\nProgram exiting...\nThanks for playing" << endl;
            return 0;
        }
    } while (categoryChoice != 6);

    return 0;
}