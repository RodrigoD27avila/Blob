#include <cstdio>
#include <memory>
#include <list>
#include <queue>

template<class T>
struct TownComp {
    bool operator() (const T &a, const T &b) const {
        return (a->num > b->num);
    }
};

class Town {
  public:
    Town(int num, int hpns) : num(num), hpns(hpns),
        ptowns(TownComp<std::unique_ptr<Town> >(), towns)
    {
    }

    virtual ~Town() {
    }

  private:
    int num, hpns;
    std::priority_queue<std::unique_ptr<Town> > ptowns;
    std::list<std::unique_ptr<Town> > towns;
};

int main()
{

}
