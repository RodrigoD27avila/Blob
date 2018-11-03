#include <fstream>
#include <yaml-cpp/yaml.h>

int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;

    std::ifstream fin(argv[1]);

    YAML::Parser parser(fin);

    YAML::Node doc;
    while (parser.GetNextDocument(doc))
    {
    }

    return 0;
}
