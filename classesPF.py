import char
import random


def updateIndex(input, old, new):
    try: input[input.index(old)] = new
    except ValueError:
        print "Error: %s is not in list" % (old)


# Base Class

class Class(object):
    Name = ""
    Source = "Core"
    Archetype = "Warrior"
    KeyScores = []
    FavoredScores = []
    UnfavoredScores = []
    GoodSaves = []
    BaseAttackMod = 1
    ForbiddenAlignment = []
    RequiredAlignment = []
    HitDie = "d6"
    SkillPoints = 4
    ClassSkills = []
    Feats = [1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11]
    WeaponProficiencies = []
    UnfavoredWeapons = [] # exceptions to any general rules, like 'all simple weapons except X'
    ArmorProficiencies = []

    def _arrangeAbilityScores(self, char):
        """Arranges the character's ability scores in an order beneficial to the class."""
        sortedScores = list(char.AbilityScores)
        arrangedScores = []
        random.shuffle(self.KeyScores)
        random.shuffle(self.FavoredScores)
        random.shuffle(self.UnfavoredScores)
        arrangedScores.extend(self.KeyScores)
        arrangedScores.extend(self.FavoredScores)
        arrangedScores.extend(self.UnfavoredScores)
        char.AbilityScores[0] = sortedScores[arrangedScores.index(0)]
        char.AbilityScores[1] = sortedScores[arrangedScores.index(1)]
        char.AbilityScores[2] = sortedScores[arrangedScores.index(2)]
        char.AbilityScores[3] = sortedScores[arrangedScores.index(3)]
        char.AbilityScores[4] = sortedScores[arrangedScores.index(4)]
        char.AbilityScores[5] = sortedScores[arrangedScores.index(5)]


    def _feats(self, char):
        pass


    def _otherFeatures(self, char):
        """This method will always be overridden by child classes"""
        pass


    def apply(self, char):
        char.Class._arrangeAbilityScores(char)
        char.AbilityScores[char.AbilityScores.index(max(char.AbilityScores))] += char.Level / 4
        char.Class._feats(char)
        char.Class._otherFeatures(char)

# End Base Class



class Barbarian(Class):
    Name = "Barbarian"
    Source = "Core"
    Archetype = "Warrior"
    KeyScores = [0, 2]
    FavoredScores = [1, 4]
    UnfavoredScores = [3, 5]
    GoodSaves = ["Fortitude"]
    BaseAttackMod = 1
    ForbiddenAlignment = ["Lawful"]
    HitDie = 12
    SkillPoints = 4
    ClassSkills = ["Acrobatics", "Climb", "Craft", "Handle Animal", "Intimidate", "Knowledge(nature)", "Perception", "Ride", "Survival", "Swim"]
    WeaponProficiencies = ["Simple", "Martial"]
    ArmorProficiencies = ["Light", "Medium"]

    def _chooseRagePower(self, char, level):
        legalPowers = ["Animal Fury*", "Guarded Stance*", "Intimidating Glare*",
                       "Knockback*", "Moment of Clarity*", "No Escape*", "Powerful Blow*",
                       "Quick Reflexes*", "Raging Climber*", "Raging Leaper*", "Raging Swimmer*",
                       "Rolling Dodge*", "Roused Anger*", "Scent*", "Strength Surge*",
                       "Superstition*", "Surprise Accuracy*", "Swift Foot*"]
        if level >= 4:
            legalPowers.append("Renewed Vigor*")
        if level >= 8:
            legalPowers.extend(["Clear Mind*", "Increased Damage Reduction*",
                                "Internal Fortitude*", "Terrifying Howl*", "Unexpected Strike*"])

        # choose a random power, and return it if the character does not already have it
        # (for simplicity, this ignores powers that can be chosen more than once)
        newPower = random.choice(legalPowers)
        if newPower in char.SpecialAbilities:
            return self._chooseRagePower(char, level)
        else:
            return newPower


    def _otherFeatures(self, char):
        level = char.Level
        if level >= 1:
            char.SpecialAbilities.append("Rage")
            char.SpecialAbilities.append("Fast Movement"); char.Race.Speed += 10
        if level >= 2:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            char.SpecialAbilities.append("Uncanny Dodge")
        if level >= 3:
            char.SpecialAbilities.append("Trap Sense +1")
        if level >= 4:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
        if level >= 5:
            char.SpecialAbilities.append("Improved Uncanny Dodge")
        if level >= 6:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            updateIndex(char.SpecialAbilities, "Trap Sense +1", "Trap Sense +2")
        if level >= 7:
            char.SpecialAbilities.append("Damage Reduction 1/-"); char.DR.append("1/-")
        if level >= 8:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
        if level >= 9:
            updateIndex(char.SpecialAbilities, "Trap Sense +2", "Trap Sense +3")
        if level >= 10:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            updateIndex(char.SpecialAbilities, "Damage Reduction 1/-", "Damage Reduction 2/-")
            updateIndex(char.DR, "1/-", "2/-")
        if level >= 11:
            updateIndex(char.SpecialAbilities, "Rage", "Greater Rage")
        if level >= 12:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            updateIndex(char.SpecialAbilities, "Trap Sense +3", "Trap Sense +4")
        if level >= 13:
            updateIndex(char.SpecialAbilities, "Damage Reduction 2/-", "Damage Reduction 3/-")
            updateIndex(char.DR, "2/-", "3/-")
        if level >= 14:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            char.SpecialAbilities.append("Indomitable Will")
        if level >= 15:
            updateIndex(char.SpecialAbilities, "Trap Sense +4", "Trap Sense +5")
        if level >= 16:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            updateIndex(char.SpecialAbilities, "Damage Reduction 3/-", "Damage Reduction 4/-")
            updateIndex(char.DR, "3/-", "4/-")
        if level >= 17:
            updateIndex(char.SpecialAbilities, "Greater Rage", "Tireless Rage")
        if level >= 18:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            updateIndex(char.SpecialAbilities, "Trap Sense +5", "Trap Sense +6")
        if level >= 19:
            updateIndex(char.SpecialAbilities, "Damage Reduction 4/-", "Damage Reduction 5/-")
            updateIndex(char.DR, "4/-", "5/-")
        if level >= 20:
            char.SpecialAbilities.append(self._chooseRagePower(char, level))
            updateIndex(char.SpecialAbilities, "Tireless Rage", "Mighty Rage")



