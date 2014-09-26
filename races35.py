"""
Race specifications for D&D 3.5
"""


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
    
    def RacialTraits(self, newChar):
        pass

# End Base class



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
        
    def RacialTraits(self, newChar):
        newChar.SkillPoints += 4 + (newChar.Level - 1)
        for i in newChar.Class.Feats:
            newChar.Class.Feats[i] += 1

            
class Dwarf(Race):
    Name = "Dwarf"
    Adjective = "Dwarven"
    Type = "Humanoid"
    Subtype = "Dwarf"
    Source = "Core"
    FavoredClass = "Fighter"
    Languages = ["Common", "Dwarven"]
    BonusLanguages = ["Giant", "Gnome", "Orc", "Terran", "Undercommon"]
    Speed = 20
    Senses = "Darvision 60 ft."
    FavoredAlignments = ["Lawful"]
    AlignmentBias = "Often"
    WeaponFamiliarity = ["Dwarven Waraxe", "Dwarven Urgrosh"]
        
    def RacialTraits(self, newChar):
        newChar.Con += 2; newChar.ConMod += 1
        newChar.Cha -= 2; newChar.ChaMod -= 1
        

class Elf(Race):
    Name = "Elf"
    Adjective = "Elven"
    Type = "Humanoid"
    Subtype = "Elf"
    Source = "Core"
    FavoredClass = "Wizard"
    Languages = ["Common", "Elven"]
    BonusLanguages = ["Draconic", "Gnoll", "Gnome", "Goblin", "Orc", "Sylvan"]
    Senses = "Low-Light Vision"
    Speed = 30
    FavoredAlignments = ["Chaotic", "Good"]
    AlignmentBias = "Usually"
    WeaponProficiencies = ["Shortbow", "Composite Shortbow", "Longbow", "Composite Longbow", "Longsword", "Rapier"]
        
    def RacialTraits(self, newChar):
        applySkillBonus(["Listen", "Search", "Spot"], 2, newChar) #needs to add 2 to Listen, Search, and Spot
        newChar.Dex += 2; newChar.DexMod += 1
        newChar.Con -= 2; newChar.ConMod -= 1
        newChar.Immune.append("Sleep")

        
class Gnome(Race):
    Name = "Gnome"
    Adjective = "Gnome"
    Type = "Humanoid"
    Subtype = "Gnome"
    Source = "Core"
    FavoredClass = "Bard"
    Languages = ["Common", "Gnome"]
    BonusLanguages = ["Draconic", "Dwarven", "Elven", "Giant", "Goblin", "Orc"]
    SizeMod = 1
    Speed = 20
    Senses = "Low-Light Vision"
    FavoredAlignments = ["Good"]
    AlignmentBias = "Usually"
    WeaponFamiliarity = ["Gnome Hooked Hammer"]
        
    def RacialTraits(self, newChar):
        newChar.Con += 2; newChar.ConMod += 1
        newChar.Str -= 2; newChar.StrMod -= 1
        newChar.SpecialAbilities.append("Speak with Animals(1/day)")
        if newChar.Cha >= 10:
            newChar.SpecialAbilities.append("Dancing Lights(1/day)", "Ghost Sound(1/day)", "Prestidigitation(1/day)")

            
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
    FavoredAlignments = ["Chaotic"]
    AlignmentBias = "Usually"
        
    def RacialTraits(self, newChar):
        applySkillBonus(["Listen", "Search", "Spot"], 1, newChar)   #needs to add 1 to Listen, Search, and Spot; +2 to Diplomacy and Gather Information
        applySkillBonus(["Diplomacy", "Gather Information"], 1, newChar)
        newChar.Dex += 2; newChar.DexMod += 1
        newChar.Con -= 2; newChar.ConMod -= 1
        newChar.Immune.append("Sleep")

        
class HalfOrc(Race):
    Name = "Half-Orc"
    Adjective = "Half-Orc"
    Type = "Humanoid"
    Subtype = "Orc"
    Source = "Core"
    FavoredClass = "Barbarian"
    Languages = ["Common", "Orc"]
    BonusLanguages = ["Draconic", "Giant", "Gnoll", "Goblin", "Abyssal"]
    Senses = "Darkvision 60 ft."
    Speed = 30
    FavoredAlignments = ["Chaotic"]
    AlignmentBias = "Usually"
        
    def RacialTraits(self, newChar):
        newChar.Str += 2; newChar.StrMod += 1
        newChar.Int -= 2; newChar.IntMod -= 1
        newChar.Cha -= 2; newChar.ChaMod -= 1

        
class Halfling(Race):
    Name = "Halfling"
    Adjective = "Halfling"
    Type = "Humanoid"
    Subtype = "Halfling"
    Source = "Core"
    FavoredClass = "Rogue"
    Languages = ["Common", "Halfling"]
    BonusLanguages = ["Dwarven", "Elven", "Gnome", "Goblin", "Orc"]
    SizeMod = 1
    Speed = 20
    FavoredAlignments = ["Neutral"]
    AlignmentBias = "Often"
    WeaponFamiliarity = ["Gnome Hooked Hammer"]
        
    def RacialTraits(self, newChar):
        applySkillBonus(["Climb", "Jump", "Move Silently"], 2, newChar)  # +2 to Climb, Jump, Move Silently
        newChar.Dex += 2; newChar.DexMod += 1
        newChar.Str -= 2; newChar.StrMod -= 1
        newChar.FortSave += 1; newChar.RefSave += 1; newChar.WillSave += 1
