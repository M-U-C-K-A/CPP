#include "PmergeMe.hpp"

static bool isDigital(const char *av) {
	for (size_t i = 0; i < strlen(av); i++) {
		if (!isdigit(av[i]))
			return (false);
	}
	return (true);
}

static bool checkDup(const int ac, char **av) {
	for (size_t i = 1; i < static_cast<size_t>(ac); i++) {
		for (size_t j = i + 1; j < static_cast<size_t>(ac); j++) {
			if (atoi(av[i]) == atoi(av[j])) {
				std::cout << MSG_ERR_DUP << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

static void getTime(struct timeval &src) {
	if (gettimeofday(&src, NULL) == -1)
		throw(TimeError());
}

static void timeToSort(const t_time &time, const std::string &type, const int &size) {
	double preTime = (time.preSort.tv_sec * 1000.0) + (time.preSort.tv_usec / 1000.0);
	double postTime = (time.postSort.tv_sec * 1000.0) + (time.postSort.tv_usec / 1000.0);
	std::cout << "Time to process a range of " << size
	<< " elements with " << type << " : "
	<< postTime - preTime
	<< " ms" << std::endl;
}


static void sort(int ac, char **av) {
	PmergeMe fj(ac, av);
	std::vector<unsigned int>vect;
	std::deque<unsigned int>deq;

	std::cout << "Before:	";
	fj.printVect();

	t_time time;

	try {
		getTime(time.preSort);
		fj.sortVect(vect);
		getTime(time.postSort);
		std::cout << "After:	";
		fj.printVect();
		timeToSort(time, "std::vector", ac - 1);

		getTime(time.preSort);
		fj.sortDeq(deq);
		getTime(time.postSort);
		timeToSort(time, "std::deque", ac - 1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << MSG_ERR_WRONGARGNB << std::endl;
		return (127);
	}

	for (size_t i = 1; i < static_cast<size_t>(ac); i++) {
		if (!isDigital(av[i])) {
			std::cout << MSG_ERR_ONLYPOSITIVE << std::endl;
			return (127);
		}
	}

	if (!checkDup(ac, av))
		return (127);

	sort(ac, av);
	return (0);
}
