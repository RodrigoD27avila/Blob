#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

struct Vec3
{
    float x, y, z;
};

struct Power
{
    int         damage;
    std::string name;
};

struct Monster
{
    Vec3               position;
    std::string        name;
    std::vector<Power> powers;
};

void operator >>(const YAML::Node &node, Vec3 &vec)
{
    node[0] >> vec.x;
    node[1] >> vec.y;
    node[2] >> vec.z;
}

void operator >>(const YAML::Node &node, Power &power)
{
    node["name"]   >> power.name;
    node["damage"] >> power.damage;
}

void operator >>(const YAML::Node &node, Monster &monster)
{
    node["name"]     >> monster.name;
    node["position"] >> monster.position;

    const YAML::Node &powers = node["powers"];

    unsigned int i;
    for(i=0; i<powers.size(); ++i)
    {
        Power power;
        powers[i] >> power;
        monster.powers.push_back(power);
    }
}

int main()
{
    std::ifstream fin("monsters.yaml");
    YAML::Parser parser(fin);
    YAML::Node doc;
    parser.GetNextDocument(doc);

    unsigned int i;
    for (i=0; i < doc.size(); ++i)
    {
        Monster monster;
        doc[i] >> monster;
        std::cout << monster.name << std::endl;
    }
}
