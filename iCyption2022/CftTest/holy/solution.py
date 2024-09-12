ROLES_COUNT = 6
roles = ["Saber", "Lancer", "Archer", "Caster", "Assassin", "Berserker"]

dummyFormation = { "fmt": {}, "value" : 0, "cost" : 0, "cnt": 0}

for role in roles :
    dummyFormation["fmt"][role] = None

heroes = {"Saber" : [], "Lancer" : [], "Archer" : [], "Caster" : [], "Assassin" : [], "Berserker" : []}

n = int(input())

for i in range(n) :
    name, role, skillValue, price = map(str, input().split())
    skillValue, price = int(skillValue), int(price)
    heroes[role].append({"name": name, "role": role, "skillValue": skillValue, "price": price})

budget = int(input())

dpFormation = [dummyFormation for i in range(budget + 1)]

for i in range(ROLES_COUNT) :
    prevDPFormation = dpFormation
    
    for j in range(len(heroes[roles[i]])) :
        currBudget = budget
        currHero = heroes[roles[i]][j]

        while (currBudget >= currHero["price"]) :
            prevFormation = prevDPFormation[currBudget - (currHero["price"])]
            if (prevFormation["cnt"] == i) :
                newFormation = prevFormation
                
                newFormation["fmt"][currHero["role"]] = heroes[roles[i]][j]
                newFormation["value"] += currHero["skillValue"]
                newFormation["cost"] += currHero["price"]
                newFormation["cnt"] += 1

                if ((dpFormation[currBudget]["cnt"] <= i) or (dpFormation[currBudget]["value"] <= newFormation["value"])) :
                    dpFormation[currBudget] = newFormation

            currBudget -= 1

bestFormation = dpFormation[budget]
valid = (True if bestFormation["cnt"] == ROLES_COUNT else False)

if (valid) :
    print(bestFormation["value"])
else :
    print("Tidak bisa ikut :(")