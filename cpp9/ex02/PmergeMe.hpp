#pragma once

#include <algorithm>
#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#include <sys/time.h>

#define MSG_ERR_WRONGARGNB "Error: you need to pass at least one arg"
#define MSG_ERR_ONLYPOSITIVE "Error: only postive number allowed"
#define MSG_ERR_DUP "Error: no duplicate allowed"
#define MSG_ERR_TIMEERROR "Error: failed to get actual time"

typedef struct {
	struct timeval preSort;
	struct timeval postSort;
}				t_time;

typedef struct {
	int	winner;
	int	loser;
}				t_pair;

typedef struct {
	int nb;
	int lostTo;
}				t_historic;

class PmergeMe {
private:
	std::vector<unsigned int> vect;
	std::deque<unsigned int> deq;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	void operator=(const PmergeMe &src);
	~PmergeMe();

	PmergeMe(const int &ac, char **av);
	void printVect() const;
	std::vector<t_pair> makePairVect(const std::vector<unsigned int> &vect);
	std::deque<t_pair> makePairDeq(const std::deque<unsigned int> &vect);
	std::vector<int> JacobsthalSequence(size_t size);
	int		Jacobsthal(int n);
	void	sortVect(std::vector<unsigned int> &pending);
	void	sortDeq(std::deque<unsigned int> &pending);
};

class TimeError : public std::exception {
	public:
		const char* what() const throw() {
			return (MSG_ERR_TIMEERROR);
		}
};
