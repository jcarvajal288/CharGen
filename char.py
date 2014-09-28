import die
import inspect
import random
import skillsPF as skills

def signed(num):
    """returns a string of the given integer and its sign"""
    if num >= 0: return "+%d" % num
    else: return str(num)


def updateIndex(set, oldIndex, newIndex):
    """searches the given list for oldIndex and replaces it with newIndex"""
    if(set.count(oldIndex)) > 0:
        set[set.index(oldIndex)] = newIndex
    else:
        print("ERROR: %s not found!" % (oldIndex))


def _determineName(Race, Gender):
    """generates a random name for a character based on race and gender"""
    #opening text files for reading
    d100 = die.roll('d100')
    if Race == "Human" or (Race == "Half-Elf" and d100 <= 50):
        if Gender == "Male":
            data = open('./CharNames/HumanMaleFirstNames.txt')
        else:
            data = open('./CharNames/HumanFemaleFirstNames.txt')
        data2 = open('./CharNames/HumanLastNames.txt')
    elif Race == "Dwarf":
        if Gender == "Male":
            data = open('./CharNames/DwarfMaleFirstNames.txt')
        else:
            data = open('./CharNames/DwarfFemaleFirstNames.txt')
        data2 = open('./CharNames/DwarfLastNames.txt')
    elif Race == "Elf" or (Race == "Half-Elf" and d100 > 50):
        if Gender == "Male":
            data = open('./CharNames/ElfMaleFirstNames.txt')
        else:
            data = open('./CharNames/ElfFemaleFirstNames.txt')
        data2 = open('./CharNames/ElfLastNames.txt')
    elif Race == "Gnome":
        if Gender == "Male":
            data = open('./CharNames/GnomeMaleFirstNames.txt')
        else:
            data = open('./CharNames/GnomeFemaleFirstNames.txt')
        data2 = open('./CharNames/GnomeLastNames.txt')
    elif Race == "Halfling":
        if Gender == "Male":
            data = open('./CharNames/HalflingMaleFirstNames.txt')
        else:
            data = open('./CharNames/HalflingFemaleFirstNames.txt')
        data2 = open('./CharNames/HalflingLastNames.txt')
    elif Race == "Half-Orc":
        if Gender == "Male":
            data = open('./CharNames/OrcMaleNames.txt')
        else:
            data = open('./CharNames/OrcFemaleNames.txt')
        data2 = open('./CharNames/OrcMaleNames.txt') #Orcs use the first name of their father as their last name   
    else:
        print("ERROR: Invalid race '%s'." % (Race))
        quit()

    #getting data from text files and transferring them into lists
    dataList = data.readlines()
    data.close()
    data2List = data2.readlines()
    data2.close()

    #randomly transferring a name in the lists to variables
    d1 = random.randint(0, len(dataList)-1)
    d2 = random.randint(0, len(data2List)-1)
    firstName = dataList[d1]
    lastName = data2List[d2]

    #stripping null characters from the end of firstName and lastName
    firstName = firstName.rstrip()
    lastName = lastName.rstrip()
    return firstName + " " + lastName


def _rollAbilityScore(numdice=4):
    """Generates a single ability score by rolling the supplied number of dice
    and returning the highest three."""
    rolls = []
    for i in range(numdice):
        rolls.append(die.roll('d6'))
    rolls.sort(reverse=True)
    return sum(rolls[:3])



def rollAbilityScores(numdice=4):
    """returns a list of six ability scores."""
    scores = []
    for i in range(6):
        scores.append(_rollAbilityScore(numdice))
    if max(scores) <= 13 or sum([Character.mod(x) for x in scores]) <= 0:
        # the ability ray does not meet minimum requirements, as outlined in PHB p. 8
        return rollAbilityScores(numdice)
    return scores



def getObject(objectname, filename):
    """Given the name of a object, this function searches through the given file until it 
    finds a class definition with that name, and returns that class.  The given name and 
    the name of the class are both converted into lowercase during comparison so that 
    the comparison is case-insensitive.  If a class with the given name is not found, an 
    error message is printed and the program exits."""

    object_module = __import__(filename)
    objects = dir(object_module)

    if(objectname is 'random'):
        object = getattr(object_module, random.choice(objects))
        # keep selecting if object isn't a class or if it ends up as the base Race class
        while not ((inspect.isclass(object)) and (getattr(object, "Name") is not "")):
            object = getattr(object_module, random.choice(objects))
        return object

    else:
        for name in objects:
            object = getattr(object_module, name)
            if((inspect.isclass(object)) and (getattr(object, "Name").lower() == objectname.lower())):
                return object
        # if the loop terminates, then no object by the given name was found
        else:
            print("Invalid choice '%s'.  Choices are:" % (objectname),)
            for name in objects:
                object = getattr(object_module, name)
                if inspect.isclass(object):
                    print("%s " % (getattr(object, "Name").lower()),)
            quit()



