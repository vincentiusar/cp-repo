#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct hero {
    string name;
    string role;
    int skillValue;
    int price;
};

typedef struct hero *ptrHero;

struct formation {
    map<string, ptrHero> fmt;
    int value = 0;
    int cost = 0;
    int cnt = 0;
};

const int ROLES_COUNT = 6;
const string roles[ROLES_COUNT] = { "Saber", "Lancer", "Archer", "Caster", "Assassin", "Berserker" };

int main() {
    int n;
    int budget, skillValue, price;

    formation dummyFormation;
    for (string role : roles) dummyFormation.fmt[role] = nullptr;

    string name, role;

    map<string, vector<hero>> heroes;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name >> role >> skillValue >> price;
        heroes[role].push_back({name, role, skillValue, price});
    }
    
    cin >> budget;

    vector<formation> dpFormations(budget + 1, dummyFormation);

    for (int i = 0; i < ROLES_COUNT; i++) {
        vector<formation> prevDPFormations(dpFormations);

        for (int j = 0; j < (int)heroes[roles[i]].size(); j++) {
            int currBudget = budget;
            hero currHero = heroes[roles[i]][j];

            while (currBudget >= currHero.price) {
                formation prevFormation = prevDPFormations[currBudget - (currHero.price)];
                if (prevFormation.cnt == i) {
                    formation newFormation = prevFormation;

                    newFormation.fmt[currHero.role] = &heroes[roles[i]][j];
                    newFormation.value += currHero.skillValue;
                    newFormation.cost += (currHero.price);
                    newFormation.cnt++;

                    if ((dpFormations[currBudget].cnt <= i) || (dpFormations[currBudget].value <= newFormation.value)) {
                        dpFormations[currBudget] = newFormation;
                    }
                }

                currBudget--;
            }
        }
    }

    formation bestFormation;

    bestFormation = dpFormations[budget];
    bool valid = bestFormation.cnt == ROLES_COUNT;

    if (valid) {
        cout << bestFormation.value << endl;
    } else {
        cout << "Tidak bisa ikut :(" << endl;
    }
}