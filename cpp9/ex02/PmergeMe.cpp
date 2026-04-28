#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &src) {*this = src;}
void PmergeMe::operator=(const PmergeMe &src) {
	this->vect = src.vect;
	this->deq = src.deq;
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const int &ac, char **av) {
	for (size_t i = 1; i < static_cast<size_t>(ac); i++) {
		this->vect.push_back(atoi(av[i]));
		this->deq.push_back(atoi(av[i]));
	}
}

void	PmergeMe::printVect() const {
	for (size_t i = 0; i < this->vect.size(); i++) {
		std::cout << this->vect[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<t_pair> PmergeMe::makePairVect(const std::vector<unsigned int> &vect) {
	std::vector<t_pair> pairs;

	for (size_t i = 0; i + 1 < vect.size(); i += 2) {
		t_pair tmp;
		if (vect[i] > vect[i + 1]) {
			tmp.winner = vect[i];
			tmp.loser = vect[i + 1];
		} else {
			tmp.winner = vect[i + 1];
			tmp.loser = vect[i];
		}
		pairs.push_back(tmp);
	}

	if (vect.size() % 2 != 0) {
		t_pair tmp;
		tmp.winner = vect.back();
		tmp.loser = -1;
		pairs.push_back(tmp);
	}
	return (pairs);
}

std::deque<t_pair> PmergeMe::makePairDeq(const std::deque<unsigned int> &vect) {
	std::deque<t_pair> pairs;

	for (size_t i = 0; i + 1 < vect.size(); i += 2) {
		t_pair tmp;
		if (vect[i] > vect[i + 1]) {
			tmp.winner = vect[i];
			tmp.loser = vect[i + 1];
		} else {
			tmp.winner = vect[i + 1];
			tmp.loser = vect[i];
		}
		pairs.push_back(tmp);
	}

	if (vect.size() % 2 != 0) {
		t_pair tmp;
		tmp.winner = vect.back();
		tmp.loser = -1;
		pairs.push_back(tmp);
	}
	return (pairs);
}

int PmergeMe::Jacobsthal(int n) {
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);

	int sign;
	if (n % 2 == 0)
		sign = -1;
	else
		sign = 1;

	return (2 * Jacobsthal(n - 1) + sign);
}

std::vector<int> PmergeMe::JacobsthalSequence(size_t size) {
	std::vector<int> jacob;

	jacob.push_back(1);
	if (size == 1) {
		return (jacob);
	}

	int	jacobNb = 3;
	int	lastJacob = 1;
	int	jacobIdx = 4;
	jacob.push_back(jacobNb);
	while (jacob.size() < size) {
		for (int i = jacobNb - 1; i != lastJacob; i--) {
			jacob.push_back(i);
			if (jacob.size() == size) {
				return (jacob);
			}
		}
		lastJacob = jacobNb;
		jacobNb = Jacobsthal(jacobIdx);
		jacob.push_back(jacobNb);
		jacobIdx++;
	}

	return (jacob);
}

void PmergeMe::sortVect(std::vector<unsigned int> &pending) {
	if (this->vect.size() > 1) {
		std::vector<t_pair> pairs = makePairVect(this->vect);
		this->vect.clear();

		for (size_t i = 0; i < pairs.size(); ++i) {
			this->vect.push_back(pairs[i].winner);
			if (pairs[i].loser != -1) {
				pending.push_back(pairs[i].loser);
			}
		}
		sortVect(pending);
		return;
	}

	if (pending.empty()) {
		return ;
	}

	this->vect.insert(this->vect.begin(), pending.back());
	pending.pop_back();

	if (pending.empty()) {
		return ;
	}
	for (size_t i = 0; i < pending.size(); i++) {
		std::cout << pending[i] << std::endl;
	}
	std::vector<int> jacob = JacobsthalSequence(pending.size());

	for (size_t i = 0; i < jacob.size(); ++i) {
		size_t idx = jacob[i];
		if (idx >= pending.size())
			idx = pending.size() - 1;

		int element = pending[idx];

		std::vector<unsigned int>::iterator pos = std::upper_bound(this->vect.begin(), this->vect.end(), element);

		this->vect.insert(pos, element);

		pending.erase(pending.begin() + idx);
	}
}

void PmergeMe::sortDeq(std::deque<unsigned int> &pending) {
	if (this->deq.size() > 1) {
		std::deque<t_pair> pairs = makePairDeq(this->deq);
		this->deq.clear();

		for (size_t i = 0; i < pairs.size(); ++i) {
			this->deq.push_back(pairs[i].winner);
			if (pairs[i].loser != -1) {
				pending.push_back(pairs[i].loser);
			}
		}
		sortDeq(pending);
		return;
	}

	if (pending.empty()) {
		return ;
	}

	this->deq.insert(this->deq.begin(), pending.back());
	pending.pop_back();

	if (pending.empty()) {
		return ;
	}

	std::vector<int> jacob = JacobsthalSequence(pending.size());

	for (size_t i = 0; i < jacob.size(); ++i) {
		size_t idx = jacob[i];
		if (idx >= pending.size())
			idx = pending.size() - 1;

		int element = pending[idx];

		std::deque<unsigned int>::iterator pos = std::upper_bound(deq.begin(), deq.end(), element);

		deq.insert(pos, element);

		pending.erase(pending.begin() + idx);
	}
}