class Character(object):
    def __init__(self, args):
    # set biological and personal stats
        # determine ability scores
        if(args.abilities == 'stdarray'):
            self.AbilityScores = [15,14,13,12,10,8]
        elif(args.abilities == 'low'):
            self.AbilityScores = rollAbilityScores(3)
        elif(args.abilities == 'high'):
            self.AbilityScores = rollAbilityScores(5)
        else:
            self.AbilityScores = rollAbilityScores(4)
        self.AbilityScores.sort(reverse=True)

        # determine gender
        if(args.gender is None):
            if(die.roll('1d4') == 1): self.Gender = 'female'
            else: self.Gender = 'male'
        else: self.Gender = args.gender

        # determine race and class
        # TODO: change the hardcoded filenames
        self.Race = getObject(args.race, 'racesPF')()
        self.Class = getObject(args._class, 'classesPF')()

        # determine name
        if(args.name is None):
            self.Name = _determineName(self.Race.Name, self.Gender)

    # set game stats
        self.Level = args.level
        self.Skills = skills.skillDict
        self.Feats = []
        self.SavingThrows = [0,0,0]
        self.SpecialAbilities = []
        self.DR = [] # lists all the damage reduction the character has
        self.Immune = [] # lists all of a character's immunities

    # start character generation
        self.Race.RacialTraits(self)
        self.Class.apply(self)
        self.spendSkillPoints()


    def Str(self): return self.AbilityScores[0]
    def Dex(self): return self.AbilityScores[1]
    def Con(self): return self.AbilityScores[2]
    def Int(self): return self.AbilityScores[3]
    def Wis(self): return self.AbilityScores[4]
    def Cha(self): return self.AbilityScores[5]

    @staticmethod
    def mod(score): return (score - 10) / 2

    def StrMod(self): return Character.mod(self.AbilityScores[0])
    def DexMod(self): return Character.mod(self.AbilityScores[1])
    def ConMod(self): return Character.mod(self.AbilityScores[2])
    def IntMod(self): return Character.mod(self.AbilityScores[3])
    def WisMod(self): return Character.mod(self.AbilityScores[4])
    def ChaMod(self): return Character.mod(self.AbilityScores[5])


    def spendSkillPoints(self):
        """Spends a character's skill points on a selection of class skills"""
        skills = list(self.Class.ClassSkills)
        random.shuffle(skills)
        for i in range(0, self.Class.SkillPoints + self.IntMod()):
            self.Skills[skills[i]].ranks = self.Level + 3


    def modifySkill(self, name, amount):
        """modifies the skill named <name> by the given amount"""
        self.Skills[name].miscBonus += amount


    def display(self):
        print("Name: %s" % (self.Name))
        print("Race: %s" % (self.Race.Name))
        print("Class: %s" % (self.Class.Name))
        print("")
        print("STR: %d (%s)" % (self.Str(), signed(self.StrMod())))
        print("DEX: %d (%s)" % (self.Dex(), signed(self.DexMod())))
        print("CON: %d (%s)" % (self.Con(), signed(self.ConMod())))
        print("INT: %d (%s)" % (self.Int(), signed(self.IntMod())))
        print("WIS: %d (%s)" % (self.Wis(), signed(self.WisMod())))
        print("CHA: %d (%s)" % (self.Cha(), signed(self.ChaMod())))
        print("")
        print("Ranked Skills:")
        skills = self.Skills.keys()
        skills.sort()
        for name in skills:
            if self.Skills[name].ranks > 0:
                print("\t%s: %s" % (name, signed(self.Skills[name].bonus(self))))
        print("")
        print("Special Abilities:")
        for ability in self.SpecialAbilities:
            print("\t%s" % (ability))

    def summarize(self):
        """Prints a brief summary of the character to standard output"""
        print("%s, Level %d %s %s" % (self.Name, self.Level, self.Race.Adjective, 
                                      self.Class.Name))