class Bard(Class):
    Name = "Bard"
    Source = "Core"
    Archetype = "Thief"
    KeyScores = [5]
    FavoredScores = [0, 1, 3]
    UnfavoredScores = [2, 4]
    GoodSaves = ["Reflex", "Will"]
    BaseAttackMod = .75
    HitDie = "d8"
    SkillPoints = 6
    ClassSkills = ["Acrobatics", "Appraise", "Bluff", "Climb", "Craft", "Diplomacy", 
                   "Disguise", "Escape Artist", "Intimidate", "Knowledge(arcana)", 
                   "Knowledge(dungeoneering)", "Knowledge(engineering)", "Knowledge(geography)", 
                   "Knowledge(history)", "Knowledge(local)", "Knowledge(nature)", 
                   "Knowledge(nobility)", "Knowledge(planes)", "Knowledge(religion)", 
                   "Linguistics", "Perception", "Perform", "Profession", "Sense Motive", 
                   "Sleight of Hand", "Spellcraft", "Stealth", "Use Magic Device"]
    WeaponProficiencies = ["Simple", "Longsword", "Rapier", "Sap", "Short Sword", "Shortbow", "Whip"]
    ArmorProficiencies = ["Light", "Shields"]
    SpellsPerDay = [[1, 0, 0, 0, 0, 0],
                    [2, 0, 0, 0, 0, 0],
                    [3, 0, 0, 0, 0, 0],
                    [3, 1, 0, 0, 0, 0],
                    [4, 2, 0, 0, 0, 0],
                    [4, 3, 0, 0, 0, 0],
                    [4, 3, 1, 0, 0, 0],
                    [4, 4, 2, 0, 0, 0],
                    [5, 4, 3, 0, 0, 0],
                    [5, 4, 3, 1, 0, 0],
                    [5, 4, 4, 2, 0, 0],
                    [5, 5, 4, 3, 0, 0],
                    [5, 5, 4, 3, 1, 0],
                    [5, 5, 4, 4, 2, 0],
                    [5, 5, 5, 4, 3, 0],
                    [5, 5, 5, 4, 3, 1],
                    [5, 5, 5, 4, 4, 2],
                    [5, 5, 5, 5, 4, 3],
                    [5, 5, 5, 5, 5, 4],
                    [5, 5, 5, 5, 5, 5]]

    def _otherFeatures(self, char):
        level = char.Level
        if level >= 1:
            char.SpecialAbilities.extend(["Bardic Knowledge",
                                           "Bardic Performance",
                                           "Countersong",
                                           "Distraction",
                                           "Fascinate",
                                           "Inspire Courage +1"])
        if level >= 2:
            char.SpecialAbilities.extend(["Versatile Performance(1)", "Well-Versed"])
        if level >= 3:
            char.SpecialAbilities.append("Inspire Competence +2")
        if level >= 5:
            updateIndex(char.SpecialAbilities, "Inspire Courage +1", "Inspire Courage +2")
            char.SpecialAbilities.append("Lore Master(1/day)")
        if level >= 6:
            char.SpecialAbilities.append("Suggestion")
            updateIndex(char.SpecialAbilities, "Versatile Performance(1)", "Versatile Performance(2)")
        if level >= 7:
            updateIndex(char.SpecialAbilities, "Inspire Competence +2", "Inspire Competence +3")
        if level >= 8:
            char.SpecialAbilities.append("Dirge of Doom")
        if level >= 9:
            char.SpecialAbilities.append("Inspire Greatness")
        if level >= 10:
            char.SpecialAbilities.append("Jack-of-all-Trades")
            updateIndex(char.SpecialAbilities, "Versatile Performance(2)", "Versatile Performance(3)")
        if level >= 11:
            updateIndex(char.SpecialAbilities, "Inspire Competence +3", "Inspire Competence +4")
            updateIndex(char.SpecialAbilities, "Inspire Courage +2", "Inspire Courage +3")
            updateIndex(char.SpecialAbilities, "Lore Master(1/day)", "Lore Master(2/day)")
        if level >= 12:
            char.SpecialAbilities.append("Soothing Performance")
        if level >= 14:
            char.SpecialAbilities.append("Frightening Tune")
            updateIndex(char.SpecialAbilities, "Versatile Performance(3)", "Versatile Performance(4)")
        if level >= 15:
            updateIndex(char.SpecialAbilities, "Inspire Competence +4", "Inspire Competence +5")
            char.SpecialAbilities.append("Inspire Heroics")
        if level >= 17:
            updateIndex(char.SpecialAbilities, "Inspire Courage +3", "Inspire Courage +4")
            updateIndex(char.SpecialAbilities, "Versatile Performance(4)", "Versatile Performance(5)")
        if level >= 18:
            char.SpecialAbilities.append("Mass Suggestion")
            updateIndex(char.SpecialAbilities, "Versatile Performance(5)", "Versatile Performance(6)")
        if level >= 19:
            updateIndex(char.SpecialAbilities, "Inspire Competence +5", "Inspire Competence +6")
        if level >= 20:
            char.SpecialAbilities.append("Deadly Performance")



