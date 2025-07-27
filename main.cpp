#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <thread>
#include <string>

using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int time_between_messages_ms = 300;
long long wins = 0, losses = 0, ties = 0;

void print(const string& s) {
    this_thread::sleep_for(chrono::milliseconds(time_between_messages_ms));
    for (auto i : s) {
        this_thread::sleep_for(chrono::milliseconds(16));
        cout << i;
    }
}

int main() {
    vector<string> items = {"Rock", "Paper", "Scissors"};
    print("WELCOME TO THE ROCK PAPER SCISSORS GAME!\n\n");
    long long turn = 1;
    while (true) {
        print("Turn #" + to_string(turn) + "\n");
        print("Please, type an integer from 1 to 3:\n1, if you want to choose Rock\n2, if you want to choose Paper\n3, if you want to choose Scissors\n");
        string choice;
        cin >> choice;
        set<string> possible_choices = {"1", "2", "3"};
        while (!possible_choices.count(choice)) {
            cout << "Please, type only an integer from 1 to 3:\n";
            cin >> choice;
        }
        int id = stoi(choice) - 1;
        print("You choose " + items[id] + ".\n");
        int random_num = rnd() % 100;
        if (random_num < 33) {
            print("Your opponent chooses " + items[(id + 2) % 3] + ".\n");
            print("You WON! :)\n");
            wins ++;
        } else if (random_num < 67) {
            print("Your opponent chooses " + items[(id + 1) % 3] + ".\n");
            print("You LOST! :(\n");
            losses++;
        } else {
            print("Your opponent chooses " + items[id] + ".\n");
            print("TIE. :|\n");
            ties++;
        }
        print("Statistics: \n" + to_string(wins) + " wins\n" + to_string(losses) + " losses\n" + to_string(ties) + " ties\n\n\n\n");
        this_thread::sleep_for(chrono::milliseconds(1000));
        turn++;
    }
    return 0;
}
