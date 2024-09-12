from copy import deepcopy

class Hero:
    def __init__(self, name="", role="", skillValue=0, price=0):
        self.name = name
        self.role = role
        self.skillValue = skillValue
        self.price = price

class Formation:
    def __init__(self, fmt={}, value=0, cost=0, cnt=0):
        self.fmt = fmt
        self.value = value
        self.cost = cost
        self.cnt = cnt

ROLES_COUNT = 6
roles = ['Saber', 'Lancer', 'Archer', 'Caster', 'Assassin', 'Berserker']

n = int(input())

heroes = {}
for role in roles: heroes[role] = []

for i in range(n):
    name, role, skillValue, price = map(str, input().split())
    skillValue, price = int(skillValue), int(price)
    heroes[role].append(Hero(name, role, skillValue, price))

budget = int(input())

dpFormations = [Formation() for i in range(budget + 1)]
for i in range(ROLES_COUNT):
    prevDPFormations = deepcopy(dpFormations)
    for curHero in heroes[roles[i]]:
        for b in range(curHero.price, budget + 1):
            prevFormation = deepcopy(prevDPFormations[b - curHero.price])
            if prevFormation.cnt == i:
                newFormation = deepcopy(prevFormation)
                newFormation.fmt[curHero.role] = curHero
                newFormation.value += curHero.skillValue
                newFormation.cost += curHero.price
                newFormation.cnt += 1
                if dpFormations[b].cnt <= i or newFormation.value > dpFormations[b].value:
                    dpFormations[b] = newFormation

bestFormation = dpFormations[budget]
valid = bestFormation.cnt == ROLES_COUNT

print(bestFormation.value if valid else "Tidak bisa ikut :(")
