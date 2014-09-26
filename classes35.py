import char
import random


def updateIndex(input, old, new):
    input[input.index(old)] = new


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
    WeaponProficiencies = []
    UnfavoredWeapons = []
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
    BaseAttack = "Good"
    ForbiddenAlignment = ["Lawful"]
    HitDie = 12
    SkillPoints = 4
    ClassSkills = ["Climb", "Craft", "Handle Animal", "Intimidate", "Jump", "Listen", "Ride", "Survival", "Swim"]
    WeaponProficiencies = ["Martial", "Exotic", "Morningstar", "Longspear"]
    UnfavoredWeapons = ["Rapier", "Shortbow", "Composite Shortbow", "Hand Crossbow", "Light Repeating Crossbow", "Heavy Repeating Crossbow"]
    ArmorProficiencies = ["Light", "Medium"]

    def _otherFeatures(self, char):
        level = char.Level
        if level >= 1:
            char.SpecialAbilities.append("Rage(1/day)")
            char.SpecialAbilities.append("Illiteracy")
            char.SpecialAbilities.append("Fast Movement"); char.Race.Speed += 10
        if level >= 2:
            char.SpecialAbilities.append("Uncanny Dodge")
        if level >= 3:
            char.SpecialAbilities.append("Trap Sense +1")
        if level >= 4:
            updateIndex(char.SpecialAbilities, "Rage(1/day)", "Rage(2/day)")
        if level >= 5:
            char.SpecialAbilities.append("Improved Uncanny Dodge")
        if level >= 6:
            updateIndex(char.SpecialAbilities, "Trap Sense +1", "Trap Sense +2")
        if level >= 7:
            char.SpecialAbilities.append("Damage Reduction 1/-"); char.DR.append("1/-")
        if level >= 8:
            updateIndex(char.SpecialAbilities, "Rage(2/day)", "Rage(3/day)")
        if level >= 9:
            updateIndex(char.SpecialAbilities, "Trap Sense +2", "Trap Sense +3")
        if level >= 10:
            updateIndex(char.SpecialAbilities, "Damage Reduction 1/-", "Damage Reduction 2/-")
            updateIndex(char.DR, "1/-", "2/-")
        if level >= 11:
            updateIndex(char.SpecialAbilities, "Rage(3/day)", "Greater Rage(3/day)")
        if level >= 12:
            updateIndex(char.SpecialAbilities, "Greater Rage(3/day)", "Greater Rage(4/day)")
            updateIndex(char.SpecialAbilities, "Trap Sense +3", "Trap Sense +4")
        if level >= 13:
            updateIndex(char.SpecialAbilities, "Damage Reduction 2/-", "Damage Reduction 3/-")
            updateIndex(char.DR, "2/-", "3/-")
        if level >= 14:
            char.SpecialAbilities.append("Indomitable Will")
        if level >= 15:
            updateIndex(char.SpecialAbilities, "Trap Sense +4", "Trap Sense +5")
        if level >= 16:
            updateIndex(char.SpecialAbilities, "Damage Reduction 3/-", "Damage Reduction 4/-")
            updateIndex(char.DR, "3/-", "4/-")
            updateIndex(char.SpecialAbilities, "Greater Rage(4/day)", "Greater Rage(5/day)")
        if level >= 17:
            updateIndex(char.SpecialAbilities, "Greater Rage(5/day)", "Tireless Rage(5/day)")
        if level >= 18:
            updateIndex(char.SpecialAbilities, "Trap Sense +5", "Trap Sense +6")
        if level >= 19:
            updateIndex(char.SpecialAbilities, "Damage Reduction 4/-", "Damage Reduction 5/-")
            updateIndex(char.DR, "4/-", "5/-")
        if level >= 20:
            updateIndex(char.SpecialAbilities, "Tireless Rage(5/day)", "Mighty Rage(6/day)")





