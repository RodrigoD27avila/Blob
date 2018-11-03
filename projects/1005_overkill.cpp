#include <cstdio>
#include <cmath>
#include <vector>

std::vector<int> stones;
int min = 2147483647;
int sum;

void find(unsigned int next, int result)
{
	int aux = std::abs(sum - (2*result));
	if (aux < min)
		min = aux;

	for (unsigned int i=next; i<stones.size() - 1; i++) {
		find(i+1, result+stones[i]);
	}
}

int main()
{
	int weight = 0;
	int count = 0;
	scanf("%i", &count);

        for (int i=0; i<count; i++) {
                scanf("%i", &weight);
                stones.push_back(weight);
                sum += weight;
        }	

	find(0, 0);
	printf("%i\n", min);
}