class Cleric(Class):
    Name = "Cleric"
    Source = "Core"
    Archetype = "Priest"
    KeyScores = [4]
    FavoredScores = [5, 0, 2]
    UnfavoredScores = [1, 3]
    GoodSaves = ["Fortitude", "Will"]
    BaseAttackMod = .75
    HitDie = 8
    SkillPoints = 2
    ClassSkills = ["Appraise", "Craft", "Diplomacy", "Heal", "Knowledge(arcana)",
                   "Knowledge(history)", "Knowledge(nobility)", "Knowledge(planes)",
                   "Knowledge(religion)", "Linguistics", "Profession", "Sense Motive",
                   "Spellcraft"]
    WeaponProficiencies = ["Simple"]
    ArmorProficiencies = ["Light", "Medium", "Shields"]
    SpellsPerDay = [[3, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                    [4, 2, 0, 0, 0, 0, 0, 0, 0, 0],
                    [4, 2, 1, 0, 0, 0, 0, 0, 0, 0],
                    [4, 3, 2, 0, 0, 0, 0, 0, 0, 0],
                    [4, 3, 2, 1, 0, 0, 0, 0, 0, 0],
                    [4, 3, 3, 2, 0, 0, 0, 0, 0, 0],
                    [4, 4, 3, 2, 1, 0, 0, 0, 0, 0],
                    [4, 4, 3, 3, 2, 0, 0, 0, 0, 0],
                    [4, 4, 4, 3, 2, 1, 0, 0, 0, 0],
                    [4, 4, 4, 3, 3, 2, 0, 0, 0, 0],
                    [4, 4, 4, 4, 3, 2, 1, 0, 0, 0],
                    [4, 4, 4, 4, 3, 3, 2, 0, 0, 0],
                    [4, 4, 4, 4, 4, 3, 2, 1, 0, 0],
                    [4, 4, 4, 4, 4, 3, 3, 2, 0, 0],
                    [4, 4, 4, 4, 4, 4, 3, 2, 1, 0],
                    [4, 4, 4, 4, 4, 4, 3, 3, 2, 0],
                    [4, 4, 4, 4, 4, 4, 4, 3, 2, 1],
                    [4, 4, 4, 4, 4, 4, 4, 3, 3, 2],
                    [4, 4, 4, 4, 4, 4, 4, 4, 3, 3],
                    [4, 4, 4, 4, 4, 4, 4, 4, 4, 4]]

    def _chooseDeity(self, char):
        # TODO: write deity and domain choosing code
        pass

    def _otherFeatures(self, char):
        _chooseDeity(char)
        char.SpecialAbilities.extend(["Aura", "Channel Energy %dd6" % ((char.Level/2)+1)])
