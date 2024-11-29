#pragma once

#include <string>
#include <vector>
#include <iostream>

class Sim {
private:
    std::string name;
    int age;

public:
    Sim(const std::string& name, int age);
    void dive();
    void learnMarineBiology();
};

class MarineLife;

class Creature {
protected:
    std::string name;
    int age;

public:
    Creature(const std::string& name, int age);
    virtual void swim();
    virtual void interactWith(Sim& sim);
    virtual void bondWith(Sim& sim);
    virtual ~Creature() = default;
};

class AquaticCreature : public Creature {
protected:
    std::string habitat;

public:
    AquaticCreature(const std::string& name, int age, const std::string& habitat);
    virtual ~AquaticCreature() = default;
};

class Dolphin : public AquaticCreature {
private:
    int intelligence_level;

public:
    Dolphin(const std::string& name, int age, const std::string& habitat, int intelligence_level);
    void communicate() const;
};

class Fish : public AquaticCreature {
private:
    std::string species;

public:
    Fish(const std::string& name, int age, const std::string& habitat, const std::string& species);
    void schooling() const;
};

class SeaPlant : public AquaticCreature {
private:
    std::string plantType;
    float growthRate;

public:
    SeaPlant(const std::string& name, int age, const std::string& habitat, const std::string& plantType, float growthRate);
    void photosynthesize();
};

class Skill {
protected:
    std::string skill_name;
    int level;

public:
    Skill(const std::string& skill_name, int level);
    virtual void level_up();
    virtual ~Skill() = default;
};

class MarineBiologySkill : public Skill {
private:
    std::vector<std::string> knowledge;

public:
    MarineBiologySkill(int level);
    void study(const std::string& topic);
    void perform_research();
    void interact_with_marine_life(MarineLife& marine_life);
};

class DivingSkill : public Skill {
private:
    std::string equipment;

public:
    DivingSkill(int level, const std::string& equipment);
    void dive(int depth);
    void surface();
    void check_equipment() const;
};

class Home {
protected:
    std::string location;
    std::string design;

public:
    Home(const std::string& location, const std::string& design = "Standard");
    virtual void description() const;
    virtual ~Home() = default;
};

class UnderwaterHome : public Home {
private:
    float depth;

public:
    UnderwaterHome(const std::string& location, float depth, const std::string& design = "Aquatic");
    void buildAquaticHome();
};

class PressureResistantWall {
private:
    std::string material;

public:
    PressureResistantWall(const std::string& material);
    void material_info();
    void buildUnderwaterPressureResWall();
};

