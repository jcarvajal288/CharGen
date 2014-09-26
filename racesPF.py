"""
Race specifications for Pathfinder
"""
import random


# Base class
class Race(object):
    Name = ""
    Adjective = "" # Elven, Dwarven, etc.
    Type = "" # Genus of the race.  Most races here will be humanoid
    Subtype = "" # Species of the race.  Human, Elf, etc.
    Source = "" # What rule book the race comes from.
    LevelAdjustment = 0
    FavoredClass = "Any"
    Languages = ["Common"]
    BonusLanguages = []
    SizeMod = 0 # Most characters are assumed to be medium size (with a size modifier of 0)
    Speed = 30 # Most characters are assumed to have speed 30
    Senses = "" # Low-light vision, darkvision, etc.
    FavoredAlignments = []
    AlignmentBias = "" # How strictly the race adheres to its favored alignments ("Often", "Usually", "Always")
    WeaponProficiencies = []
    WeaponFamiliarity = [] # exotic weapons that this race treats as martial
    
    def RacialTraits(self, char):
        pass

# End Base class


class Dwarf(Race):
    Name = "Dwarf"
    Adjective = "Dwarven"
    Type = "Humanoid"
    Subtype = "Dwarf"
    Source = "Core"
    Languages = ["Common", "Dwarven"]
    BonusLanguages = ["Giant", "Gnome", "Goblin", "Orc", "Terran", "Undercommon"]
    Speed = 20
    Senses = "Darvision 60 ft."
    FavoredAlignments = ["Lawful"]
    AlignmentBias = "Often"
    WeaponProficiencies = ["Battleaxe", "Heavy Pick", "Warhammer"]
    WeaponFamiliarity = ["Dwarven Waraxe", "Dwarven Urgrosh"]
        
    def RacialTraits(self, char):
        # add +2 to Con and Wis, -2 to Cha
        char.AbilityScores[2] += 2
        char.AbilityScores[4] += 2
        char.AbilityScores[5] -= 2
        


class Elf(Race):
    Name = "Elf"
    Adjective = "Elven"
    Type = "Humanoid"
    Subtype = "Elf"
    Source = "Core"
    Languages = ["Common", "Elven"]
    BonusLanguages = ["Celestial", "Draconic", "Gnoll", "Gnome", "Goblin", "Orc", "Sylvan"]
    Senses = "Low-Light Vision"
    Speed = 30
    FavoredAlignments = ["Chaotic", "Good"]
    AlignmentBias = "Usually"
    WeaponProficiencies = ["Shortbow", "Composite Shortbow", "Longbow", "Composite Longbow", "Longsword", "Rapier"]
        
    def RacialTraits(self, char):
        # add +2 to Dex and Int, -2 to Con
        char.AbilityScores[1] += 2
        char.AbilityScores[3] += 2
        char.AbilityScores[2] -= 2
        char.Skills["Perception"].miscBonus += 2
        char.Immune.append("Sleep")



class Gnome(Race):
    Name = "Gnome"
    Adjective = "Gnome"
    Type = "Humanoid"
    Subtype = "Gnome"
    Source = "Core"
    Languages = ["Common", "Gnome", "Sylvan"]
    BonusLanguages = ["Draconic", "Dwarven", "Elven", "Giant", "Goblin", "Orc"]
    SizeMod = 1
    Speed = 20
    Senses = "Low-Light Vision"
    FavoredAlignments = ["Good"]
    AlignmentBias = "Usually"
    WeaponFamiliarity = ["Gnome Hooked Hammer"]
        
    def RacialTraits(self, char):
        # add +2 to Con and Cha, -2 to Str
        char.AbilityScores[2] += 2
        char.AbilityScores[5] += 2
        char.AbilityScores[0] -= 2
        char.Skills["Perception"].miscBonus += 2
        if random.randint(0,1):
            char.Skills["Craft"].miscBonus += 2
        else:
            char.Skills["Profession"].miscBonus += 2
        char.SpecialAbilities.append("Speak with Animals(1/day)")
        if char.AbilityScores[5] >= 11:
            char.SpecialAbilities.extend(["Dancing Lights(1/day)", "Ghost Sound(1/day)", "Prestidigitation(1/day)"])

            

class HalfElf(Race):
    Name = "Half-Elf"
    Adjective = "Half-Elven"
    Type = "Humanoid"
    Subtype = "Elf"
    Source = "Core"
    Speed = 30
    Languages = ["Common", "Elven"]
    BonusLanguages = ["Dwarven", "Elven", "Halfling", "Gnome", "Orc", "Goblin", "Undercommon", "Abyssal", \
                           "Celestial", "Infernal", "Draconic", "Terran", "Sylvan"] #more will be added
    Senses = "Low-Light Vision"
    FavoredAlignments = ["Chaotic", "Good"]
    AlignmentBias = "Usually"
        
    def RacialTraits(self, char):
        # +2 to the half-elf's highest ability score
        char.AbilityScores[char.AbilityScores.index(max(char.AbilityScores))] += 2
        char.Skills["Perception"].miscBonus += 2
        char.Immune.append("Sleep")

        

class HalfOrc(Race):
    Name = "Half-Orc"
    Adjective = "Half-Orc"
    Type = "Humanoid"
    Subtype = "Orc"
    Source = "Core"
    Languages = ["Common", "Orc"]
    BonusLanguages = ["Abyssal", "Draconic", "Giant", "Gnoll", "Goblin"]
    Senses = "Darkvision 60 ft."
    Speed = 30
    FavoredAlignments = ["Chaotic"]
    AlignmentBias = "Usually"
    WeaponProficiencies = ["Greataxe", "Falchion"]
    WeaponFamiliarity = ["Orc Double Axe"]
        
    def RacialTraits(self, char):
        # +2 to the half-orc's highest ability score
        char.AbilityScores[char.AbilityScores.index(max(char.AbilityScores))] += 2
        char.Skills["Intimidate"].miscBonus += 2



class Halfling(Race):
    Name = "Halfling"
    Adjective = "Halfling"
    Type = "Humanoid"
    Subtype = "Halfling"
    Source = "Core"
    Languages = ["Common", "Halfling"]
    BonusLanguages = ["Dwarven", "Elven", "Gnome", "Goblin"]
    SizeMod = 1
    Speed = 20
    FavoredAlignments = ["Neutral"]
    AlignmentBias = "Often"
    WeaponProficiencies = ["Sling"]
        
    def RacialTraits(self, char):
        # +2 to Dex and Cha, -2 to Str
        char.AbilityScores[1] += 2
        char.AbilityScores[5] += 2
        char.AbilityScores[0] -= 2
        # +1 to each saving throw
        for save in char.SavingThrows:
            save += 1
        char.Skills["Perception"].miscBonus += 2
        char.Skills["Acrobatics"].miscBonus += 2
        char.Skills["Climb"].miscBonus += 2

        
        
class Human(Race):
    Name = "Human"
    Adjective = "Human"
    Type = "Humanoid"
    Subtype = "Human"
    Source = "Core"
    Speed = 30
    FavoredClass = "Any"
    Languages = ["Common"]
    BonusLanguages = ["Dwarven", "Elven", "Halfling", "Gnome", "Orc", "Goblin", "Undercommon", "Abyssal", \
                           "Celestial", "Infernal", "Draconic", "Terran", "Sylvan"] #more will be added
        
    def RacialTraits(self, char):
        # +2 to the human's highest ability score
        char.AbilityScores[char.AbilityScores.index(max(char.AbilityScores))] += 2
        # +1 skill point
        for i in char.Class.Feats:
            char.Class.Feats[i] += 1

            
