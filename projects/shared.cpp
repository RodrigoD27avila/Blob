#include <iostream>
#include <vector>
#include <memory>

class Professor {
public:
	virtual std::string printInfo();	
};

class ProfessorSubstituto : public Professor {
public:
	std::string printInfo() override;

};

class ProfessorSubstitutoFDP : public ProfessorSubstituto {
public:
	std::string printInfo() override;

};

std::string Professor::printInfo()
{
	return "Eu sou um professor!";
}

std::string ProfessorSubstituto::printInfo()
{
	return "Eu sou um professor substituto!";
}

std::string ProfessorSubstitutoFDP::printInfo()
{
	return "Eu sou um professor substituto FDP!";
}

int main(int argc, char **argv)
{
	std::vector<std::shared_ptr<Professor>> professores;
	professores.push_back(std::shared_ptr<Professor>(new Professor()));
	professores.push_back(std::shared_ptr<Professor>(new ProfessorSubstituto()));
	professores.push_back(std::shared_ptr<Professor>(new ProfessorSubstitutoFDP()));

	for (auto &p : professores) {
		std::cout << p->printInfo() << std::endl;
	}
}
